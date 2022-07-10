#ifndef KEYWORDVEC_H
#define KEYWORDVEC_H

#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <string>

class keyWord;

class keyWordVec
{
  public:
    keyWordVec() : kWM{} {}
    ~keyWordVec() = default;

    keyWordVec&& operator=(keyWordVec&& inKWM) = delete;
    keyWordVec(const keyWordVec& inKWV) : kWM(inKWV.kWM){};
    keyWordVec(keyWordVec&& inKWV) : kWM(std::move(inKWV.kWM)){};
    keyWordVec& operator=(const keyWordVec& inKWV)
    {
        kWM = inKWV.kWM;
        return *this;
    }

    bool containsKeyWord(const keyWord& inKw) const;
    bool containsKeyWord(const std::string& name, keyWord& inKw);

    bool addKeyWord(const keyWord& inKw, bool overWrite = false);

    bool isOk() const;

    size_t size() const;

    void print() const;

  private:
    std::map<std::string, keyWord, std::less<>> kWM;
    constexpr static const char*                className = "keyWordVec";
};

#endif // KEYWORDVEC_H
