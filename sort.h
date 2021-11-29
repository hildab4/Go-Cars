#ifndef SORT_H
#define SORT_H

#include <iostream> 
#include <vector>
#include <list>
#include <string>
#include "datos.h"

using namespace std;

template <class T>
class Sorts{
    private:
        void swap(vector<T> &carros, int i, int ref);
    public:
        void ordenaCarro(vector<T> &carros);
        int busqCarro(vector<T>&carros, string modelo);
        void leeArchivo(vector<T>&carros);
        void muestraDatos(vector<T>&carros);
        void mayormenor(vector<T>&carros);
};

template <class T>
void Sorts<T>::mayormenor(vector<T>&carros) {
    ordenaCarro(carros);
    int mayor = carros.size() - 1;
    cout << "Mayor ventas: " << carros[mayor].get_modelo() << " con "
    << carros[mayor].get_cant() << endl;
    cout << "Menor ventas: " << carros[0].get_modelo() << " con "
    << carros[0].get_cant() << endl;
}

template <class T>
void Sorts<T>::muestraDatos(vector<T>&carros) {
    for(int i = 0; i < carros.size(); i++){
        cout << carros[i].get_modelo() << ", " << carros[i].get_cant() << endl;
    }
}

template <class T>
void Sorts<T>::leeArchivo(vector<T>&carros){
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

template <class T>
void Sorts<T>::swap(vector<T> &carros, int i, int ref){
    T aux = carros[i];
    carros[i] = carros[ref];
    carros[ref] = aux;
}

template <class T>
void Sorts<T>::ordenaCarro(vector<T> &carros){
    for (int i = carros.size() - 1; i > 0; i --){
        for (int j = 0; j < i; j ++){
            if (stoi(carros[j].get_cant()) > stoi(carros[j + 1].get_cant())){
                swap(carros, j, j + 1);
            }
        }
    }
}

template <class T>
int Sorts<T>::busqCarro(vector<T>&carros, string modelo){
    for(int i = 1; i < carros.size(); i ++){
        if (modelo == carros[i].get_modelo()){
            return stoi(carros[i].get_cant());
        }
    }
    return -1;
}

#endif 