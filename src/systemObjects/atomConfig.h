// atom config item (stores everything needed to set up an atom)
// meant to be short lived!


// to do - add pos/vel/for
// + type! (enum?) and default the other values

class atomConfig
{
    public:

    char* acName;
    double* xyz;

    atomConfig(char*, double, double, double );
};
