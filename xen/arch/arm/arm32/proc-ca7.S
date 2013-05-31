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

.globl cortex_a7_init
cortex_a7_init:
        /* Set up the SMP bit in ACTLR */
        mrc   CP32(r0, ACTLR)
        orr   r0, r0, #(ACTLR_CA7_SMP) /* enable SMP bit */
        mcr   CP32(r0, ACTLR)
        mov   pc, lr

/*
 * Local variables:
 * mode: ASM
 * indent-tabs-mode: nil
 * End:
 */
