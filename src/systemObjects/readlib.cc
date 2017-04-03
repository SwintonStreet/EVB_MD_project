#include "readlib.h"

bool readlib::readBOO(std::string word,
                      std::string errorText)
{
    bool outBool;
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
            std::cerr << errorText;
            throw;
        }
    }
    else
    {
        std::cerr << errorText;
        throw;
    }

    std::cerr.clear();
    return outBool;
}

int readlib::readINT(std::string word,
                            std::string errorText)
{
    int outInt;
    try
    {
        outInt = std::stoi(word);
    }
    catch (const std::invalid_argument &)
    {
        std::cerr << errorText;
        throw;
    }

    std::cerr.clear();
    return outInt;
}

double readlib::readDOU(std::string word,
                        std::string errorText)
{
    double outDoub;
    try
    {
        outDoub = std::stod(word);
    }
    catch (const std::invalid_argument &)
    {
        std::cerr << errorText;
        throw;
    }

    std::cerr.clear();
    return outDoub;
}
