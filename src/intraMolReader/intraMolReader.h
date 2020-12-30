// intraMolReader Reeader class

#ifndef INTRAMOLREADER_H
#define INTRAMOLREADER_H

class intraMolReader
{
    constexpr static const char* defaultFileName {"SYS_INTRA_MOLECULES"};
    constexpr static const char* className       {"intraMolReader"};

    public:
    intraMolReader()  = default;
    ~intraMolReader() = default;

    // read intra molecular bonds
    static bool readIntraMolReader();
};

#endif // INTRAMOLREADER_H
