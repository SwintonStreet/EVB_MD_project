#ifndef KEYWORDVEC_H
#define KEYWORDVEC_H

#include "map"
#include "string"

class keyWord;

class keyWordVec
{
    private:
        std::map<std::string,keyWord> kWM;
    public:
        keyWordVec() = default;

        bool containsKeyWord(keyWord& inKw);
        bool containsKeyWord(const std::string& name,
                             keyWord&           inKw);

        bool addKeyWord(keyWord inKw,
                        bool    overWrite = false);

        bool isOk();

        unsigned int size();
};

#endif // KEYWORDVEC_H
