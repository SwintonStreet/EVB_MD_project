#pragma once

#include <memory>
#include <stdexcept>

namespace utils
{
class fileAccess;
}

namespace reader
{
class keyWordVec;
} // namespace reader

namespace reader
{
constexpr static const char* fileName        = "SYS_CONFIG";
constexpr static const char* defaultFileName = "SYS_DEFAULT";

class configReadError : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

class keyWordReader
{
  public:
    keyWordReader();

    // exposed for testing
    explicit keyWordReader(std::shared_ptr<utils::fileAccess> fileAccess);

    keyWordVec defaultReader();

  private:
    std::shared_ptr<utils::fileAccess> fileAccess_;
};

} // namespace reader
