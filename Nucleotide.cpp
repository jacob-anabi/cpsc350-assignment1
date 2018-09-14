#include <string>
#include "Nucleotide.h"

// default constructor
Nucleotide::Nucleotide(int a, int c, int t, int g, int total)
: Dna(total), a(a), c(c), t(t), g(g)
{
}

// copy constructor
Nucleotide::Nucleotide(const Nucleotide& nucleotide)
: Dna(nucleotide), a(nucleotide.a), c(nucleotide.c), t(nucleotide.t), g(nucleotide.g)
{
}

// destructor (is trivial)
Nucleotide::~Nucleotide()
= default;

// increment specified nucleotide by one
void Nucleotide::increment(char nucleotide)
{
    if (std::isalpha(nucleotide)) // if nucleotide is alphabetic
    {
        switch (std::islower(nucleotide) ? std::toupper(nucleotide) :  nucleotide) // making sure nucleotide is uppercase
        {
            case 'A':
                ++a;
                break;
            case 'C':
                ++c;
                break;
            case 'T':
                ++t;
                break;
            case 'G':
                ++g;
                break;
            default:
                break;
        }
    }
}

// accessors
int Nucleotide::getA()
{
    return a;
}

int Nucleotide::getC()
{
    return c;
}

int Nucleotide::getT()
{
    return t;
}

int Nucleotide::getG()
{
    return g;
}

double Nucleotide::getProbA()
{
    calculateTotal();
    probA = static_cast<double>(a)/total;
    return probA;
}

double Nucleotide::getProbC()
{
    calculateTotal();
    probC = static_cast<double>(c)/total;
    return probC;
}

double Nucleotide::getProbT()
{
    calculateTotal();
    probT = static_cast<double>(t)/total;
    return probT;
}

double Nucleotide::getProbG()
{
    calculateTotal();
    probG = static_cast<double>(g)/total;
    return probG;
}

// calculate total number of nucleotides
void Nucleotide::calculateTotal() {
    total = (a+c+t+g);
}