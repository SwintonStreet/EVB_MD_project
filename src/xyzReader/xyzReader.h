
#include "iostream"
#include "sstream"
#include "string"
#include "vector"
#include "fstream"
#include "molecule.h"
#include "atom.h"
#include "stdexcept"
#include "readlib.h"
#include "sys.h"
#include "stdlib.h"



class xyzReader
{
    const char* defaultMolFile = "SYS_MOLECULES";
    const char* defaultXyzFile = "SYS_XYZ";

    public:
    xyzReader() = default;

    void readAtom(const std::string&,atom&,int);
    sys  readXyzFile(std::vector<molecule>&);

};
