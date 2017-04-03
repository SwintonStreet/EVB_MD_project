
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
    const char* fileName        = "SYS_CONFIG";
    const char* defaultFileName = "SYS_DEFAULT";

    public:

    keyWordReader();
    bool defaultReader(keyWordVec& kwv);

};

#endif // KEYWORDREADER_H
