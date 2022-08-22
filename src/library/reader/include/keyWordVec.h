#ifndef KEYWORDVEC_H
#define KEYWORDVEC_H

#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <ostream>
#include <string>

class keyWord;

class keyWordVec
{
  public:
    keyWordVec() : kWM_{} {}
    ~keyWordVec() = default;

    keyWordVec&& operator=(keyWordVec&& inKWM) = delete;
    keyWordVec(const keyWordVec& inKWV) : kWM_(inKWV.kWM_){};
    keyWordVec(keyWordVec&& inKWV) : kWM_(std::move(inKWV.kWM_)){};
    keyWordVec& operator=(const keyWordVec& inKWV)
    {
        kWM_ = inKWV.kWM_;
        return *this;
    }

    bool containsKeyWord(const keyWord& inKw) const;
    bool containsKeyWord(const std::string& name, keyWord& inKw) const;

    bool addKeyWord(const keyWord& inKw, bool overWrite = false);

    std::optional<keyWord> at(const std::string& name) const;

    bool isOk() const;

    size_t size() const;

    void print() const;

  private:
    std::map<std::string, keyWord> kWM_;
    constexpr static const char*   className = "keyWordVec";
};

#endif // KEYWORDVEC_H
