RESULT ?= ssh_server_demo

DEFINES = \
	-DCPU_MIMXRT1064DVL6A \
	-DXIP_EXTERNAL_FLASH=1 \
	-DXIP_BOOT_HEADER_ENABLE=1 \
	-DXIP_BOOT_HEADER_DCD_ENABLE=1 \
	-DUSE_MIMXRT1064_EVK \
	-D__MCUXPRESSO \
	-D__USE_CMSIS \
	-D__NEWLIB__ \
	-D_WINSOCK_H \
	-D__error_t_defined

INCLUDES = \
	-I../src \
	-I../../../../../third_party/cmsis/include \
	-I../../../../../third_party/nxp/devices/mimxrt1064 \
	-I../../../../../third_party/nxp/devices/mimxrt1064/drivers \
	-I../../../../../third_party/nxp/devices/mimxrt1064/xip \
	-I../../../../../third_party/nxp/boards/mimxrt1064_evk \
	-I../../../../../third_party/freertos/include \
	-I../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1 \
	-I../../../../../common \
	-I../../../../../cyclone_tcp \
	-I../../../../../cyclone_ssh \
	-I../../../../../cyclone_crypto

ASM_SOURCES = \
	./startup_mimxrt1064.S

C_SOURCES = \
	../src/system_mimxrt1064.c \
	./syscalls.c \
	../src/main.c \
	../src/debug.c \
	../src/res.c \
	../../../../../common/cpu_endian.c \
	../../../../../common/os_port_freertos.c \
	../../../../../common/date_time.c \
	../../../../../common/str.c \
	../../../../../common/resource_manager.c \
	../../../../../cyclone_tcp/core/net.c \
	../../../../../cyclone_tcp/core/net_mem.c \
	../../../../../cyclone_tcp/core/net_misc.c \
	../../../../../cyclone_tcp/drivers/mac/mimxrt1060_eth1_driver.c \
	../../../../../cyclone_tcp/drivers/phy/ksz8081_driver.c \
	../../../../../cyclone_tcp/core/nic.c \
	../../../../../cyclone_tcp/core/ethernet.c \
	../../../../../cyclone_tcp/core/ethernet_misc.c \
	../../../../../cyclone_tcp/ipv4/arp.c \
	../../../../../cyclone_tcp/ipv4/arp_cache.c \
	../../../../../cyclone_tcp/ipv4/ipv4.c \
	../../../../../cyclone_tcp/ipv4/ipv4_frag.c \
	../../../../../cyclone_tcp/ipv4/ipv4_multicast.c \
	../../../../../cyclone_tcp/ipv4/ipv4_misc.c \
	../../../../../cyclone_tcp/ipv4/icmp.c \
	../../../../../cyclone_tcp/igmp/igmp_host.c \
	../../../../../cyclone_tcp/igmp/igmp_host_misc.c \
	../../../../../cyclone_tcp/igmp/igmp_common.c \
	../../../../../cyclone_tcp/igmp/igmp_debug.c \
	../../../../../cyclone_tcp/ipv6/ipv6.c \
	../../../../../cyclone_tcp/ipv6/ipv6_frag.c \
	../../../../../cyclone_tcp/ipv6/ipv6_multicast.c \
	../../../../../cyclone_tcp/ipv6/ipv6_pmtu.c \
	../../../../../cyclone_tcp/ipv6/ipv6_misc.c \
	../../../../../cyclone_tcp/ipv6/icmpv6.c \
	../../../../../cyclone_tcp/ipv6/ndp.c \
	../../../../../cyclone_tcp/ipv6/ndp_cache.c \
	../../../../../cyclone_tcp/ipv6/ndp_misc.c \
	../../../../../cyclone_tcp/ipv6/slaac.c \
	../../../../../cyclone_tcp/ipv6/slaac_misc.c \
	../../../../../cyclone_tcp/mld/mld_node.c \
	../../../../../cyclone_tcp/mld/mld_node_misc.c \
	../../../../../cyclone_tcp/mld/mld_common.c \
	../../../../../cyclone_tcp/mld/mld_debug.c \
	../../../../../cyclone_tcp/core/ip.c \
	../../../../../cyclone_tcp/core/tcp.c \
	../../../../../cyclone_tcp/core/tcp_fsm.c \
	../../../../../cyclone_tcp/core/tcp_misc.c \
	../../../../../cyclone_tcp/core/tcp_timer.c \
	../../../../../cyclone_tcp/core/udp.c \
	../../../../../cyclone_tcp/core/socket.c \
	../../../../../cyclone_tcp/core/socket_misc.c \
	../../../../../cyclone_tcp/core/bsd_socket.c \
	../../../../../cyclone_tcp/core/bsd_socket_options.c \
	../../../../../cyclone_tcp/core/bsd_socket_misc.c \
	../../../../../cyclone_tcp/core/raw_socket.c \
	../../../../../cyclone_tcp/dns/dns_cache.c \
	../../../../../cyclone_tcp/dns/dns_client.c \
	../../../../../cyclone_tcp/dns/dns_common.c \
	../../../../../cyclone_tcp/dns/dns_debug.c \
	../../../../../cyclone_tcp/mdns/mdns_client.c \
	../../../../../cyclone_tcp/mdns/mdns_responder.c \
	../../../../../cyclone_tcp/mdns/mdns_responder_misc.c \
	../../../../../cyclone_tcp/mdns/mdns_common.c \
	../../../../../cyclone_tcp/netbios/nbns_client.c \
	../../../../../cyclone_tcp/netbios/nbns_responder.c \
	../../../../../cyclone_tcp/netbios/nbns_common.c \
	../../../../../cyclone_tcp/llmnr/llmnr_client.c \
	../../../../../cyclone_tcp/llmnr/llmnr_responder.c \
	../../../../../cyclone_tcp/llmnr/llmnr_common.c \
	../../../../../cyclone_tcp/dhcp/dhcp_client.c \
	../../../../../cyclone_tcp/dhcp/dhcp_client_fsm.c \
	../../../../../cyclone_tcp/dhcp/dhcp_client_misc.c \
	../../../../../cyclone_tcp/dhcp/dhcp_common.c \
	../../../../../cyclone_tcp/dhcp/dhcp_debug.c \
	../../../../../cyclone_ssh/ssh/ssh.c \
	../../../../../cyclone_ssh/ssh/ssh_server.c \
	../../../../../cyclone_ssh/ssh/ssh_server_misc.c \
	../../../../../cyclone_ssh/ssh/ssh_algorithms.c \
	../../../../../cyclone_ssh/ssh/ssh_extensions.c \
	../../../../../cyclone_ssh/ssh/ssh_transport.c \
	../../../../../cyclone_ssh/ssh/ssh_kex.c \
	../../../../../cyclone_ssh/ssh/ssh_kex_rsa.c \
	../../../../../cyclone_ssh/ssh/ssh_kex_dh.c \
	../../../../../cyclone_ssh/ssh/ssh_kex_dh_gex.c \
	../../../../../cyclone_ssh/ssh/ssh_kex_ecdh.c \
	../../../../../cyclone_ssh/ssh/ssh_kex_hybrid.c \
	../../../../../cyclone_ssh/ssh/ssh_auth.c \
	../../../../../cyclone_ssh/ssh/ssh_auth_password.c \
	../../../../../cyclone_ssh/ssh/ssh_auth_public_key.c \
	../../../../../cyclone_ssh/ssh/ssh_connection.c \
	../../../../../cyclone_ssh/ssh/ssh_request.c \
	../../../../../cyclone_ssh/ssh/ssh_channel.c \
	../../../../../cyclone_ssh/ssh/ssh_packet.c \
	../../../../../cyclone_ssh/ssh/ssh_key_material.c \
	../../../../../cyclone_ssh/ssh/ssh_exchange_hash.c \
	../../../../../cyclone_ssh/ssh/ssh_modp_groups.c \
	../../../../../cyclone_ssh/ssh/ssh_key_import.c \
	../../../../../cyclone_ssh/ssh/ssh_key_export.c \
	../../../../../cyclone_ssh/ssh/ssh_key_parse.c \
	../../../../../cyclone_ssh/ssh/ssh_key_format.c \
	../../../../../cyclone_ssh/ssh/ssh_key_decrypt.c \
	../../../../../cyclone_ssh/ssh/ssh_key_verify.c \
	../../../../../cyclone_ssh/ssh/ssh_cert_import.c \
	../../../../../cyclone_ssh/ssh/ssh_cert_export.c \
	../../../../../cyclone_ssh/ssh/ssh_cert_parse.c \
	../../../../../cyclone_ssh/ssh/ssh_cert_verify.c \
	../../../../../cyclone_ssh/ssh/ssh_sign_generate.c \
	../../../../../cyclone_ssh/ssh/ssh_sign_verify.c \
	../../../../../cyclone_ssh/ssh/ssh_sign_misc.c \
	../../../../../cyclone_ssh/ssh/ssh_misc.c \
	../../../../../cyclone_ssh/shell/shell_server.c \
	../../../../../cyclone_ssh/shell/shell_server_pty.c \
	../../../../../cyclone_ssh/shell/shell_server_misc.c \
	../../../../../cyclone_crypto/hardware/mimxrt1060/mimxrt1060_crypto.c \
	../../../../../cyclone_crypto/hardware/mimxrt1060/mimxrt1060_crypto_trng.c \
	../../../../../cyclone_crypto/hardware/mimxrt1060/mimxrt1060_crypto_hash.c \
	../../../../../cyclone_crypto/hardware/mimxrt1060/mimxrt1060_crypto_cipher.c \
	../../../../../cyclone_crypto/hash/md5.c \
	../../../../../cyclone_crypto/hash/ripemd160.c \
	../../../../../cyclone_crypto/hash/sha1.c \
	../../../../../cyclone_crypto/hash/sha256.c \
	../../../../../cyclone_crypto/hash/sha384.c \
	../../../../../cyclone_crypto/hash/sha512.c \
	../../../../../cyclone_crypto/hash/sha3_256.c \
	../../../../../cyclone_crypto/hash/sha3_512.c \
	../../../../../cyclone_crypto/mac/hmac.c \
	../../../../../cyclone_crypto/cipher/rc4.c \
	../../../../../cyclone_crypto/cipher/cast128.c \
	../../../../../cyclone_crypto/cipher/idea.c \
	../../../../../cyclone_crypto/cipher/des.c \
	../../../../../cyclone_crypto/cipher/des3.c \
	../../../../../cyclone_crypto/cipher/aes.c \
	../../../../../cyclone_crypto/cipher/blowfish.c \
	../../../../../cyclone_crypto/cipher/twofish.c \
	../../../../../cyclone_crypto/cipher/serpent.c \
	../../../../../cyclone_crypto/cipher/camellia.c \
	../../../../../cyclone_crypto/cipher/seed.c \
	../../../../../cyclone_crypto/cipher_modes/cbc.c \
	../../../../../cyclone_crypto/cipher_modes/ctr.c \
	../../../../../cyclone_crypto/aead/gcm.c \
	../../../../../cyclone_crypto/cipher/chacha.c \
	../../../../../cyclone_crypto/mac/poly1305.c \
	../../../../../cyclone_crypto/pkc/dh.c \
	../../../../../cyclone_crypto/pkc/rsa.c \
	../../../../../cyclone_crypto/pkc/dsa.c \
	../../../../../cyclone_crypto/ecc/ec.c \
	../../../../../cyclone_crypto/ecc/ec_curves.c \
	../../../../../cyclone_crypto/ecc/ecdh.c \
	../../../../../cyclone_crypto/ecc/ecdsa.c \
	../../../../../cyclone_crypto/ecc/eddsa.c \
	../../../../../cyclone_crypto/ecc/curve25519.c \
	../../../../../cyclone_crypto/ecc/curve448.c \
	../../../../../cyclone_crypto/ecc/x25519.c \
	../../../../../cyclone_crypto/ecc/x448.c \
	../../../../../cyclone_crypto/ecc/ed25519.c \
	../../../../../cyclone_crypto/ecc/ed448.c \
	../../../../../cyclone_crypto/pqc/kem.c \
	../../../../../cyclone_crypto/pqc/mlkem768.c \
	../../../../../cyclone_crypto/pqc/mlkem1024.c \
	../../../../../cyclone_crypto/pqc/sntrup761.c \
	../../../../../cyclone_crypto/mpi/mpi.c \
	../../../../../cyclone_crypto/encoding/base64.c \
	../../../../../cyclone_crypto/encoding/asn1.c \
	../../../../../cyclone_crypto/encoding/oid.c \
	../../../../../cyclone_crypto/pkix/pem_import.c \
	../../../../../cyclone_crypto/pkix/pem_decrypt.c \
	../../../../../cyclone_crypto/pkix/pem_common.c \
	../../../../../cyclone_crypto/pkix/pkcs5_decrypt.c \
	../../../../../cyclone_crypto/pkix/pkcs5_common.c \
	../../../../../cyclone_crypto/pkix/pkcs8_key_parse.c \
	../../../../../cyclone_crypto/pkix/x509_key_parse.c \
	../../../../../cyclone_crypto/pkix/x509_common.c \
	../../../../../cyclone_crypto/kdf/pbkdf.c \
	../../../../../cyclone_crypto/xof/keccak.c \
	../../../../../cyclone_crypto/xof/shake.c \
	../../../../../cyclone_crypto/rng/yarrow.c \
	../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1/port.c \
	../../../../../third_party/freertos/croutine.c \
	../../../../../third_party/freertos/list.c \
	../../../../../third_party/freertos/queue.c \
	../../../../../third_party/freertos/tasks.c \
	../../../../../third_party/freertos/timers.c \
	../../../../../third_party/freertos/portable/memmang/heap_3.c \
	../../../../../third_party/nxp/boards/mimxrt1064_evk/clock_config.c \
	../../../../../third_party/nxp/boards/mimxrt1064_evk/evkmimxrt1064_flexspi_nor_config.c \
	../../../../../third_party/nxp/boards/mimxrt1064_evk/evkmimxrt1064_sdram_ini_dcd.c \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_cache.c \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_clock.c \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_common.c \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_dcp.c \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_gpio.c \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_lpuart.c \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_semc.c \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_trng.c \
	../../../../../third_party/nxp/devices/mimxrt1064/xip/fsl_flexspi_nor_boot.c

