RESULT ?= snmp_agent_demo

DEFINES = \
	-DSTM32F779xx \
	-DUSE_HAL_DRIVER \
	-DUSE_STM32F769I_EVAL \
	-DUSE_IOEXPANDER \
	-D_WINSOCK_H \
	-D__error_t_defined

INCLUDES = \
	-I../src \
	-I../../../../../third_party/cmsis/include \
	-I../../../../../third_party/st/devices/stm32f7xx \
	-I../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc \
	-I../../../../../third_party/st/boards/stm32f769i_eval \
	-I../../../../../common \
	-I../../../../../cyclone_tcp \
	-I../../../../../cyclone_crypto

ASM_SOURCES = \
	./startup_stm32f779xx.S

C_SOURCES = \
	../src/system_stm32f7xx.c \
	../src/stm32f7xx_it.c \
	./syscalls.c \
	../src/main.c \
	../src/private_mib_module.c \
	../src/private_mib_impl.c \
	../src/smi_driver.c \
	../src/debug.c \
	../../../../../common/cpu_endian.c \
	../../../../../common/os_port_none.c \
	../../../../../common/date_time.c \
	../../../../../common/str.c \
	../../../../../cyclone_tcp/core/net.c \
	../../../../../cyclone_tcp/core/net_mem.c \
	../../../../../cyclone_tcp/core/net_misc.c \
	../../../../../cyclone_tcp/drivers/mac/stm32f7xx_eth_driver.c \
	../../../../../cyclone_tcp/drivers/phy/dp83848_driver.c \
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
	../../../../../cyclone_crypto/hardware/stm32f7xx/stm32f7xx_crypto.c \
	../../../../../cyclone_crypto/hardware/stm32f7xx/stm32f7xx_crypto_trng.c \
	../../../../../cyclone_crypto/hardware/stm32f7xx/stm32f7xx_crypto_hash.c \
	../../../../../cyclone_crypto/hardware/stm32f7xx/stm32f7xx_crypto_cipher.c \
	../../../../../cyclone_crypto/hash/md5.c \
	../../../../../cyclone_crypto/hash/sha1.c \
	../../../../../cyclone_crypto/mac/hmac.c \
	../../../../../cyclone_crypto/cipher/des.c \
	../../../../../cyclone_crypto/cipher/aes.c \
	../../../../../cyclone_crypto/cipher_modes/cbc.c \
	../../../../../cyclone_crypto/cipher_modes/cfb.c \
	../../../../../cyclone_crypto/encoding/asn1.c \
	../../../../../cyclone_crypto/encoding/oid.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_camera.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_eeprom.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_io.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_lcd.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_nor.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_qspi.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_sd.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_sdram.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_sram.c \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_ts.c \
	../../../../../third_party/st/boards/components/mfxstm32l152/mfxstm32l152.c \
	../../../../../third_party/st/boards/components/ft6x06/ft6x06.c \
	../../../../../third_party/st/boards/components/s5k5cag/s5k5cag.c \
	../../../../../third_party/st/boards/components/otm8009a/otm8009a.c \
	../../../../../third_party/st/boards/components/ov5640/ov5640.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_adc.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_adc_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_can.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_cec.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_cortex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_crc.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_crc_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_cryp.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_cryp_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_dac.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_dac_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_dcmi.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_dcmi_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_dfsdm.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_dma.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_dma_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_dma2d.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_dsi.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_eth.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_flash.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_flash_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_gpio.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_hash.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_hash_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_hcd.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_i2c.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_i2c_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_i2s.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_irda.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_iwdg.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_jpeg.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_lptim.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_ltdc.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_ltdc_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_mdios.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_nand.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_nor.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_pcd.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_pcd_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_pwr.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_pwr_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_qspi.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_rcc.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_rcc_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_rng.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_rtc.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_rtc_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_sai.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_sai_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_sd.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_sdram.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_smartcard.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_smartcard_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_spdifrx.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_spi.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_sram.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_tim.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_tim_ex.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_uart.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_usart.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_hal_wwdg.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_ll_fmc.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_ll_sdmmc.c \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/src/stm32f7xx_ll_usb.c

