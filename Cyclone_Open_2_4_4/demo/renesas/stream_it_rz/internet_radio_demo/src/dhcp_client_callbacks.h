/**
 * @file dhcp_client_callbacks.h
 * @brief DHCP client custom callbacks
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

#ifndef _DHCP_CLIENT_CALLBACKS_H
#define _DHCP_CLIENT_CALLBACKS_H

//Dependencies
#include "core/net.h"
#include "dhcp/dhcp_client.h"

//DHCP client callbacks
void dhcpClientTimeoutCallback(DhcpClientContext *context,
   NetInterface *interface);

void dhcpClientLinkChangeCallback(DhcpClientContext *context,
   NetInterface *interface, bool_t linkState);

#endif
