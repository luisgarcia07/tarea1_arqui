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

void cpu::DADDI(int RX, int RY, int n){
    regs[RX] = regs[RY] + n;
}

void cpu::DADD(int RX, int RY, int RZ){
    regs[RX] = regs[RY] + regs[RZ];
}

void cpu::DSUB(int RX, int RY, int RZ){
    regs[RX] = regs[RY] - regs[RZ];
}
