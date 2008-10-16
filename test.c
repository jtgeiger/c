#include <stdio.h>

int main( int argc, char** argv )
{
    printf( "Hello: %d.\n", argc );
    int i;
    for ( i = 0; i < argc; i++ )
    {
        printf( "Arg %d: %s\n", i + 1, argv[i] );
    }
}
