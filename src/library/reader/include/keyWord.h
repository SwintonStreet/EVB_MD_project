#pragma once

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "keyWordVec.h"
#include "keyWordsList.h"

class keyWord
{
    std::string name;
    bool        isOk{true};
    bool        isDefault{true};
    int         intValue{0};
    double      douValue{0};
    bool        booValue{true};
    std::string sValue;
    char        Type{'?'};

  public:
    keyWord(std::string_view, int);
    keyWord(std::string_view, double);
    keyWord(std::string_view, bool);
    keyWord(std::string_view, std::string_view);
    explicit keyWord(const keyWordsList::keyWordDefault&);

    keyWord()  = default;
    ~keyWord() = default;

    void setValue(int);
    void setValue(double);
    void setValue(bool);

    [[nodiscard]] int         getInt() const;
    [[nodiscard]] double      getDou() const;
    [[nodiscard]] bool        getBoo() const;
    [[nodiscard]] std::string getString() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] bool        getOk() const;

    [[nodiscard]] const char& getType() const { return Type; };

    [[nodiscard]] bool getDef() const { return isDefault; };

    // copy constructor
    keyWord(const keyWord& kW) noexcept = default;

    // copy assignment operator
    keyWord& operator=(const keyWord& kW) noexcept
    {
        if (this != &kW)
        {
            name      = kW.name;
            Type      = kW.Type;
            intValue  = kW.intValue;
            douValue  = kW.douValue;
            booValue  = kW.booValue;
            sValue    = kW.sValue;
            isOk      = kW.isOk;
            isDefault = kW.isDefault;
        }

        return *this;
    }

    // move assignment operator
    keyWord& operator=(keyWord&& kW) noexcept
    {
        name      = std::move(kW.name);
        Type      = kW.Type;
        intValue  = kW.intValue;
        douValue  = kW.douValue;
        booValue  = kW.booValue;
        sValue    = std::move(kW.sValue);
        isOk      = kW.isOk;
        isDefault = kW.isDefault;

        return *this;
    }

    static keyWord getKeyWord(keyWordVec&        kwv,
                              const std::string& keyName,
                              bool               mandatory = false);

    bool operator==(const keyWord& rhs) const
    {
        return name == rhs.name && Type == rhs.Type &&
               intValue == rhs.intValue && douValue == rhs.douValue &&
               booValue == rhs.booValue && sValue == rhs.sValue &&
               isOk == rhs.isOk && isDefault == rhs.isDefault;
    }

    friend std::ostream& operator<<(std::ostream& os, const keyWord& kW)
    {
        return os << kW.name << '\n'
                  << "INT: " << kW.intValue << '\n'
                  << "DOUBLE: " << kW.douValue << '\n'
                  << "BOOLEAN: " << (kW.booValue ? 'Y' : 'N') << '\n'
                  << "STRING: " << kW.sValue;
    }
};
