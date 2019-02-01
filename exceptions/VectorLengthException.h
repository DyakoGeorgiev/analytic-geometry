
#ifndef  _VECTORLENGTHEXCEPTION_H
#define _VECTORLENGTHEXCEPTION_H


#include <exception>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class VectorLengthException:public std::exception {
public:
    VectorLengthException(string const&) throw();
    virtual ~VectorLengthException() throw();
    virtual const char* what() const throw();
private:
    string msg;
};
#endif // ! _VECTORLENGTHEXCEPTION_H
