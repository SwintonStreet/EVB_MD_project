#ifndef KEYWORDVEC_H
#define KEYWORDVEC_H

#include "map"
#include "string"
#include "ostream"

class keyWord;

class keyWordVec
{
    private:
        std::map<std::string,keyWord> kWM;
    public:
        keyWordVec() = default;

        bool containsKeyWord(const keyWord& inKw) const;
        bool containsKeyWord(const std::string& name,
                             keyWord&           inKw);

        bool addKeyWord(const keyWord& inKw,
                        bool           overWrite = false);

        bool isOk() const;

        unsigned int size() const;

        void print(std::ostream& out) const;
};

#endif // KEYWORDVEC_H
