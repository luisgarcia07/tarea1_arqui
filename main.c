#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

struct directorio {
    char **dir;
    int size;
};

/*
 * Función que devuleve un arreglo con los nombres de los archivos en el directorio path
 */
struct directorio getDirectorio(char* path){
    DIR *d = opendir(path);
    struct dirent *dir;
    
    int size = 0;
    char **lista = malloc(size++ * sizeof(char*));
    
    if (d){
        while ((dir = readdir(d)) != NULL){
            char ** temporal = realloc(lista, size * sizeof(char*)); // hacer la lista más grande
            temporal[size - 1] = dir->d_name; // guardar nombre de archivo
            //printf("[%d]%s \n", size, temporal[size - 1]); // imprimir en pantalla
            size++; // aumento el tamaño
            lista = temporal; // actualizo lista
        }
        
        closedir(d);
    }
    
    struct directorio a;
    a.dir = lista;
    a.size = size;
    
    return a;
}

/*
 * Imprime la lista de archivos en el directorio dir
 */
void imprimir(struct directorio dir){
    int indice;
    for (indice = 2; indice < dir.size - 1; indice++) {
        printf("[%d]%s \n", indice - 1, dir.dir[indice]); // imprimir en pantalla
    }
}


/*
 * Función principal del programa
 */
int main(int argc, char** argv) {
    
    printf("Simulador de MIPS\n");
    
    // Obtener la cantidad de hilos a ejecutar
    printf("Cuantos hilos desea ejecutar ? ->  ");
    int hilos;
    scanf("%d", &hilos);
    
    // Obtener el directorio donde se encuentran los hilos
    printf("Donde se encuentran los hilos ? ->  ");
    char * path = malloc(sizeof(char) * 256);
    scanf("%s", path);
    struct directorio dir = getDirectorio(path);
    
    // Mostrar el contenido del directorio
    imprimir(dir);
    
    // Obtener los hilos a ejecutar
    int * dirs = malloc(sizeof(int) * hilos);
    int indice;
    for (indice = 0; indice < hilos; indice++) {
        printf("Digite el numero del %dº hilo a ejecutar ->  ", indice + 1);
        scanf("%d", &dirs[indice]);
        dirs[indice] += 1;
        printf("%s\n", dir.dir[dirs[indice]]);
    }
    
    printf("Ejecutando %d hilos \n", hilos);
    for (indice = 0; indice < hilos; indice++) {
        printf("hilo %d -> [%d] %s\n", indice+1, dirs[indice] - 1, dir.dir[dirs[indice]]);
    }
    
    // cargar los hilos
    
    
    
    printf("Adios\n");
    return(0);
}