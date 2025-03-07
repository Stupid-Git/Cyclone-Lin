/**
 * @file ssh_config.h
 * @brief CycloneSSH configuration file
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2024 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneSSH Open.
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

#ifndef _SSH_CONFIG_H
#define _SSH_CONFIG_H

//Desired trace level (for debugging purposes)
#define SSH_TRACE_LEVEL   TRACE_LEVEL_INFO
#define SCP_TRACE_LEVEL   TRACE_LEVEL_INFO
#define SFTP_TRACE_LEVEL  TRACE_LEVEL_INFO
#define SHELL_TRACE_LEVEL TRACE_LEVEL_INFO

//SSH client support
#define SSH_CLIENT_SUPPORT ENABLED
//SSH server support
#define SSH_SERVER_SUPPORT DISABLED

//Password authentication support
#define SSH_PASSWORD_AUTH_SUPPORT ENABLED
//Public key authentication support
#define SSH_PUBLIC_KEY_AUTH_SUPPORT ENABLED

//Encrypted private key support (OpenSSH format)
#define SSH_ENCRYPTED_KEY_SUPPORT DISABLED
//Certificate support (OpenSSH format)
#define SSH_CERT_SUPPORT DISABLED

//Extension negotiation mechanism
#define SSH_EXT_INFO_SUPPORT ENABLED
//"server-sig-algs" extension support
#define SSH_SERVER_SIG_ALGS_EXT_SUPPORT ENABLED
//"global-requests-ok" extension support
#define SSH_GLOBAL_REQ_OK_EXT_SUPPORT DISABLED

//Encrypt-then-MAC mode support
#define SSH_ETM_SUPPORT DISABLED

//Stream cipher support (insecure)
#define SSH_STREAM_CIPHER_SUPPORT DISABLED
//CBC cipher mode support (weak)
#define SSH_CBC_CIPHER_SUPPORT DISABLED
//CTR cipher mode support
#define SSH_CTR_CIPHER_SUPPORT ENABLED
//GCM AEAD support
#define SSH_GCM_CIPHER_SUPPORT ENABLED
//ChaCha20Poly1305 AEAD support
#define SSH_CHACHA20_POLY1305_SUPPORT DISABLED

//RC4 128-bit cipher support (insecure)
#define SSH_RC4_128_SUPPORT DISABLED
//RC4 256-bit cipher support (insecure)
#define SSH_RC4_256_SUPPORT DISABLED
//CAST-128 cipher support (insecure)
#define SSH_CAST128_SUPPORT DISABLED
//IDEA cipher support (insecure)
#define SSH_IDEA_SUPPORT DISABLED
//Blowfish cipher support (insecure)
#define SSH_BLOWFISH_SUPPORT DISABLED
//Triple DES cipher support (weak)
#define SSH_3DES_SUPPORT DISABLED
//AES 128-bit cipher support
#define SSH_AES_128_SUPPORT ENABLED
//AES 192-bit cipher support
#define SSH_AES_192_SUPPORT DISABLED
//AES 256-bit cipher support
#define SSH_AES_256_SUPPORT ENABLED
//Twofish 128-bit cipher support
#define SSH_TWOFISH_128_SUPPORT DISABLED
//Twofish 192-bit cipher support
#define SSH_TWOFISH_192_SUPPORT DISABLED
//Twofish 256-bit cipher support
#define SSH_TWOFISH_256_SUPPORT DISABLED
//Serpent 128-bit cipher support
#define SSH_SERPENT_128_SUPPORT DISABLED
//Serpent 192-bit cipher support
#define SSH_SERPENT_192_SUPPORT DISABLED
//Serpent 256-bit cipher support
#define SSH_SERPENT_256_SUPPORT DISABLED
//Camellia 128-bit cipher support
#define SSH_CAMELLIA_128_SUPPORT DISABLED
//Camellia 192-bit cipher support
#define SSH_CAMELLIA_192_SUPPORT DISABLED
//Camellia 256-bit cipher support
#define SSH_CAMELLIA_256_SUPPORT DISABLED
//SEED cipher support
#define SSH_SEED_SUPPORT DISABLED

//MD5 hash support (insecure)
#define SSH_MD5_SUPPORT DISABLED
//MD5/96 hash support (insecure)
#define SSH_MD5_96_SUPPORT DISABLED
//RIPEMD-160 hash support (weak)
#define SSH_RIPEMD160_SUPPORT DISABLED
//SHA-1 hash support (weak)
#define SSH_SHA1_SUPPORT ENABLED
//SHA-1/96 hash support (insecure)
#define SSH_SHA1_96_SUPPORT DISABLED
//SHA-224 hash support (weak)
#define SSH_SHA224_SUPPORT DISABLED
//SHA-256 hash support
#define SSH_SHA256_SUPPORT ENABLED
//SHA-384 hash support
#define SSH_SHA384_SUPPORT ENABLED
//SHA-512 hash support
#define SSH_SHA512_SUPPORT ENABLED

//RSA key exchange support
#define SSH_RSA_KEX_SUPPORT DISABLED
//Diffie-Hellman key exchange support
#define SSH_DH_KEX_SUPPORT ENABLED
//DH GEX key exchange support
#define SSH_DH_GEX_KEX_SUPPORT DISABLED
//ECDH key exchange support
#define SSH_ECDH_KEX_SUPPORT ENABLED
//Post-quantum hybrid key exchange support
#define SSH_HYBRID_KEX_SUPPORT DISABLED

//RSA signature support
#define SSH_RSA_SIGN_SUPPORT ENABLED
//DSA signature support
#define SSH_DSA_SIGN_SUPPORT ENABLED
//ECDSA signature support
#define SSH_ECDSA_SIGN_SUPPORT ENABLED
//Ed25519 signature support
#define SSH_ED25519_SIGN_SUPPORT ENABLED
//Ed448 signature support
#define SSH_ED448_SIGN_SUPPORT DISABLED

//NIST P-256 elliptic curve support
#define SSH_NISTP256_SUPPORT ENABLED
//NIST P-384 elliptic curve support
#define SSH_NISTP384_SUPPORT ENABLED
//NIST P-521 elliptic curve support
#define SSH_NISTP521_SUPPORT DISABLED
//Curve25519 elliptic curve support
#define SSH_CURVE25519_SUPPORT ENABLED
//Curve448 elliptic curve support
#define SSH_CURVE448_SUPPORT DISABLED

//ML-KEM-768 key encapsulation mechanism support
#define SSH_MLKEM768_SUPPORT DISABLED
//ML-KEM-1024 key encapsulation mechanism support
#define SSH_MLKEM1024_SUPPORT DISABLED
//Streamlined NTRU Prime 761 key encapsulation mechanism support
#define SSH_SNTRUP761_SUPPORT DISABLED

//Minimum acceptable size for Diffie-Hellman prime modulus
#define SSH_MIN_DH_MODULUS_SIZE 1024
//Preferred size for Diffie-Hellman prime modulus
#define SSH_PREFERRED_DH_MODULUS_SIZE 2048
//Maximum acceptable size for Diffie-Hellman prime modulus
#define SSH_MAX_DH_MODULUS_SIZE 2048

//Minimum acceptable size for RSA modulus
#define SSH_MIN_RSA_MODULUS_SIZE 1024
//Maximum acceptable size for RSA modulus
#define SSH_MAX_RSA_MODULUS_SIZE 2048

//Minimum acceptable size for DSA prime modulus
#define SSH_MIN_DSA_MODULUS_SIZE 1024
//Maximum acceptable size for DSA prime modulus
#define SSH_MAX_DSA_MODULUS_SIZE 2048

//SFTP client support
#define SFTP_CLIENT_SUPPORT ENABLED

#endif
