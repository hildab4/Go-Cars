#include <iostream> 
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "sort.h"
#include "datos.h"
#include "dlist.h"
#include "bst.h"

using namespace std;

int main(){
    vector <Carro> carros;
    Sorts <Carro> sorts;
    DList <Carro> dlist;
    BST <Carro> bst;
    dlist.leeArchivo();
    dlist.escribeArchivo();
    bst.leeArchivo();

    while(true) {
        dlist.clear();
        bst.removeCarros();
        cout << "------------------------------------------" << endl << 
        "Bienvenido a Fast Cars" << endl << endl;
        cout << endl << "Seleccione la opción de la operación que desea llevar a cabo" <<
        endl << endl << "\t 1: Desplegar modelos en orden alfabético" << endl << 
        "\t 2: Desplegar ventas ordenadas" << endl <<
        "\t 3: Actualizar ventas" << endl <<
        "\t 4: Agregar modelo y ventas" << endl <<
        "\t 5: Buscar ventas por modelo" << endl << "\t 6: Exit" << endl;

        int opc;
        cin >> opc;
        cout << endl;

        if (opc == 1) {
            cout << "Desplegar modelos en orden alfabético" << endl << 
            "---------------------------" << endl;
            carros.clear();
            sorts.leeArchivo(carros);
            sorts.ordenaCarro(carros);
            sorts.muestraDatos(carros);
        }
        else if (opc == 2) {
            cout << "Desplegar ventas ordenadas" << endl << 
            "---------------------------" << endl;
            cout << "Menor a mayor ventas" << endl;
            bst.leeArchivo();
            cout << bst.inorder() << endl;
        }
        else if (opc == 3) {
            cout << "Actualizar ventas" << endl << 
            "---------------------------" << endl;
            dlist.leeArchivo();
            cout << "Modelo: ";
            string m; cin >> m; cout << endl;
            cout << "Cantidad: ";
            int c; cin >> c; cout << endl;
            dlist.actualizaCarro(m, c);
            dlist.escribeArchivo();
            dlist.toStringForward();
        }
        else if (opc == 4) {
            cout << "Agregar modelo y ventas" << endl << 
            "---------------------------" << endl;
            dlist.leeArchivo();
            cout << "Modelo: ";
            string m; cin >> m; cout << endl;
            cout << "Cantidad: ";
            string c; cin >> c; cout << endl;
            dlist.agregaCarro(m, c);
            dlist.escribeArchivo();
        }
        else if (opc == 5) {
            cout << "Buscar ventas por modelo" << endl << 
            "---------------------------" << endl;
            dlist.leeArchivo();
            cout << "Modelo: ";
            string m; cin >> m; cout << endl;
            cout << dlist.buscaCarro(m) << endl;
            dlist.escribeArchivo();
        }
        else if (opc == 6) {
            cout << "Gracias por visitar Fast Cars" << endl;
            cout << "-----------------------------" << endl;
            exit(1);
        } 
    }
}