#include "Dna.h"

// default constructor
Dna::Dna(int total)
: total(total)
{
}

// copy constructor
Dna::Dna(const Dna& dna)
: total(dna.total)
{
}

// destructor (is virtual because it's in an abstract class and is trivial)
Dna::~Dna()
= default;