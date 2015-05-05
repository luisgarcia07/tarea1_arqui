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
    
    cpu();
    
    cpu(int&, int&);
    
    ~cpu();
    
    int get_pc() const;
    
    void DADDI(int, int, int);

    void DADD(int, int, int);

    void DSUB(int, int, int);
    
    
private:
    
    
    
};

#endif /* defined(__proyecto_de_arqui__cpu__) */
