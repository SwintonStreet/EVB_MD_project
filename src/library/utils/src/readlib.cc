#include "readlib.h"

#include <iostream>
#include <stdexcept>
#include <string>

using std::cerr;
using std::invalid_argument;
using std::string;

bool readlib::readBOO(const string& word, const string& errorText)
{
    bool outBool;
    try
    {
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
                throw errorText;
            }
        }
        else
        {
            throw errorText;
        }
    }
    catch (const string& err)
    {
        cerr << err;
        exit(1);
    }

    return outBool;
}

int readlib::readINT(const string& word, const string& errorText)
{
    int outInt;
    try
    {
        try
        {
            outInt = stoi(word);
        }
        catch (const invalid_argument&)
        {
            throw errorText;
        }
    }
    catch (const string& err)
    {
        cerr << err;
        exit(1);
    }

    return outInt;
}

size_t readlib::readSIZE_T(const string& word, const string& errorText)
{
    return static_cast<size_t>(readINT(word, errorText));
}

double readlib::readDOU(const string& word, const string& errorText)
{
    double outDoub;
    try
    {
        try
        {
            outDoub = stod(word);
        }
        catch (const invalid_argument&)
        {
            throw errorText;
        }
    }
    catch (const string& err)
    {
        cerr << err;
        exit(1);
    }

    return outDoub;
}
