#include <memory>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "fileAccess.h"
#include "keyWord.h"
#include "keyWordReader.h"
#include "keyWordVec.h"
#include "mocks/utils/fileAccessMock.h"

using std::make_shared;
using std::nullopt;
using std::optional;
using std::string;
using std::string_view;
using std::stringstream;

using testing::utils::fileAccessMock;

using reader::keyWordReader;

using namespace std::string_literals;

using namespace ::testing;

namespace
{

using reader_variant = std::variant<int, double, bool, string>;

enum class reader_type
{
    INT,
    DOUBLE,
    BOOLEAN,
    STRING,
};

template <typename T> reader_type toReaderType(const T& /*var*/)
{

    if constexpr (std::is_same<int, T>::value)
    {
        return reader_type::INT;
    }
    else if constexpr (std::is_same<double, T>::value)
    {
        return reader_type::DOUBLE;
    }
    else if constexpr (std::is_same<bool, T>::value)
    {
        return reader_type::BOOLEAN;
    }
    else if constexpr (std::is_same<string, T>::value)
    {
        return reader_type::STRING;
    }

    throw std::runtime_error("Failed to determine the reader type");
};

template <typename T> char toReaderChar(const T& /*var*/)
{

    if constexpr (std::is_same<int, T>::value)
    {
        return 'I';
    }
    else if constexpr (std::is_same<double, T>::value)
    {
        return 'D';
    }
    else if constexpr (std::is_same<bool, T>::value)
    {
        return 'B';
    }
    else if constexpr (std::is_same<string, T>::value)
    {
        return 'S';
    }

    throw std::runtime_error("Failed to determine the reader type");
};

struct testCase
{
    const string         key;
    const string         line;
    const reader_type    vtype;
    const reader_variant data;
    const reader_variant expectedData;

    template <typename T>
    string generateLine(string_view key_view, const T& val) const
    {

        stringstream ss;

        ss << toReaderChar(val) << ' ' << key_view << ' ' << val;
        return ss.str();
    }

    string generateLine(string_view key_view, const bool& val) const
    {

        stringstream ss;

        ss << toReaderChar(val) << ' ' << key_view << ' ' << (val ? 'Y' : 'N');
        return ss.str();
    }

    keyWord toKeyWord() const
    {
        if (vtype == reader_type::INT)
        {
            return keyWord(key, std::get<int>(expectedData));
        }
        else if (vtype == reader_type::DOUBLE)
        {
            return keyWord(key, std::get<double>(expectedData));
        }
        else if (vtype == reader_type::BOOLEAN)
        {
            return keyWord(key, std::get<bool>(expectedData));
        }
        else if (vtype == reader_type::STRING)
        {
            return keyWord(key, std::get<string>(expectedData));
        }

        throw std::runtime_error("Failed to determine the reader type");
    };

    template <typename T>
    testCase(string_view key, const T& val) :
        key{key}, line{generateLine(key, val)}, vtype{toReaderType(val)},
        data{val}, expectedData{val}
    {
    }

    template <typename T>
    testCase(string_view key, const T& val, const T& expectedVal) :
        key{key}, line{generateLine(key, val)}, vtype{toReaderType(val)},
        data{val}, expectedData{expectedVal}
    {
    }
};

TEST(readConfigTests, CanReadValues)
{
    auto          fileAccess_ = make_shared<StrictMock<fileAccessMock>>();
    keyWordReader keyWordsReader(fileAccess_);

    const std::vector<testCase> testCases{
        {"key0", 10},
        {"key1", 0},
        {"key2", -657},
        {"key3", 10.5},
        {"key4", 0},
        {"key5", -7.9},
        {"key6", false},
        {"key7", true},
        {"key8", "any old value"s},
        {"key9", "# any old value with comments"s},
        {"key10", "any old    value"s, "any old value"s},
    };

    size_t index{0};
    auto   generateLines = [&]
    {
        optional<string> ret = nullopt;
        if (index < testCases.size())
        {
            ret = testCases[index].line;
        }
        ++index;
        return ret;
    };
    EXPECT_CALL(*fileAccess_, getLine())
        .Times(static_cast<int>(testCases.size()) + 1)
        .WillRepeatedly(InvokeWithoutArgs(generateLines));

    const auto kw = keyWordsReader.defaultReader();

    EXPECT_TRUE(kw.size() == testCases.size());

    for (const auto& testCase : testCases)
    {
        EXPECT_EQ(kw.at(testCase.key), testCase.toKeyWord());
    }
    EXPECT_EQ(kw.at("garbage"), nullopt);
}

TEST(readConfigTests, ThrowsOnGarbage)
{
    auto          fileAccess_ = make_shared<StrictMock<fileAccessMock>>();
    keyWordReader keyWordsReader(fileAccess_);

    EXPECT_CALL(*fileAccess_, getLine()).WillOnce(Return("garbage"s));
    EXPECT_CALL(*fileAccess_, getFileName()).WillOnce(Return("TestFile"s));

    EXPECT_THROW(keyWordsReader.defaultReader(), reader::configReadError);
}

TEST(readConfigTests, IgnoresEmptyAndCommentLines)
{
    auto          fileAccess_ = make_shared<StrictMock<fileAccessMock>>();
    keyWordReader keyWordsReader(fileAccess_);

    EXPECT_CALL(*fileAccess_, getLine())
        .WillOnce(Return(""s))
        .WillOnce(Return("              "s))
        .WillOnce(Return("# some comment"s))
        .WillOnce(Return(nullopt));

    const auto kw = keyWordsReader.defaultReader();

    EXPECT_TRUE(kw.size() == 0);
    EXPECT_EQ(kw.at("key0"), nullopt);
}

} // namespace

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
