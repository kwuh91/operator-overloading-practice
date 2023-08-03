#include "IncompatibleDimException.h"

//Initializing
IncompatibleDimException::IncompatibleDimException() = default;

//Initializing with a message
IncompatibleDimException::IncompatibleDimException(std::string error_msg) : msg_(std::move(error_msg)) {}

//Error output
const char *IncompatibleDimException::what() const noexcept {
    return msg_.c_str();
}
