// Reader class header

#ifndef READLIB_H
#define READLIB_H

#include "iostream"
#include "string"
#include "stdexcept"

class readlib
{
    public:
    static bool   readBOO(std::string,std::string);
    static int    readINT(std::string,std::string);
    static double readDOU(std::string,std::string);
};



#endif // READLIB_H
