 

 

/*
 Using RAW Sockets
 RAW sockets allows you to bypass the TCP/UDP layer (Layer 4) in the RtxTcpIp stack and communicate directly with the Network IP layer (Layer 3). This functionality allows you to skip the addition of TCP/UDP protocols to your frames and, optionally, provide a comparable protocol of your own.

 With the current implementation, only one raw socket can be opened per device at any given time. To create a raw socket, the type field should be set to SOCK_RAW and the protocol field should be IPPROTO_RAW:

 sock = socket (AF_INET, SOCK_RAW, IPPROTO_RAW);
 An application must use sendto to send datagrams on a raw socket. Also, for the current implementation, the application must build the entire IP datagram, including the IP header. No processing is performed by the IP layer on a raw Ethernet socket except for setting the IP header checksum bit to 0. This lets the stack, versus the application, calculate the checksum and populate the IP header checksum value accordingly.

 An application must use recvfrom to read datagrams from a raw socket. Before you can receive packets on a raw socket, you must bind the socket to the IP address of the interface on which you want to receive packets.

 The following pseudo code shows you how to create the socket, define the IP header, and send and receive using the socket.

 char sendbuf[maxsize];
 char recvbuf[maxsize];

 char *Iphdr = sendbuf;

 sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
 Iphdr[0] = version
 IPhdr[1] = Internet header length
 IPhdr[2] = Type of Service
 IPhdr[3] = Total Length
 IPhdr[4] = Identification
 IPhdr[5] = Flags
 IPhdr[6] = Fragment Offset
 IPhdr[7] = Time to Live
 IPhdr[8] = Protocol
 IPhdr[9] = Header Checksum
 IPhdr[10] = Source IP address
 IPhdr[11] = destination IP address
 bind(sock, (sockaddr*) & sendaddr, sizeof(sendaddr);
 if (transmit)
 len = sendto(sock, sendbuf, sizeof(sendbuf), 0,(SOCKADDR *)
 &pFrom, iFromSize);
 else
 len = recvfrom(sock, recvbuf, sizeof(recvbuf), 0,(SOCKADDR *)
 &pFrom, &iFromSize);
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <linux/ip.h>
#include <linux/udp.h>

#include <netinet/if_ether.h>

#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/ether.h>


#include "raw_sock.h"

#define DEST_MAC0	0x00
#define DEST_MAC1	0x00
#define DEST_MAC2	0x00
#define DEST_MAC3	0x00
#define DEST_MAC4	0x00
#define DEST_MAC5	0x00

#define ETHER_TYPE	0x0800

//#define DEFAULT_IF	"eth0"
#define DEFAULT_IF	"eno1"
#define BUF_SIZ		1024


error_t RAW_openZ(int *psd)
{
    error_t err;
    err = NO_ERROR;
    *psd = 0;
    int sock, n;
    //char buffer[2048];
    //unsigned char *iphead, *ethhead;
    
    sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP));
    //sock = socket(PF_PACKET, SOCK_RAW, htons(IPPROTO_RAW));
    if(sock  < 0) {
        perror("socket");
        exit(1);
    }

    *psd = sock;
    return err;
}


// https://github.com/c-bata/xpcap/blob/master/sniffer.c

error_t RAW_open(int *psd)
{
    error_t err;
    err = NO_ERROR;
    *psd = 0;

    //////////////////////////////////
    struct ifreq if_req;
    struct sockaddr_ll sa;
    int soc;

    if ((soc = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) {
        perror("socket");
        return -1;
    }

    strcpy(if_req.ifr_name, "eno1"); //params.interface);
    if (ioctl(soc, SIOCGIFINDEX, &if_req) == -1) {
        perror("ioctl SIOCGIFINDEX");
        close(soc);
        return -1;
    }
    {
        printf("ifr_ifindex = %d\r\n", if_req.ifr_ifindex);
    }

    sa.sll_family = PF_PACKET;
    sa.sll_protocol = htons(ETH_P_ALL);
    sa.sll_ifindex = if_req.ifr_ifindex;
    if (bind(soc, (struct sockaddr *) &sa, sizeof(sa)) == -1) {
        perror("bind");
        close(soc);
        return (-1);
    }

    if (ioctl(soc, SIOCGIFFLAGS, &if_req) == -1) {
        perror("ioctl");
        close(soc);
        return (-1);
    }

    if_req.ifr_flags = if_req.ifr_flags|IFF_PROMISC|IFF_UP;
    if (ioctl(soc, SIOCSIFFLAGS, &if_req) == -1) {
        perror("ioctl");
        close(soc);
        return (-1);
    }

    //sniffer->fd = soc;
    //sniffer->buffer = malloc(sizeof(char) * sniffer->buf_len);
    //if (params.buf_len > 0) {
    //    sniffer->buf_len = params.buf_len;
    //} else {
    //    sniffer->buf_len = 4096;
    //}
    //return 0;
    
    //////////////////////////////////
	*psd = soc;
	return err;

}

// https://github.com/baoqger/raw-socket-packet-capture/blob/master/raw_socket.c

error_t RAW_open_1(int *psd)
{
    error_t err;
    err = NO_ERROR;
    *psd = 0;
    int sock, n;
    //char buffer[2048];
    //unsigned char *iphead, *ethhead;
    
    sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP)); // RX OK, TX TX: No such device or address
    //sock = socket(AF_PACKET, SOCK_RAW, htons(IPPROTO_RAW));//No RX, TX: No such device or address
    
    //sock = socket(AF_NETLINK, SOCK_RAW, NETLINK_GENERIC);
    ///sock = socket(AF_UNIX, SOCK_RAW, 0); // No RX, TX: send: Transport endpoint is not connected

    //sock = socket(AF_PACKET, SOCK_RAW, 0); //No RX, TX: No such device or address
    //sock = socket(AF_INET, SOCK_RAW, 0); // NG socket: Protocol not supported
    //sock = socket(AF_UNIX, SOCK_RAW,  htons(ETH_P_IP)); // NG socket: Protocol not supported
    //sock = socket(AF_UNIX, SOCK_RAW, htons(IPPROTO_RAW)); // NG socket: Protocol not supported
    
    if(sock  < 0) {
        perror("socket");
        exit(1);
    }
    // bind to eth0 interface only
    const char *opt;
    opt = "eth0";
    opt = "eno1";
    if (setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, opt, strlen(opt) + 1) < 0) {
        perror("setsockopt bind device");
        close(sock);
        exit(1);
    }
#if 1    
    /* set the network card in promiscuos mode*/
    // An ioctl() request has encoded in it whether the argument is an in parameter or out parameter
    // SIOCGIFFLAGS	0x8913		/* get flags			*/
    // SIOCSIFFLAGS	0x8914		/* set flags			*/
    struct ifreq ethreq;
    strncpy(ethreq.ifr_name, opt/*"eth0"*/, IF_NAMESIZE);
    if (ioctl(sock, SIOCGIFFLAGS, &ethreq) == -1) {
        perror("ioctl A");
        close(sock);
        exit(1);
    }
    ethreq.ifr_flags |= IFF_PROMISC;
    if (ioctl(sock, SIOCSIFFLAGS, &ethreq) == -1) {
        perror("ioctl B");
        close(sock);
        exit(1);
    }
    
    //--- more candy ---
    char ifName[IFNAMSIZ];
    strcpy(ifName, "eno1");  //DEFAULT_IF);

    struct ifreq if_idx;    
    /* Get the index of the interface to send on */
    memset(&if_idx, 0, sizeof(struct ifreq));
    strncpy(if_idx.ifr_name, ifName, IFNAMSIZ-1);
    if (ioctl(sock, SIOCGIFINDEX, &if_idx) < 0)
        perror("SIOCGIFINDEX");
    else
    {
        printf("ifr_ifindex = %d\r\n", if_idx.ifr_ifindex);
    }

    /* Get the MAC address of the interface to send on */
    struct ifreq if_mac;
    memset(&if_mac, 0, sizeof(struct ifreq));
    strncpy(if_mac.ifr_name, ifName, IFNAMSIZ-1);
    if (ioctl(sock, SIOCGIFHWADDR, &if_mac) < 0)
        perror("SIOCGIFHWADDR");    
    else
    {
        printf("if_mac.ifr_hwaddr.sa_family = %d\r\n", if_mac.ifr_hwaddr.sa_family);
        printf("if_mac.ifr_hwaddr.sa_X[0] = %02X\r\n", (uint8_t)if_mac.ifr_hwaddr.sa_data[0]);
        printf("if_mac.ifr_hwaddr.sa_X[1] = %02X\r\n", (uint8_t)if_mac.ifr_hwaddr.sa_data[1]);
        printf("if_mac.ifr_hwaddr.sa_X[2] = %02X\r\n", (uint8_t)if_mac.ifr_hwaddr.sa_data[2]);
        printf("if_mac.ifr_hwaddr.sa_X[3] = %02X\r\n", (uint8_t)if_mac.ifr_hwaddr.sa_data[3]);
        printf("if_mac.ifr_hwaddr.sa_X[4] = %02X\r\n", (uint8_t)if_mac.ifr_hwaddr.sa_data[4]);
        printf("if_mac.ifr_hwaddr.sa_X[5] = %02X\r\n", (uint8_t)if_mac.ifr_hwaddr.sa_data[5]);
    }
