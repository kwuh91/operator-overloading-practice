#ifndef OPERATOR_OUTOFRANGEEXCEPTION_H
#define OPERATOR_OUTOFRANGEEXCEPTION_H

#include <iostream>

class OutOfRangeException : std::exception {
private:
    std::string msg_;
public:
    //Initializing
    explicit OutOfRangeException();

    //Initializing with a message
    explicit OutOfRangeException(std::string);

    //Error output
    [[nodiscard]] const char *what() const noexcept override;

    //Destruct
    ~OutOfRangeException() override = default;
};

#endif //OPERATOR_OUTOFRANGEEXCEPTION_H
