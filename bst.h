/*
 * Fast Cars
 * 
 * Hilda Beltrán Acosta
 * A01251916
 *
 * bst.h
*/

#ifndef BST_H
#define BST_H

//Se incluyen las librerías necesarias
#include <string>
#include <sstream>
#include <iostream>
#include "datos.h"

using namespace std;

template <class T> class BST;

/*
 * Dentro de esta clase Node se definen los atributos privados del objeto, 
 * así como funciones necesarias para los métodos públicos. Los métodos son 
 * llamados desde la clase BST para generar los nodos del árbol BST.
*/
template <class T>
class Node {
private:
	Carro value;
	Node *left, *right;

	Node<T>* succesor();

public:
	Node(Carro);
	Node(Carro, Node<Carro>*, Node<Carro>*);
	void add(Carro);
	bool find(Carro);
	int height() const;
	void removeChilds();
	void inorder(stringstream&);

	friend class BST<T>;
};

// Constructor primer valor
template <class T>
Node<T>::Node(Carro val) : value(val), left(0), right(0) {}

// Constructor
template <class T>
Node<T>::Node(Carro val, Node<Carro> *l, Node<Carro> *r) : 
	value(val), left(l), right(r) {}

/*
 * La función add recibe el dato a insertar y recorre el árbol
 * hasta encontrar en qué posición almacenarlo; el lado izquiero 
 * es para cuando el valor es menor, mientras el derecho es el
 * valor mayor.
 * 
 * @param Carro
 * @return 
*/ 
template <class T>
void Node<T>::add(Carro val) {
	if (val.get_cant() < value.get_cant()) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<Carro>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<Carro>(val);
		}
	}
}

/*
 * La función find busca el nodo correspondiente al atributo
 * modelo del objeto ingresado.
 * 
 * @param Carro
 * @return bool
*/ 
template <class T>
bool Node<T>::find(Carro val) {
	if (val.get_modelo() == value.get_modelo()) {
		return true;
	} else if (val.get_modelo() < value.get_modelo()) {
		return (left != 0 && left->find(val));
	} else if (val.get_modelo() > value.get_modelo()) {
		return (right != 0 && right->find(val));
	}
    return false;
}

/*
 * La función removeChilds recorre el árbol, tanto las ramas
 * izquierdas como las derechas para eliminar los nodos.
 * 
 * @param 
 * @return 
*/ 
template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

/*
 * La función inorder recorre el árbol y guarda el atributo
 * modelo del nodo en una variable auxiliar; los datos son
 * guardados de manera ascendente en cuanto al atributo modelo.
 * 
 * @param stringstream &
 * @return 
*/ 
template <class T>
void Node<T>::inorder(stringstream &aux) {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << "\n";
	}
	aux << value.get_modelo();
	if (right != 0) {
		right->inorder(aux);
	}
}

/*
 * Dentro de esta clase BST se definen los atributos privados del objeto, 
 * así como funciones necesarias para los métodos públicos. Los métodos 
 * incluyen addCarro para añadir el objeto al árbol, findCarro para buscar 
 * el nodo dentro del árbol BST, removeCarros para vaciar el árbol. Inorder 
 * para mostrar el árbol de manera ordenada, y leeArchivo para cargar los 
 * datos al árbol por medio de addCarro.
*/
template <class T>
class BST {
private:
	Node<Carro> *root;

public:
	BST();
	bool empty() const;
	void addCarro(Carro);
	bool findCarro(Carro) const;
	int height();
	void removeCarros();
	string inorder() const;
    void leeArchivo();
};

/*
 * La función leeArchivo lee línea por línea el archivo datos.csv, se crea
 * el objeto y manda a llamar a la función addCarro para añadir un nodo.
 * 
 * @param 
 * @return 
*/ 
template <class T>
void BST<T>::leeArchivo(){
    Carro nuevo;
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
        nuevo.get_Datos(modelo, cant);

        addCarro(nuevo);
    }
    filecarros.close(); 
}

// Constructor
template <class T>
BST<T>::BST() : root(0) {}

/*
 * La función empty solo revisa si el árbol está vacío
 * o no.
 * 
 * @param 
 * @return bool
*/ 
template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::addCarro(Carro nuevo) {
	if (root != 0) {
		if (!root->find(nuevo)) {
			root->add(nuevo);
		}
	} else {
		root = new Node<Carro>(nuevo);
	}
}

/*
 * La función removeCarros recorre el árbol y elimino los nodos
 * asociados, es una función recursiva para eliminar los nodos del 
 * lado izquierdo y el lado derecho.
 * 
 * @param 
 * @return 
*/ 
template <class T>
void BST<T>::removeCarros() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

/*
 * La función findCarro recorre el árbol buscando el nodo que concuerde con
 * el parametro recibido, regresa un valor booleano, es decir falso o verdadero.
 * 
 * @param Carro
 * @return bool
*/ 
template <class T>
bool BST<T>::findCarro(Carro val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}

/*
 * La función inorder llama a la función inorder de la clase Node
 * para ir guardando en una variable auxiliar los datos recolectados
 * del recorrido del árbol.
 * 
 * @param  
 * @return string
*/ 
template <class T>
string BST<T>::inorder() const {
	stringstream aux;

	if (!empty()) {
		root->inorder(aux);
	}
    aux << "\n";
	return aux.str();
}

#endif