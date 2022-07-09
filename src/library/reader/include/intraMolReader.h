// intraMolReader Reeader class

#ifndef INTRAMOLREADER_H
#define INTRAMOLREADER_H

#include "readlib.h"

class intraMolBondDefs;

class intraMolReader
{
    constexpr static const char* defaultFileName{"SYS_INTRA_MOLECULES"};
    constexpr static const char* className{"intraMolReader"};

  public:
    intraMolReader()  = default;
    ~intraMolReader() = default;

    // read intra molecular bonds
    static bool readIntraMolDefReader();

  private:
    // read intra mol bond def
    static intraMolBondDefs readSingleIntraMolBondDef(std::ifstream& file);
};

#endif // INTRAMOLREADER_H
