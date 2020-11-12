#include <iostream>
#include "laboratory.h"


using namespace std;

int main()
{
    Laboratory l;

    string op;

    while(true){

        cout << "1.- AGREGAR COMPUTADORAS" << endl;
        cout << "2.- MOSTRAR" << endl;
        cout << "3.- RESPALDAR" << endl;
        cout << "4.- RECUPERAR" << endl;
        cout << "5.- INSERTAR" << endl;
        cout << "6.- INICIALIZAR" << endl;
        cout << "7.- ELIMINAR" << endl;
        cout << "8.- ORDENAR" << endl;
        cout << "9.- BUSCAR" << endl;
        cout << "0.- SALIR" << endl;


        getline(cin, op);
        cout << endl;

        if(op == "1"){
            Computer c;
            cin >> c;
            l.addComputer(c);
            cout << endl;

        }
        else if(op == "2"){
            l.mostrar();
            cout << endl;
        }
        else if (op == "3"){
            l.respaldar();
            l.respaldarTabla();
            cout << endl;
        }
        else if(op == "4"){
            l.recuperar();
            cout << endl;
        }
        else if(op == "5"){
            Computer c;
            cin >> c;

            size_t pos;
            cout << "pos: ";
            cin >> pos;

            if (pos >= l.tam()){
                cout << "POSICION NO VALIDA" << endl;
            }
            else{
            l.insertar(c, pos);
            }
            cout << endl;
        }
        else if (op == "6"){
            Computer c;
            cin >> c;

            size_t n;
            cout << "n: ";
            cin >> n;

            l.inicializar(c,n);

            cout << endl;

        }
        else if(op == "7"){

            size_t pos;
            cout << "pos: ";
            cin >> pos;

            if (pos >= l.tam()){
                cout << "POSICION NO VALIDA" << endl;
            }
            else{
            l.eliminar(pos);
            }
            cout << endl;
        }
        else if(op == "8"){
            l.ordenar();
            cout << endl;
        }
        else if (op == "9"){
            Computer c;
            cin >> c; cin.ignore();
            cout << endl;

            Computer *ptr = l.buscar(c);

            if (ptr == nullptr){
                cout << "NO ENCONTRADO" << endl;
            }
            else {
                cout << *ptr << endl;
            }
            cout<<endl;
        }
        else if (op == "0"){
            break;
        }

    }

    return 0;

}
