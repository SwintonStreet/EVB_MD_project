// Reader class header
#ifndef READLIB_H
#define READLIB_H

#include <string>

struct readlib
{
    static bool   readBOO(const std::string&, const std::string&);
    static int    readINT(const std::string&, const std::string&);
    static size_t readSIZE_T(const std::string&, const std::string&);
    static double readDOU(const std::string&, const std::string&);
};

#endif // READLIB_H
