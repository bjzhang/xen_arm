#include <xen/config.h>

#define DISABLE_EX

#if __LINUX_ARM_ARCH__ >= 6
	.macro	bitop, instr
	ands	ip, r1, #3
	strneb	r1, [ip]		@ assert word-aligned
	mov	r2, #1
	and	r3, r0, #31		@ Get bit offset
	mov	r0, r0, lsr #5
	add	r1, r1, r0, lsl #2	@ Get word offset
	mov	r3, r2, lsl r3
#ifdef DISABLE_EX
	ldr		r2, [r1]
#else
	ldrex	r2, [r1]
#endif
	\instr	r2, r2, r3
#ifdef DISABLE_EX
	str		r2, [r1]
#else
	strex	r0, r2, [r1]
	cmp	r0, #0
	bne	1b
#endif
	bx	lr
	.endm

	.macro	testop, instr, store
	ands	ip, r1, #3
	strneb	r1, [ip]		@ assert word-aligned
	mov	r2, #1
	and	r3, r0, #31		@ Get bit offset
	mov	r0, r0, lsr #5
	add	r1, r1, r0, lsl #2	@ Get word offset
	mov	r3, r2, lsl r3		@ create mask
#ifdef DISABLE_EX
    dmb
	ldrex	r2, [r1]
#else
	smp_dmb
1:	ldrex	r2, [r1]
#endif
	ands	r0, r2, r3		@ save old value of bit
	\instr	r2, r2, r3		@ toggle bit
#ifdef DISABLE_EX
	strex	ip, r2, [r1]
	dmb
	mov	r0, #0
#else
	strex	ip, r2, [r1]
	cmp	ip, #0
	bne	1b
	smp_dmb
#endif
	cmp	r0, #0
	movne	r0, #1
2:	bx	lr
	.endm
#else
	.macro	bitop, name, instr
ENTRY(	\name		)
UNWIND(	.fnstart	)
	ands	ip, r1, #3
	strneb	r1, [ip]		@ assert word-aligned
	and	r2, r0, #31
	mov	r0, r0, lsr #5
	mov	r3, #1
	mov	r3, r3, lsl r2
	save_and_disable_irqs ip
	ldr	r2, [r1, r0, lsl #2]
	\instr	r2, r2, r3
	str	r2, [r1, r0, lsl #2]
	restore_irqs ip
	mov	pc, lr
UNWIND(	.fnend		)
ENDPROC(\name		)
	.endm

/**
 * testop - implement a test_and_xxx_bit operation.
 * @instr: operational instruction
 * @store: store instruction
 *
 * Note: we can trivially conditionalise the store instruction
 * to avoid dirtying the data cache.
 */
	.macro	testop, name, instr, store
ENTRY(	\name		)
UNWIND(	.fnstart	)
	ands	ip, r1, #3
	strneb	r1, [ip]		@ assert word-aligned
	and	r3, r0, #31
	mov	r0, r0, lsr #5
	save_and_disable_irqs ip
	ldr	r2, [r1, r0, lsl #2]!
	mov	r0, #1
	tst	r2, r0, lsl r3
	\instr	r2, r2, r0, lsl r3
	\store	r2, [r1]
	moveq	r0, #0
	restore_irqs ip
	mov	pc, lr
UNWIND(	.fnend		)
ENDPROC(\name		)
	.endm
#endif
