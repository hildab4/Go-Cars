#include <iostream> 
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "datos.h"

using namespace std;

template <class T>
void leeArchivo(vector<T>&vec){
    string strDatos;
    stringstream ss;
    string cantidad;
    string modelo;

    ifstream filedatos("datos.csv");
    if(!filedatos){
        cerr << "No se encontró el archivo datos.csv" << endl;
        exit(1);
    }
    getline(filedatos, strDatos);
    while(getline(filedatos, strDatos)){
        ss.clear();
        ss << strDatos;
        getline(ss, modelo, ',');
        getline(ss, cantidad);
        int cant = stoi(cantidad);
        vec.push_back(cant);
    }
    filedatos.close();
}

int main(){
    vector <int> vec;
    leeArchivo(vec);

    Sorts <int> sorts;
    sorts.ordenaMerge(vec);

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}