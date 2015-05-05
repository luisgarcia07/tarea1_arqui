//
//  cpu.h
//  proyecto de arqui
//
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#ifndef __proyecto_de_arqui__cpu__
#define __proyecto_de_arqui__cpu__

class cpu {
public:
    int pc;
    int * mem;
    int * threads;
    int regs[32];
    int ir[4]; //registro de instrucción
    
    cpu();
    
    cpu(int&, int&);
    
    ~cpu();
    
    int get_pc() const;
    
    void DADDI(int, int, int);

    void DADD(int, int, int);

    void DSUB(int, int, int);
    
    void cargarInstruccion(int, int, int, int); // carga una instrucción al IR

    void ejecutarInstruccion(); // ejecuta la instrucción que se encuantra en el IR actualmente
    
    
private:
    
    
    
};

#endif /* defined(__proyecto_de_arqui__cpu__) */
