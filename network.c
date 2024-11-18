#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

struct addrinfo {
        int ai_flags;
        int ai_family;
        int ai_socktype;
        int ai_protocol;
        size_t ai_ddrlen;
        struct sockaddr *ai_addr;
        char *ai_canonname;
        struct addrinfo *ai_next;
    };

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct sockaddr_in {
	short in sin_family;
	unsigned short int sin_port;
	struct in_addr sin_addr;
	unsigned char sin_zero[8];
};

struct in_addr {
	uint32_t s_addr;
};

struct sockaddr_in16 {
	u_int16_t sin6_family;
	u_int16_t sin6_port;
	u_int32_t sin6_flowinfo;
	struct in6_addr sin6_addr;
	u_int32_t sin6_scope_id;
};

struct in6_addr {
	unsigned char s6_addr[16];
};

struct sockaddr_storage {
	sa_family_tss_family;
	char __ss_pad1[SS_PAD1SIZE];
	int64_t __ss_align;
	char __ss_pad2[SSPAD2SIZE];
}

int main()
{
    
}