HEADERS = \
	../src/os_port_config.h \
	../src/net_config.h \
	../src/ssh_config.h \
	../src/crypto_config.h \
	../src/FreeRTOSConfig.h \
	../../../../../common/cpu_endian.h \
	../../../../../common/os_port.h \
	../../../../../common/os_port_freertos.h \
	../../../../../common/date_time.h \
	../../../../../common/str.h \
	../../../../../common/resource_manager.h \
	../../../../../common/error.h \
	../../../../../common/debug.h \
	../../../../../cyclone_tcp/core/net.h \
	../../../../../cyclone_tcp/core/net_mem.h \
	../../../../../cyclone_tcp/core/net_misc.h \
	../../../../../cyclone_tcp/drivers/mac/mimxrt1060_eth1_driver.h \
	../../../../../cyclone_tcp/drivers/phy/ksz8081_driver.h \
	../../../../../cyclone_tcp/core/nic.h \
	../../../../../cyclone_tcp/core/ethernet.h \
	../../../../../cyclone_tcp/core/ethernet_misc.h \
	../../../../../cyclone_tcp/ipv4/arp.h \
	../../../../../cyclone_tcp/ipv4/arp_cache.h \
	../../../../../cyclone_tcp/ipv4/ipv4.h \
	../../../../../cyclone_tcp/ipv4/ipv4_frag.h \
	../../../../../cyclone_tcp/ipv4/ipv4_multicast.h \
	../../../../../cyclone_tcp/ipv4/ipv4_misc.h \
	../../../../../cyclone_tcp/ipv4/icmp.h \
	../../../../../cyclone_tcp/igmp/igmp_host.h \
	../../../../../cyclone_tcp/igmp/igmp_host_misc.h \
	../../../../../cyclone_tcp/igmp/igmp_common.h \
	../../../../../cyclone_tcp/igmp/igmp_debug.h \
	../../../../../cyclone_tcp/ipv6/ipv6.h \
	../../../../../cyclone_tcp/ipv6/ipv6_frag.h \
	../../../../../cyclone_tcp/ipv6/ipv6_multicast.h \
	../../../../../cyclone_tcp/ipv6/ipv6_pmtu.h \
	../../../../../cyclone_tcp/ipv6/ipv6_misc.h \
	../../../../../cyclone_tcp/ipv6/icmpv6.h \
	../../../../../cyclone_tcp/ipv6/ndp.h \
	../../../../../cyclone_tcp/ipv6/ndp_cache.h \
	../../../../../cyclone_tcp/ipv6/ndp_misc.h \
	../../../../../cyclone_tcp/ipv6/slaac.h \
	../../../../../cyclone_tcp/ipv6/slaac_misc.h \
	../../../../../cyclone_tcp/mld/mld_node.h \
	../../../../../cyclone_tcp/mld/mld_node_misc.h \
	../../../../../cyclone_tcp/mld/mld_common.h \
	../../../../../cyclone_tcp/mld/mld_debug.h \
	../../../../../cyclone_tcp/core/ip.h \
	../../../../../cyclone_tcp/core/tcp.h \
	../../../../../cyclone_tcp/core/tcp_fsm.h \
	../../../../../cyclone_tcp/core/tcp_misc.h \
	../../../../../cyclone_tcp/core/tcp_timer.h \
	../../../../../cyclone_tcp/core/udp.h \
	../../../../../cyclone_tcp/core/socket.h \
	../../../../../cyclone_tcp/core/socket_misc.h \
	../../../../../cyclone_tcp/core/bsd_socket.h \
	../../../../../cyclone_tcp/core/bsd_socket_options.h \
	../../../../../cyclone_tcp/core/bsd_socket_misc.h \
	../../../../../cyclone_tcp/core/raw_socket.h \
	../../../../../cyclone_tcp/dns/dns_cache.h \
	../../../../../cyclone_tcp/dns/dns_client.h \
	../../../../../cyclone_tcp/dns/dns_common.h \
	../../../../../cyclone_tcp/dns/dns_debug.h \
	../../../../../cyclone_tcp/mdns/mdns_client.h \
	../../../../../cyclone_tcp/mdns/mdns_responder.h \
	../../../../../cyclone_tcp/mdns/mdns_responder_misc.h \
	../../../../../cyclone_tcp/mdns/mdns_common.h \
	../../../../../cyclone_tcp/netbios/nbns_client.h \
	../../../../../cyclone_tcp/netbios/nbns_responder.h \
	../../../../../cyclone_tcp/netbios/nbns_common.h \
	../../../../../cyclone_tcp/llmnr/llmnr_client.h \
	../../../../../cyclone_tcp/llmnr/llmnr_responder.h \
	../../../../../cyclone_tcp/llmnr/llmnr_common.h \
	../../../../../cyclone_tcp/dhcp/dhcp_client.h \
	../../../../../cyclone_tcp/dhcp/dhcp_client_fsm.h \
	../../../../../cyclone_tcp/dhcp/dhcp_client_misc.h \
	../../../../../cyclone_tcp/dhcp/dhcp_common.h \
	../../../../../cyclone_tcp/dhcp/dhcp_debug.h \
	../../../../../cyclone_ssh/ssh/ssh.h \
	../../../../../cyclone_ssh/ssh/ssh_server.h \
	../../../../../cyclone_ssh/ssh/ssh_server_misc.h \
	../../../../../cyclone_ssh/ssh/ssh_algorithms.h \
	../../../../../cyclone_ssh/ssh/ssh_extensions.h \
	../../../../../cyclone_ssh/ssh/ssh_transport.h \
	../../../../../cyclone_ssh/ssh/ssh_kex.h \
	../../../../../cyclone_ssh/ssh/ssh_kex_rsa.h \
	../../../../../cyclone_ssh/ssh/ssh_kex_dh.h \
	../../../../../cyclone_ssh/ssh/ssh_kex_dh_gex.h \
	../../../../../cyclone_ssh/ssh/ssh_kex_ecdh.h \
	../../../../../cyclone_ssh/ssh/ssh_kex_hybrid.h \
	../../../../../cyclone_ssh/ssh/ssh_auth.h \
	../../../../../cyclone_ssh/ssh/ssh_auth_password.h \
	../../../../../cyclone_ssh/ssh/ssh_auth_public_key.h \
	../../../../../cyclone_ssh/ssh/ssh_connection.h \
	../../../../../cyclone_ssh/ssh/ssh_request.h \
	../../../../../cyclone_ssh/ssh/ssh_channel.h \
	../../../../../cyclone_ssh/ssh/ssh_packet.h \
	../../../../../cyclone_ssh/ssh/ssh_key_material.h \
	../../../../../cyclone_ssh/ssh/ssh_exchange_hash.h \
	../../../../../cyclone_ssh/ssh/ssh_modp_groups.h \
	../../../../../cyclone_ssh/ssh/ssh_key_import.h \
	../../../../../cyclone_ssh/ssh/ssh_key_export.h \
	../../../../../cyclone_ssh/ssh/ssh_key_parse.h \
	../../../../../cyclone_ssh/ssh/ssh_key_format.h \
	../../../../../cyclone_ssh/ssh/ssh_key_decrypt.h \
	../../../../../cyclone_ssh/ssh/ssh_key_verify.h \
	../../../../../cyclone_ssh/ssh/ssh_cert_import.h \
	../../../../../cyclone_ssh/ssh/ssh_cert_export.h \
	../../../../../cyclone_ssh/ssh/ssh_cert_parse.h \
	../../../../../cyclone_ssh/ssh/ssh_cert_verify.h \
	../../../../../cyclone_ssh/ssh/ssh_sign_generate.h \
	../../../../../cyclone_ssh/ssh/ssh_sign_verify.h \
	../../../../../cyclone_ssh/ssh/ssh_sign_misc.h \
	../../../../../cyclone_ssh/ssh/ssh_misc.h \
	../../../../../cyclone_ssh/shell/shell_server.h \
	../../../../../cyclone_ssh/shell/shell_server_pty.h \
	../../../../../cyclone_ssh/shell/shell_server_misc.h \
	../../../../../cyclone_crypto/core/crypto.h \
	../../../../../cyclone_crypto/hardware/mimxrt1060/mimxrt1060_crypto.h \
	../../../../../cyclone_crypto/hardware/mimxrt1060/mimxrt1060_crypto_config.h \
	../../../../../cyclone_crypto/hardware/mimxrt1060/mimxrt1060_crypto_trng.h \
	../../../../../cyclone_crypto/hardware/mimxrt1060/mimxrt1060_crypto_hash.h \
	../../../../../cyclone_crypto/hardware/mimxrt1060/mimxrt1060_crypto_cipher.h \
	../../../../../cyclone_crypto/hash/md5.h \
	../../../../../cyclone_crypto/hash/ripemd160.h \
	../../../../../cyclone_crypto/hash/sha1.h \
	../../../../../cyclone_crypto/hash/sha256.h \
	../../../../../cyclone_crypto/hash/sha384.h \
	../../../../../cyclone_crypto/hash/sha512.h \
	../../../../../cyclone_crypto/hash/sha3_256.h \
	../../../../../cyclone_crypto/hash/sha3_512.h \
	../../../../../cyclone_crypto/mac/hmac.h \
	../../../../../cyclone_crypto/cipher/rc4.h \
	../../../../../cyclone_crypto/cipher/cast128.h \
	../../../../../cyclone_crypto/cipher/idea.h \
	../../../../../cyclone_crypto/cipher/des.h \
	../../../../../cyclone_crypto/cipher/des3.h \
	../../../../../cyclone_crypto/cipher/aes.h \
	../../../../../cyclone_crypto/cipher/blowfish.h \
	../../../../../cyclone_crypto/cipher/twofish.h \
	../../../../../cyclone_crypto/cipher/serpent.h \
	../../../../../cyclone_crypto/cipher/camellia.h \
	../../../../../cyclone_crypto/cipher/seed.h \
	../../../../../cyclone_crypto/cipher_modes/cbc.h \
	../../../../../cyclone_crypto/cipher_modes/ctr.h \
	../../../../../cyclone_crypto/aead/gcm.h \
	../../../../../cyclone_crypto/cipher/chacha.h \
	../../../../../cyclone_crypto/mac/poly1305.h \
	../../../../../cyclone_crypto/pkc/dh.h \
	../../../../../cyclone_crypto/pkc/rsa.h \
	../../../../../cyclone_crypto/pkc/dsa.h \
	../../../../../cyclone_crypto/ecc/ec.h \
	../../../../../cyclone_crypto/ecc/ec_curves.h \
	../../../../../cyclone_crypto/ecc/ecdh.h \
	../../../../../cyclone_crypto/ecc/ecdsa.h \
	../../../../../cyclone_crypto/ecc/eddsa.h \
	../../../../../cyclone_crypto/ecc/curve25519.h \
	../../../../../cyclone_crypto/ecc/curve448.h \
	../../../../../cyclone_crypto/ecc/x25519.h \
	../../../../../cyclone_crypto/ecc/x448.h \
	../../../../../cyclone_crypto/ecc/ed25519.h \
	../../../../../cyclone_crypto/ecc/ed448.h \
	../../../../../cyclone_crypto/pqc/kem.h \
	../../../../../cyclone_crypto/pqc/mlkem768.h \
	../../../../../cyclone_crypto/pqc/mlkem1024.h \
	../../../../../cyclone_crypto/pqc/sntrup761.h \
	../../../../../cyclone_crypto/mpi/mpi.h \
	../../../../../cyclone_crypto/encoding/base64.h \
	../../../../../cyclone_crypto/encoding/asn1.h \
	../../../../../cyclone_crypto/encoding/oid.h \
	../../../../../cyclone_crypto/pkix/pem_import.h \
	../../../../../cyclone_crypto/pkix/pem_decrypt.h \
	../../../../../cyclone_crypto/pkix/pem_common.h \
	../../../../../cyclone_crypto/pkix/pkcs5_decrypt.h \
	../../../../../cyclone_crypto/pkix/pkcs5_common.h \
	../../../../../cyclone_crypto/pkix/pkcs8_key_parse.h \
	../../../../../cyclone_crypto/pkix/x509_key_parse.h \
	../../../../../cyclone_crypto/pkix/x509_common.h \
	../../../../../cyclone_crypto/kdf/pbkdf.h \
	../../../../../cyclone_crypto/xof/keccak.h \
	../../../../../cyclone_crypto/xof/shake.h \
	../../../../../cyclone_crypto/rng/yarrow.h \
	../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1/portmacro.h \
	../../../../../third_party/freertos/include/croutine.h \
	../../../../../third_party/freertos/include/FreeRTOS.h \
	../../../../../third_party/freertos/include/list.h \
	../../../../../third_party/freertos/include/mpu_wrappers.h \
	../../../../../third_party/freertos/include/portable.h \
	../../../../../third_party/freertos/include/projdefs.h \
	../../../../../third_party/freertos/include/queue.h \
	../../../../../third_party/freertos/include/semphr.h \
	../../../../../third_party/freertos/include/stack_macros.h \
	../../../../../third_party/freertos/include/task.h \
	../../../../../third_party/freertos/include/timers.h \
	../../../../../third_party/nxp/boards/mimxrt1064_evk/board.h \
	../../../../../third_party/nxp/boards/mimxrt1064_evk/clock_config.h \
	../../../../../third_party/nxp/boards/mimxrt1064_evk/evkmimxrt1064_flexspi_nor_config.h \
	../../../../../third_party/nxp/boards/mimxrt1064_evk/evkmimxrt1064_sdram_ini_dcd.h \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_cache.h \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_clock.h \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_common.h \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_dcp.h \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_gpio.h \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_iomuxc.h \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_lpuart.h \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_semc.h \
	../../../../../third_party/nxp/devices/mimxrt1064/drivers/fsl_trng.h \
	../../../../../third_party/nxp/devices/mimxrt1064/xip/fsl_flexspi_nor_boot.h