#endif
    
/*    
    int sockfd;
    int sockopt;
    struct ifreq if_idx;
    struct ifreq if_mac;
    int tx_len = 0;
    char sendbuf[BUF_SIZ];
    struct ether_header *eh = (struct ether_header *) sendbuf;
    struct iphdr *iph = (struct iphdr *) (sendbuf + sizeof(struct ether_header));
    struct sockaddr_ll socket_address;
    char ifName[IFNAMSIZ];
    
    strcpy(ifName, DEFAULT_IF);

	if ((sockfd = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW)) == -1) {
		perror("socket");
	}

	// Get the index of the interface to send on 
	memset(&if_idx, 0, sizeof(struct ifreq));
	strncpy(if_idx.ifr_name, ifName, IFNAMSIZ - 1);
	if (ioctl(sockfd, SIOCGIFINDEX, &if_idx) < 0)
		perror("SIOCGIFINDEX");
	// Get the MAC address of the interface to send on 
	memset(&if_mac, 0, sizeof(struct ifreq));
	strncpy(if_mac.ifr_name, ifName, IFNAMSIZ - 1);
	if (ioctl(sockfd, SIOCGIFHWADDR, &if_mac) < 0)
		perror("SIOCGIFHWADDR");
*/
    //
	*psd = sock;
	return err;
}


