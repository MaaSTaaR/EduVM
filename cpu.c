/**
 * Simple and Educational VM
 *
 * Author : Mohammed Q. Hussain <MaaSTaaR@gmail.com>
 * Date : 2-6-2012
 * License : GNU GPL
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "cpu.h"

void init_cpu( cpu *curr_cpu )
{
    curr_cpu->reg[ 0 ] = curr_cpu->reg[ 1 ] = curr_cpu->reg[ 2 ] = 0;
    
    curr_cpu->memory = NULL;
    
    curr_cpu->memory_words = curr_cpu->ip = 0;
}

uint16_t fetch( cpu *curr_cpu )
{
    if ( curr_cpu->ip < curr_cpu->memory_words )
    {
        return curr_cpu->memory[ curr_cpu->ip++ ];
    }
    else
    {
        return halt;
    }
}

void execute( isa opcode, cpu *curr_cpu )
{
    if ( opcode == mov )
    {
        uint16_t reg, oprand;
        
        reg = fetch( curr_cpu );
        oprand = fetch( curr_cpu );
        
        //printf( "REG[ %hu ] = %hu\n", reg, oprand );
        
        curr_cpu->reg[ reg ] = oprand;
    }
    else if ( opcode == addr )
    {
        uint16_t reg1, reg2, reg3;
        
        reg1 = fetch( curr_cpu );
        reg2 = fetch( curr_cpu );
        reg3 = fetch( curr_cpu );
        
        //printf( "REG[ %hu ] = REG[ %hu ] + REG[ %hu ]\n", reg3, reg1, reg2 );
        
        curr_cpu->reg[ reg3 ] = curr_cpu->reg[ reg1 ] + curr_cpu->reg[ reg2 ];
    }
    else if ( opcode == addv )
    {
        uint16_t reg, oprand1, oprand2;
        
        oprand1 = fetch( curr_cpu );
        oprand2 = fetch( curr_cpu );
        reg = fetch( curr_cpu );
        
        //printf( "REG[ %hu ] = %hu + %hu\n", reg, oprand1, oprand2 );
        
        curr_cpu->reg[ reg ] = oprand1 + oprand2;
    }
    else if ( opcode == print )
    {
        uint16_t reg;
        
        reg = fetch( curr_cpu );
        
        printf( "%hu\n", curr_cpu->reg[ reg ] );
    }
    else if ( opcode == cpuid )
    {
        printf( "EduCPU 0.1 : The Educational CPU\n" );
        printf( "16-bit architecture\n" );
    }
}

void cpu_run( cpu *curr_cpu )
{
    uint16_t code;
    
    while ( ( code = fetch( curr_cpu ) ) != halt )
    {
        execute( code, curr_cpu );
    }
}
