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
    
    cpu();
    
    cpu(int&, int&);
    
    ~cpu();
    
    int get_pc() const;
    
    
private:
    
    
    
};

#endif /* defined(__proyecto_de_arqui__cpu__) */
