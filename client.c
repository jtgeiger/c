#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>


void go( char* addr, char* port )
{
	int ret;
	struct addrinfo hints;
	struct addrinfo *servinfo;  // will point to the results
	
	memset(&hints, 0, sizeof hints); // make sure the struct is empty
	hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
	//hints.ai_flags = AI_PASSIVE;     // fill in my IP for me


	ret = getaddrinfo( addr, port, &hints, &servinfo );
	
	printf( "ret=%d\n", ret );
	
	if ( ret == 0 )
	{
		char str[50];
		struct sockaddr_in *mycast = (struct sockaddr_in *)servinfo->ai_addr;	//Only works for IPv4.
		inet_ntop( servinfo->ai_family, & mycast->sin_addr, str, sizeof str );
		printf( "Got addrinfo!\n" );
		printf( "Addr=%s.\n", str );
		
		int s = socket( servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol );
		
		printf( "Got sockfd=%i.\n", s );
		
		if ( s > 0 )
		{
			printf( "I got a sock fd!\n" );
			
			ret = connect( s, servinfo->ai_addr, servinfo->ai_addrlen );
			
			printf( "Connect ret=%i.\n", ret );
			
			if ( ret == 0 )
			{
				//printf( "Going into sleep loop.\n" );
				//while ( 1 ){};
				char* msg = "GET / HTTP/1.0\r\n\r\n";
				
				printf( "Sending %i bytes:\n%s\n", strlen( msg ), msg );
				
					//TODO: Set up a loop in case the whole msg doesn't go out in a single send.
				int num_sent = send( s, msg, strlen( msg ), 0 );
				
				if ( num_sent == strlen( msg ) )
				{
					printf( "Sent ok!\n" );
					
					int recv_ret = 1;
					int total_read = 0;
					
					while ( recv_ret > 0 )
					{
						char buf[10 * 1024];
						memset( buf, 0, sizeof buf );
						//printf( "Buf size=%i.\n", sizeof buf );
						recv_ret = recv( s, buf, sizeof buf, 0 );
						
						if ( recv_ret > 0 )
							total_read += recv_ret;
						
						printf( "Recv ret=%i.\n%s\n", recv_ret , buf );
					}
					
					printf( "Conection closed; received %i byte(s).\n", total_read );
				}
				else
				{
					printf( "Didn't send ok.  Not at all.\n" );
				}
			}
		}
		else
		{
			printf( "It didn't work.\n" );
		}
		
		freeaddrinfo( servinfo ); // free the linked-list
	}
	else
	{
		fprintf( stderr, "Sorry Charlie; it didn't work.\n" );
	}
}

void traceit( char* msg )
{
	printf( "%s\n", msg );
}

int main( int argc, char* argv[] )
{
	char str[50];
    sprintf( str, "Started with: %d arg(s).", argc );
	traceit( str );
    int i;
    for ( i = 0; i < argc; i++ )
    {
        printf( "Arg %d: %s\n", i + 1, argv[i] );
    }
    
    if ( argc >= 3 )
    {
	go( argv[1], argv[2] );
    }
    else
    {
	    printf( "Feed me, Seymour!\n" );
	   return 2;
    }
    
    return 0;
}
