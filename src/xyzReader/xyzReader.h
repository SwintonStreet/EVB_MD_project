#include "string"
#include "vector"
#include "molecule.h"
#include "atom.h"
#include "sys.h"

class xyzReader
{
    constexpr static const char* defaultMolFile = "SYS_MOLECULES";
    constexpr static const char* defaultXyzFile = "SYS_XYZ";
    constexpr static const char* className      = "xyzReader";

    public:
    xyzReader() = default;
    ~xyzReader() = default;

    static void readAtom(const std::string&,atom&,int);
    static sys  readXyzFile(std::vector<molecule>&);
};
