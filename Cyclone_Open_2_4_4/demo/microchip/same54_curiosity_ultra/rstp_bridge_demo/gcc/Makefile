RESULT ?= rstp_bridge_demo

DEFINES = \
	-D__SAME54P20A__ \
	-DUSE_CMSIS_INIT \
	-DUSE_SAME54_CURIOSITY_ULTRA \
	-DUSE_LAN9303 \
	-D_WINSOCK_H \
	-D__error_t_defined

INCLUDES = \
	-I../src \
	-I../../../../../third_party/cmsis/include \
	-I../../../../../third_party/microchip/devices/same54 \
	-I../../../../../third_party/microchip/boards/same54_curiosity_ultra \
	-I../../../../../third_party/freertos/include \
	-I../../../../../third_party/freertos/portable/gcc/arm_cm4f \
	-I../../../../../common \
	-I../../../../../cyclone_stp \
	-I../../../../../cyclone_tcp \
	-I../../../../../cyclone_crypto

ASM_SOURCES =

C_SOURCES = \
	./startup_same54.c \
	../src/system_same54.c \
	./syscalls.c \
	../src/main.c \
	../src/spi_driver.c \
	../src/debug.c \
	../../../../../common/cpu_endian.c \
	../../../../../common/os_port_freertos.c \
	../../../../../common/date_time.c \
	../../../../../common/str.c \
	../../../../../cyclone_stp/rstp/rstp.c \
	../../../../../cyclone_stp/rstp/rstp_mgmt.c \
	../../../../../cyclone_stp/rstp/rstp_fsm.c \
	../../../../../cyclone_stp/rstp/rstp_bdm.c \
	../../../../../cyclone_stp/rstp/rstp_pim.c \
	../../../../../cyclone_stp/rstp/rstp_ppm.c \
	../../../../../cyclone_stp/rstp/rstp_prs.c \
	../../../../../cyclone_stp/rstp/rstp_prt.c \
	../../../../../cyclone_stp/rstp/rstp_prx.c \
	../../../../../cyclone_stp/rstp/rstp_pst.c \
	../../../../../cyclone_stp/rstp/rstp_pti.c \
	../../../../../cyclone_stp/rstp/rstp_ptx.c \
	../../../../../cyclone_stp/rstp/rstp_tcm.c \
	../../../../../cyclone_stp/rstp/rstp_procedures.c \
	../../../../../cyclone_stp/rstp/rstp_conditions.c \
	../../../../../cyclone_stp/rstp/rstp_bpdu.c \
	../../../../../cyclone_stp/rstp/rstp_misc.c \
	../../../../../cyclone_stp/mibs/bridge_mib_module.c \
	../../../../../cyclone_stp/mibs/bridge_mib_impl.c \
	../../../../../cyclone_stp/mibs/bridge_mib_impl_base.c \
	../../../../../cyclone_stp/mibs/bridge_mib_impl_stp.c \
	../../../../../cyclone_stp/mibs/bridge_mib_impl_tp.c \
	../../../../../cyclone_stp/mibs/bridge_mib_impl_static.c \
	../../../../../cyclone_stp/mibs/rstp_mib_module.c \
	../../../../../cyclone_stp/mibs/rstp_mib_impl.c \
	../../../../../cyclone_tcp/core/net.c \
	../../../../../cyclone_tcp/core/net_mem.c \
	../../../../../cyclone_tcp/core/net_misc.c \
	../../../../../cyclone_tcp/drivers/mac/same54_eth_driver.c \
	../../../../../cyclone_tcp/drivers/switch/ksz8863_driver.c \
	../../../../../cyclone_tcp/drivers/switch/lan9303_driver.c \
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
	../../../../../cyclone_tcp/mibs/snmp_mib_module.c \
	../../../../../cyclone_tcp/mibs/snmp_mib_impl.c \
	../../../../../cyclone_crypto/hash/md5.c \
	../../../../../cyclone_crypto/hash/sha1.c \
	../../../../../cyclone_crypto/mac/hmac.c \
	../../../../../cyclone_crypto/cipher/des.c \
	../../../../../cyclone_crypto/cipher/aes.c \
	../../../../../cyclone_crypto/cipher_modes/cbc.c \
	../../../../../cyclone_crypto/cipher_modes/cfb.c \
	../../../../../cyclone_crypto/encoding/asn1.c \
	../../../../../cyclone_crypto/encoding/oid.c \
	../../../../../third_party/freertos/portable/gcc/arm_cm4f/port.c \
	../../../../../third_party/freertos/croutine.c \
	../../../../../third_party/freertos/list.c \
	../../../../../third_party/freertos/queue.c \
	../../../../../third_party/freertos/tasks.c \
	../../../../../third_party/freertos/timers.c \
	../../../../../third_party/freertos/portable/memmang/heap_3.c

