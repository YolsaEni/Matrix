#pragma once

#include "vector.h"

class Matrix {
    int nRows, nCols;

    void pointerCheck() const;

    void pointerCheck(int i) const;

protected:
    double **pA;

public:
    // constructors and destructor
    Matrix(int nrows = 0, int ncols = 0, double a = 0.);

    Matrix(int nrows, int ncols, const double *const *pa);

    Matrix(const Matrix &A);

    virtual ~Matrix();

    //overloaded operators
    Matrix &operator=(const Matrix &B);

    Matrix operator+(const Matrix &B) const;

    Matrix &operator+=(const Matrix &B);

    Matrix operator-(const Matrix &B) const;

    Matrix &operator-=(const Matrix &B);

    Matrix operator*(const Matrix &B) const;

    Matrix operator*(double b) const;

    Vector operator*(const Vector &v) const;

    const double *operator[](int i) const { pA[i]; }

    //matrix operations
    Matrix trans() const;

    //solution of a linear system
    virtual Vector backward(const Vector &RHS) const;

    virtual Vector forward(const Vector &RHS) const;

    Vector gauss(const Vector &RHS) const;

    virtual Vector cholesky(const Vector &RHS) const;

    //banded systems
    Vector bandBack(const Vector &RHS, int bWidth) const;

    Vector bandFor(const Vector &RHS, int bWidth) const;

    Vector bandChol(const Vector &RHS, Matrix &G, int bWidth) const;

    void QR(Matrix &Q, Matrix &R) const;

    //computation of spectra
    Vector eigen(int Nvals, Vector &v, Matrix &U, int itMax = 38,
                 double delta = .00000001) const;

    Vector SVD(int Nvals, Vector &v, Matrix &U, Matrix &V,
               int itMax = 38, double delta = .00000001) const;

    //utilities accessors
    void printMatrix() const;

    Vector matToVec(int j) const;// jth column to a vector

    void vecToMat(int j, const Vector &v);// vector into jth column

    int getnRows() const { return nRows; }

    int getnCols() const { return nCols; }

    friend Matrix operator*(const Vector &v1, const Vector &v2);
};

Matrix operator*(const Vector &v1, const Vector &v2);

Matrix operator*(double, const Matrix &A);