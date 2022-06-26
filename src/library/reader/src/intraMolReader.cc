#include "intraMolReader.h"
#include "atom.h"
#include "intraMolBondDefs.h"
#include "logger.h"
#include "stdlib.h" // for the exit statement
#include <string>
#include <vector>

using std::string;

bool intraMolReader::readIntraMolDefReader()
{
    std::ifstream                 file(defaultFileName);
    string                        line;
    std::vector<intraMolBondDefs> intraMolBondDefsVec;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            if (line == "IM")
            {
                intraMolBondDefsVec.emplace_back(
                    readSingleIntraMolBondDef(file));
            }
        }
    }

    return true;
}

intraMolBondDefs intraMolReader::readSingleIntraMolBondDef(std::ifstream& file)
{
    string molecule_1;
    string molecule_2;
    string atom_1;
    string atom_2;

    std::getline(file, molecule_1);
    std::getline(file, molecule_2);
    std::getline(file, atom_1);
    std::getline(file, atom_2);

    return intraMolBondDefs{std::move(molecule_1),
                            std::move(molecule_2),
                            std::move(atom_1),
                            std::move(atom_2)};
}
