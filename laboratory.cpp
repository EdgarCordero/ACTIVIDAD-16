#include "laboratory.h"
#include <fstream>
#include<algorithm>

using namespace std;

Laboratory::Laboratory()
{
}

void Laboratory::addComputer(const Computer &c){

    computadoras.push_back(c);
}

void Laboratory::mostrar(){
    cout << left;
    cout << setw(20) << "NOMBRE EQUIPO";
    cout << setw(13) << "SISTEMA";
    cout << setw(10) << "CPU";
    cout << setw(5) << "RAM";
    cout << endl;

    for(int i = 0; i<computadoras.size(); i++){
        Computer &p = computadoras[i];
        cout << p;
    }
}

void Laboratory::respaldarTabla(){
    ofstream archivo ("computadorasTabla.txt");
    if(archivo.is_open()){
        archivo << left;
        archivo << setw(17) << "NOMBRE EQUIPO";
        archivo << setw(13) << "SISTEMA";
        archivo << setw(10) << "CPU";
        archivo << setw(5) << "RAM";
        archivo << endl;
        for(int i = 0; i<computadoras.size(); i++){
            Computer &p = computadoras[i];
            archivo << p;
        }
    }
    archivo.close();
}

void Laboratory::respaldar(){
    ofstream archivo ("computadoras.txt");
    if(archivo.is_open()){

        for(int i = 0; i<computadoras.size(); i++){
            Computer &p = computadoras[i];
            archivo << p.getName() << endl;
            archivo << p.getSystem() << endl;
            archivo << p.getCpu() << endl;
            archivo << p.getRam() << endl;

        }
    }
    archivo.close();
}
void Laboratory::recuperar()
{
    ifstream archivo ("computadoras.txt");
    if(archivo.is_open()){
        string temp;
        Computer c;

        while(true){
            getline(archivo, temp);
            if(archivo.eof()){
                break;
            }
            c.setName(temp);

            getline(archivo, temp);
            c.setSystem(temp);

            getline(archivo, temp);
            c.setCpu(temp);

            getline(archivo, temp);
            c.setRam(stoi(temp));

            addComputer(c);
        }
        archivo.close();
    }

}

void Laboratory::insertar (const Computer &c, size_t pos){
    computadoras.insert(computadoras.begin()+pos, c);
}

size_t Laboratory::tam(){
    return computadoras.size();
}

void Laboratory::inicializar(const Computer &c, size_t n){
    computadoras = vector<Computer>(n, c);
}

void Laboratory::eliminar(size_t pos){
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratory::ordenar(){
    sort(computadoras.begin(), computadoras.end());
}

Computer* Laboratory::buscar(const Computer &c){
    auto it = find(computadoras.begin(), computadoras.end(), c);

    if (it == computadoras.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }


}
