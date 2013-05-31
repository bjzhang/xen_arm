#ifndef __ASM_ARM_PROCESSOR_CA7_H
#define __ASM_ARM_PROCESSOR_CA7_H


#define CORTEX_A7_ID     (0x410FC070)

/* ACTLR Auxiliary Control Register, Cortex A7 */
#define ACTLR_CA7_DDI                (1<<28)
#define ACTLR_CA7_DDVM               (1<<15)
/* 2 bits */
#define ACTLR_CA7_L1PCTL             (1<<13)
#define ACTLR_CA7_L1RADIS            (1<<12)
#define ACTLR_CA7_L2RADIS            (1<<11)
#define ACTLR_CA7_DODMBS             (1<<10)
#define ACTLR_CA7_SMP                (1<<6)

#endif /* __ASM_ARM_PROCESSOR_CA7_H */
/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 */
