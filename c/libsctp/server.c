#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>



#define MAX_BUFFER 			1024
#define	DEFAULT_PORT 		45000


struct sctp_initmsg *sctp_init(out, in, att)
{
	struct sctp_initmsg m = {
		.sinit_num_ostreams = 5,
	  .sinit_max_instreams = 5,
	  .sinit_max_attempts = 4,
	};

	return &m;
}



int main(int argc, char const *argv[])
{

	return 0;
}
