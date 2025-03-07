/**
 * @file esp_packet_decrypt.h
 * @brief ESP packet decryption
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2022-2024 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneIPSEC Open.
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

#ifndef _ESP_PACKET_DECRYPT_H
#define _ESP_PACKET_DECRYPT_H

//Dependencies
#include "ipsec/ipsec.h"
#include "esp/esp.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//ESP related functions
error_t espDecryptPacket(IpsecContext *context, IpsecSadEntry *sa,
   const EspHeader *espHeader, uint8_t *payload, size_t *payloadLen,
   uint8_t *nextHeader);

error_t espVerifyChecksum(IpsecContext *context, IpsecSadEntry *sa,
   const EspHeader *espHeader, const uint8_t *payload, size_t length,
   const uint8_t *icv);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
