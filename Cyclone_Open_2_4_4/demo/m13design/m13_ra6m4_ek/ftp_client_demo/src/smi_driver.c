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
#include "bsp_api.h"
#include "m13_ra6m4_ek.h"
#include "core/net.h"
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
   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure MDIO as an open-drain output
   R_PFS->MDIO_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk |
      R_PFS_PORT_PIN_PmnPFS_NCODR_Msk;

   //Configure MDC as an output
   R_PFS->MDC_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Deassert MDC
   MDC_PORT->PCNTR3 = MDC_MASK << R_PORT0_PCNTR3_PORR_Pos;

   //Successful processing
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
   //Synchronization pattern
   smiWriteData(SMI_SYNC, 32);
   //Start of frame
   smiWriteData(SMI_START, 2);
   //Set up a write operation
   smiWriteData(opcode, 2);
   //Write PHY address
   smiWriteData(phyAddr, 5);
   //Write register address
   smiWriteData(regAddr, 5);
   //Turnaround
   smiWriteData(SMI_TA, 2);
   //Write register value
   smiWriteData(data, 16);
   //Release MDIO
   smiReadData(1);
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
   uint16_t data;

   //Synchronization pattern
   smiWriteData(SMI_SYNC, 32);
   //Start of frame
   smiWriteData(SMI_START, 2);
   //Set up a read operation
   smiWriteData(opcode, 2);
   //Write PHY address
   smiWriteData(phyAddr, 5);
   //Write register address
   smiWriteData(regAddr, 5);
   //Turnaround to avoid contention
   smiReadData(1);
   //Read register value
   data = smiReadData(16);
   //Force the PHY to release the MDIO pin
   smiReadData(1);

   //Return the value of the PHY register
   return data;
}


/**
 * @brief SMI write operation
 * @param[in] data Raw data to be written
 * @param[in] length Number of bits to be written
 **/

void smiWriteData(uint32_t data, uint_t length)
{
   uint_t i;

   //Skip the most significant bits since they are meaningless
   data <<= 32 - length;

   //Write the specified number of bits
   for(i = 0; i < length; i++)
   {
      //Write MDIO
      if(data & 0x80000000)
      {
         MDIO_PORT->PCNTR3 = MDIO_MASK << R_PORT0_PCNTR3_POSR_Pos;
      }
      else
      {
         MDIO_PORT->PCNTR3 = MDIO_MASK << R_PORT0_PCNTR3_PORR_Pos;
      }

      //Delay
      usleep(1);
      //Assert MDC
      MDC_PORT->PCNTR3 = MDC_MASK << R_PORT0_PCNTR3_POSR_Pos;
      //Delay
      usleep(1);
      //Deassert MDC
      MDC_PORT->PCNTR3 = MDC_MASK << R_PORT0_PCNTR3_PORR_Pos;

      //Rotate data
      data <<= 1;
   }
}


/**
 * @brief SMI read operation
 * @param[in] length Number of bits to be read
 * @return Data resulting from the MDIO read operation
 **/

uint32_t smiReadData(uint_t length)
{
   uint_t i;
   uint32_t data;

   //Release MDIO
   MDIO_PORT->PCNTR3 = MDIO_MASK << R_PORT0_PCNTR3_POSR_Pos;

   //Initialize data
   data = 0;

   //Read the specified number of bits
   for(i = 0; i < length; i++)
   {
      //Rotate data
      data <<= 1;

      //Assert MDC
      MDC_PORT->PCNTR3 = MDC_MASK << R_PORT0_PCNTR3_POSR_Pos;
      //Delay
      usleep(1);
      //Deassert MDC
      MDC_PORT->PCNTR3 = MDC_MASK << R_PORT0_PCNTR3_PORR_Pos;
      //Delay
      usleep(1);

      //Check MDIO state
      if((MDIO_PORT->PCNTR2 & MDIO_MASK) != 0)
      {
         data |= 0x00000001;
      }
   }

   //Return the received data
   return data;
}
