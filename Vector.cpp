#include "Vector.h"
#include <cmath>
#include <iostream>
#include <cstdio>

//Initializing
Vector::Vector(int size, double initial_v) : size_(size), vec_(new double[size]) {
    for (size_t i = 0; i < size; ++i) vec_[i] = initial_v;
}

//Copying
Vector::Vector(const Vector &source_v) : size_(source_v.size_), vec_(new double[source_v.size_]) {
    for (size_t i = 0; i < size_; ++i) vec_[i] = source_v.vec_[i];
}

//Extra
[[maybe_unused]] Vector::Vector(std::initializer_list<double> args) : size_(args.size()),
                                                                      vec_(new double[args.size()]) {
    size_t j = 0;
    for (auto i: args) vec_[j] = i, j++;
}

//Vector size
[[maybe_unused]] size_t Vector::vector_size(const Vector &vec_obj) {
    return vec_obj.size_;
}

//Vector capacity
[[maybe_unused]] double Vector::vector_len(const Vector &vec_obj) {
    double res = 0;
    for (size_t i = 0; i < vec_obj.size_; ++i) res += vec_obj.vec_[i] * vec_obj.vec_[i];
    return sqrt(res);
}

//Push_back
[[maybe_unused]] void Vector::push_back(const double &numb) {
    double *new_ptr = new double[size_ + 1];
    std::copy(vec_, vec_ + size_, new_ptr);
    delete[] vec_;
    vec_ = new_ptr;
    vec_[Vector::vector_size(*this)] = numb;
    ++size_;
}

//Operators
//+,++
//vector3 = vector1 + vector2
Vector Vector::operator+(Vector const &obj) const {
    Vector res(std::max((int) obj.size_, (int) size_));
    for (size_t i = 0; i < std::max((int) obj.size_, (int) size_); ++i)
        size_ > obj.size_ ? res.vec_[i] += vec_[i] : res.vec_[i] += obj.vec_[i];
    for (size_t i = 0; i < std::min((int) obj.size_, (int) size_); ++i)
        size_ > obj.size_ ? res.vec_[i] += obj.vec_[i] : res.vec_[i] += vec_[i];
    return res;
}

//vector3 = vector1 + number
Vector Vector::operator+(double number) const {
    Vector res(*this);
    for (size_t i = 0; i < size_; ++i) res.vec_[i] += number;
    return res;
}

//vector3 = number + vector1
Vector operator+(double number, const Vector &obj) {
    Vector res(obj);
    for (size_t i = 0; i < obj.size_; ++i) res.vec_[i] += number;
    return res;
}

//++vector
const Vector &Vector::operator++() {
    for (size_t i = 0; i < size_; ++i) vec_[i]++;
    return *this;
}

//vector++
const Vector Vector::operator++(int) {
    Vector copy = *this;
    operator++();
    return copy;
}

//+vector
const Vector &Vector::operator+() {
    for (size_t i = 0; i < size_; ++i) vec_[i] = std::abs(vec_[i]);
    return *this;
}

//=
//vector1 = vector2
Vector &Vector::operator=(Vector const &obj) {
    if (&obj == this) return *this;
    vec_ = obj.vec_;
    size_ = obj.size_;
    return *this;
}

//+=
//vector1 += vector2
Vector &Vector::operator+=(const Vector &obj) {
    auto *new_arr = new double[std::max((int) obj.size_, (int) size_)];
    if (obj.size_ > size_) {
        for (size_t i = 0; i < size_; ++i) new_arr[i] = vec_[i] + obj.vec_[i];
        for (size_t i = std::min((int) obj.size_, (int) size_); i < std::max((int) obj.size_, (int) size_); ++i)
            new_arr[i] = obj.vec_[i];
        delete[] vec_;
        vec_ = new_arr;
        size_ = obj.size_;
    } else {
        for (size_t i = 0; i < obj.size_; ++i) vec_[i] += obj.vec_[i];
    }
    return *this;
}

//vector += number
Vector &Vector::operator+=(double number) {
    for (size_t i = 0; i < size_; ++i) vec_[i] += number;
    return *this;
}

//-,--
//vector3 = vector1 - vector2
Vector Vector::operator-(const Vector &obj) {
    Vector res(std::max((int) obj.size_, (int) size_));
    for (size_t i = 0; i < std::min((int) obj.size_, (int) size_); ++i) res.vec_[i] += vec_[i] - obj.vec_[i];
    if (size_ != obj.size_) {
        if (obj.size_ > size_) {
            for (size_t i = std::min((int) obj.size_, (int) size_); i < std::max((int) obj.size_, (int) size_); ++i)
                res.vec_[i] -= obj.vec_[i];
        } else {
            for (size_t i = std::min((int) obj.size_, (int) size_); i < std::max((int) obj.size_, (int) size_); ++i)
                res.vec_[i] += vec_[i];
        }
    }
    return res;
}

