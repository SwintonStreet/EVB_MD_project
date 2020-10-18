#ifndef KEYWORDVEC_H
#define KEYWORDVEC_H

#include "map"
#include "string"
#include "ostream"
#include "iostream"

class keyWord;

class keyWordVec
{
    private:
        std::map<std::string,keyWord> kWM;
        constexpr static const char* className = "keyWordVec";
    public:
        keyWordVec(): kWM{}
        {
        }
        ~keyWordVec() = default;

        keyWordVec&& operator=(keyWordVec&& inKWM) = delete;
        keyWordVec(const keyWordVec& inKWV): kWM(inKWV.kWM) {};
        keyWordVec(keyWordVec&&) = delete;
        keyWordVec& operator=(const keyWordVec& inKWV)
        {
            kWM = inKWV.kWM;
            return *this;
        }

        bool containsKeyWord(const keyWord& inKw) const;
        bool containsKeyWord(const std::string& name,
                             keyWord&           inKw);

        bool addKeyWord(const keyWord& inKw,
                        bool           overWrite = false);

        bool isOk() const;

        unsigned int size() const;

        void print() const;

};

#endif // KEYWORDVEC_H
