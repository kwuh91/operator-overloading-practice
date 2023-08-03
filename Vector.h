#ifndef VECTOR_H
#define VECTOR_H

#pragma once

#include "OutOfRangeException.h"
#include "IncompatibleDimException.h"
#include <cstdlib>
#include <iostream>

class Vector {
private:
    double *vec_;
    size_t size_;
public:
    //Initializing
    explicit Vector(int, double = 0);

    //Copying
    Vector(const Vector &);

    //Extra
    [[maybe_unused]] Vector(std::initializer_list<double>);

    //Vector size
    [[maybe_unused]] static size_t vector_size(const Vector &);

    //Vector capacity
    [[maybe_unused]] static double vector_len(const Vector &);

    //Destruct
    ~Vector() = default;

    //Push_back
    [[maybe_unused]] void push_back(const double &);

    //Operators

    //+,++
    //vector3 = vector1 + vector2
    Vector operator+(Vector const &) const;

    //vector3 = vector1 + number
    Vector operator+(double) const;

    //vector3 = number + vector1
    friend Vector operator+(double, const Vector &);

    //++vector
    const Vector &operator++();

    //vector++
    const Vector operator++(int);

    //+vector
    const Vector &operator+();

    //=
    //vector1 = vector2
    Vector &operator=(Vector const &);

    //+=
    //vector1 += vector2
    Vector &operator+=(const Vector &);

    //vector += number
    Vector &operator+=(double);

    //-,--
    //vector3 = vector1 - vector2
    Vector operator-(const Vector &);

    //vector3 = vector1 - number
    Vector operator-(double) const;

    //--vector
    const Vector &operator--();

    //vector--
    const Vector operator--(int);

    //-vector
    const Vector &operator-();

    //-=

    //vector1 -= vector2
    Vector &operator-=(const Vector &);

    //vector -= number
    Vector &operator-=(double);

    //*

    //vector3 = vector1 * number
    Vector operator*(double) const;

    //double = vector1 * vector2
    double operator*(const Vector &);

    //vector3 = number * vector1
    friend Vector operator*(double, const Vector &);

    //[]
    double operator[](size_t) &;

    //>>
    friend std::istream &operator>>(std::istream &, Vector &);

    //<<
    friend std::ostream &operator<<(std::ostream &, Vector &);

    //max element
    [[maybe_unused]] static size_t max_element(const Vector &);

    //min element
    [[maybe_unused]] static size_t min_element(const Vector &);
};

#endif
