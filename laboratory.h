#ifndef LABORATORY_H
#define LABORATORY_H

#include "computer.h"
#include <vector>

class Laboratory
{
    private:
        vector<Computer> computadoras;

    public:
        Laboratory();

        void addComputer (const Computer &c);
        void mostrar();

        void respaldarTabla();
        void respaldar();
        void recuperar();

        size_t tam();
        void insertar (const Computer &c, size_t pos);
        void inicializar (const Computer &c, size_t n);
        void eliminar(size_t pos);
        void ordenar();
        Computer* buscar(const Computer &c);

        friend Laboratory& operator<<(Laboratory &lb, const Computer &c){

            lb.addComputer(c);

            return lb;
        }

};

#endif // LABORATORY_H
