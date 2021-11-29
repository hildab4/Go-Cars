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

using namespace std;

int main(){
    vector <Carro> carros;
    Sorts <Carro> sorts;
    DList <Carro> dlist;
    //Heap <Carro> heapc(carros.size());
    sorts.leeArchivo(carros);
    dlist.leeArchivo();

    while(true) {
        cout << "------------------------------------------" << endl << "Bienvenido a Fast Cars" << endl << endl;
        cout << endl << "Seleccione la opción de la operación que desea llevar a cabo" <<
        endl << endl << "\t 1: Desplegar ventas" << endl << "\t 2: Desplegar ventas ordenadas" << endl <<
        "\t 3: Consultar mayor y menor ventas" << endl <<
        "\t 4: Actualizar ventas" << endl <<
        "\t 5: Agregar modelo y ventas" << endl <<
        "\t 6: Buscar ventas por modelo" << endl << "\t 7: Exit" << endl;

        int opc;
        cin >> opc;
        cout << endl;

        if (opc == 1) {
            cout << "Desplegar ventas" << endl << "---------------------------" << endl;
            sorts.muestraDatos(carros);
        }
        else if (opc == 2) {
            cout << "Desplegar ventas ordenadas" << endl << "---------------------------" << endl;
            sorts.ordenaCarro(carros);
            sorts.muestraDatos(carros);
        }
        else if (opc == 3) {
            cout << "Consultar mayor y menor ventas" << endl << "---------------------------" << endl;
            sorts.mayormenor(carros);
        }
        else if (opc == 4) {
            cout << "Actualizar ventas" << endl << "---------------------------" << endl;
            cout << "Modelo: ";
            string m; cin >> m; cout << endl;
            cout << "Cantidad: ";
            int c; cin >> c; cout << endl;
            dlist.actualizaCarro(m, c);
            dlist.toStringForward();
        }
        else if (opc == 5) {
            cout << "Agregar modelo y ventas" << endl << "---------------------------" << endl;
            cout << "Modelo: ";
            string m; cin >> m; cout << endl;
            cout << "Cantidad: ";
            string c; cin >> c; cout << endl;
            dlist.agregaCarro(m, c);
            dlist.toStringForward();
        }
        else if (opc == 6) {
            cout << "Buscar ventas por modelo" << endl << "---------------------------" << endl;
            cout << "Modelo: ";
            string m; cin >> m; cout << endl;
            cout << dlist.buscaCarro(m) << endl;
        }
        else if (opc == 7) {
            cout << "Gracias por visitar Fast Cars" << endl;
            cout << "-----------------------------" << endl;
            exit(1);
        }
    }
}