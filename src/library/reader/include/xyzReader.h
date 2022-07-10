#include <string>

#include "atom.h"
#include "molecule.h"
#include "sys.h"

class xyzReader
{
    constexpr static const char* defaultMolFile = "SYS_MOLECULES";
    constexpr static const char* defaultXyzFile = "SYS_XYZ";
    constexpr static const char* className      = "xyzReader";

  public:
    xyzReader()  = default;
    ~xyzReader() = default;

    static void readAtom(const std::string&, atom&, size_t);
    static sys  readXyzFile(std::vector<molecule>&);
};
