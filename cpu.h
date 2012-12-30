#include <inttypes.h>

typedef enum 
{
    mov = 0,
    addr,
    addv,
    print,
    cpuid,
    halt
} isa;

typedef struct
{
    uint16_t reg[ 3 ];
    uint16_t *memory;
    int memory_words,ip;
} cpu;

void init_cpu( cpu * );
uint16_t fetch( cpu * );
void execute( isa, cpu * );
void cpu_run( cpu * );
