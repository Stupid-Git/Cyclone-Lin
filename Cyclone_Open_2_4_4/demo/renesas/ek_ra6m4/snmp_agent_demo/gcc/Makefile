RESULT ?= snmp_agent_demo

DEFINES = \
	-DBSP_MCU_GROUP_RA6M4 \
	-DUSE_EK_RA6M4 \
	-D_WINSOCK_H \
	-D__error_t_defined

INCLUDES = \
	-I../src \
	-I../../../../../third_party/cmsis/include \
	-I../../../../../third_party/renesas/devices/ra \
	-I../../../../../third_party/renesas/devices/ra/all \
	-I../../../../../third_party/renesas/devices/ra/ra6m4 \
	-I../../../../../third_party/renesas/devices/ra/fsp/inc \
	-I../../../../../third_party/renesas/devices/ra/fsp/inc/api \
	-I../../../../../third_party/renesas/devices/ra/fsp/src/r_sce \
	-I../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/common \
	-I../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/public/inc \
	-I../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/private/inc \
	-I../../../../../third_party/renesas/boards/ek_ra6m4 \
	-I../../../../../common \
	-I../../../../../cyclone_tcp \
	-I../../../../../cyclone_crypto

ASM_SOURCES = \
	./startup_ra6m4.S

C_SOURCES = \
	../src/system_ra6m4.c \
	./syscalls.c \
	../src/main.c \
	../src/private_mib_module.c \
	../src/private_mib_impl.c \
	../src/debug.c \
	../src/ext_int_driver.c \
	../../../../../common/cpu_endian.c \
	../../../../../common/os_port_none.c \
	../../../../../common/date_time.c \
	../../../../../common/str.c \
	../../../../../cyclone_tcp/core/net.c \
	../../../../../cyclone_tcp/core/net_mem.c \
	../../../../../cyclone_tcp/core/net_misc.c \
	../../../../../cyclone_tcp/drivers/mac/ra6_eth_driver.c \
	../../../../../cyclone_tcp/drivers/phy/ksz8091_driver.c \
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
	../../../../../cyclone_tcp/snmp/snmp_agent.c \
	../../../../../cyclone_tcp/snmp/snmp_agent_dispatch.c \
	../../../../../cyclone_tcp/snmp/snmp_agent_message.c \
	../../../../../cyclone_tcp/snmp/snmp_agent_pdu.c \
	../../../../../cyclone_tcp/snmp/snmp_agent_object.c \
	../../../../../cyclone_tcp/snmp/snmp_agent_trap.c \
	../../../../../cyclone_tcp/snmp/snmp_agent_inform.c \
	../../../../../cyclone_tcp/snmp/snmp_agent_usm.c \
	../../../../../cyclone_tcp/snmp/snmp_agent_vacm.c \
	../../../../../cyclone_tcp/snmp/snmp_agent_misc.c \
	../../../../../cyclone_tcp/mibs/mib_common.c \
	../../../../../cyclone_tcp/mibs/mib2_module.c \
	../../../../../cyclone_tcp/mibs/mib2_impl.c \
	../../../../../cyclone_tcp/mibs/mib2_impl_sys.c \
	../../../../../cyclone_tcp/mibs/mib2_impl_if.c \
	../../../../../cyclone_tcp/mibs/mib2_impl_ip.c \
	../../../../../cyclone_tcp/mibs/mib2_impl_tcp.c \
	../../../../../cyclone_tcp/mibs/mib2_impl_udp.c \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto.c \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto_trng.c \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto_hash.c \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto_cipher.c \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto_pkc.c \
	../../../../../cyclone_crypto/hash/md5.c \
	../../../../../cyclone_crypto/hash/sha1.c \
	../../../../../cyclone_crypto/mac/hmac.c \
	../../../../../cyclone_crypto/cipher/des.c \
	../../../../../cyclone_crypto/cipher/aes.c \
	../../../../../cyclone_crypto/cipher_modes/cbc.c \
	../../../../../cyclone_crypto/cipher_modes/cfb.c \
	../../../../../cyclone_crypto/encoding/asn1.c \
	../../../../../cyclone_crypto/encoding/oid.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/adaptors/r_sce_adapt.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func000.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func001.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func002.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func027.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func028.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func031.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func043.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func044.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func048.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func049.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func050.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func051.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func052.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func053.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func054.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func057.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func058.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func059.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func060.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func061.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func062.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func063.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func064.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func065.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func066.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func067.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func068.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func070.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func071.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func074.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func075.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func076.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func077.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func080.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func081.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func082.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func100.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func101.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func102.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func103.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func200.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func202.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func205.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func206.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func207.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func300.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func301.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func302.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func304.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func307.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func308.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func309.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func310.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func311.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func312.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func313.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func314.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func315.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func316.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func317.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func318.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func319.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func320.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func321.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func322.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func323.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func324.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_func325.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p00.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p01.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p02.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p07.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p08.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p15.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p16.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p17.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p20.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p21.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p26.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p29a.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p29f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p29i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p29t.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p29u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p2b.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p32a.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p32f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p32i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p32t.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p32u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p34a.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p34f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p34i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p34t.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p34u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p36a.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p36f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p36i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p36t.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p36u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p40.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p41f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p41i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p41u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p44f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p44i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p44u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p47f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p47i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p47u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p50f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p50i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p50u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p56.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p57.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p6e.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p72.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p76f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p76i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p76u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p79.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p7b.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p83a.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p83f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p83i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p83t.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p83u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p85a.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p85f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p85i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p85t.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p85u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p89f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p89i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p89u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p92.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p95f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p95i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p95u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p98f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p98i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p98u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p9a.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_p9b.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pa1f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pa1i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pa1u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pa4f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pa4i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pa4u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pa7f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pa7i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pa7u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb0f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb0i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb0u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb3f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb3i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb3u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb6f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb6i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb6u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb9f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb9i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pb9u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pc2f.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pc2i.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pc2u.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pf0.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pf1.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pf4.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pf5.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pf6.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_pf9.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/hw_sce_p_subprc01.c \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/s_flash2.c

