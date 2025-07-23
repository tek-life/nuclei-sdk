/* SPDX-License-Identifier: GPL-2.0 */
/*
 * USB PHY defines
 *
 * These APIs may be used between USB controllers.  USB device drivers
 * (for either host or peripheral roles) don't use these calls; they
 * continue to use just usb_device and usb_gadget.
 */

#ifndef __LINUX_USB_PHY_H
#define __LINUX_USB_PHY_H

#if 0
#include <dm/ofnode.h>
#endif
enum usb_phy_interface {
	USBPHY_INTERFACE_MODE_UNKNOWN,
	USBPHY_INTERFACE_MODE_UTMI,
	USBPHY_INTERFACE_MODE_UTMIW,
};

typedef void * ofnode;

static inline enum usb_phy_interface usb_get_phy_mode(ofnode node)
{
	return USBPHY_INTERFACE_MODE_UNKNOWN;
}

#endif /* __LINUX_USB_PHY_H */
