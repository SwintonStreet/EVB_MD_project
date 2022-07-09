// molecule Reader class

#ifndef MOLREADER_H
#define MOLREADER_H

#include "fstream"
#include "iostream"
#include "molecule.h"
#include "readlib.h"
#include "sstream"
#include "stdexcept"
#include "stdlib.h" // for the exit statement
#include "string"
#include "vector"

class atom;
class twoAtomBonds;

class molReader
{
    constexpr static const char* defaultFileName{"SYS_MOLECULES"};
    constexpr static const char* className{"molReader"};

  public:
    molReader() = default;

    // will read the SYS_MOLECULES file
    [[nodiscard]] static std::vector<molecule> MolConfReader();

    // read a single molecules config
    [[nodiscard]] static molecule readSingleMol(std::ifstream&);

    // read an atom
    static bool
    readAtom(const std::string&, atom&, const std::string&, int, int&);

    // read 2 atom bonds
    static bool
    read2ABond(const std::string&, twoBonds_t&, const std::string&, int);
};

#endif // MOLREADER_H
