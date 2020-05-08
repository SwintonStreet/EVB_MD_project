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
    public:
        keyWordVec() = default;
        ~keyWordVec() = default;

        keyWordVec&& operator=(keyWordVec&& inKWM) = delete;
        keyWordVec(keyWordVec&) = delete;
        keyWordVec(keyWordVec&&) = delete;
        keyWordVec& operator=(keyWordVec& inKWV)
        {
            kWM = inKWV.kWM;
            std::cout << "coping keywordvec now";
            print(std::cout);
            return *this;
        }

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