error_t RAW_openQ(int *psd)
{
    error_t err;
    err = NO_ERROR;
    *psd = 0;
    
    int sockfd;
    int sockopt;
    struct ifreq if_idx;
    struct ifreq if_mac;
    int tx_len = 0;
    char sendbuf[BUF_SIZ];
    struct ether_header *eh = (struct ether_header *) sendbuf;
    struct iphdr *iph = (struct iphdr *) (sendbuf + sizeof(struct ether_header));
    struct sockaddr_ll socket_address;
    char ifName[IFNAMSIZ];
    
    strcpy(ifName, DEFAULT_IF);

	/* Open RAW socket to send on */
	if ((sockfd = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW)) == -1) {
		perror("socket");
	}

	/* Get the index of the interface to send on */
	memset(&if_idx, 0, sizeof(struct ifreq));
	strncpy(if_idx.ifr_name, ifName, IFNAMSIZ - 1);
	if (ioctl(sockfd, SIOCGIFINDEX, &if_idx) < 0)
		perror("SIOCGIFINDEX");
	/* Get the MAC address of the interface to send on */
	memset(&if_mac, 0, sizeof(struct ifreq));
	strncpy(if_mac.ifr_name, ifName, IFNAMSIZ - 1);
	if (ioctl(sockfd, SIOCGIFHWADDR, &if_mac) < 0)
		perror("SIOCGIFHWADDR");

	*psd = sockfd;
	return err;
}

error_t RAW_openX(int *psd) {
	error_t err;
	err = NO_ERROR;
	*psd = 0;

	char sender[INET6_ADDRSTRLEN];
	int sockfd, ret, i;
	int sockopt;
	ssize_t numbytes;
	struct ifreq ifopts; /* set promiscuous mode */
	struct ifreq if_ip; /* get ip addr */
	struct sockaddr_storage their_addr;
	uint8_t buf[BUF_SIZ];
	char ifName[IFNAMSIZ];

	/* Get interface name */
	//if (argc > 1)
	//	strcpy(ifName, argv[1]);
	//else
	strcpy(ifName, DEFAULT_IF);

	/* Header structures */
	struct ether_header *eh = (struct ether_header*) buf;
	struct iphdr *iph = (struct iphdr*) (buf + sizeof(struct ether_header));
	struct udphdr *udph = (struct udphdr*) (buf + sizeof(struct iphdr)
			+ sizeof(struct ether_header));

	memset(&if_ip, 0, sizeof(struct ifreq));

	/* Open PF_PACKET socket, listening for EtherType ETHER_TYPE */
	if ((sockfd = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW)) == -1)
	//if ((sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETHER_TYPE))) == -1)
	//if ((sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETHER_TYPE))) == -1)
			{
		perror("listener: socket");
		return ERROR_FAILURE;		//-1;
	}

	/* Set interface to promiscuous mode - do we need to do this every time? */
	strncpy(ifopts.ifr_name, ifName, IFNAMSIZ - 1);
	ioctl(sockfd, SIOCGIFFLAGS, &ifopts);
	ifopts.ifr_flags |= IFF_PROMISC;
	ioctl(sockfd, SIOCSIFFLAGS, &ifopts);
	/* Allow the socket to be reused - incase connection is closed prematurely */
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof sockopt)
			== -1) {
		perror("setsockopt");
		close(sockfd);
		return ERROR_FAILURE;		//exit(EXIT_FAILURE);
	}
	/* Bind to device */
	/**/
	if (setsockopt(sockfd, SOL_SOCKET, SO_BINDTODEVICE, ifName, IFNAMSIZ - 1)
			== -1) {
		perror("SO_BINDTODEVICE");
		close(sockfd);
		return ERROR_FAILURE;		//exit(EXIT_FAILURE);
	}
	/**/

