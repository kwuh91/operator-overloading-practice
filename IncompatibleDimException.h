#ifndef OPERATOR_INCOMPATIBLEDIMEXCEPTION_H
#define OPERATOR_INCOMPATIBLEDIMEXCEPTION_H

#include <iostream>

class IncompatibleDimException : std::exception {
private:
    std::string msg_;
public:
    //Initializing
    explicit IncompatibleDimException();

    //Initializing with a message
    explicit IncompatibleDimException(std::string);

    //Error output
    [[nodiscard]] const char *what() const noexcept override;

    //Destruct
    ~IncompatibleDimException() override = default;
};

#endif //OPERATOR_INCOMPATIBLEDIMEXCEPTION_H
