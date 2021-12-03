/*
 * Fast Cars
 * 
 * Hilda Beltrán Acosta
 * A01251916
 *
 * sort.h
*/

#ifndef SORT_H
#define SORT_H

//Se incluyen las librerías necesarias
#include <iostream> 
#include <vector>
#include <list>
#include <string>
#include "datos.h"

using namespace std;

/*
 * Dentro de esta clase Sorts se definen los atributos privados del objeto, 
 * así como funciones necesarias para los métodos públicos. Los métodos incluyen 
 * ordenaCarro que ordena el vector en orden alfabético con el atributo modelo con
 * ayuda de la función swap, busqCarro regresa la cantidad de ventas por modelo; 
 * mientras que muestraDatos imprime el vector en la consola, y leeArchivo se 
 * encarga de cargar los datos del archivo al vector.
*/
template <class T>
class Sorts{
    private:
        void swap(vector<T> &carros, int i, int ref);
    public:
        void ordenaCarro(vector<T> &carros);
        int busqCarro(vector<T>&carros, string modelo);
        void leeArchivo(vector<T>&carros);
        void muestraDatos(vector<T>&carros);
};

/*
 * La función muestraDatos imprime el vector de objetos con ambos
 * atributos en la consola.
 * 
 * @param vector<Carro>&
 * @return 
*/ 
template <class T>
void Sorts<T>::muestraDatos(vector<T>&carros) {
    for(int i = 0; i < carros.size(); i++){
        cout << carros[i].get_modelo() << 
        ", " << carros[i].get_cant() << endl;
    }
}

/*
 * La función leeArchivo lee línea por línea el archivo datos.csv, se crea
 * el objeto y lo coloca en la última posición del vector.
 * 
 * @param vector<Carro>&
 * @return 
*/ 
template <class T>
void Sorts<T>::leeArchivo(vector<T>&carros) {
    string strMod, modelo, cant;
    stringstream ss;

    ifstream filecarros("datos.csv");
    if(!filecarros) {
        cerr << "No se encontró el archivo datos.csv" << endl;
        exit(1);
    }
    Carro datosCarro;
    getline(filecarros, strMod);
    while(getline(filecarros, strMod)) {
        ss.clear();
        ss << strMod;
        getline(ss, modelo, ',');
        getline(ss, cant, ',');
        datosCarro.get_Datos(modelo, cant);
        carros.push_back(datosCarro);
    }
    filecarros.close();
}

/*
 * La función swap se encarga de voltear los valores no ordenados
 * con ayuda de una variable auxiliar.
 * 
 * @param vector<Carro>&, int, int
 * @return 
*/ 
template <class T>
void Sorts<T>::swap(vector<T> &carros, int i, int ref) {
    T aux = carros[i];
    carros[i] = carros[ref];
    carros[ref] = aux;
}

/*
 * La función ordenaCarro compara el atributo modelo para ordenar de manera
 * correcta los objetos en orden alfabético.
 * 
 * @param vector<Carro>&
 * @return 
*/ 
template <class T>
void Sorts<T>::ordenaCarro(vector<T> &carros) {
    for (int i = carros.size() - 1; i > 0; i --){
        for (int j = 0; j < i; j ++){
            if ((carros[j].get_modelo()).compare(carros[j+1].get_modelo()) > 0){
                swap(carros, j, j + 1);
            }
        }
    }
}

/*
 * La función busqCarro recorre el vector hasta encontrar una
 * coincidencia con el atributo modelo; regresa la cantidad de ventas
 * de ese modelo.
 * 
 * @param vector<Carro>&, string
 * @return int
*/ 
template <class T>
int Sorts<T>::busqCarro(vector<T>&carros, string modelo) {
    for(int i = 1; i < carros.size(); i ++){
        if (modelo == carros[i].get_modelo()){
            return stoi(carros[i].get_cant());
        }
    }
    return -1;
}

#endif 