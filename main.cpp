//
//  main.cpp
//  proyecto de arqui
//
//
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <fstream>

using namespace std;

/*
 * Función que devuleve un arreglo con los nombres de los archivos en el directorio path
 */
void getDirectorio(string path, vector<string> &archivos){
    DIR *d = opendir(path.c_str());
    struct dirent *dir;
    
    if (d){
        while ((dir = readdir(d)) != NULL){
            archivos.push_back(path + dir->d_name);
        }
        closedir(d);
    }
}

/*
 * Función que imprime en consola un arreglo de string
 */
void imprimir(vector<string> &v){
    for (int i = 0; i < v.size(); i++) {
        cout << "[" << i << "] " << v[i] << endl;
    }
}


/*
 * Función que pregunta al usuario los hilos a ejecutar
 */
void preguntarDatos(vector<string> &hilos){
    
    // Preguntar la cantidad de hilos a ejecutar
    int cantidad_de_hilos;
    cout << "Cuantos hilos desea ejecutar ? ->  ";
    cin >> cantidad_de_hilos;
    
    // Preguntar el directorio donde se encuentran los hilos
    string path;
    cout << "Donde se encuentran los hilos ? ->  ";
    cin >> path;
    
    vector<string> archivos;
    getDirectorio(path, archivos);
    
    imprimir(archivos);
    
    vector<int> indices_de_archivo;
    
    for (int i = 1; i <= cantidad_de_hilos; i++) {
        cout << "Digite el indice del " << i << "º hilo ->  ";
        int temporal;
        cin >> temporal;
        indices_de_archivo.push_back(temporal);
    }
    
    for (int i = 0; i < indices_de_archivo.size(); i++) {
        hilos.push_back(archivos[indices_de_archivo[i]]);
    }
    
}

/*
 * Función que lee los hilos y los almacena en un vector
 */
void getInstrucciones(vector<string> &nombres_de_archivo, vector<int> &instrucciones){
    
    for (int i = 0; i < nombres_de_archivo.size(); i++) {
        ifstream infile(nombres_de_archivo[i].c_str());
        int opcode,rs,rt,rd;
        while (infile >> opcode >> rs >> rt >> rd) {
            instrucciones.push_back(opcode);
            instrucciones.push_back(rs);
            instrucciones.push_back(rt);
            instrucciones.push_back(rd);
        }
    }
}


int main(){
    
    vector<string> hilos;
    vector<int>    instrucciones;
    
    preguntarDatos(hilos);
    getInstrucciones(hilos, instrucciones);
    
    for (int i = 0; i < instrucciones.size(); i++) {
        cout << "[" << instrucciones[i] << "] ";
        if ((i+1)%4 == 0) cout << endl;
        
    }
    
    
    
    return 0;
}