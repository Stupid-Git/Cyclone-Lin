/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "evkmimxrt1060_sdram_ini_dcd.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.xip_board"
#endif

#if defined(XIP_BOOT_HEADER_ENABLE) && (XIP_BOOT_HEADER_ENABLE == 1)
#if defined(XIP_BOOT_HEADER_DCD_ENABLE) && (XIP_BOOT_HEADER_DCD_ENABLE == 1)
#if defined(__CC_ARM) || defined(__ARMCC_VERSION) || defined(__GNUC__)
__attribute__((section(".boot_hdr.dcd_data")))
#elif defined(__ICCARM__)
#pragma location = ".boot_hdr.dcd_data"
#endif
/*************************************
 *  DCD Data
 *************************************/
const uint8_t dcd_data[] = {
    /*0000*/ DCD_TAG_HEADER,
    0x04,
    0x30,
    0x41,
    0xCC,
    0x03,
    0xAC,
    0x04,
    0x40,
    0x0F,
    0xC0,
    0x68,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    /*0010*/ 0x40,
    0x0F,
    0xC0,
    0x6C,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0x40,
    0x0F,
    0xC0,
    0x70,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    /*0020*/ 0x40,
    0x0F,
    0xC0,
    0x74,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0x40,
    0x0F,
    0xC0,
    0x78,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    /*0030*/ 0x40,
    0x0F,
    0xC0,
    0x7C,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0x40,
    0x0F,
    0xC0,
    0x80,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    /*0040*/ 0x40,
    0x0D,
    0x80,
    0x30,
    0x00,
    0x00,
    0x20,
    0x01,
    0x40,
    0x0D,
    0x81,
    0x00,
    0x00,
    0x1D,
    0x00,
    0x00,
    /*0050*/ 0x40,
    0x0F,
    0xC0,
    0x14,
    0x00,
    0x01,
    0x0D,
    0x40,
    0x40,
    0x1F,
    0x80,
    0x14,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0060*/ 0x40,
    0x1F,
    0x80,
    0x18,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x1C,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0070*/ 0x40,
    0x1F,
    0x80,
    0x20,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x24,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0080*/ 0x40,
    0x1F,
    0x80,
    0x28,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x2C,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0090*/ 0x40,
    0x1F,
    0x80,
    0x30,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x34,
    0x00,
    0x00,
    0x00,
    0x00,
    /*00a0*/ 0x40,
    0x1F,
    0x80,
    0x38,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x3C,
    0x00,
    0x00,
    0x00,
    0x00,
    /*00b0*/ 0x40,
    0x1F,
    0x80,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x44,
    0x00,
    0x00,
    0x00,
    0x00,
    /*00c0*/ 0x40,
    0x1F,
    0x80,
    0x48,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x4C,
    0x00,
    0x00,
    0x00,
    0x00,
    /*00d0*/ 0x40,
    0x1F,
    0x80,
    0x50,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x54,
    0x00,
    0x00,
    0x00,
    0x00,
    /*00e0*/ 0x40,
    0x1F,
    0x80,
    0x58,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x5C,
    0x00,
    0x00,
    0x00,
    0x00,
    /*00f0*/ 0x40,
    0x1F,
    0x80,
    0x60,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x64,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0100*/ 0x40,
    0x1F,
    0x80,
    0x68,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x6C,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0110*/ 0x40,
    0x1F,
    0x80,
    0x70,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x74,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0120*/ 0x40,
    0x1F,
    0x80,
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x7C,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0130*/ 0x40,
    0x1F,
    0x80,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x84,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0140*/ 0x40,
    0x1F,
    0x80,
    0x88,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x8C,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0150*/ 0x40,
    0x1F,
    0x80,
    0x90,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x94,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0160*/ 0x40,
    0x1F,
    0x80,
    0x98,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0x9C,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0170*/ 0x40,
    0x1F,
    0x80,
    0xA0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0xA4,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0180*/ 0x40,
    0x1F,
    0x80,
    0xA8,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x80,
    0xAC,
    0x00,
    0x00,
    0x00,
    0x00,
    /*0190*/ 0x40,
    0x1F,
    0x80,
    0xB0,
    0x00,
    0x00,
    0x00,
    0x10,
    0x40,
    0x1F,
    0x80,
    0xB4,
    0x00,
    0x00,
    0x00,
    0x00,
    /*01a0*/ 0x40,
    0x1F,
    0x80,
    0xB8,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x1F,
    0x82,
    0x04,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*01b0*/ 0x40,
    0x1F,
    0x82,
    0x08,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x0C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*01c0*/ 0x40,
    0x1F,
    0x82,
    0x10,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x14,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*01d0*/ 0x40,
    0x1F,
    0x82,
    0x18,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x1C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*01e0*/ 0x40,
    0x1F,
    0x82,
    0x20,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x24,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*01f0*/ 0x40,
    0x1F,
    0x82,
    0x28,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x2C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0200*/ 0x40,
    0x1F,
    0x82,
    0x30,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x34,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0210*/ 0x40,
    0x1F,
    0x82,
    0x38,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x3C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0220*/ 0x40,
    0x1F,
    0x82,
    0x40,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x44,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0230*/ 0x40,
    0x1F,
    0x82,
    0x48,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x4C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0240*/ 0x40,
    0x1F,
    0x82,
    0x50,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x54,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0250*/ 0x40,
    0x1F,
    0x82,
    0x58,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x5C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0260*/ 0x40,
    0x1F,
    0x82,
    0x60,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x64,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0270*/ 0x40,
    0x1F,
    0x82,
    0x68,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x6C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0280*/ 0x40,
    0x1F,
    0x82,
    0x70,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x74,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*0290*/ 0x40,
    0x1F,
    0x82,
    0x78,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x7C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*02a0*/ 0x40,
    0x1F,
    0x82,
    0x80,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x84,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*02b0*/ 0x40,
    0x1F,
    0x82,
    0x88,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x8C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*02c0*/ 0x40,
    0x1F,
    0x82,
    0x90,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x94,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*02d0*/ 0x40,
    0x1F,
    0x82,
    0x98,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0x9C,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*02e0*/ 0x40,
    0x1F,
    0x82,
    0xA0,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x1F,
    0x82,
    0xA4,
    0x00,
    0x01,
    0x10,
    0xF9,
    /*02f0*/ 0x40,
    0x1F,
    0x82,
    0xA8,
    0x00,
    0x01,
    0x10,
    0xF9,
    0x40,
    0x2F,
    0x00,
    0x00,
    0x10,
    0x00,
    0x00,
    0x04,
    /*0300*/ 0x40,
    0x2F,
    0x00,
    0x08,
    0x00,
    0x03,
    0x05,
    0x24,
    0x40,
    0x2F,
    0x00,
    0x0C,
    0x06,
    0x03,
    0x05,
    0x24,
    /*0310*/ 0x40,
    0x2F,
    0x00,
    0x10,
    0x80,
    0x00,
    0x00,
    0x1B,
    0x40,
    0x2F,
    0x00,
    0x14,
    0x82,
    0x00,
    0x00,
    0x1B,
    /*0320*/ 0x40,
    0x2F,
    0x00,
    0x18,
    0x84,
    0x00,
    0x00,
    0x1B,
    0x40,
    0x2F,
    0x00,
    0x1C,
    0x86,
    0x00,
    0x00,
    0x1B,
    /*0330*/ 0x40,
    0x2F,
    0x00,
    0x20,
    0x90,
    0x00,
    0x00,
    0x21,
    0x40,
    0x2F,
    0x00,
    0x24,
    0xA0,
    0x00,
    0x00,
    0x19,
    /*0340*/ 0x40,
    0x2F,
    0x00,
    0x28,
    0xA8,
    0x00,
    0x00,
    0x17,
    0x40,
    0x2F,
    0x00,
    0x2C,
    0xA9,
    0x00,
    0x00,
    0x1B,
    /*0350*/ 0x40,
    0x2F,
    0x00,
    0x30,
    0x00,
    0x00,
    0x00,
    0x21,
    0x40,
    0x2F,
    0x00,
    0x04,
    0x00,
    0x00,
    0x79,
    0xA8,
    /*0360*/ 0x40,
    0x2F,
    0x00,
    0x40,
    0x00,
    0x00,
    0x0F,
    0x31,
    0x40,
    0x2F,
    0x00,
    0x44,
    0x00,
    0x65,
    0x29,
    0x22,
    /*0370*/ 0x40,
    0x2F,
    0x00,
    0x48,
    0x00,
    0x01,
    0x09,
    0x20,
    0x40,
    0x2F,
    0x00,
    0x4C,
    0x50,
    0x21,
    0x0A,
    0x08,
    /*0380*/ 0x40,
    0x2F,
    0x00,
    0x80,
    0x00,
    0x00,
    0x00,
    0x21,
    0x40,
    0x2F,
    0x00,
    0x84,
    0x00,
    0x88,
    0x88,
    0x88,
    /*0390*/ 0x40,
    0x2F,
    0x00,
    0x94,
    0x00,
    0x00,
    0x00,
    0x02,
    0x40,
    0x2F,
    0x00,
    0x98,
    0x00,
    0x00,
    0x00,
    0x00,
    /*03a0*/ 0x40,
    0x2F,
    0x00,
    0x90,
    0x80,
    0x00,
    0x00,
    0x00,
    0x40,
    0x2F,
    0x00,
    0x9C,
    0xA5,
    0x5A,
    0x00,
    0x0F,
    /*03b0*/ 0xCF,
    0x00,
    0x0C,
    0x1C,
    0x40,
    0x2F,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x00,
    0x01,
    0xCC,
    0x00,
    0x14,
    0x04,
    /*03c0*/ 0x40,
    0x2F,
    0x00,
    0x90,
    0x80,
    0x00,
    0x00,
    0x00,
    0x40,
    0x2F,
    0x00,
    0x9C,
    0xA5,
    0x5A,
    0x00,
    0x0C,
    /*03d0*/ 0xCF,
    0x00,
    0x0C,
    0x1C,
    0x40,
    0x2F,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x00,
    0x01,
    0xCC,
    0x00,
    0x14,
    0x04,
    /*03e0*/ 0x40,
    0x2F,
    0x00,
    0x90,
    0x80,
    0x00,
    0x00,
    0x00,
    0x40,
    0x2F,
    0x00,
    0x9C,
    0xA5,
    0x5A,
    0x00,
    0x0C,
    /*03f0*/ 0xCF,
    0x00,
    0x0C,
    0x1C,
    0x40,
    0x2F,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x00,
    0x01,
    0xCC,
    0x00,
    0x1C,
    0x04,
    /*0400*/ 0x40,
    0x2F,
    0x00,
    0xA0,
    0x00,
    0x00,
    0x00,
    0x33,
    0x40,
    0x2F,
    0x00,
    0x90,
    0x80,
    0x00,
    0x00,
    0x00,
    /*0410*/ 0x40,
    0x2F,
    0x00,
    0x9C,
    0xA5,
    0x5A,
    0x00,
    0x0A,
    0xCF,
    0x00,
    0x0C,
    0x1C,
    0x40,
    0x2F,
    0x00,
    0x3C,
    /*0420*/ 0x00,
    0x00,
    0x00,
    0x01,
    0xCC,
    0x00,
    0x0C,
    0x04,
    0x40,
    0x2F,
    0x00,
    0x4C,
    0x50,
    0x21,
    0x0A,
    0x09,
};
#else
/*************************************
 *  DCD Data
 *************************************/
const uint8_t dcd_data[] = {0x00};
#endif /* XIP_BOOT_HEADER_DCD_ENABLE */
#endif /* XIP_BOOT_HEADER_ENABLE */
