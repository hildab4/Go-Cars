/*
 * Fast Cars
 * 
 * Hilda Beltrán Acosta
 * A01251916
 *
 * dlist.h
*/

#ifndef LINKEDL_H
#define LINKEDL_H

//Se incluyen las librerías necesarias
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "datos.h"
using namespace std;

/*
 * Dentro de esta clase DList se definen los atributos privados del objeto, 
 * así como funciones necesarias para los métodos públicos. Los métodos incluyen 
 * agregaCarro para añadir elementos a la lista, buscaCarro recorre la lista hasta
 * encontrar el elemento deseado; actualizaCarro permite modificar las ventas 
 * por modelo, leeArchivo carga los datos a la lista por medio de agregaCarro. 
 * Mientras que escribeArchivo sobreescribe la lista modificada al archivo.
*/
template <class T>
class DList {
    public:
        DList();
        void agregaCarro(string data1, string data2);
        string buscaCarro(string data);
        void actualizaCarro(string index, int data);
        void removeFirst();
        void deleteAt(string index);
        string toStringForward() const;
        void toStringBackward() const;
        void leeArchivo();
        void escribeArchivo();
        void clear();
    private:
        Carro *head;
        Carro *tail;
        int size;
};

/*
 * La función leeArchivo lee línea por línea el archivo datos.csv, se crea
 * el objeto y manda a llamar a la función agregaCarro para añadir un nodo.
 * 
 * @param 
 * @return 
*/ 
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

/*
 * La función leeArchivo sobreescribe el archivo datos.csv con 
 * la información de la nueva lista doblemente ligada.
 * 
 * @param 
 * @return 
*/ 
template <class T>
void DList<T>::escribeArchivo() {
    Carro *p = new Carro();
    ofstream filecarrosnuevo("datos.csv", ios::trunc);
    filecarrosnuevo << "Modelo,cantidad" << endl;
    p = head;
	if(head) {
        int i = 1;
        while(i < (size + 1)){
            filecarrosnuevo << p->get_modelo() << 
            "," << p->get_cant() << endl;
            p = p-> next;
            i++;
        }
    }
}

// Destructor
template <class T>
void DList<T>::clear() {
    Carro *p, *q;
    p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

// Constructor
template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {};

/*
 * La función toStringBackward no se utilizó,
 * aunque en un futuro se puede usar para escribir el archivo según las 
 * ventas más recientes.
 * 
 * @param 
 * @return 
*/ 
/*
template <class T>
void DList<T>::toStringBackward() const {
	stringstream aux;
	Carro *p = new Carro();

	p = tail;
	if(tail) {
        int i = 1;
        while(i < (size + 1)){
            cout << i << " " << p->get_modelo() << 
            " " << p->get_cant() << endl;
            p = p-> previous;
            i++;
        }
    }
    else {
        cout << "hola" << endl;
    }
}
*/

/*
 * La función toStringForward recorre la lista doblemente
 * ligada para imprimir elemento por elemento de acuerdo al
 * orden en que se agregaron elementos. Los últimos elementos
 * agregados se imprimen al final.
 * 
 * @param
 * @return 
*/ 
template <class T>
string DList<T>::toStringForward() const {
	stringstream aux;
	Carro *p = new Carro();

	p = head;
	if(head) {
        int i = 1;
        while(i < (size + 1)){
            aux << i << " " << p->get_modelo() << 
            " " << p->get_cant() << "\n";
            p = p-> next;
            i++;
        }
    }
    return aux.str();
}


/*
 * La función agregaCarro recibe dos strings y crea un objeto nuevo en el
 * heap para asignar los valores recibidos a los atributos. El objeto
 * se agrega al final de la lista doblemente ligada.
 * 
 * @param string, string
 * @return 
*/ 
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

/*
 * La función buscaCarro recorre la lista ligada para buscar una
 * coincidencia en cuanto al atributo modelo del objeto; al 
 * encontrarla regresa un string que contiene la cantidad de ventas.
 * 
 * @param string
 * @return string
*/ 
template <class T>
string DList<T>::buscaCarro(string data){
    int pos = 0;
    stringstream aux;
    string res;
    Carro *nd = new Carro();

    nd = head;
    while(nd != 0){
        if(nd -> get_modelo() == data){
            res = "Se vendieron " + nd -> get_cant();
            return res;
        }
        nd = nd -> next;
        pos ++;

    }
    aux << "No se encontró el modelo";
    return aux.str();
}

/*
 * La función actualizaCarro recibe el modelo y la cantidad para
 * actualizar el valor de ventas.
 * 
 * @param string, int
 * @return 
*/ 
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