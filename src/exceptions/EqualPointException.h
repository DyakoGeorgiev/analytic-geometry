
#ifndef PROJECTLINEARALGEBRA_EQUALPOINTEXCEPTION_H
#define PROJECTLINEARALGEBRA_EQUALPOINTEXCEPTION_H

#include <exception>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
class EqualPointException : public exception
{
public:
    EqualPointException(string const&) throw() ;
    virtual const char* what() const throw() ;
    virtual ~EqualPointException() throw();
private:
    string msg;
};

#pragma once
#endif //PROJECTLINEARALGEBRA_EQUALPOINTEXCEPTION_H
