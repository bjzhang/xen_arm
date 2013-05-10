/*
 * xen/arch/arm/arm32/debug-sun6i.inc
 *
 * Allwinner A31 specific debug code
 *
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

#define EARLY_UART_BASE_ADDRESS 0x01c28000

/* sun6i UART initialization
 * rb: register which contains the UART base address
 * rc: scratch register 1
 * rd: scratch register 2 (unused here) */
.macro early_uart_init rb, rc, rd
/* assume the uart already init by u-boot */
.endm

/* sun6i UART wait UART to be ready to transmit
 * rb: register which contains the UART base address
 * rc: scratch register */
.macro early_uart_ready rb, rc
1:
        ldr   \rc, [\rb, #0x7c]     /* <- UART_USR (Status Register) */
        tst   \rc, #0x2             /* Check BUSY bit */
        beq   1b                    /* Wait for the UART to be ready */
.endm

/* sun6i UART transmit character
 * rb: register which contains the UART base address
 * rt: register which contains the character to transmit */
.macro early_uart_transmit rb, rt
        str   \rt, [\rb]            /* -> UART_THR (Transmit Holding Register) */
.endm

/*
 * Local variables:
 * mode: ASM
 * indent-tabs-mode: nil
 * End:
 */
