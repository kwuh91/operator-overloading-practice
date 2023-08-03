#ifndef OPERATOR_MATRIX_H
#define OPERATOR_MATRIX_H

#include "vector.h"
#include <iostream>
#include <iomanip>

//initializing
class [[maybe_unused]] CSRMatrix {
private:
    Vector row_;
    Vector column_;
    Vector value_;
public:
    //Initializing full
    [[maybe_unused]] explicit CSRMatrix(const Vector & = {0}, const Vector & = {0}, const Vector & = {0});

    //Destruct
    ~CSRMatrix() = default;

    //matrix size
    [[maybe_unused]] static size_t matrix_size(CSRMatrix &);

    //amount of !0
    [[maybe_unused]] static size_t amount_of_notz(CSRMatrix &);

    //vec = matrix * vec
    Vector operator*(Vector &);

    //vec = vec * matrix
    //friend Vector operator*(Vector &, CSRMatrix &);

    //matrix = matrix * numb
    CSRMatrix operator*(double) const;

    //matrix = numb * matrix
    friend CSRMatrix operator*(double, const CSRMatrix &);

    //>>
    friend std::istream &operator>>(std::istream &, CSRMatrix &);

    //<<
    friend std::ostream &operator<<(std::ostream &, CSRMatrix &);
};

#endif //OPERATOR_MATRIX_H
