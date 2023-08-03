#include "Matrix.h"
#include <iostream>

int main() {
    size_t TEST = 1;
    //initializing
    Vector my_vec(10, 2);
    std::cout << "TEST " << TEST << std::endl;
    TEST++;
    std::cout << "vec:\n";
    std::cout << my_vec;

    //copy
    Vector copy(my_vec);
    std::cout << "\n\nTEST " << TEST;
    TEST++;
    std::cout << "\ncopy of vec:\n";
    std::cout << copy;

    //size
    std::cout << "\n\nTEST " << TEST;
    TEST++;
    std::cout << "\nsize of vec:\n";
    std::cout << Vector::vector_size(my_vec);

    //len
    std::cout << "\n\nTEST " << TEST;
    TEST++;
    std::cout << "\nlen of vec:\n";
    std::cout << Vector::vector_len(my_vec);

    //operators

    //=
    //vec = vec
    Vector vec4(0);
    vec4 = my_vec;
    std::cout << "\n\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 = vec2\n";
    std::cout << "vec2 = { " << my_vec << "}\n";
    std::cout << "vec1 = { " << vec4 << "}\n";

    //+=
    //vec += vec (1)
    Vector sum_vec0(10, 3);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 += vec2 (vec1.size == vec2.size)\n";
    std::cout << "vec1 (before) = { " << sum_vec0 << "}\n";
    std::cout << "vec2 = { " << vec4 << "}\n";
    sum_vec0 += vec4;
    std::cout << "vec1 (after) = { " << sum_vec0 << "}\n";

    //vec += vec (2)
    Vector sum_vec1(10, 4);
    Vector exp4(5, 7);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 += vec2 (vec1.size > vec2.size)\n";
    std::cout << "vec1 (before) = { " << sum_vec1 << "}\n";
    std::cout << "vec2 = { " << exp4 << "}\n";
    sum_vec1 += exp4;
    std::cout << "vec1 (after) = { " << sum_vec1 << "}\n";

    //vec += vec (3)
    Vector sum_vec4(5, 9);
    Vector exp5(10, 7);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 += vec2 (vec1.size < vec2.size)\n";
    std::cout << "vec1 (before) = { " << sum_vec4 << "}\n";
    std::cout << "vec2 = { " << exp5 << "}\n";
    sum_vec4 += exp5;
    std::cout << "vec1 (after) = { " << sum_vec4 << "}\n";

    //vec += numb
    Vector sum_vec5(10, 3);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec += numb\n";
    std::cout << "vec (before) = { " << sum_vec5 << "}\n";
    std::cout << "numb = " << 123 << "\n";
    sum_vec5 += 123;
    std::cout << "vec (after) = { " << sum_vec5 << "}\n";

    //+,++
    //vec = vec + vec (1)
    Vector sum_vec = my_vec + copy;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec3 = vec1 + vec2 (vec1.size == vec2.size)\n";
    std::cout << "vec1 = { " << my_vec << "}\n";
    std::cout << "vec2 = { " << copy << "}\n";
    std::cout << "vec3 = { " << sum_vec << "}\n";

    //vec = vec + vec (2)
    Vector exp(4, 3);
    Vector sum_vec2 = my_vec + exp;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec3 = vec1 + vec2 (vec1.size > vec2.size)\n";
    std::cout << "vec1 = { " << my_vec << "}\n";
    std::cout << "vec2 = { " << exp << "}\n";
    std::cout << "vec3 = { " << sum_vec2 << "}\n";

    //vec = vec + vec (3)
    Vector exp2(15, 3);
    Vector exp3(10, 2);
    Vector sum_vec3 = exp2 + exp3;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec3 = vec1 + vec2 (vec1.size < vec2.size)\n";
    std::cout << "vec1 = { " << exp2 << "}\n";
    std::cout << "vec2 = { " << exp3 << "}\n";
    std::cout << "vec3 = { " << sum_vec3 << "}\n";

    //vec = vec + numb
    Vector exp6(3, 3);
    Vector sum_vec6 = exp6 + 11;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 = vec2 + numb\n";
    std::cout << "vec2 = { " << exp6 << "}\n";
    std::cout << "numb = " << 11 << "\n";
    std::cout << "vec1 = { " << sum_vec6 << "}\n";

    //vec = numb + vec
    Vector exp7(6, 31);
    Vector sum_vec7 = 789 + exp7;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 = numb + vec2\n";
    std::cout << "vec2 = { " << exp7 << "}\n";
    std::cout << "numb = " << 789 << "\n";
    std::cout << "vec1 = { " << sum_vec7 << "}\n";

    //++vec
    Vector exp8(13, 7);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\n++vec\n";
    std::cout << "vec (before) = { " << exp8 << "}\n";
    ++exp8;
    std::cout << "vec (after) = { " << exp8 << "}\n";

    //vec++
    Vector exp9(13, 2);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec++\n";
    std::cout << "vec (before) = { " << exp9 << "}\n";
    exp9++;
    std::cout << "vec (after) = { " << exp9 << "}\n";

    //+vec
    Vector exp10(10, -3);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\n+vec\n";
    std::cout << "vec (before) = { " << exp10 << "}\n";
    +exp10;
    std::cout << "vec (after) = { " << exp10 << "}\n";

    //-,--
    //vec = vec - vec (1)
    Vector negvec1(10, 8);
    Vector negvec(10, 3);
    Vector sum_vec8 = negvec1 - negvec;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec3 = vec1 - vec2 (vec1.size == vec2.size)\n";
    std::cout << "vec1 = { " << negvec1 << "}\n";
    std::cout << "vec2 = { " << negvec << "}\n";
    std::cout << "vec3 = { " << sum_vec8 << "}\n";

    //vec = vec - vec (2)
    Vector negvec2(15, 8);
    Vector negvec3(10, 3);
    Vector sum_vec9 = negvec2 - negvec3;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec3 = vec1 - vec2 (vec1.size > vec2.size)\n";
    std::cout << "vec1 = { " << negvec2 << "}\n";
    std::cout << "vec2 = { " << negvec3 << "}\n";
    std::cout << "vec3 = { " << sum_vec9 << "}\n";

    //vec = vec - vec (3)
    Vector negvec4(10, 8);
    Vector negvec5(15, 3);
    Vector sum_vec10 = negvec4 - negvec5;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec3 = vec1 - vec2 (vec1.size < vec2.size)\n";
    std::cout << "vec1 = { " << negvec4 << "}\n";
    std::cout << "vec2 = { " << negvec5 << "}\n";
    std::cout << "vec3 = { " << sum_vec10 << "}\n";

    //vec = vec - numb
    Vector negvec6(15, 3);
    Vector sum_vec11 = negvec6 - 2;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 = vec2 - numb\n";
    std::cout << "vec2 = { " << negvec6 << "}\n";
    std::cout << "numb = " << 2 << "\n";
    std::cout << "vec1 = { " << sum_vec11 << "}\n";

    //--vec
    Vector negvec7(13, 7);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\n--vec\n";
    std::cout << "vec (before) = { " << negvec7 << "}\n";
    --negvec7;
    std::cout << "vec (after) = { " << negvec7 << "}\n";

    //vec--
    Vector negvec8(13, 9);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec--\n";
    std::cout << "vec (before) = { " << negvec8 << "}\n";
    negvec8--;
    std::cout << "vec (after) = { " << negvec8 << "}\n";

    //-vec
    Vector negvec9(10, 3);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\n-vec\n";
    std::cout << "vec (before) = { " << negvec9 << "}\n";
    -negvec9;
    std::cout << "vec (after) = { " << negvec9 << "}\n";

    //-=
    //vec -= vec (1)
    Vector sum_vec12(10, 3);
    Vector exp11(10, 1);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 -= vec2 (vec1.size == vec2.size)\n";
    std::cout << "vec1 (before) = { " << sum_vec12 << "}\n";
    std::cout << "vec2 = { " << exp11 << "}\n";
    sum_vec12 -= exp11;
    std::cout << "vec1 (after) = { " << sum_vec12 << "}\n";

    //vec -= vec (2)
    Vector sum_vec13(10, 3);
    Vector exp12(5, 1);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 -= vec2 (vec1.size > vec2.size)\n";
    std::cout << "vec1 (before) = { " << sum_vec13 << "}\n";
    std::cout << "vec2 = { " << exp12 << "}\n";
    sum_vec13 -= exp12;
    std::cout << "vec1 (after) = { " << sum_vec13 << "}\n";

    //vec -= vec (3)
    Vector sum_vec14(5, 3);
    Vector exp13(10, 1);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 -= vec2 (vec1.size < vec2.size)\n";
    std::cout << "vec1 (before) = { " << sum_vec14 << "}\n";
    std::cout << "vec2 = { " << exp13 << "}\n";
    sum_vec14 -= exp13;
    std::cout << "vec1 (after) = { " << sum_vec14 << "}\n";

    //vec -= numb
    Vector sum_vec15(10, 123);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec -= numb\n";
    std::cout << "vec (before) = { " << sum_vec15 << "}\n";
    std::cout << "numb = " << 90 << "\n";
    sum_vec15 -= 90;
    std::cout << "vec (after) = { " << sum_vec15 << "}\n";

    //*
    //vec = vec * vec (1)
    Vector vec_t1(10, 5);
    Vector vec_t2(10, 7);
    double times_vec1 = vec_t1 * vec_t2;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nnumb = vec1 * vec2 (vec1.size == vec2.size)\n";
    std::cout << "vec1 = { " << vec_t1 << "}\n";
    std::cout << "vec2 = { " << vec_t2 << "}\n";
    std::cout << "numb = " << times_vec1 << "\n";

    //vec = vec * vec (2)
    Vector vec_t3(10, 5);
    Vector vec_t4(5, 7);
    double times_vec2 = vec_t3 * vec_t4;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nnumb = vec1 * vec2 (vec1.size != vec2.size)\n";
    std::cout << "vec1 = { " << vec_t3 << "}\n";
    std::cout << "vec2 = { " << vec_t4 << "}\n";
    std::cout << "numb = " << times_vec2 << "\n";

    //vec = matrix * vec
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 = matrix * vec2\n";
    Vector vec2{1, 2, -1};
    Vector row1{0, 0, 0, 1, 1, 1, 2, 2, 2};
    Vector column1{0, 1, 2, 0, 1, 2, 0, 1, 2};
    Vector value1{2, 4, 0, -2, 1, 3, -1, 0, 1};
    CSRMatrix matr(row1, column1, value1);
    std::cout << "vec2 = { " << vec2 << "}\n";
    std::cout << "matrix:\n";
    std::cout << matr;
    Vector vec1 = matr * vec2;
    std::cout << "vec1 = { " << vec1 << "}\n";

    //vec = matrix * vec (Incompatible dimensions)
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 = matrix * vec2 (Incompatible dimensions)\n";
    Vector vec2_{1, 2};
    Vector row1_{0, 0, 0, 1, 1, 1, 2, 2, 2};
    Vector column1_{0, 1, 2, 0, 1, 2, 0, 1, 2};
    Vector value1_{2, 4, 0, -2, 1, 3, -1, 0, 1};
    try {
        CSRMatrix matr_(row1_, column1_, value1_);
        std::cout << "vec2 = { " << vec2_ << "}\n";
        std::cout << "matrix:\n";
        std::cout << matr_;
        Vector vec1_ = matr_ * vec2_;
        std::cout << "vec1 = { " << vec1_ << "}\n";
    }
    catch (IncompatibleDimException &e) {
        std::cout << "Exception caught:\n";
        std::cout << e.what() << std::endl;
    }

    //vec = vec * matrix
    /*
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 = vec2 * matrix\n";
    Vector vec2_1{1, 3, -4};
    Vector row1_1{0, 0, 0, 1, 1, 1, 2, 2, 2};
    Vector column1_1{0, 1, 2, 0, 1, 2, 0, 1, 2};
    Vector value1_1{0, 1, 0, -2, 0, 0, 0, 0, 3};
    CSRMatrix matr_1(row1_1, column1_1, value1_1);
    std::cout << "vec2 = { " << vec2_1 << "}\n";
    std::cout << "matrix:\n";
    std::cout << matr_1;
    Vector vec1_1 = vec2_1 * matr_1;
    std::cout << "vec1 = { " << vec1_1 << "}\n";
    */

    //vec = vec * numb
    Vector vec_t5(10, 5);
    Vector times_vec3 = vec_t5 * 8;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 = vec2 * numb\n";
    std::cout << "vec2 = { " << vec_t5 << "}\n";
    std::cout << "numb = " << 8 << "\n";
    std::cout << "vec1 = { " << times_vec3 << "}\n";

    //vec = numb * vec
    Vector vec_t6(10, 5);
    Vector times_vec4 = 71 * vec_t6;
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec1 = numb * vec2\n";
    std::cout << "vec2 = { " << vec_t6 << "}\n";
    std::cout << "numb = " << 71 << "\n";
    std::cout << "vec1 = { " << times_vec4 << "}\n";

    //[]
    Vector VEC{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec[]\n";
    std::cout << "vec = { " << VEC << "}\n";
    for (size_t i = 0; i < Vector::vector_size(VEC); ++i) std::cout << "vec[" << i << "] = " << VEC[(int) i] << "; ";
    std::cout << std::endl;

    //[] out of range
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nvec[100] (out of range)\n";
    std::cout << "vec = { " << VEC << "}\n";
    try {
        std::cout << VEC[100] << std::endl;
    }
    catch (OutOfRangeException &e) {
        std::cout << "Exception caught:\n";
        std::cout << e.what() << std::endl;
    }

    //<<, >>
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nWould you like to create your own vector? (Y/N)\n";
    char choice;
    std::cin >> choice;
    switch (choice) {
        case 'Y': {
            std::cout << "Enter your vector:\n";
            Vector cinvec(0);
            std::cin >> cinvec;
            std::cout << "Your vector:\n";
            std::cout << cinvec;
            break;
        }
        case 'N': {
            std::cout << "Skipped\n";
            break;
        }
        default: {
            std::cout << "Invalid input\n";
            break;
        }
    }

    //difficult test
    std::cout << "\nTEST " << TEST;
    TEST++;
    double numb1 = 7;
    Vector vecc2(7, 8);
    double numb2 = 12;
    Vector vecc3(9, 9);
    Vector vecc4(3, 4);
    double numb3 = 78;
    Vector vecc1 = -numb1 * (vecc2 - numb2 * vecc3) + vecc4 * numb3;
    std::cout << "\nvec1 = -numb1 * (vec2 - numb2 * vec3) + vec4 * numb3\n";
    std::cout << "numb1 = " << 7 << "\n";
    std::cout << "vec2 = { " << vecc2 << "}\n";
    std::cout << "numb2 = " << 12 << "\n";
    std::cout << "vec3 = { " << vecc3 << "}\n";
    std::cout << "vec4 = { " << vecc4 << "}\n";
    std::cout << "numb3 = " << 78 << "\n";
    std::cout << "vec4 = { " << vecc4 << "}\n";
    std::cout << "vec1 = { " << vecc1 << "}\n";

    //difficult test 2
    std::cout << "\nTEST " << TEST;
    TEST++;
    double numb1_ = 7;
    Vector vecc2_(7, 8);
    double numb2_ = 12;
    Vector vecc3_(9, 9);
    Vector vecc4_(3, 4);
    double numb3_ = 78;

    Vector row_{0, 0, 1, 1, 3, 3, 0};
    Vector column_{2, 4, 2, 3, 1, 2, 8};
    Vector value_{3, 4, 5, 7, 2, 6, 11};

    CSRMatrix matr1_(row_, column_, value_);
    matr1_ = -numb1_ * matr1_;
    Vector vecc1_ = (vecc2_ - numb2_ * vecc3_);
    try {
        vecc1_ = matr1_ * vecc1_;
    }
    catch (IncompatibleDimException &e) {
        std::cout << e.what() << std::endl;
    }
    vecc1_ = vecc1_ + vecc4_ * numb3_;
    std::cout << "\nvec1 = -numb1 * matr * (vec2 - numb2 * vec3) + vec4 * numb3\n";
    std::cout << "matr:\n";
    std::cout << matr1_;
    std::cout << "numb1 = " << numb1_ << "\n";
    std::cout << "vec2 = { " << vecc2_ << "}\n";
    std::cout << "numb2 = " << numb2_ << "\n";
    std::cout << "vec3 = { " << vecc3_ << "}\n";
    std::cout << "vec4 = { " << vecc4_ << "}\n";
    std::cout << "numb3 = " << numb3_ << "\n";
    std::cout << "vec4 = { " << vecc4_ << "}\n";
    std::cout << "vec1 = { " << vecc1_ << "}\n";

    //matrix initializing
    Vector row{0, 0, 1, 1, 3, 3};
    Vector column{2, 4, 2, 3, 1, 2};
    Vector value{3, 4, 5, 7, 2, 6};

    CSRMatrix matr1(row, column, value);
    std::cout << "\nTEST " << TEST;
    TEST++;
    std::cout << "\nMATRIX(vec1,vec2,vec3)\n";
    std::cout << "vec1 = { " << row << "}\n";
    std::cout << "vec2 = { " << column << "}\n";
    std::cout << "vec3 = { " << value << "}\n";
    std::cout << "MATRIX:\n";
    std::cout << matr1;

    //matrix input
    std::cout << "\nTEST " << TEST;
    //TEST++;
    char choice1;
    std::cout << "\nWould you like to create your own matrix? (Y/N)\n";
    std::cin >> choice1;
    switch (choice1) {
        case 'Y': {
            std::cout << "Enter your matrix:\n";
            CSRMatrix obj;
            try {
                std::cin >> obj;
                std::cout << "Your matrix:\n";
                std::cout << obj;
            }
            catch (OutOfRangeException &e) {
                std::cout << "Exception caught:\n";
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 'N': {
            std::cout << "Skipped\n";
            break;
        }
        default: {
            std::cout << "Invalid input\n";
            break;
        }
    }
    return 0;
}
