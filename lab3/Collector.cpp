#include "Collector.h"

Collector::Collector(const string& name_of_file) {
    int byte;
    std::ifstream file("inputs/" + name_of_file + ".txt");
    if (file.is_open()) {
        while(file >> hex >> byte >> setbase(0)){
            bytes.push_back(byte);
        }
    }
}

Command Collector::define_command(int byte){
    switch(byte){
        case 0x1A: return mov_reg_reg(bytes);
        case 0x1C: return mov_reg_lit(bytes);
        case 0x03: return add_reg_reg_reg(bytes);
        case 0x04: return add_reg_reg_addr(bytes);
        case 0x21: return mul_reg_reg_reg(bytes);
        case 0x23: return mul_reg_reg_addr(bytes);
        case 0x1B: return mov_reg_addr(bytes);
        case 0x90: return jmp_shift(bytes);
        case 0x91: return jmp_addr(bytes);
        default:
            error_indicator = true;
            return Command("Error command with code [" + int_to_hex(byte) + "]");
    }
}

void Collector::collect_commands() {
    while(!bytes.empty() && !error_indicator){
        commands.push_back(define_command(bytes[0]));
    }
}

void Collector::get_program() {
    collect_commands();
    for(Command com : commands){
        com.print_command();
    }
}
