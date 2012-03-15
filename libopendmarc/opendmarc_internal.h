#ifndef OPENDMARC_INTERNAL_H
#define OPENDMARC_INTERNAL_H
#include "build-config.h"

# if HAVE_CTYPE_H
#	include <ctype.h>
# endif
# if HAVE_ERRNO_H
#	include <errno.h>
# endif
# if HAVE_POLL_H
#	include <poll.h>
# endif
# if HAVE_FCNTL_H
#	include <fcntl.h>
# endif
# ifdef sun
#	include <libgen.h>
# endif
# if HAVE_MEMORY_H
#	include <memory.h>
# endif
# if HAVE_STDIO_H
#	 include <stdio.h>
# endif
# if HAVE_STDLIB_H
#	include <stdlib.h>
# endif
# if HAVE_STRING_H
#	include <string.h>
# endif
# if HAVE_SYS_SOCKET_H
#	include <sys/socket.h>
# endif
# if HAVE_SYS_STAT_H
#	include <sys/stat.h>
# endif
# if HAVE_SYS_TYPES_H
#	include <sys/types.h>
# endif
# if HAVE_SYSEXITS_H
#	include <sysexits.h>
# endif
# if HAVE_SYSLOG_H
#	include <syslog.h>
# endif
# if TM_IN_SYS_TIME
#	include <sys/time.h>
# else
#	include <time.h>
# endif
# if TIME_WITH_SYS_TIME && TM_IN_SYS_TIME
#	include <time.h>
# endif
# if HAVE_UNISTD_H
#	include <unistd.h>
# endif
# if HAVE_NETDB_H
#	include <netdb.h>
# endif
# if HAVE_NETINET_IN_H
#	include <netinet/in.h>
# endif
# if HAVE_SYS_PARAM_H
#	include <sys/param.h>
# endif
# if HAVE_ARPA_INET_H
#	include <arpa/inet.h>
# endif
# if HAVE_ARPA_NAMESER_H
#	include <arpa/nameser.h>
# endif
# if HAVE_ARPA_NAMESER_COMPAT_H
#	include <arpa/nameser_compat.h>
# endif
# if HAVE_RESOLV_H
#	include <resolv.h>
# endif
# if HAVE_SIGNAL_H
#	include <signal.h>
# endif

# ifndef UNDEFINED
#       define UNDEFINED	(-1) 
# endif
# ifndef TRUE
#       define TRUE		(1) 
# endif
# ifndef FALSE 
#       define FALSE		(0)
# endif 
# ifndef MAYBE 
#       define MAYBE		(2)
# endif 
# define bool int

/*****************************************************************************
** DMARC_POLICY_T -- The opaque context for the library.
** 	Memory needs to be allocated and freed.
*****************************************************************************/
typedef struct dmarc_policy_t {
	char *	domain;		/* Input: domain sought */

	/*
	 * Computed Organizational domain if subdomain lacked a record.
	 */
	char *	organizational_domain;

	/*
	 * Found in the _dmarc record.
	 */
	int	h_error;	/* Zero if found */
	int	adkim;
	int	aspf;
	int	p;
	int	sp;
	int	pct;
	int	rf;
	uint32_t ri;
	int	rua_cnt;
	char **	rua_list;
	int	ruf_cnt;
	char **	ruf_list;
} DMARC_POLICY_T;

#define DMARC_RECORD_A_UNSPECIFIED	('\0')		/* adkim and aspf */
#define DMARC_RECORD_A_STRICT		('s')		/* adkim and aspf */
#define DMARC_RECORD_A_RELAXED		('r')		/* adkim and aspf */
#define DMARC_RECORD_P_UNSPECIFIED	('\0')		/* p and sp */
#define DMARC_RECORD_P_NONE		('n')		/* p and sp */
#define DMARC_RECORD_P_QUARANTINE	('q')		/* p and sp */
#define DMARC_RECORD_P_REJECT		('r')		/* p and sp */
#define DMARC_RECORD_R_UNSPECIFIED	(0x0)		/* rf, a bitmap */
#define DMARC_RECORD_R_AFRF		(0x1)		/* rf, a bitmap */
#define DMARC_RECORD_R_IODEF		(0x2)		/* rf, a bitmap */

/* dmarc_dns.c */
char * dmarc_dns_get_record(char *domain, int *reply, char *got_txtbuf, size_t got_txtlen);


#endif /* OPENDMARC_INTERNAL_H */