//vector3 = vector1 - number
Vector Vector::operator-(double number) const {
    Vector res(*this);
    for (size_t i = 0; i < res.size_; ++i) res.vec_[i] -= number;
    return res;
}

//--vector
const Vector &Vector::operator--() {
    for (size_t i = 0; i < size_; ++i) vec_[i]--;
    return *this;
}

//vector--
const Vector Vector::operator--(int) {
    Vector copy = *this;
    operator--();
    return copy;
}

//-vector
const Vector &Vector::operator-() {
    for (size_t i = 0; i < size_; ++i) vec_[i] *= -1;
    return *this;
}

//-=
//vector1 -= vector2
Vector &Vector::operator-=(const Vector &obj) {
    auto *new_arr = new double[std::max((int) obj.size_, (int) size_)];
    if (obj.size_ > size_) {
        for (size_t i = 0; i < size_; ++i) new_arr[i] = vec_[i] - obj.vec_[i];
        for (size_t i = std::min((int) obj.size_, (int) size_); i < std::max((int) obj.size_, (int) size_); ++i)
            new_arr[i] = -obj.vec_[i];
        delete[] vec_;
        vec_ = new_arr;
        size_ = obj.size_;
    } else {
        for (size_t i = 0; i < obj.size_; ++i) vec_[i] -= obj.vec_[i];
    }
    return *this;
}

//vector -= number
Vector &Vector::operator-=(double number) {
    for (size_t i = 0; i < size_; ++i) vec_[i] -= number;
    return *this;
}

//*
//vector3 = vector1 * number
Vector Vector::operator*(double number) const {
    Vector res(*this);
    for (size_t i = 0; i < res.size_; ++i) {
        res.vec_[i] *= number;
    }
    return res;
}

//double = vector1 * vector2
double Vector::operator*(const Vector &obj) {
    if (size_ != obj.size_) {
        return 0;
    }
    double res = 0;
    for (size_t i = 0; i < obj.size_; ++i) {
        res += obj.vec_[i] * vec_[i];
    }
    return res;
}

//vector3 = number * vector1
Vector operator*(double number, const Vector &obj) {
    Vector res(obj);
    for (size_t i = 0; i < res.size_; ++i) {
        res.vec_[i] *= number;
    }
    return res;
}

//[]
double Vector::operator[](size_t i) &{
    if (i > Vector::vector_size(*this)) {
        std::string msg1 = "Out of range ( Vector[";
        std::string msg2 = std::to_string(i);
        msg1.append(msg2);
        std::string msg3 = "] > Vector.size = ";
        msg1.append(msg3);
        std::string msg4 = std::to_string(Vector::vector_size(*this));
        msg1.append(msg4);
        msg1.append(" )");
        throw OutOfRangeException(msg1);
    }
    return vec_[i];
}

//>>
std::istream &operator>>(std::istream &cin, Vector &obj) {
    double numb;
    size_t curr_size = 0;
    bool flag = true;
    while (flag) {
        std::cout << "Enter your element:\n";
        cin >> numb;
        curr_size++;
        auto *temp_arr = new double[curr_size];
        for (size_t i = 0; i < obj.size_; ++i) temp_arr[i] = obj.vec_[i];
        temp_arr[curr_size - 1] = numb;
        delete[] obj.vec_;
        obj.vec_ = temp_arr;
        obj.size_++;
        std::cout << "Would you like to add another element? (Y/N)\n";
        char choice;
        std::cin >> choice;
        if (choice == 'N') {
            flag = false;
        } else if (choice == 'Y') {
            continue;
        } else {
            std::cout << "Invalid option\n";
            flag = false;
        }
    }
    return cin;
}

//<<
std::ostream &operator<<(std::ostream &cout, Vector &obj) {
    for (size_t i = 0; i < obj.size_; ++i) cout << obj.vec_[i] << ' ';
    return cout;
}

//max element
[[maybe_unused]] size_t Vector::max_element(const Vector &obj) {
    double res = -1000000000000000000.;
    for (size_t i = 0; i < obj.size_; ++i) {
        if (obj.vec_[i] > res) {
            res = obj.vec_[i];
        }
    }
    return (size_t) res;
}

//min element
[[maybe_unused]] size_t Vector::min_element(const Vector &obj){
    double res = 1000000000000000000.;
    for (size_t i = 0; i < obj.size_; ++i) {
        if (obj.vec_[i] < res) {
            res = obj.vec_[i];
        }
    }
    return (size_t) res;
}
