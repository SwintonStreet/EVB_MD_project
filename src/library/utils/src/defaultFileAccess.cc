#include "defaultFileAccess.h"

#include <fstream>
#include <string>

using std::getline;
using std::nullopt;
using std::optional;
using std::string;

namespace utils
{

defaultFileAccess::defaultFileAccess(const string& path) :
    fileName_{path}, fileHandle_{path}
{
}

string defaultFileAccess::getFileName() { return fileName_; }

optional<string> defaultFileAccess::getLine()
{
    string line;

    getline(fileHandle_, line);

    if (line.empty())
    {
        return nullopt;
    }
    else
    {
        return line;
    }
}

} // namespace utils
