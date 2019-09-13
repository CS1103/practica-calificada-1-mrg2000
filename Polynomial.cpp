//
// Created by rudri on 9/12/2019.
//

#include <stdexcept>
#include <iostream>
#include "Polynomial.h"


Polynomial::Polynomial() {

}

Polynomial::~Polynomial() {

}

void Polynomial::add(TipoEntero coeficiente, TipoEntero exponente){
    if(grado < exponente)
        grado = exponente;

    if(numTerminos != 0) {
        for (TipoEntero i = 0; i < numTerminos; i++) {
            if (pExponentes[i] == exponente)
                pCoeficientes[i] += coeficiente;
            else{
                pCoeficientes[numTerminos] = coeficiente;
                pExponentes[numTerminos] = exponente;
                numTerminos++;
            }
        };

    }else{
        pCoeficientes[0] = coeficiente;
        pExponentes[0] = exponente;
        numTerminos++;
    }

}


TipoEntero Polynomial::degree() {
    return grado;
}


ostream& operator<<(ostream &os, const Polynomial polinomio) {

    for(TipoEntero i=0; i<polinomio.numTerminos;i++)
        for(TipoEntero j=0; j<polinomio.numTerminos;j++){
            if(polinomio.pExponentes[j] == i && i != j){
                 cout << showpos << polinomio.pCoeficientes[j];
                 cout << "x^" << polinomio.pExponentes[j];
            }
        }

        return os;

}


Polynomial Polynomial::operator+(Polynomial &polinomio) {
    Polynomial* newPoli = new Polynomial();

    if(newPoli->numTerminos !=0){
    for(TipoEntero i=1;i<polinomio.numTerminos;i++){
        for(TipoEntero j=0;j<numTerminos;j++){
                if(polinomio.pExponentes[i] == pExponentes[j]){
                    newPoli->pCoeficientes[i] = polinomio.pCoeficientes[i] + pCoeficientes[j];
                    newPoli->pExponentes[i] = pExponentes[i];
                    newPoli->numTerminos++;
                }else if(j-1 == numTerminos){
                    newPoli->pCoeficientes[i] = polinomio.pCoeficientes[i];
                    newPoli->pExponentes[i] = pExponentes[i];
                    newPoli->numTerminos++;
                }
            }
        }
    }else{
        for(TipoEntero j=0;j<numTerminos;j++) {
            if(polinomio.pExponentes[0] == pExponentes[j]) {
                newPoli->pCoeficientes[0] = polinomio.pCoeficientes[0] + pCoeficientes[j];
                newPoli->pExponentes[0] = pExponentes[0];
                newPoli->numTerminos++;
            }else{
                newPoli->pCoeficientes[0] = polinomio.pCoeficientes[0];
                newPoli->pExponentes[0] = pExponentes[0];
                newPoli->numTerminos++;
            }
        }
    }

    newPoli->grado = grado;


    return *newPoli;
}


void Polynomial::operator+=(Polynomial &polinomio) {

        for(TipoEntero i=0;i<polinomio.numTerminos;i++){
            for(TipoEntero j=0;j<numTerminos;j++){
                if(polinomio.pExponentes[i] == pExponentes[j]){
                    pCoeficientes[i] = polinomio.pCoeficientes[i] + pCoeficientes[j];
                    pExponentes[i] = pExponentes[i];
                }else if(j-1 == numTerminos){
                    pCoeficientes[i] = polinomio.pCoeficientes[i];
                    pExponentes[i] = pExponentes[i];
                    numTerminos++;
                    if(grado<pExponentes[i]){
                        grado = pExponentes[i];
                    }
                }
            }
        }
    }


Polynomial Polynomial::operator+(TipoEntero escalar) {
    Polynomial* newPoli = new Polynomial();

    for(TipoEntero i =0;i<numTerminos;i++){
        if(pExponentes[i] == 0){
            newPoli->pCoeficientes[i] += pCoeficientes[i];
            newPoli->pExponentes[i] = 0;
            newPoli->numTerminos++;

        }else{
            newPoli->pCoeficientes[i] = pCoeficientes[i];
            newPoli->pExponentes[i] = pExponentes[i];
            newPoli->numTerminos++;
        }
    }

    newPoli->grado = grado;

    return *newPoli;
}

void Polynomial::operator+=(TipoEntero escalar) {
    for(TipoEntero i =0;i<numTerminos;i++){
        if(pExponentes[i] == 0){
            pCoeficientes[i] += pCoeficientes[i];
            pExponentes[i] = 0;

        }else{
            pCoeficientes[i] = pCoeficientes[i];
            pExponentes[i] = pExponentes[i];
        }
    }

}


Polynomial Polynomial::operator*(Polynomial &polinomio) {
    Polynomial* newPoli = new Polynomial();

    for(TipoEntero i =0;i<numTerminos;i++){
        for(TipoEntero j=0;j<polinomio.numTerminos;j++){
            newPoli->pCoeficientes[i] = pCoeficientes[i]*polinomio.pCoeficientes[j];
        };
    }

    newPoli->grado = grado;

    return *newPoli;

}



Polynomial Polynomial::operator*(TipoEntero escalar) {
    Polynomial* newPoli = new Polynomial();

    for(TipoEntero i=0;i<numTerminos;i++){
        newPoli->pCoeficientes[i] = pCoeficientes[i]*escalar;
        newPoli->pExponentes[i] = pExponentes[i];
        newPoli->numTerminos++;
    }

    return *newPoli;
}




Polynomial Polynomial::operator^(TipoEntero escalar) {

    Polynomial* newPoli = new Polynomial();
    Polynomial* aux = new Polynomial();


    for(TipoEntero i=0;i<numTerminos;i++){
        newPoli->pCoeficientes[i] = pCoeficientes[i];
        newPoli->pExponentes[i] = pExponentes[i];
        newPoli->grado = grado;
        newPoli->numTerminos = numTerminos;
    }

    for(TipoEntero i=0; i<escalar;i++){
        aux = newPoli*newPoli;
    }




    return *aux();
}
