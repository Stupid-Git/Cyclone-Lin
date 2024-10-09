/**
 * @file smi_driver.c
 * @brief Serial management interface driver
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2024 Oryx Embedded SARL. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.4.4
 **/

//Dependencies
#include "core/net.h"
#include "drivers/mac/mpc5748_eth1_driver.h"
#include "smi_driver.h"
#include "debug.h"


/**
 * @brief SMI driver
 **/

const SmiDriver smiDriver =
{
   smiInit,
   smiWritePhyReg,
   smiReadPhyReg
};


/**
 * @brief Initialize serial management interface
 * @return Error code
 **/

error_t smiInit(void)
{
   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Write PHY register
 * @param[in] opcode Access type (2 bits)
 * @param[in] phyAddr PHY address (5 bits)
 * @param[in] regAddr Register address (5 bits)
 * @param[in] data Register value
 **/

void smiWritePhyReg(uint8_t opcode, uint8_t phyAddr,
   uint8_t regAddr, uint16_t data)
{
   //The PHY is managed via the MDC/MDIO interface of ENET0 instance
   mpc5748Eth1WritePhyReg(opcode, phyAddr, regAddr, data);
}


/**
 * @brief Read PHY register
 * @param[in] opcode Access type (2 bits)
 * @param[in] phyAddr PHY address (5 bits)
 * @param[in] regAddr Register address (5 bits)
 * @return Register value
 **/

uint16_t smiReadPhyReg(uint8_t opcode, uint8_t phyAddr,
   uint8_t regAddr)
{
   //The PHY is managed via the MDC/MDIO interface of ENET0 instance
   return mpc5748Eth1ReadPhyReg(opcode, phyAddr, regAddr);
}
