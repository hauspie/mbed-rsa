/* This file is part of rflpc. Copyright 2010-2011 Michael Hauspie                        
 *									 
 * rflpc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by	 
 * the Free Software Foundation, either version 3 of the License, or	 
 * (at your option) any later version.					 
 * 									 
 * rflpc is distributed in the hope that it will be useful,		 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of	 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the	 
 * GNU General Public License for more details.				 
 * 									 
 * You should have received a copy of the GNU General Public License	 
 * along with rflpc.  If not, see <http://www.gnu.org/licenses/>.	 
 */
/*
  
    Author: Michael Hauspie <michael.hauspie@univ-lille1.fr>
    Created: 
    Time-stamp: <2013-02-25 10:32:40 (hauspie)>

    Basic protocol handling.  Not meant to be trully used, but just useful
    tools for basic protocol handling for the ethernet sample.

    Works ONLY with Ethernet and IPv4
 */
#ifndef __PROTOCOLS_H__
#define __PROTOCOLS_H__
#include <stdint.h>


#define PROTO_MAC_HLEN  14
#define PROTO_ARP_HLEN  28
#define PROTO_ICMP_HLEN  8
#define PROTO_ICMP_CSUM_OFFSET 2

#define PROTO_ARP 0x0806
#define PROTO_IP  0x0800

#define PROTO_IP_HLEN 20


#define PROTO_ICMP 1
#define PROTO_ICMP_ECHO_REQUEST 8
#define PROTO_ICMP_ECHO_REPLY   0

#define PROTO_UDP_HLEN 8
#define PROTO_UDP 0x11 /* 17 */

typedef struct
{
    uint8_t addr[6];
} EthAddr;



typedef struct
{
    EthAddr src;
    EthAddr dst;
    uint16_t type;
} EthHead;


#define MAC_ADDR_EQUAL(a,b) (((a)[0] == (b)[0]) && ((a)[1] == (b)[1]) && ((a)[2] == (b)[2]) && ((a)[3] == (b)[3]) && ((a)[4] == (b)[4]) && ((a)[5] == (b)[5]))

static inline uint32_t ntohl(uint32_t val)
{
    uint8_t *c = (uint8_t*)&val;

    return (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | (c[3]);
}

typedef struct
{
    uint16_t hard_type;
    uint16_t protocol_type;
    uint8_t hlen;
    uint8_t plen;
    uint16_t opcode;
    EthAddr sender_mac;
    uint32_t sender_ip;
    EthAddr target_mac;
    uint32_t target_ip;
} ArpHead;

typedef struct
{
    uint8_t version_length;
    uint8_t dscp_ecn;
    uint16_t total_length;
    uint16_t identification;
    uint16_t flags_frag_offset;
    uint8_t  ttl;
    uint8_t  protocol;
    uint16_t header_checksum;
    uint32_t src_addr;
    uint32_t dst_addr;
} IpHead;

typedef struct
{
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    union
    {
	struct
	{
	    uint16_t identifier;
	    uint16_t sn;
	} echo;
	uint32_t raw;
    } data;
}IcmpHead;

typedef struct
{
		uint16_t src_port, dst_port;
		uint16_t len, checksum;
}UdpHead;

void proto_eth_demangle(EthHead *eh, const uint8_t *data);
void proto_eth_mangle(EthHead *eh, uint8_t *data);

void proto_arp_demangle(ArpHead *ah, const uint8_t *data);
void proto_arp_mangle(ArpHead *ah, uint8_t *data);

void proto_ip_demangle(IpHead *ih, const uint8_t *data);
void proto_ip_mangle(IpHead *ih, uint8_t *data);

void proto_icmp_demangle(IcmpHead *ih, const uint8_t *data);
void proto_icmp_mangle(IcmpHead *ih, uint8_t *data);

/* Todo:  maybe constify packet header */
void proto_udp_demangle(UdpHead *uh, const uint8_t *data);
void proto_udp_mangle(UdpHead *uh, uint8_t *data);

/* 16 bits checksum */
uint16_t proto_checksum(uint8_t *buffer, unsigned int bytes_count);

#endif
