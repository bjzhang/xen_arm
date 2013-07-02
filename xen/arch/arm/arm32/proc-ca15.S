/*
 * xen/arch/arm/proc-ca15.S
 *
 * Cortex A15 specific initializations
 *
 * Copyright (c) 2011 Citrix Systems.
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
#include <asm/processor-ca15.h>

.globl cortex_a15_init
cortex_a15_init:
        b     v7_init

        .section ".init.proc.info", #alloc, #execinstr
        .type __v7_ca15mp_proc_info, #object
__v7_ca15mp_proc_info:
        .long 0x410FC0F0             /* Cortex-A15 */
        b     cortex_a15_init
        .size __v7_ca15mp_proc_info, . - __v7_ca15mp_proc_info
/*
 * Local variables:
 * mode: ASM
 * indent-tabs-mode: nil
 * End:
 */
