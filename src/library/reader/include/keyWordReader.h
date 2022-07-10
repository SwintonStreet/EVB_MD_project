#ifndef KEYWORDREADER_H
#define KEYWORDREADER_H

class keyWordVec;

namespace keyWordReader
{
constexpr static const char* fileName        = "SYS_CONFIG";
constexpr static const char* defaultFileName = "SYS_DEFAULT";

keyWordVec defaultReader();

}; // namespace keyWordReader

#endif // KEYWORDREADER_H
