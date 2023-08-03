#include "OutOfRangeException.h"

//Initializing
OutOfRangeException::OutOfRangeException() = default;

//Initializing with a message
OutOfRangeException::OutOfRangeException(std::string error_msg) : msg_(std::move(error_msg)) {}

//Error output
const char *OutOfRangeException::what() const noexcept {
    return msg_.c_str();
}
