// Reader class header
#ifndef READLIB_H
#define READLIB_H

#include <stdexcept>
#include <string>

class readLib_error : public std::runtime_error
{
    using runtime_error::runtime_error;
};

namespace readlib
{

bool   readBOO(const std::string&, const std::string&);
int    readINT(const std::string&, const std::string&);
size_t readSIZE_T(const std::string&, const std::string&);
double readDOU(const std::string&, const std::string&);

}; // namespace readlib

#endif // READLIB_H
