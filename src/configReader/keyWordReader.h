
#ifndef KEYWORDREADER_H
#define KEYWORDREADER_H

#include "iostream"
//#include "keyWords.h"
#include "keyWord.h"
#include "fstream"
#include "string"
#include "sstream"
#include "cstring"
#include "stdio.h"
#include <vector>
#include "memory"
#include "stdexcept"
#include "readlib.h"

class keyWordReader
{
    constexpr static const char* fileName        = "SYS_CONFIG";
    constexpr static const char* defaultFileName = "SYS_DEFAULT";

    public:

    keyWordReader();
    bool defaultReader(keyWordVec& kwv) const;

    [[nodiscard]]
    std::string errorString(const std::string& name,
                            int                lineNumber) const;

};

#endif // KEYWORDREADER_H
