#include <stdio.h>

int regs[32]; // registros

void DADDI(int RX, int RY, int n){
    regs[RX] = regs[RY] + n;
}

void DADD(int RX, int RY, int RZ){
    regs[RX] = regs[RY] + regs[RZ];
}

void DSUB(int RX, int RY, int RZ){
    regs[RX] = regs[RY] - regs[RZ]; //números negativos?
}

/*
 * Función principal del programa
 */
int main(int argc, char** argv) {
	int *mem = malloc(n * sizeof(int)); // memoria principal
	
	regs[5] = 5;
    	DADDI(5, 5, 10);
	printf("\nregs[5] = %d", regs[5]);
	
	printf("Hola\n");
}
