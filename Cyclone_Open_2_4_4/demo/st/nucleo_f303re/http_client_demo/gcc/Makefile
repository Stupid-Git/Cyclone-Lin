RESULT ?= http_client_demo

DEFINES = \
	-DSTM32F303xE \
	-DUSE_HAL_DRIVER \
	-DUSE_STM32F3XX_NUCLEO \
	-DUSE_W5500 \
	-D_WINSOCK_H \
	-D__error_t_defined

INCLUDES = \
	-I../src \
	-I../../../../../third_party/cmsis/include \
	-I../../../../../third_party/st/devices/stm32f3xx \
	-I../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc \
	-I../../../../../third_party/st/boards/stm32f3xx_nucleo \
	-I../../../../../third_party/freertos/include \
	-I../../../../../third_party/freertos/portable/gcc/arm_cm4f \
	-I../../../../../common \
	-I../../../../../cyclone_tcp

ASM_SOURCES = \
	./startup_stm32f303xe.S

C_SOURCES = \
	../src/system_stm32f3xx.c \
	../src/stm32f3xx_it.c \
	./syscalls.c \
	../src/main.c \
	../src/debug.c \
	../src/spi_driver.c \
	../src/ext_int_driver.c \
	../../../../../common/cpu_endian.c \
	../../../../../common/os_port_freertos.c \
	../../../../../common/date_time.c \
	../../../../../common/str.c \
	../../../../../cyclone_tcp/core/net.c \
	../../../../../cyclone_tcp/core/net_mem.c \
	../../../../../cyclone_tcp/core/net_misc.c \
	../../../../../cyclone_tcp/drivers/eth/w3150a_driver.c \
	../../../../../cyclone_tcp/drivers/eth/w5100_driver.c \
	../../../../../cyclone_tcp/drivers/eth/w5100s_driver.c \
	../../../../../cyclone_tcp/drivers/eth/w5200_driver.c \
	../../../../../cyclone_tcp/drivers/eth/w5500_driver.c \
	../../../../../cyclone_tcp/drivers/eth/w6100_driver.c \
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
	../../../../../cyclone_tcp/http/http_client.c \
	../../../../../cyclone_tcp/http/http_client_transport.c \
	../../../../../cyclone_tcp/http/http_client_misc.c \
	../../../../../cyclone_tcp/http/http_common.c \
	../../../../../third_party/freertos/portable/gcc/arm_cm4f/port.c \
	../../../../../third_party/freertos/croutine.c \
	../../../../../third_party/freertos/list.c \
	../../../../../third_party/freertos/queue.c \
	../../../../../third_party/freertos/tasks.c \
	../../../../../third_party/freertos/timers.c \
	../../../../../third_party/freertos/portable/memmang/heap_3.c \
	../../../../../third_party/st/boards/stm32f3xx_nucleo/stm32f3xx_nucleo.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_adc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_adc_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_can.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_cec.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_comp.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_cortex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_crc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_crc_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_dac.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_dac_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_dma.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_exti.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_flash.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_flash_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_gpio.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_hrtim.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_i2c.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_i2c_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_i2s.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_i2s_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_irda.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_iwdg.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_nand.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_nor.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_opamp.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_opamp_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_pccard.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_pcd.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_pcd_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_pwr.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_pwr_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_rcc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_rcc_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_rtc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_rtc_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_sdadc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_smartcard.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_smartcard_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_smbus.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_spi.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_spi_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_sram.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_tim.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_tim_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_tsc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_uart.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_uart_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_usart.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_usart_ex.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_hal_wwdg.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_adc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_comp.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_crc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_dac.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_dma.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_exti.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_fmc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_gpio.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_hrtim.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_i2c.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_opamp.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_pwr.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_rcc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_rtc.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_spi.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_tim.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_usart.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_usb.c \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/src/stm32f3xx_ll_utils.c

HEADERS = \
	../src/os_port_config.h \
	../src/net_config.h \
	../src/FreeRTOSConfig.h \
	../src/stm32f3xx_hal_conf.h \
	../src/stm32f3xx_it.h \
	../src/spi_driver.h \
	../src/ext_int_driver.h \
	../../../../../common/cpu_endian.h \
	../../../../../common/os_port.h \
	../../../../../common/os_port_freertos.h \
	../../../../../common/date_time.h \
	../../../../../common/str.h \
	../../../../../common/error.h \
	../../../../../common/debug.h \
	../../../../../cyclone_tcp/core/net.h \
	../../../../../cyclone_tcp/core/net_mem.h \
	../../../../../cyclone_tcp/core/net_misc.h \
	../../../../../cyclone_tcp/drivers/eth/w3150a_driver.h \
	../../../../../cyclone_tcp/drivers/eth/w5100_driver.h \
	../../../../../cyclone_tcp/drivers/eth/w5100s_driver.h \
	../../../../../cyclone_tcp/drivers/eth/w5200_driver.h \
	../../../../../cyclone_tcp/drivers/eth/w5500_driver.h \
	../../../../../cyclone_tcp/drivers/eth/w6100_driver.h \
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
	../../../../../cyclone_tcp/http/http_client.h \
	../../../../../cyclone_tcp/http/http_client_transport.h \
	../../../../../cyclone_tcp/http/http_client_misc.h \
	../../../../../cyclone_tcp/http/http_common.h \
	../../../../../third_party/freertos/portable/gcc/arm_cm4f/portmacro.h \
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
	../../../../../third_party/st/boards/stm32f3xx_nucleo/stm32f3xx_nucleo.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_adc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_adc_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_can.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_cec.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_comp.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_comp_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_cortex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_crc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_crc_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_dac.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_dac_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_def.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_dma.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_dma_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_exti.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_flash.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_flash_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_gpio.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_gpio_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_hrtim.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_i2c.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_i2c_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_i2s.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_i2s_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_irda.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_irda_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_iwdg.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_nand.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_nor.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_opamp.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_opamp_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_pccard.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_pcd.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_pcd_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_pwr.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_pwr_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_rcc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_rcc_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_rtc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_rtc_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_sdadc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_smartcard.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_smartcard_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_smbus.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_spi.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_spi_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_sram.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_tim.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_tim_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_tsc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_uart.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_uart_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_usart.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_usart_ex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_hal_wwdg.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_adc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_bus.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_comp.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_cortex.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_crc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_dac.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_dma.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_exti.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_fmc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_gpio.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_hrtim.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_i2c.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_iwdg.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_opamp.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_pwr.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_rcc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_rtc.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_spi.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_system.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_tim.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_usart.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_usb.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_utils.h \
	../../../../../third_party/st/drivers/stm32f3xx_hal_driver/inc/stm32f3xx_ll_wwdg.h

ASM_OBJECTS = $(patsubst %.S, %.o, $(ASM_SOURCES))

C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

OBJ_DIR = obj

LINKER_SCRIPT = stm32f303_flash.ld

CFLAGS += -fno-common -Wall -Os -g3
CFLAGS += -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp
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
	openocd -f board/st_nucleo_f4.cfg -c "init; reset halt; flash write_image erase $(RESULT).bin 0x08000000; reset run; shutdown"

clean:
	rm -f $(RESULT).elf
	rm -f $(RESULT).bin
	rm -f $(RESULT).map
	rm -f $(RESULT).hex
	rm -f $(RESULT).lst
	rm -f $(OBJ_DIR)/*.o
