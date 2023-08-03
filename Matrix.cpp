#include "Matrix.h"
#include <iostream>

int amount_of_elements_in_a_number(int numb) {
    int count = 0;
    while (numb) {
        count++;
        numb /= 10;
    }
    return count;
}

//initializing full
[[maybe_unused]] CSRMatrix::CSRMatrix(const Vector &row, const Vector &column, const Vector &value) : row_(row),
                                                                                                      column_(column),
                                                                                                      value_(value) {}

//<<
std::ostream &operator<<(std::ostream &cout, CSRMatrix &obj) {
    for (size_t i = 0; i < Vector::vector_size(obj.row_); ++i) {
        if (obj.row_[i] < 0) {
            throw OutOfRangeException("Row position can't be < 0");
        }
    }
    for (size_t i = 0; i < Vector::vector_size(obj.column_); ++i) {
        if (obj.column_[i] < 0) {
            throw OutOfRangeException("Column position can't be < 0");
        }
    }
    auto **arr = new double *[Vector::max_element(obj.row_) + 1];
    for (size_t i = 0; i < Vector::max_element(obj.row_) + 1; ++i)
        arr[i] = new double[Vector::max_element(obj.column_) + 1];
    for (size_t i = 0; i < Vector::max_element(obj.row_) + 1; ++i) {
        for (size_t j = 0; j < Vector::max_element(obj.column_) + 1; ++j) arr[i][j] = 0;
    }
    for (size_t i = 0; i < Vector::vector_size(obj.value_); ++i)
        arr[(size_t) (obj.row_[i])][(size_t) (obj.column_[i])] = obj.value_[i];
    for (size_t i = 0; i < Vector::max_element(obj.row_) + 1; ++i) {
        for (size_t j = 0; j < Vector::max_element(obj.column_) + 1; ++j) cout << std::setw(
                    amount_of_elements_in_a_number(std::max((int) Vector::max_element(obj.value_),
                                                            abs((int) Vector::min_element(obj.value_))))+1) << arr[i][j]
                                                                               << ' ';
        cout << std::endl;
    }
    for (size_t i = 0; i < Vector::max_element(obj.row_) + 1; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    return cout;
}

//>>
std::istream &operator>>(std::istream &cin, CSRMatrix &obj) {
    Vector new_row{};
    Vector new_column{};
    Vector new_value{};
    double numb;
    bool flag = true;
    while (flag) {
        std::cout << "Enter row position\n";
        std::cin >> numb;
        if (numb < 0) {
            throw OutOfRangeException("Row position can't be < 0");
        }
        new_row.push_back(numb);
        std::cout << "Enter column position\n";
        std::cin >> numb;
        if (numb < 0) {
            throw OutOfRangeException("Column position can't be < 0");
        }
        new_column.push_back(numb);
        std::cout << "Enter value\n";
        std::cin >> numb;
        new_value.push_back(numb);
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
    CSRMatrix new_matr(new_row, new_column, new_value);
    obj = new_matr;
    return cin;
}

//matrix size
[[maybe_unused]] size_t CSRMatrix::matrix_size(CSRMatrix &obj) {
    size_t maxim = -1;
    for (size_t i = 0; i < Vector::vector_size(obj.row_); ++i) {
        if ((size_t) obj.row_[i] > maxim) {
            maxim = (size_t) obj.row_[i];
        }
    }
    for (size_t i = 0; i < Vector::vector_size(obj.column_); ++i) {
        if ((size_t) obj.column_[i] > maxim) {
            maxim = (size_t) obj.column_[i];
        }
    }
    return maxim;
}

//amount of !0
[[maybe_unused]] size_t CSRMatrix::amount_of_notz(CSRMatrix &obj) {
    return Vector::vector_size(obj.value_);
}

//matrix = matrix * numb
CSRMatrix CSRMatrix::operator*(double numb) const {
    Vector temp_vec(value_);
    temp_vec = temp_vec * numb;
    CSRMatrix res(row_, column_, temp_vec);
    return res;
}

//matrix = numb * matrix
CSRMatrix operator*(double numb, const CSRMatrix &obj) {
    Vector temp_vec(obj.value_);
    temp_vec = temp_vec * numb;
    CSRMatrix res(obj.row_, obj.column_, temp_vec);
    return res;
}

//vec = matrix * vec
Vector CSRMatrix::operator*(Vector &vec_obj) {
    if (Vector::max_element((this->column_) + 1) != Vector::vector_size(vec_obj)) {
        std::string msg1 = "Incompatible dimensions ( amount of columns in a matrix (";
        std::string msg2 = std::to_string(Vector::max_element((this->column_) + 1));
        std::string msg3 = ") != Vector.size = ";
        std::string msg4 = std::to_string(Vector::vector_size(vec_obj));
        std::string msg5 = " )";
        msg1.append(msg2);
        msg1.append(msg3);
        msg1.append(msg4);
        msg1.append(msg5);
        throw IncompatibleDimException(msg1);
    }
    Vector res_vec{};
    double sumy = 0;
    for (size_t i = 0; i < Vector::vector_size(vec_obj); ++i) {
        for (size_t j = 0; j < Vector::vector_size(row_); ++j) {
            if (row_[j] == (double) i) {
                sumy += (value_[j] * vec_obj[(int) column_[j]]);
            }
        }
        res_vec.push_back((double) sumy);
        sumy = 0;
    }
    return res_vec;
}

//vec = vec * matrix
/*
Vector operator*(Vector &vec_obj, CSRMatrix &matr_obj) {
    Vector res_vec{};
    double sumy = 0;
    for (size_t i = 0; i < Vector::vector_size(vec_obj); ++i) {
        for (size_t j = 0; j < Vector::vector_size(matr_obj.value_); ++j) {
            if (matr_obj.row_[j] == (double) i) {
                sumy += (matr_obj.value_[j] * vec_obj[(int) matr_obj.column_[j]]);
            }
        }
        res_vec.push_back((double) sumy);
        sumy = 0;
    }
    return res_vec;
}
*/
