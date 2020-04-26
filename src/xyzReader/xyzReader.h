
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
    constexpr static const char* defaultMolFile = "SYS_MOLECULES";
    constexpr static const char* defaultXyzFile = "SYS_XYZ";

    public:
    xyzReader() = default;
    ~xyzReader() = default;

    static void readAtom(const std::string&,atom&,int);
    static sys  readXyzFile(std::vector<molecule>&);

};
