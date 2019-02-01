

#include "VectorLengthException.h"
#include <iostream>
#include <cstring>
#include <string>


VectorLengthException::VectorLengthException(string const& m) noexcept
        : exception(), msg(m)
{
}

VectorLengthException::~VectorLengthException() noexcept {
    msg.clear();
}

const char* VectorLengthException::what() const noexcept {
    return msg.c_str();
}