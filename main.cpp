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
#include <thread>
#include <mutex>

#include "cpu.h"

using namespace std;

/* Using mutex to synchronize threads */
//mutex m_mutex;


void task1(std::string msg)
{
    std::cout << "task1 says: " << msg;
}

/*
 * Función que devuleve un arreglo con los nombres de los archivos en el directorio path
 */
void getDirectorio(string path, vector<string> &directorio){
    DIR *d = opendir(path.c_str());
    struct dirent *dir;
    
    if (d){
        while ((dir = readdir(d)) != NULL){
            directorio.push_back(path + dir->d_name);
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
void preguntarDatos(vector<string> &nombres_de_archivo){
    
    // Preguntar la cantidad de hilos a ejecutar
    int cantidad_de_hilos = 3;
    //cout << "Cuantos hilos desea ejecutar ? ->  ";
    //cin >> cantidad_de_hilos;
    
    // Preguntar el directorio donde se encuentran los hilos
    string path = "/Users/nehemias/Desktop/CI-1323/Proyecto/tarea1_arqui/hilos/";
    //cout << "Donde se encuentran los hilos ?, digite ./ para el directorio actual ->  ";
    //cin >> path;
    
    //~/Desktop/CI-1323/Proyecto/tarea1_arqui/hilos
    
    // Obtener todos los archivos del directorio path
    vector<string> directorio;
    getDirectorio(path, directorio);
    imprimir(directorio);
    
    // Preguntar por los hijos a ejecutar
    //for (int i = 1; i <= cantidad_de_hilos; i++) {
    for (int i = 3; i <= 5; i++) {
        nombres_de_archivo.push_back(directorio[i]); // Almacenar el nombre del hilo a ejecutar
        //cout << "Digite el indice del " << i << "º hilo ->  ";
        //int temporal;
        //cin >> temporal;
        //nombres_de_archivo.push_back(directorio[temporal]); // Almacenar el nombre del hilo a ejecutar
        
    }
}

/*
 * Función que lee nombres_de_hilos y almacena las intrucciones un arreglo
 */
void getInstrucciones(vector<string> &nombres_de_archivo, vector<int> &instrucciones, vector<int> &indices_de_hilos){
    
    for (int i = 0; i < nombres_de_archivo.size(); i++) { //por cada nombre de hilo
        indices_de_hilos.push_back((int)instrucciones.size()); // almacenar el indice donde empieza
        ifstream infile(nombres_de_archivo[i].c_str()); // abrir archivo
        int opcode,rs,rt,rd; // partes de la instruccion
        while (infile >> opcode >> rs >> rt >> rd) { //cargar instruccion
            // almacenar la instruccion en e; arreglo de instrucciones
            instrucciones.push_back(opcode);
            instrucciones.push_back(rs);
            instrucciones.push_back(rt);
            instrucciones.push_back(rd);
        }
    }
}


void cargar_cpu(int id, vector<int>& instrucciones, vector<int>& indices_de_hilos, mutex& m_mutex) {
    
    cpu::cpu c(id, instrucciones, indices_de_hilos, m_mutex);
    
}

int main(){
    
    int cantidad_cpu = 3;
    
    vector<string> nombres_de_archivo_de_hilos; // nombres de archivo donde se encuentran los hilos
    vector<int>    instrucciones; // arreglo con todas las instrucciones de cada hilo
    vector<int>    indices_de_hilos; // indices de donde comienza cada hilo en el arreglo de instrucciones
    vector<thread> hilos;
    vector<cpu>    cpus;
    mutex m_mutex;
   
    preguntarDatos(nombres_de_archivo_de_hilos); // Obtener datos del usuario
    getInstrucciones(nombres_de_archivo_de_hilos, instrucciones, indices_de_hilos); //cargar los hilos en el arreglo de instrucciones
    
    
    for (int i = 0; i < cantidad_cpu; i++) {
        hilos.push_back(thread(cargar_cpu, i, ref(instrucciones), ref(indices_de_hilos), ref(m_mutex)));
    }

    cout << indices_de_hilos.size() << " hilos seleccionados" << endl;
    for (int i = 0; i < indices_de_hilos.size(); i++) {
        cout << "Hilo " << i << " -> inicia en indice " << indices_de_hilos[i] << endl;;
    }
    
    cout << "joining..." << endl;
    for(auto &t : hilos){
        t.join();
    }
    
    cout << "Fin hilo cero" << endl;
    
//    for (int hilo = 0; hilo < indices_de_hilos.size(); hilo++) {
//        cout << "Ejecutando hilo " << hilo << ", " << nombres_de_archivo_de_hilos[hilo] << endl;
//        int primero = indices_de_hilos[hilo];
//        int ultimo;
//        if (hilo == indices_de_hilos.size() - 1) ultimo = instrucciones.size() - 1;
//        else ultimo = indices_de_hilos[hilo + 1];
//        
//        for (int h = primero; h <= ultimo; h++) {
//            cout << "[" << instrucciones[h] << "] ";
//            if ((h+1)%4 == 0) cout << endl;
//        }
//    }
    
    return 0;
}
