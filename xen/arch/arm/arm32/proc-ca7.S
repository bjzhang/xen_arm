/*
 * xen/arch/arm/proc-ca7.S
 *
 * Cortex A7 specific initializations
 *
 * Bamvor Jian Zhang <bjzhang@suse.com>
 * Copyright (c) 2013 SUSE
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <asm/asm_defns.h>
#include <asm/processor-ca7.h>

#if (defined (EARLY_PRINTK)) && (defined (EARLY_PRINTK_INC))
#include EARLY_PRINTK_INC
#endif
.globl cortex_a7_init
cortex_a7_init:
        b     v7_init


/* Print a 32-bit number in hex.  Specific to the PL011 UART.
 * r0: Number to print.
 * r11: Early UART base address
 * Clobbers r0-r3 */
putn:
        adr   r1, hex
        mov   r3, #8
1:
        early_uart_ready r11, r2
        and   r2, r0, #0xf0000000    /* Mask off the top nybble */
        ldrb  r2, [r1, r2, lsr #28]  /* Convert to a char */
        early_uart_transmit r11, r2
        lsl   r0, #4                 /* Roll it through one nybble at a time */
        subs  r3, r3, #1
        bne   1b
        mov   pc, lr

hex:    .ascii "0123456789abcdef"
        .align 2


        .section ".init.proc.info", #alloc, #execinstr
        .type __v7_ca7mp_proc_info, #object
__v7_ca7mp_proc_info:
        .long 0x410FC070             /* Cortex-A7 */
        b     cortex_a7_init
        .size __v7_ca7mp_proc_info, . - __v7_ca7mp_proc_info
/*
 * Local variables:
 * mode: ASM
 * indent-tabs-mode: nil
 * End:
 */
