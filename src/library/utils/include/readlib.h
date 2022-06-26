// Reader class header

#ifndef READLIB_H
#define READLIB_H

#include "iostream"
#include "string"
#include "stdexcept"

class readlib
{
    public:
    static bool   readBOO(const std::string&,
                          const std::string&);
    static int    readINT(const std::string&,
                          const std::string&);
    static double readDOU(const std::string&,
                          const std::string&);
};



#endif // READLIB_H
