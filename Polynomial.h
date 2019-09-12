//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H

#include <vector>
#include <iostream>
using namespace std;
typedef int TipoEntero;
typedef float TipoNumerico;
typedef string TipoCadena;



class Polynomial {
private:
    TipoEntero grado = 0;
    TipoEntero numTerminos = 0;
    TipoEntero* pCoeficientes = new TipoEntero[numTerminos];
    TipoEntero* pExponentes = new TipoEntero[numTerminos];

public:

    Polynomial();
    ~Polynomial();

    void add(TipoEntero coeficiente, TipoEntero exponente); //Validar que no se repita termino
    TipoEntero degree();
    Polynomial operator+(Polynomial& polinomio);
    void operator+=(Polynomial& polinomio);
    Polynomial operator+(TipoEntero escalar);
    void operator+=(TipoEntero escalar);
    Polynomial operator*(Polynomial& polinomio);
    Polynomial operator*(TipoEntero escalar);
    Polynomial operator^(TipoEntero escalar);


    friend ostream& operator<<(ostream &os, Polynomial &polinomio);

};

#endif //POLINOMIO_POLINOMIO_H
