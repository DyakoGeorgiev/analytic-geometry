

#include "EqualPointException.h"
#include <iostream>
#include <cstring>

EqualPointException::EqualPointException(string const& m) noexcept
        : exception(), msg(m)
{
}

EqualPointException::~EqualPointException() noexcept {
    msg.clear();
}

const char* EqualPointException::what() const noexcept {
    return msg.c_str();
}
