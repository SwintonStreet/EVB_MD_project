#ifndef KEYWORDREADER_H
#define KEYWORDREADER_H

class keyWordVec;

class keyWordReader
{
    constexpr static const char* fileName        = "SYS_CONFIG";
    constexpr static const char* defaultFileName = "SYS_DEFAULT";

    public:

    keyWordReader() = default;
    static bool defaultReader(keyWordVec& kwv);
};

#endif // KEYWORDREADER_H