HEADERS = \
	../src/os_port_config.h \
	../src/stp_config.h \
	../src/net_config.h \
	../src/crypto_config.h \
	../src/FreeRTOSConfig.h \
	../src/spi_driver.h \
	../../../../../common/cpu_endian.h \
	../../../../../common/os_port.h \
	../../../../../common/os_port_freertos.h \
	../../../../../common/date_time.h \
	../../../../../common/str.h \
	../../../../../common/error.h \
	../../../../../common/debug.h \
	../../../../../cyclone_stp/rstp/rstp.h \
	../../../../../cyclone_stp/rstp/rstp_mgmt.h \
	../../../../../cyclone_stp/rstp/rstp_fsm.h \
	../../../../../cyclone_stp/rstp/rstp_bdm.h \
	../../../../../cyclone_stp/rstp/rstp_pim.h \
	../../../../../cyclone_stp/rstp/rstp_ppm.h \
	../../../../../cyclone_stp/rstp/rstp_prs.h \
	../../../../../cyclone_stp/rstp/rstp_prt.h \
	../../../../../cyclone_stp/rstp/rstp_prx.h \
	../../../../../cyclone_stp/rstp/rstp_pst.h \
	../../../../../cyclone_stp/rstp/rstp_pti.h \
	../../../../../cyclone_stp/rstp/rstp_ptx.h \
	../../../../../cyclone_stp/rstp/rstp_tcm.h \
	../../../../../cyclone_stp/rstp/rstp_procedures.h \
	../../../../../cyclone_stp/rstp/rstp_conditions.h \
	../../../../../cyclone_stp/rstp/rstp_bpdu.h \
	../../../../../cyclone_stp/rstp/rstp_misc.h \
	../../../../../cyclone_stp/mibs/bridge_mib_module.h \
	../../../../../cyclone_stp/mibs/bridge_mib_impl.h \
	../../../../../cyclone_stp/mibs/bridge_mib_impl_base.h \
	../../../../../cyclone_stp/mibs/bridge_mib_impl_stp.h \
	../../../../../cyclone_stp/mibs/bridge_mib_impl_tp.h \
	../../../../../cyclone_stp/mibs/bridge_mib_impl_static.h \
	../../../../../cyclone_stp/mibs/rstp_mib_module.h \
	../../../../../cyclone_stp/mibs/rstp_mib_impl.h \
	../../../../../cyclone_tcp/core/net.h \
	../../../../../cyclone_tcp/core/net_mem.h \
	../../../../../cyclone_tcp/core/net_misc.h \
	../../../../../cyclone_tcp/drivers/mac/same54_eth_driver.h \
	../../../../../cyclone_tcp/drivers/switch/ksz8863_driver.h \
	../../../../../cyclone_tcp/drivers/switch/lan9303_driver.h \
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
	../../../../../cyclone_tcp/mibs/snmp_mib_module.h \
	../../../../../cyclone_tcp/mibs/snmp_mib_impl.h \
	../../../../../cyclone_crypto/core/crypto.h \
	../../../../../cyclone_crypto/hash/md5.h \
	../../../../../cyclone_crypto/hash/sha1.h \
	../../../../../cyclone_crypto/mac/hmac.h \
	../../../../../cyclone_crypto/cipher/des.h \
	../../../../../cyclone_crypto/cipher/aes.h \
	../../../../../cyclone_crypto/cipher_modes/cbc.h \
	../../../../../cyclone_crypto/cipher_modes/cfb.h \
	../../../../../cyclone_crypto/encoding/asn1.h \
	../../../../../cyclone_crypto/encoding/oid.h \
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
	../../../../../third_party/microchip/boards/same54_curiosity_ultra/same54_curiosity_ultra.h

ASM_OBJECTS = $(patsubst %.S, %.o, $(ASM_SOURCES))

C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

OBJ_DIR = obj

LINKER_SCRIPT = same54_flash.ld

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
	openocd -f board/microchip_same54_xplained_pro.cfg -c "init; reset halt; flash write_image erase $(RESULT).bin 0x00000000; reset run; shutdown"

clean:
	rm -f $(RESULT).elf
	rm -f $(RESULT).bin
	rm -f $(RESULT).map
	rm -f $(RESULT).hex
	rm -f $(RESULT).lst
	rm -f $(OBJ_DIR)/*.o
