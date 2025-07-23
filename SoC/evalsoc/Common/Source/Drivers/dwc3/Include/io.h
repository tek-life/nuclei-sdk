/**
 * io.h - DesignWare USB3 DRD IO Header
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com
 *
 * Authors: Felipe Balbi <balbi@ti.com>,
 *	    Sebastian Andrzej Siewior <bigeasy@linutronix.de>
 *
 * Taken from Linux Kernel v3.19-rc1 (drivers/usb/dwc3/io.h) and ported
 * to uboot.
 *
 * commit 2c4cbe6e5a : usb: dwc3: add tracepoints to aid debugging
 *
 * SPDX-License-Identifier:     GPL-2.0
 *
 */

#ifndef __DRIVERS_USB_DWC3_IO_H
#define __DRIVERS_USB_DWC3_IO_H
#if 0
#include <asm/io.h>
#endif
#define CONFIG_SYS_CACHELINE_SIZE 32
#define	CACHELINE_SIZE		CONFIG_SYS_CACHELINE_SIZE

#define __raw_writeb __raw_writeb
static inline void __raw_writeb(unsigned char val, volatile void *addr)
{
    asm volatile("sb %0, 0(%1)" : : "r" (val), "r" (addr));
}

#define __raw_writew __raw_writew
static inline void __raw_writew(unsigned short val, volatile void *addr)
{
    asm volatile("sh %0, 0(%1)" : : "r" (val), "r" (addr));
}

#define __raw_writel __raw_writel
static inline void __raw_writel(unsigned long val, volatile void *addr)
{
    asm volatile("sw %0, 0(%1)" : : "r" (val), "r" (addr));
}

#define __raw_readb __raw_readb
static inline unsigned char __raw_readb(const volatile void *addr)
{
    unsigned char val;
    asm volatile("lb %0, 0(%1)" : "=r" (val) : "r" (addr));
    return val;
}
#define __raw_readw __raw_readw
static inline unsigned short __raw_readw(const volatile void *addr)
{
    unsigned short val;
    asm volatile("lh %0, 0(%1)" : "=r" (val) : "r" (addr));
    return val;
}

#define __raw_readl __raw_readl
static inline unsigned long __raw_readl(const volatile void *addr)
{
    unsigned long val;
    asm volatile("lw %0, 0(%1)" : "=r" (val) : "r" (addr));
    return val;
}

/*
 * FIXME: I'm flip-flopping on whether or not we should keep this or enforce
 * the ordering with I/O on spinlocks like PowerPC does.  The worry is that
 * drivers won't get this correct, but I also don't want to introduce a fence
 * into the lock code that otherwise only uses AMOs (and is essentially defined
 * by the ISA to be correct).   For now I'm leaving this here: "o,w" is
 * sufficient to ensure that all writes to the device have completed before the
 * write to the spinlock is allowed to commit.  I surmised this from reading
 * "ACQUIRES VS I/O ACCESSES" in memory-barriers.txt.
 */
#define mmiowb() __asm__ __volatile__("fence o,w" : : : "memory");

/*
 * I/O memory access primitives. Reads are ordered relative to any
 * following Normal memory access. Writes are ordered relative to any prior
 * Normal memory access.  The memory barriers here are necessary as RISC-V
 * doesn't define any ordering between the memory space and the I/O space.
 */
#define __io_br() do {} while (0)

#define __io_ar() __asm__ __volatile__("fence i,r" : : : "memory");
#define __io_bw() __asm__ __volatile__("fence w,o" : : : "memory");

#define __io_aw() do {} while (0)

#define readb(c) ({ unsigned char __v; __io_br(); __v = __raw_readb((const volatile void *)c); __io_ar(); __v; })
#define readw(c) ({ unsigned short __v; __io_br(); __v = __raw_readw((const volatile void *)c); __io_ar(); __v; })
#define readl(c) ({ unsigned long __v; __io_br(); __v = __raw_readl((const volatile void *)c); __io_ar(); __v; })
// clang-format on

#define writeb(v, c) ({ __io_bw(); __raw_writeb((v),((volatile void *)c)); __io_aw(); })
#define writew(v, c) ({ __io_bw(); __raw_writew((v),((volatile void *)c)); __io_aw(); })
#define writel(v, c) ({ __io_bw(); __raw_writel((v),((volatile void *)c)); __io_aw(); })


static inline u32 dwc3_readl(void __iomem *base, u32 offset)
{
	unsigned long offs = offset - DWC3_GLOBALS_REGS_START;
	u32 value;

	/*
	 * We requested the mem region starting from the Globals address
	 * space, see dwc3_probe in core.c.
	 * However, the offsets are given starting from xHCI address space.
	 */
	value = readl(base + offs);

	return value;
}

static inline void dwc3_writel(void __iomem *base, u32 offset, u32 value)
{
	unsigned long offs = offset - DWC3_GLOBALS_REGS_START;

	/*
	 * We requested the mem region starting from the Globals address
	 * space, see dwc3_probe in core.c.
	 * However, the offsets are given starting from xHCI address space.
	 */
	writel(value, base + offs);
}

static inline void dwc3_invalidate_cache(uintptr_t addr, int length)
{
	//invalidate_dcache_range(addr, addr + ROUND(length, CACHELINE_SIZE));
}

static inline void dwc3_flush_cache(uintptr_t addr, int length)
{
	//flush_dcache_range(addr, addr + ROUND(length, CACHELINE_SIZE));
}
#endif /* __DRIVERS_USB_DWC3_IO_H */
