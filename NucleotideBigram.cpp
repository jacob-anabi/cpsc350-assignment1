#include <string>
#include "NucleotideBigram.h"

// default constructor
NucleotideBigram::NucleotideBigram(int aa, int ac, int at, int ag, int ca, int cc, int ct, int cg, int ta, int tc,
                                   int tt, int tg, int ga, int gc, int gt, int gg, int total, int bigramCount)
: Dna(total),
aa(aa), ac(ac), at(at), ag(ag),
ca(ca), cc(cc), ct(ct), cg(cg),
ta(ta), tc(tc), tt(tt), tg(tg),
ga(ga), gc(gc), gt(gt), gg(gg),
bigramCount(bigramCount)
{
}

// copy constructor
NucleotideBigram::NucleotideBigram(const NucleotideBigram& nucleotideBigram)
: Dna(nucleotideBigram),
aa(nucleotideBigram.aa), ac(nucleotideBigram.ac), at(nucleotideBigram.at), ag(nucleotideBigram.ag),
ca(nucleotideBigram.ca), cc(nucleotideBigram.cc), ct(nucleotideBigram.ct), cg(nucleotideBigram.cg),
ta(nucleotideBigram.ta), tc(nucleotideBigram.tc), tt(nucleotideBigram.tt), tg(nucleotideBigram.tg),
ga(nucleotideBigram.ga), gc(nucleotideBigram.gc), gt(nucleotideBigram.gt), gg(nucleotideBigram.gg)
{
}

// destructor (is trivial)
NucleotideBigram::~NucleotideBigram()
= default;


// accessors
int NucleotideBigram::getAa()
{
    return aa;
}

int NucleotideBigram::getAc()
{
    return ac;
}

int NucleotideBigram::getAt()
{
    return at;
}

int NucleotideBigram::getAg()
{
    return ag;
}

int NucleotideBigram::getCa()
{
    return ca;
}

int NucleotideBigram::getCc()
{
    return cc;
}

int NucleotideBigram::getCt()
{
    return ct;
}

int NucleotideBigram::getCg()
{
    return cg;
}

int NucleotideBigram::getTa()
{
    return ta;
}

int NucleotideBigram::getTc()
{
    return tc;
}

int NucleotideBigram::getTt()
{
    return tt;
}

int NucleotideBigram::getTg()
{
    return tg;
}

int NucleotideBigram::getGa()
{
    return ga;
}

int NucleotideBigram::getGc()
{
    return gc;
}

int NucleotideBigram::getGt()
{
    return gt;
}

int NucleotideBigram::getGg()
{
    return gg;
}

// mutator
void NucleotideBigram::setBigramCount(int bigramCount)
{
    this->bigramCount = bigramCount;
}

// calculate total number of nucleotide bigrams
void NucleotideBigram::calculateTotal()
{
    total = bigramCount;
}

// incrementers
void NucleotideBigram::incrementAA()
{
    ++aa;
}

void NucleotideBigram::incrementAC()
{
    ++ac;
}

void NucleotideBigram::incrementAT()
{
    ++at;
}

void NucleotideBigram::incrementAG()
{
    ++ag;
}

void NucleotideBigram::incrementCA()
{
    ++ca;
}

void NucleotideBigram::incrementCC()
{
    ++cc;
}

void NucleotideBigram::incrementCT()
{
    ++ct;
}

void NucleotideBigram::incrementCG()
{
    ++cg;
}

void NucleotideBigram::incrementTA()
{
    ++ta;
}

void NucleotideBigram::incrementTC()
{
    ++tc;
}

void NucleotideBigram::incrementTT()
{

}

void NucleotideBigram::incrementTG()
{
    ++tg;
}

void NucleotideBigram::incrementGA()
{
    ++ga;
}

void NucleotideBigram::incrementGC()
{
    ++gc;
}

void NucleotideBigram::incrementGT()
{
    ++gt;
}

void NucleotideBigram::incrementGG()
{
    ++gg;
}