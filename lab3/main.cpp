#include "Collector.h"

int main(){
    parse_memory();
    Collector program = Collector("input");
    program.get_program();
    return 0;
}

