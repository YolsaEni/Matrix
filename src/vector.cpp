#include <iostream>
#include <cstdlib>
#include <new>
#include "vector.h"

using std::cout; using std::endl;

Vector::Vector(int nrows, double const *pa) {
    nRows = nrows;
    pA = new(std::nothrow) double[nRows];
    pointerCheck();
    for (int i = 0; i < nRows; i++)
        pA[i] = pa[i];
}

Vector::Vector(int nrows, double b) {
    nRows = nrows;
    if (nRows == 0) {
        pA = 0;
        return;
    }
    pA = new(std::nothrow) double[nRows];
    pointerCheck();
    for (int i = 0; i < nRows; i++)
        pA[i] = b;
}

void Vector::pointerCheck() const {
    if(pA == 0){
        cout << "Memory allocation for pA failed" << endl;
        exit(1);
    }
}