HEADERS = \
	../src/os_port_config.h \
	../src/net_config.h \
	../src/crypto_config.h \
	../src/stm32f7xx_hal_conf.h \
	../src/stm32f7xx_it.h \
	../src/private_mib_module.h \
	../src/private_mib_impl.h \
	../src/smi_driver.h \
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
	../../../../../cyclone_tcp/drivers/mac/stm32f7xx_eth_driver.h \
	../../../../../cyclone_tcp/drivers/phy/dp83848_driver.h \
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
	../../../../../cyclone_crypto/hardware/stm32f7xx/stm32f7xx_crypto.h \
	../../../../../cyclone_crypto/hardware/stm32f7xx/stm32f7xx_crypto_trng.h \
	../../../../../cyclone_crypto/hardware/stm32f7xx/stm32f7xx_crypto_hash.h \
	../../../../../cyclone_crypto/hardware/stm32f7xx/stm32f7xx_crypto_cipher.h \
	../../../../../cyclone_crypto/hash/md5.h \
	../../../../../cyclone_crypto/hash/sha1.h \
	../../../../../cyclone_crypto/mac/hmac.h \
	../../../../../cyclone_crypto/cipher/des.h \
	../../../../../cyclone_crypto/cipher/aes.h \
	../../../../../cyclone_crypto/cipher_modes/cbc.h \
	../../../../../cyclone_crypto/cipher_modes/cfb.h \
	../../../../../cyclone_crypto/encoding/asn1.h \
	../../../../../cyclone_crypto/encoding/oid.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_camera.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_eeprom.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_io.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_lcd.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_nor.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_qspi.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_sd.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_sdram.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_sram.h \
	../../../../../third_party/st/boards/stm32f769i_eval/stm32f769i_eval_ts.h \
	../../../../../third_party/st/boards/components/mfxstm32l152/mfxstm32l152.h \
	../../../../../third_party/st/boards/components/ft6x06/ft6x06.h \
	../../../../../third_party/st/boards/components/s5k5cag/s5k5cag.h \
	../../../../../third_party/st/boards/components/otm8009a/otm8009a.h \
	../../../../../third_party/st/boards/components/ov5640/ov5640.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_adc.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_adc_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_can.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_cec.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_cortex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_crc.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_crc_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_cryp.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_cryp_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_dac.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_dac_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_dcmi.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_dcmi_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_def.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_dfsdm.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_dma.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_dma_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_dma2d.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_dsi.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_eth.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_flash.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_flash_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_gpio.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_gpio_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_hash.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_hash_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_hcd.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_i2c.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_i2c_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_i2s.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_irda.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_irda_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_iwdg.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_jpeg.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_lptim.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_ltdc.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_ltdc_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_mdios.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_nand.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_nor.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_pcd.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_pcd_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_pwr.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_pwr_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_qspi.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_rcc.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_rcc_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_rng.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_rtc.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_rtc_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_sai.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_sai_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_sd.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_sdram.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_smartcard.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_smartcard_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_spdifrx.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_spi.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_sram.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_tim.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_tim_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_uart.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_uart_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_usart.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_usart_ex.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_hal_wwdg.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_ll_fmc.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_ll_sdmmc.h \
	../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc/stm32f7xx_ll_usb.h

ASM_OBJECTS = $(patsubst %.S, %.o, $(ASM_SOURCES))

C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

OBJ_DIR = obj

LINKER_SCRIPT = stm32f779_flash.ld

CFLAGS += -fno-common -Wall -Os -g3
CFLAGS += -mcpu=cortex-m7 -mthumb -mfpu=fpv5-d16 -mfloat-abi=hard
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

flash:
	openocd -f board/stm32f7discovery.cfg -c "init; reset halt; flash write_image erase $(RESULT).bin 0x08000000; reset run; shutdown"

clean:
	rm -f $(RESULT).elf
	rm -f $(RESULT).bin
	rm -f $(RESULT).map
	rm -f $(RESULT).hex
	rm -f $(RESULT).lst
	rm -f $(OBJ_DIR)/*.o