ASM_OBJECTS = $(patsubst %.S, %.o, $(ASM_SOURCES))

C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

OBJ_DIR = obj

LINKER_SCRIPT = mimxrt1064_flash.ld

CFLAGS += -fno-common -Wall -Os -g3
CFLAGS += -mcpu=cortex-m7 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard
CFLAGS += -ffunction-sections -fdata-sections -Wl,--gc-sections
CFLAGS += $(DEFINES)
CFLAGS += $(INCLUDES)

CROSS_COMPILE ?= arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJDUMP = $(CROSS_COMPILE)objdump
OBJCOPY = $(CROSS_COMPILE)objcopy
SIZE = $(CROSS_COMPILE)size

THIS_MAKEFILE := $(lastword $(MAKEFILE_LIST))

all: build size

install: build size program

build: $(RESULT).elf $(RESULT).lst $(RESULT).bin $(RESULT).hex
	
$(RESULT).elf: $(ASM_OBJECTS) $(C_OBJECTS) $(HEADERS) $(LINKER_SCRIPT) $(THIS_MAKEFILE)
	$(CC) -Wl,-M=$(RESULT).map -Wl,-T$(LINKER_SCRIPT) $(CFLAGS) $(addprefix $(OBJ_DIR)/, $(notdir $(ASM_OBJECTS))) $(addprefix $(OBJ_DIR)/, $(notdir $(C_OBJECTS))) -o $@

$(ASM_OBJECTS): | $(OBJ_DIR)

$(C_OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

../src/res.c: ../../../../../utils/ResourceCompiler/bin/rc
	$< ../resources $@

../../../../../utils/ResourceCompiler/bin/rc: ../../../../../utils/ResourceCompiler/main.c
	gcc $< -o $@

%.o: %.c $(HEADERS) $(THIS_MAKEFILE)
	$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $(notdir $@))

%.o: %.S $(HEADERS) $(THIS_MAKEFILE)
	$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $(notdir $@))

%.lst: %.elf
	$(OBJDUMP) -x -S $(RESULT).elf > $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@

size: $(RESULT).elf
	$(SIZE) $(RESULT).elf

clean:
	rm -f $(RESULT).elf
	rm -f $(RESULT).bin
	rm -f $(RESULT).map
	rm -f $(RESULT).hex
	rm -f $(RESULT).lst
	rm -f $(OBJ_DIR)/*.o
