#pragma once

class pdBand : public Matrix {
    int bW;
public:
    pdBand(int nrows = 0, int bw = -1, double a = 0.);

    pdBand(int nrows, int bw, const double *const *pa);

    pdBand(const pdBand &A);

    virtual ~pdBand() {};

    pdBand &operator=(const pdBand &B);

    pdBand operator+(const pdBand &B) const;

    Matrix operator+(const Matrix &B) const;

    pdBand trans() const { return pdBand(*this); }

    virtual Vector backward(const Vector &RHS) const;

    virtual Vector forward(const Vector &RHS) const;

    virtual Vector cholesky(const Vector &RHS) const;

    int getBW() const { return bW; }

    Matrix bandToFull() const;
};