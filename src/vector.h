#pragma once

class Vector {
    double *pA;
    int nRows;

    void pointerCheck() const;

public:
    //constructors and destructor
    Vector(int nrows, double const *pa);

    Vector(int nrows = 0, double b = 0.);

    Vector(const Vector &v);

    ~Vector();

    //overloaded operators
    Vector &operator=(const Vector &v);

    Vector operator+(const Vector &v) const;

    Vector &operator+=(const Vector &v);

    Vector operator-(const Vector &v) const;

    Vector &operator-=(const Vector &v);

    Vector operator*(double b) const;

    double operator[](int i) const { return pA[i]; }

    //utilities and accessors
    double dotProd(const Vector &v) const;

    void printVec() const;

    int getnRows() const { return nRows; }

    //friends
    friend class Matrix;

    friend class pdBand;
};

Vector operator*(double b, const Vector *v);
