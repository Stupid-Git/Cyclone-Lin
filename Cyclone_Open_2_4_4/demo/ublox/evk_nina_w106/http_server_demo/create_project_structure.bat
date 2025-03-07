md main\common
md main\cyclone_tcp
md main\cyclone_tcp\core
md main\cyclone_tcp\drivers
md main\cyclone_tcp\drivers\mac
md main\cyclone_tcp\drivers\phy
md main\cyclone_tcp\drivers\wifi
md main\cyclone_tcp\ipv4
md main\cyclone_tcp\igmp
md main\cyclone_tcp\ipv6
md main\cyclone_tcp\ppp
md main\cyclone_tcp\mibs
md main\cyclone_tcp\dns
md main\cyclone_tcp\mdns
md main\cyclone_tcp\dns_sd
md main\cyclone_tcp\netbios
md main\cyclone_tcp\llmnr
md main\cyclone_tcp\dhcp
md main\cyclone_tcp\dhcpv6
md main\cyclone_tcp\http
md main\cyclone_tcp\web_socket

REM Common Sources
copy ..\..\..\..\common\cpu_endian.c main\common
copy ..\..\..\..\common\os_port_freertos.c main\common
copy ..\..\..\..\common\date_time.c main\common
copy ..\..\..\..\common\str.c main\common
copy ..\..\..\..\common\path.c main\common
copy ..\..\..\..\common\resource_manager.c main\common
copy ..\..\..\..\common\debug.c main\common

REM Common Headers
copy ..\..\..\..\common\cpu_endian.h main\common
copy ..\..\..\..\common\compiler_port.h main\common
copy ..\..\..\..\common\os_port.h main\common
copy ..\..\..\..\common\os_port_freertos.h main\common
copy ..\..\..\..\common\date_time.h main\common
copy ..\..\..\..\common\str.h main\common
copy ..\..\..\..\common\path.h main\common
copy ..\..\..\..\common\resource_manager.h main\common
copy ..\..\..\..\common\error.h main\common
copy ..\..\..\..\common\debug.h main\common

REM CycloneTCP Sources
copy ..\..\..\..\cyclone_tcp\drivers\mac\esp32_eth_driver.c main\cyclone_tcp\drivers\mac
copy ..\..\..\..\cyclone_tcp\drivers\phy\ksz8081_driver.c main\cyclone_tcp\drivers\phy
copy ..\..\..\..\cyclone_tcp\drivers\wifi\esp32_wifi_driver.c main\cyclone_tcp\drivers\wifi
copy ..\..\..\..\cyclone_tcp\core\*.c main\cyclone_tcp\core
copy ..\..\..\..\cyclone_tcp\ipv4\*.c main\cyclone_tcp\ipv4
copy ..\..\..\..\cyclone_tcp\igmp\*.c main\cyclone_tcp\igmp
copy ..\..\..\..\cyclone_tcp\ipv6\*.c main\cyclone_tcp\ipv6
copy ..\..\..\..\cyclone_tcp\dns\*.c main\cyclone_tcp\dns
copy ..\..\..\..\cyclone_tcp\mdns\*.c main\cyclone_tcp\mdns
copy ..\..\..\..\cyclone_tcp\netbios\*.c main\cyclone_tcp\netbios
copy ..\..\..\..\cyclone_tcp\llmnr\*.c main\cyclone_tcp\llmnr
copy ..\..\..\..\cyclone_tcp\dhcp\*.c main\cyclone_tcp\dhcp
copy ..\..\..\..\cyclone_tcp\http\*.c main\cyclone_tcp\http

REM CycloneTCP Headers
copy ..\..\..\..\cyclone_tcp\drivers\mac\esp32_eth_driver.h main\cyclone_tcp\drivers\mac
copy ..\..\..\..\cyclone_tcp\drivers\phy\ksz8081_driver.h main\cyclone_tcp\drivers\phy
copy ..\..\..\..\cyclone_tcp\drivers\wifi\esp32_wifi_driver.h main\cyclone_tcp\drivers\wifi
copy ..\..\..\..\cyclone_tcp\core\*.h main\cyclone_tcp\core
copy ..\..\..\..\cyclone_tcp\ipv4\*.h main\cyclone_tcp\ipv4
copy ..\..\..\..\cyclone_tcp\igmp\*.h main\cyclone_tcp\igmp
copy ..\..\..\..\cyclone_tcp\ipv6\*.h main\cyclone_tcp\ipv6
copy ..\..\..\..\cyclone_tcp\ppp\*.h main\cyclone_tcp\ppp
copy ..\..\..\..\cyclone_tcp\mibs\*.h main\cyclone_tcp\mibs
copy ..\..\..\..\cyclone_tcp\dns\*.h main\cyclone_tcp\dns
copy ..\..\..\..\cyclone_tcp\mdns\*.h main\cyclone_tcp\mdns
copy ..\..\..\..\cyclone_tcp\dns_sd\*.h main\cyclone_tcp\dns_sd
copy ..\..\..\..\cyclone_tcp\netbios\*.h main\cyclone_tcp\netbios
copy ..\..\..\..\cyclone_tcp\llmnr\*.h main\cyclone_tcp\llmnr
copy ..\..\..\..\cyclone_tcp\dhcp\*.h main\cyclone_tcp\dhcp
copy ..\..\..\..\cyclone_tcp\dhcpv6\*.h main\cyclone_tcp\dhcpv6
copy ..\..\..\..\cyclone_tcp\http\*.h main\cyclone_tcp\http
copy ..\..\..\..\cyclone_tcp\web_socket\*.h main\cyclone_tcp\web_socket

REM Compile resources
..\..\..\..\utils\ResourceCompiler\bin\rc.exe resources main\res.c
