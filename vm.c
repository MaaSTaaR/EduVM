/**
 * Simple and Educational VM
 *
 * Author : Mohammed Q. Hussain <MaaSTaaR@gmail.com>
 * Date : 2-6-2012
 * License : GNU GPL
 */

#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

void loadBinToMemory( char *filename, cpu *curr_cpu )
{
    FILE *fp;
    int code_size,k = 0;
    char *ret_text,*text;
    
    fp = fopen( filename, "rb" );
    
    // ... //
    
    // Get the size of code for malloc
    
    fseek( fp, 0, SEEK_END );
    
    code_size = ftell( fp );
    
    fseek( fp, 0, SEEK_SET );
    
    // ... //
    
    curr_cpu->memory = (uint16_t *) malloc( ( code_size * sizeof( uint16_t ) ) );
        
    // ... //
    
    while ( code_size > 0 )
    {
        fread( &curr_cpu->memory[ k ], sizeof( curr_cpu->memory[ k ] ), 1, fp );
        
        k++;
        code_size -= 2;
    }
    
    curr_cpu->memory_words = k;
    
    fclose( fp );
}

int main( int argv, char *args[] )
{
    if ( argv == 1 )
    {
        printf( "Error : Please write the binary filename as an argument\n" );
        return EXIT_FAILURE;
    }
    
    // ... //
    
    cpu *curr_cpu;
    
    curr_cpu = malloc( sizeof( cpu ) );
    
    init_cpu( curr_cpu );
    
    // ... //
    
    loadBinToMemory( args[ 1 ], curr_cpu );
    
    // ... //
    
    cpu_run( curr_cpu );
            
    return 0;
}
