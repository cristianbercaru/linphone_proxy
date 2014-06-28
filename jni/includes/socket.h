/*
 * socket.h
 *
 *  Created on: Mar 12, 2013
 *      Author: codrin
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include "utils.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct inet_tcp_sk_desc {
	unsigned int		family;
	unsigned int		type;
	unsigned int		src_port;
	unsigned int		dst_port;
	unsigned int		state;
	unsigned int		rqlen;
	unsigned int		wqlen; /* sent + unsent data */
	unsigned int		uwqlen; /* unsent data */
	unsigned int		src_addr[4];
	unsigned int		dst_addr[4];
	unsigned short		shutdown;

	int rfd;
	int cpt_reuseaddr;
	struct list_head rlist;
};

struct tcp_server_repair
{
	uint32_t inq_len; /* receive queue length */
	uint32_t inq_seq; /* receive queue sequence number */
	uint32_t outq_len; /* send queue length */
	uint32_t outq_seq; /* send quueu sequence number */
	uint32_t opt_mask; /* mask used for TCP options */
	uint32_t snd_wscale; /* send window size scale */
	uint32_t mss_clamp; /* MSS clamp value */
	int has_rcv_wscale; /* if true, the next value is considered */
	uint32_t rcv_wscale; /* scale factor for receive window */
	int has_timestamp; /* if the, the next value is considered */
	uint32_t timestamp; /* timestamp */
	int has_cork; /* if true, the next value is considered */
	int cork; /* cork value for the TCP connection */
	int has_nodelay; /* if true, the next value is considered */
	int nodelay; /* no delay flag is used */
	int has_unsq_len; /* if true, the next value is considered */
	uint32_t unsq_len; /* unsent data in the send queue */
};


int
create_socket(int domain, int type);

void
destroy_socket(int sockfd);

int
bind_socket(int sockfd, int domain, int portno);

int
listen_socket(int sockfd);

int
socket_type_get(int sockfd);

int
tcp_repair_socket_get(int sockfd, struct tcp_server_repair *repair);

int
tcp_repair_socket_set(int sockfd, const struct tcp_server_repair *repair);

#endif /* SOCKET_H_ */
