/**
 * @file ah_algorithms.h
 * @brief AH algorithm negotiation
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

#ifndef _AH_ALGORITHMS_H
#define _AH_ALGORITHMS_H

//Dependencies
#include "ah/ah.h"
#include "ike/ike.h"

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//AH related functions
error_t ahSelectAuthAlgo(IkeChildSaEntry *childSa, uint16_t authAlgoId);

error_t ahAddSupportedTransforms(IkeContext *context, IkeProposal *proposal,
   uint8_t **lastSubstruc);

error_t ahAddSupportedAuthTransforms(IkeContext *context,
   IkeProposal *proposal, uint8_t **lastSubstruc);

error_t ahAddSupportedEsnTransforms(IkeContext *context,
   IkeProposal *proposal, uint8_t **lastSubstruc);

uint16_t ahSelectAuthTransform(IkeContext *context, const IkeProposal *proposal,
   size_t proposalLen);

uint16_t ahSelectEsnTransform(IkeContext *context, const IkeProposal *proposal,
   size_t proposalLen);

error_t ahSelectSaProposal(IkeChildSaEntry *childSa, const IkeSaPayload *payload);
error_t ahCheckSaProposal(IkeChildSaEntry *childSa, const IkeSaPayload *payload);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
