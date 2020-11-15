// intraMolReader Reeader class

#ifndef INTRAMOLREADER_H
#define INTRAMOLREADER_H

#include "iostream"
#include "sstream"
#include "string"
#include "vector"
#include "fstream"
#include "molecule.h"
#include "stdexcept"
#include "readlib.h"
#include "stdlib.h" // for the exit statement

class intraMolReader
{
    constexpr static const char* defaultFileName {"SYS_INTRA_MOLECULES"};
    constexpr static const char* className       {"intraMolReader"};

    public:
    intraMolReader()  = default;
    ~intraMolReader() = default;

    // read intra molecular bonds
    static bool readIntraMolReader();
};

#endif // INTRAMOLREADER_H
