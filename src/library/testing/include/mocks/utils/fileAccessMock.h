#pragma once

#include <gmock/gmock.h>

#include "fileAccess.h"

namespace testing
{
namespace utils
{

class fileAccessMock : public ::utils::fileAccess
{

  public:
    MOCK_METHOD((std::optional<std::string>), getLine, (), (override));
    MOCK_METHOD((std::string), getFileName, (), (override));
};

} // namespace utils
} // namespace testing