#if 1
#define BUF_SIZE (ETH_FRAME_LEN)
	static char broadcast_addr[ETH_ALEN] =
			{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

	{
		char *if_name;
		int listen;
		char *msg;
		int sock;
		int if_index;
		uint8_t if_addr[ETH_ALEN];
		uint8_t dest_addr[ETH_ALEN];
		size_t send_len;
		char buf[BUF_SIZE];
		int i;

		//if_name = "eth0";
		if_name = "eno1";
		memcpy(dest_addr, broadcast_addr, ETH_ALEN);
		listen = 0;
		msg = "Hello";
		/* Get the index number and MAC address of ethernet interface. */
		{
			struct ifreq ifr;

			memset(&ifr, 0, sizeof(ifr));
			strncpy(ifr.ifr_name, if_name, IFNAMSIZ - 1);

			if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0)
				perror("SIOCGIFINDEX");
			if_index = ifr.ifr_ifindex;

			if (ioctl(sock, SIOCGIFHWADDR, &ifr) < 0)
				perror("SIOCGIFHWADDR");
			memcpy(if_addr, ifr.ifr_hwaddr.sa_data, ETH_ALEN);
		}
	}
#endif

	*psd = sockfd;
	return err;
}

void xxx()
{
	// create a raw socket with UDP protocol
	//sd = socket(PF_INET, SOCK_RAW, IPPROTO_UDP);
	//sd = socket(PF_INET, SOCK_RAW, IPPROTO_RAW);
	//sd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);

#if 0
   sd = socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL)); // ETH_P_ALL????
//   sd = socket(AF_PACKET,SOCK_RAW,0); // ETH_P_ALL????
 //sd = socket(AF_INET, SOCK_RAW, 0); // 0 not supported
   if (sd < 0) {
     perror("socket() error");
     exit(2);
   }
   printf("OK: a raw socket is created.\n");

   /*
   int one = 1;
   const int *val = &one;
   // inform the kernel do not fill up the packet structure, we will build our own
   if(setsockopt(sd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0)
   //if(setsockopt(sd, IPPROTO_RAW, IP_HDRINCL, val, sizeof(one)) < 0) //NG
   {
     perror("setsockopt() error");
     exit(2);
   }
   printf("OK: socket option IP_HDRINCL is set.\n");
   */
#endif

}


error_t RAW_close(int sd)
{
    
    close(sd);
    
    return NO_ERROR;
    
}

int RAW_send(int sd, void* data, size_t length)
{
    int ret;
    
//=============================================================
	//https://help.intervalzero.com/product_help/RTX/Content/PROJECTS/Application%20Development/Understanding_Network/Using_RAW_Sockets.htm

	//  extern ssize_t send (int __fd, const void *__buf, size_t __n, int __flags);
	//ret = pcap_sendpacket(context->handle, temp, length);

	// send: No such device or address
	//ret = sendto(context->sd, temp, length, 0, NULL, 0); // (struct sockaddr *) &sock_addr, sizeof (sock_addr)) < 0)

	// send: No such device or address
	ret = write(sd, data, length);

	// send: No such device or address
	//ret = send(context->sd, temp, length, 0);
//=============================================================
#define ETH_MAC_ADDR_LEN 6
    
     struct sockaddr_ll dest_addr;
       memset(&dest_addr,0,sizeof(struct sockaddr_ll));
       dest_addr.sll_family = PF_PACKET;
       dest_addr.sll_protocol = htons(8902);
       dest_addr.sll_ifindex = 2;//0;//TODO info->if_index;
       dest_addr.sll_halen = ETH_MAC_ADDR_LEN;
       dest_addr.sll_pkttype = PACKET_OTHERHOST;
       dest_addr.sll_hatype   = ARPHRD_ETHER;
       memset(dest_addr.sll_addr,0,8);

       dest_addr.sll_addr[0] = 0x00;
       dest_addr.sll_addr[1] = 0xAB;
       dest_addr.sll_addr[2] = 0xCD;
       dest_addr.sll_addr[3] = 0xEF;
       dest_addr.sll_addr[4] = 0x00;
       dest_addr.sll_addr[5] = 0x86;

       ret = sendto(sd, data, length, 0, (struct sockaddr*) &dest_addr, sizeof(struct sockaddr_ll));
    
    return ret;
}

/*
#include <sys/types.h>
#include <sys/socket.h>

ssize_t recv(int sockfd, void *buf, size_t len, int flags);

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                 struct sockaddr *src_addr, socklen_t *addrlen);

ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);
*/

int RAW_recv(int sd, void *buf, size_t len);
int RAW_recv(int sd, void *buf, size_t len)
{
    return -1; //TODO
}

