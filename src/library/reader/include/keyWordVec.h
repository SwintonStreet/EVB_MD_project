#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace reader
{
class keyWord;
} // namespace reader

namespace reader
{

class keyWordVec
{
  public:
    keyWordVec() = default;

    ~keyWordVec() = default;

    keyWordVec&& operator=(keyWordVec&& inKWM) = delete;
    keyWordVec(const keyWordVec& inKWV)        = default;
    ;
    keyWordVec(keyWordVec&& inKWV) noexcept : kWM_(std::move(inKWV.kWM_)){};

    keyWordVec& operator=(const keyWordVec& inKWV) = default;

    [[nodiscard]] bool containsKeyWord(const keyWord& inKw) const;
    bool containsKeyWord(const std::string& name, keyWord& inKw) const;

    bool addKeyWord(const keyWord& inKw, bool overWrite = false);

    [[nodiscard]] std::optional<keyWord> at(const std::string& name) const;

    [[nodiscard]] bool isOk() const;

    [[nodiscard]] size_t size() const;

    void print() const;

  private:
    std::map<std::string, keyWord> kWM_;
    constexpr static const char*   className = "keyWordVec";
};

} // namespace reader
