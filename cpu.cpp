//
//  cpu.cpp
//  proyecto de arqui
//
//

#include "cpu.h"

cpu::cpu(int id){
    pc = 0;
    mem = new int[1024];
    threads = new int[4096];
    this->id = id;
}

cpu::cpu(int& mem, int& threads){
    this->mem = &mem;
    this->threads = &threads;
}

cpu::cpu(int id, vector<int>& instrucciones, vector<int>& indices_de_hilos, mutex& m_mutex){
    
    // calcular cuales instrucciones a ejecutar
    int primero = indices_de_hilos[id];
    int ultimo;
    if (id == indices_de_hilos.size() - 1) ultimo = (int)instrucciones.size() - 1;
    else ultimo = indices_de_hilos[id + 1];
    
    // datos del cpu
    pc = 0;
    this->id = id;
    
    string mensaje = "tiene " + to_string( (ultimo-primero)/4 ) + " instrucciones";
    ping(m_mutex, mensaje);
    
    for (int i = primero; i <= ultimo / 4; i++) {
        cargarInstruccion(instrucciones[i*4], instrucciones[i*4+1], instrucciones[i*4+2], instrucciones[i*4+3]);
        ejecutarInstruccion(m_mutex);
    }
    
}

cpu::~cpu(){
    
}

void cpu::ping(mutex& m_mutex, string message) const {
    m_mutex.lock();
    cout << "cpu = " << id << " | pc = " << pc << " || " << message << endl;
    m_mutex.unlock();
}

int cpu::get_pc() const {
    return pc;
}

void cpu::DADDI(int RX, int RY, int n){
    regs[RX] = regs[RY] + n;
    pc += 2;
}

void cpu::DADD(int RX, int RY, int RZ){
    regs[RX] = regs[RY] + regs[RZ];
    pc +=2;
}

void cpu::DSUB(int RX, int RY, int RZ){
    regs[RX] = regs[RY] - regs[RZ];
    pc +=2;
}

void cpu::cargarInstruccion(int op, int rf1, int rf2d, int rd){
    ir[0] = op;
    ir[1] = rf1;
    ir[2] = rf2d;
    ir[3] = rd;
}

void cpu::ejecutarInstruccion(mutex& m_mutex){
    string instruccion = " ejecutando " + to_string(ir[0]) + " " + to_string(ir[1]) + " " + to_string(ir[2]) + " " + to_string(ir[3]);
    ping(m_mutex, instruccion);
    //cout <<"cpu " << id << " ejecutando " << ir[0] << " " << ir[1] << " " << ir[2] << " " << ir[3] << endl;
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
