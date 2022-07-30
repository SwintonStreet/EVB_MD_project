#pragma once

#include <optional>
#include <string>

namespace utils
{

class fileAccess
{
  public:
    virtual ~fileAccess() = default;

    virtual std::optional<std::string> getLine()     = 0;
    virtual std::string                getFileName() = 0;
};
} // namespace utils
