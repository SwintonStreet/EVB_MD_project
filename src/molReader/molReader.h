
#include "iostream"
#include "sstream"
#include "string"
#include "vector"
#include "fstream"
#include "molecule.h"
#include "twoAtomBonds.h"
#include "atom.h"
#include "stdexcept"
#include "readlib.h"
#include "stdlib.h" // for the exit statement

class molReader
{
    const char* defaultFileName = "SYS_MOLECULES";
    
    public:
    molReader();


    // will read the SYS_MOLECULES file 
    std::vector<molecule> MolConfReader();
    // read a single molecules config
    molecule readSingleMol(std::ifstream&);
    // read an atom
    bool readAtom (std::string,
                   atom&,
                   std::string,
                   int,
                   int&);
    // read 2 atom bonds
    bool read2ABond(std::string&,
                    twoBonds_t&,
                    std::string,
                    int);
};
