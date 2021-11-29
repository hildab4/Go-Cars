#ifndef LINKEDL_H
#define LINKEDL_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "datos.h"
using namespace std;

template <class T>
class DList {
    public:
        DList();
        void agregaCarro(string data1, string data2);
        string buscaCarro(string data);
        void actualizaCarro(string index, int data);
        void removeFirst();
        void deleteAt(string index);
        void toStringForward() const;
        void toStringBackward() const;
        void leeArchivo();
    private:
        Carro *head;
        Carro *tail;
        int size;
};

template <class T>
void DList<T>::leeArchivo(){
    Carro *nuevo = new Carro();
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

        if (modelo.length() == 0){
            break;
        }
        nuevo -> get_Datos(modelo, cant);
        string m = nuevo -> get_modelo();
        string c = nuevo -> get_cant();

        agregaCarro(m, c);
    }
    filecarros.close();
}

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {};

template <class T>
void DList<T>::toStringBackward() const {
	stringstream aux;
	Carro *p = new Carro();

	p = tail;
	if(tail) {
        int i = 1;
        while(i < (size + 1)){
            cout << i << " " << p->get_modelo() << " " << p->get_cant() << endl;
            p = p-> previous;
            i++;
        }
    }
    else {
        cout << "hola" << endl;
    }
}

template <class T>
void DList<T>::toStringForward() const {
	stringstream aux;
	Carro *p = new Carro();

	p = head;
	if(head) {
        int i = 1;
        while(i < (size + 1)){
            cout << i << " " << p->get_modelo() << " " << p->get_cant() << endl;
            p = p-> next;
            i++;
        }
    }
    else {
        cout << "hola" << endl;
    }
}

template <class T>
void DList<T>::agregaCarro(string data1, string data2){
    Carro *newData = new Carro();
    newData->get_Datos(data1, data2);

    if(!head){
        head = newData;
        tail = newData;
    }
    else{
        tail -> next = newData;
        newData -> previous = tail;
        tail = newData;
    }
    size ++;
}

template <class T>
string DList<T>::buscaCarro(string data){
    int pos = 0;
    stringstream aux;
    Carro *nd = new Carro();

    nd = head;
    while(nd != 0){
        if(nd -> get_modelo() == data){
            aux << "Se vendieron " << nd -> get_cant();
            return aux.str();
        }
        nd = nd -> next;
        pos ++;

    }
    return "No se encontró el modelo";
}

template <class T>
void DList<T>::actualizaCarro(string index, int data){
    int pos = 0;
    string d = to_string(data);
    Carro *nd = new Carro();

    nd = head;
    while(nd != 0){
        if(nd -> get_modelo() == index){
            nd -> get_Datos(nd ->get_modelo(), d);
            break;
        }
        nd = nd -> next;
        pos ++;
    }
}

#endif