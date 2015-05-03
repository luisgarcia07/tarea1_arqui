//
//  cpu.cpp
//  proyecto de arqui
//
//

#include "cpu.h"

cpu::cpu(){
    pc = 0;
    mem = new int[1024];
    threads = new int[4096];
}

cpu::cpu(int& mem, int& threads){
    this->mem = &mem;
    this->threads = &threads;
}

cpu::~cpu(){
    
}

int cpu::get_pc() const {
    return pc;
}
