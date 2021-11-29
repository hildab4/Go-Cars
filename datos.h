#ifndef DATOS_H
#define DATOS_H

#include <string>

using namespace std;

class Carro {
    private:
        string modelo;
        string cant;
    public:
        string get_modelo() { return modelo;}
        string get_cant() { return cant;}
        Carro *previous;
        Carro *next;
        void get_Datos(string m, string c) {
            modelo = m;
            cant = c;
        }
};

#endif