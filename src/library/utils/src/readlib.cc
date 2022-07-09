#include "readlib.h"

bool readlib::readBOO(const std::string& word, const std::string& errorText)
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
    catch (const std::string& err)
    {
        std::cerr << err;
        exit(1);
    }

    return outBool;
}

int readlib::readINT(const std::string& word, const std::string& errorText)
{
    int outInt;
    try
    {
        try
        {
            outInt = std::stoi(word);
        }
        catch (const std::invalid_argument&)
        {
            throw errorText;
        }
    }
    catch (const std::string& err)
    {
        std::cerr << err;
        exit(1);
    }

    return outInt;
}

double readlib::readDOU(const std::string& word, const std::string& errorText)
{
    double outDoub;
    try
    {
        try
        {
            outDoub = std::stod(word);
        }
        catch (const std::invalid_argument&)
        {
            throw errorText;
        }
    }
    catch (const std::string& err)
    {
        std::cerr << err;
        exit(1);
    }

    return outDoub;
}
