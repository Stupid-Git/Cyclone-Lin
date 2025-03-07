/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if (defined(CPU_MKV58F1M0VLL24) || defined(CPU_MKV58F1M0VLQ24) || defined(CPU_MKV58F1M0VMD24) || \
    defined(CPU_MKV58F512VLL24) || defined(CPU_MKV58F512VLQ24) || defined(CPU_MKV58F512VMD24))

#define KV58F24_SERIES

/* CMSIS-style register definitions */
#include "MKV58F24.h"
/* CPU specific feature definitions */
#include "MKV58F24_features.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
