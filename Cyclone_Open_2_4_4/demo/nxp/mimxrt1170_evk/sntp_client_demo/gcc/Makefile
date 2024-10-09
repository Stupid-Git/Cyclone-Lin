RESULT ?= sntp_client_demo

DEFINES = \
	-DCPU_MIMXRT1176DVMAA_cm7 \
	-DXIP_EXTERNAL_FLASH=1 \
	-DXIP_BOOT_HEADER_ENABLE=1 \
	-DXIP_BOOT_HEADER_DCD_ENABLE=1 \
	-DCACHE_MODE_WRITE_THROUGH=1 \
	-DUSE_MIMXRT1170_EVK \
	-D__MCUXPRESSO \
	-D__USE_CMSIS \
	-D__NEWLIB__ \
	-D_WINSOCK_H \
	-D__error_t_defined

INCLUDES = \
	-I../src \
	-I../../../../../third_party/cmsis/include \
	-I../../../../../third_party/nxp/devices/mimxrt1176 \
	-I../../../../../third_party/nxp/devices/mimxrt1176/drivers \
	-I../../../../../third_party/nxp/devices/mimxrt1176/drivers/cm7 \
	-I../../../../../third_party/nxp/devices/mimxrt1176/xip \
	-I../../../../../third_party/nxp/boards/mimxrt1170_evk \
	-I../../../../../third_party/nxp/boards/mimxrt1170_evk/cm7 \
	-I../../../../../third_party/freertos/include \
	-I../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1 \
	-I../../../../../common \
	-I../../../../../cyclone_tcp

ASM_SOURCES = \
	./startup_mimxrt1176_cm7.S

C_SOURCES = \
	../src/system_mimxrt1176_cm7.c \
	./syscalls.c \
	../src/main.c \
	../src/debug.c \
	../../../../../common/cpu_endian.c \
	../../../../../common/os_port_freertos.c \
	../../../../../common/date_time.c \
	../../../../../common/str.c \
	../../../../../cyclone_tcp/core/net.c \
	../../../../../cyclone_tcp/core/net_mem.c \
	../../../../../cyclone_tcp/core/net_misc.c \
	../../../../../cyclone_tcp/drivers/mac/mimxrt1170_eth1_driver.c \
	../../../../../cyclone_tcp/drivers/mac/mimxrt1170_eth2_driver.c \
	../../../../../cyclone_tcp/drivers/mac/mimxrt1170_eth3_driver.c \
	../../../../../cyclone_tcp/drivers/phy/ksz8081_driver.c \
	../../../../../cyclone_tcp/drivers/phy/rtl8211f_driver.c \
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
	../../../../../cyclone_tcp/sntp/sntp_client.c \
	../../../../../cyclone_tcp/sntp/sntp_client_misc.c \
	../../../../../cyclone_tcp/ntp/ntp_common.c \
	../../../../../cyclone_tcp/ntp/ntp_debug.c \
	../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1/port.c \
	../../../../../third_party/freertos/croutine.c \
	../../../../../third_party/freertos/list.c \
	../../../../../third_party/freertos/queue.c \
	../../../../../third_party/freertos/tasks.c \
	../../../../../third_party/freertos/timers.c \
	../../../../../third_party/freertos/portable/memmang/heap_3.c \
	../../../../../third_party/nxp/boards/mimxrt1170_evk/clock_config.c \
	../../../../../third_party/nxp/boards/mimxrt1170_evk/dcd.c \
	../../../../../third_party/nxp/boards/mimxrt1170_evk/evkmimxrt1170_flexspi_nor_config.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_anatop_ai.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_caam.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_clock.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_common.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_common_arm.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_dcdc.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_gpio.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_lpuart.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_pmu.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_semc.c \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/cm7/fsl_cache.c \
	../../../../../third_party/nxp/devices/mimxrt1176/xip/fsl_flexspi_nor_boot.c

HEADERS = \
	../src/os_port_config.h \
	../src/net_config.h \
	../src/FreeRTOSConfig.h \
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
	../../../../../cyclone_tcp/drivers/mac/mimxrt1170_eth1_driver.h \
	../../../../../cyclone_tcp/drivers/mac/mimxrt1170_eth2_driver.h \
	../../../../../cyclone_tcp/drivers/mac/mimxrt1170_eth3_driver.h \
	../../../../../cyclone_tcp/drivers/phy/ksz8081_driver.h \
	../../../../../cyclone_tcp/drivers/phy/rtl8211f_driver.h \
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
	../../../../../cyclone_tcp/sntp/sntp_client.h \
	../../../../../cyclone_tcp/sntp/sntp_client_misc.h \
	../../../../../cyclone_tcp/ntp/ntp_common.h \
	../../../../../cyclone_tcp/ntp/ntp_debug.h \
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
	../../../../../third_party/nxp/boards/mimxrt1170_evk/board.h \
	../../../../../third_party/nxp/boards/mimxrt1170_evk/clock_config.h \
	../../../../../third_party/nxp/boards/mimxrt1170_evk/dcd.h \
	../../../../../third_party/nxp/boards/mimxrt1170_evk/evkmimxrt1170_flexspi_nor_config.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_anatop_ai.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_caam.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_clock.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_common.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_common_arm.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_dcdc.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_gpio.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_iomuxc.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_lpuart.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_pmu.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/fsl_semc.h \
	../../../../../third_party/nxp/devices/mimxrt1176/drivers/cm7/fsl_cache.h \
	../../../../../third_party/nxp/devices/mimxrt1176/xip/fsl_flexspi_nor_boot.h

ASM_OBJECTS = $(patsubst %.S, %.o, $(ASM_SOURCES))

C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

OBJ_DIR = obj

LINKER_SCRIPT = mimxrt1176_cm7_flash.ld

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
