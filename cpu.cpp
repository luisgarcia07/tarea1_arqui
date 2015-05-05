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

void cpu::cargarInstruccion(int op, int rf1, int rf2d, int rd){
    ir[0] = op;
    ir[1] = rf1;
    ir[2] = rf2d;
    ir[3] = rd;
}

void cpu::ejecutarInstruccion(){
    switch( ir[0] ){
        case 4:
            //cpu::BEQZ();
            break;
        case 5:
            //cpu::BNEZ();
            break;
        case 8:
            cpu::DADDI(ir[2], ir[1], ir[3]);
            break;
        case 32:
            cpu::DADD(ir[3], ir[1], ir[2]);
            break;
        case 34:
            cpu::DSUB(ir[3], ir[1], ir[2]);
            break;
        case 35:
            //cpu::LW();
            break;
        case 43:
            //cpu::SW();
            break;
        case 63:
            //cpu::FIN();
            break;
        default:
            cout << "\nCodigo de operacion invalido.\n";
            break;
    }
    //pc++;
}
