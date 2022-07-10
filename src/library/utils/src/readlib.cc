#include "readlib.h"

#include <iostream>
#include <stdexcept>
#include <string>

using std::invalid_argument;
using std::string;

namespace readlib
{

bool readBOO(const string& word, const string& errorText)
{
    bool outBool{false};
    if (word.length() == 1)
    {
        if (word[0] == 'Y')
        {
            outBool = true;
        }
        else if (word[0] == 'N')
        {
            outBool = false;
        }
        else
        {
            throw readLib_error(errorText);
        }
    }
    else
    {
        throw readLib_error(errorText);
    }

    return outBool;
}

int readINT(const string& word, const string& errorText)
{
    int outInt{0};
    try
    {
        outInt = stoi(word);
    }
    catch (const invalid_argument& /*ia*/)
    {
        throw readLib_error(errorText);
    }

    return outInt;
}

size_t readSIZE_T(const string& word, const string& errorText)
{
    return static_cast<size_t>(readINT(word, errorText));
}

double readDOU(const string& word, const string& errorText)
{
    double outDoub{0.0};
    try
    {
        outDoub = stod(word);
    }
    catch (const invalid_argument& /*ia*/)
    {
        throw readLib_error(errorText);
    }

    return outDoub;
}
} // namespace readlib
