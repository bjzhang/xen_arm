#ifndef __ASM_ARM_PLATFORMS_SUN6I_H
#define __ASM_ASM_PLATFORMS_SUN6I_H

//#define EXYNOS5_MCT_BASE            0x101c0000
//#define EXYNOS5_MCT_G_TCON          0x240       /* Relative to MCT_BASE */
//#define EXYNOS5_MCT_G_TCON_START    (1 << 8)
//
//#define EXYNOS5_PA_CHIPID           0x10000000
//#define EXYNOS5_PA_TIMER            0x12dd0000
///* Base address of system controller */
//#define EXYNOS5_PA_PMU              0x10040000
//
//#define EXYNOS5_SWRESET             0x0400      /* Relative to PA_PMU */
//
//#define S5P_PA_SYSRAM   0x02020000

/* Constants below is only used in assembly because the DTS is not yet parsed */
#ifdef __ASSEMBLY__

/* GIC Base Address */
/* \TODO it should be CPU base */
#define AW_GIC_DIST_BASE             0x01c81000
#define AW_GIC_CPU_BASE              0x01c82000
#define SUN6I_GIC_BASE_ADDRESS       AW_GIC_CPU_BASE

/* Timer's frequency */
/* \TODO I do not know yet, assume it 24MHz. check it later */
#define SUN6I_TIMER_FREQUENCY       (24 * 1000 * 1000) /* 24 MHz */

/* Arndale machine ID */
/* \TODO 3894 is off upstream number for sun6i. 4137 is upstream number for sun6i */
//#define MACH_TYPE_SUN6I             4137
#define MACH_TYPE_SUN6I             3892

#endif /* __ASSEMBLY__ */

#endif /* __ASM_ARM_PLATFORMS_SUN6I_H */
/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 */