HEADERS = \
	../src/bsp_irq_cfg.h \
	../src/os_port_config.h \
	../src/net_config.h \
	../src/crypto_config.h \
	../src/private_mib_module.h \
	../src/private_mib_impl.h \
	../src/ext_int_driver.h \
	../../../../../common/cpu_endian.h \
	../../../../../common/os_port.h \
	../../../../../common/os_port_none.h \
	../../../../../common/date_time.h \
	../../../../../common/str.h \
	../../../../../common/error.h \
	../../../../../common/debug.h \
	../../../../../cyclone_tcp/core/net.h \
	../../../../../cyclone_tcp/core/net_mem.h \
	../../../../../cyclone_tcp/core/net_misc.h \
	../../../../../cyclone_tcp/drivers/mac/ra6_eth_driver.h \
	../../../../../cyclone_tcp/drivers/phy/ksz8091_driver.h \
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
	../../../../../cyclone_tcp/snmp/snmp_agent.h \
	../../../../../cyclone_tcp/snmp/snmp_agent_dispatch.h \
	../../../../../cyclone_tcp/snmp/snmp_agent_message.h \
	../../../../../cyclone_tcp/snmp/snmp_agent_pdu.h \
	../../../../../cyclone_tcp/snmp/snmp_agent_object.h \
	../../../../../cyclone_tcp/snmp/snmp_agent_trap.h \
	../../../../../cyclone_tcp/snmp/snmp_agent_inform.h \
	../../../../../cyclone_tcp/snmp/snmp_agent_usm.h \
	../../../../../cyclone_tcp/snmp/snmp_agent_vacm.h \
	../../../../../cyclone_tcp/snmp/snmp_agent_misc.h \
	../../../../../cyclone_tcp/snmp/snmp_common.h \
	../../../../../cyclone_tcp/mibs/mib_common.h \
	../../../../../cyclone_tcp/mibs/mib2_module.h \
	../../../../../cyclone_tcp/mibs/mib2_impl.h \
	../../../../../cyclone_tcp/mibs/mib2_impl_sys.h \
	../../../../../cyclone_tcp/mibs/mib2_impl_if.h \
	../../../../../cyclone_tcp/mibs/mib2_impl_ip.h \
	../../../../../cyclone_tcp/mibs/mib2_impl_tcp.h \
	../../../../../cyclone_tcp/mibs/mib2_impl_udp.h \
	../../../../../cyclone_crypto/core/crypto.h \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto.h \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto_trng.h \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto_hash.h \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto_cipher.h \
	../../../../../cyclone_crypto/hardware/ra6/ra6_crypto_pkc.h \
	../../../../../cyclone_crypto/hash/md5.h \
	../../../../../cyclone_crypto/hash/sha1.h \
	../../../../../cyclone_crypto/mac/hmac.h \
	../../../../../cyclone_crypto/cipher/des.h \
	../../../../../cyclone_crypto/cipher/aes.h \
	../../../../../cyclone_crypto/cipher_modes/cbc.h \
	../../../../../cyclone_crypto/cipher_modes/cfb.h \
	../../../../../cyclone_crypto/encoding/asn1.h \
	../../../../../cyclone_crypto/encoding/oid.h \
	../../../../../third_party/renesas/boards/ek_ra6m4/ek_ra6m4.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/hw_sce_private.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/hw_sce_aes_private.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/hw_sce_ecc_private.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/hw_sce_hash_private.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/hw_sce_rsa_private.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/hw_sce_trng_private.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/SCE_ProcCommon.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/common/hw_sce_common.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/public/inc/r_sce_if.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/private/inc/hw_sce_ra_private.h \
	../../../../../third_party/renesas/devices/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/private/inc/SCE_module.h

ASM_OBJECTS = $(patsubst %.S, %.o, $(ASM_SOURCES))

C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

OBJ_DIR = obj

LINKER_SCRIPT = ra6m4_flash.ld

CFLAGS += -fno-common -Wall -Os -g3
CFLAGS += -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=softfp
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
