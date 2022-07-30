#pragma once

#include <fstream>
#include <string>

#include "fileAccess.h"

namespace utils
{

class defaultFileAccess : public fileAccess
{
  public:
    explicit defaultFileAccess(const std::string& path);

    std::optional<std::string> getLine() override;
    std::string                getFileName() override;

  private:
    const std::string fileName_;
    std::ifstream     fileHandle_;
};
} // namespace utils
