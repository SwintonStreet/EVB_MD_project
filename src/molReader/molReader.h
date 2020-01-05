// molecule class

#ifndef MOLREADER_H
#define MOLREADER_H

#include "iostream"
#include "sstream"
#include "string"
#include "vector"
#include "fstream"
#include "molecule.h"
#include "stdexcept"
#include "readlib.h"
#include "stdlib.h" // for the exit statement

class atom;
class twoAtomBonds;

class molReader
{
    constexpr static const char* defaultFileName = "SYS_MOLECULES";
    
    public:
    molReader() = default;

    // will read the SYS_MOLECULES file 
    [[nodiscard]] std::vector<molecule> MolConfReader() const;

    // read a single molecules config
    [[nodiscard]] molecule readSingleMol(std::ifstream&) const;

    // read an atom
    bool readAtom (std::string,
                   atom&,
                   std::string,
                   int,
                   int&) const;

    // read 2 atom bonds
    bool read2ABond(std::string&,
                    twoBonds_t&,
                    std::string,
                    int) const;
};

#endif // MOLREADER_H
