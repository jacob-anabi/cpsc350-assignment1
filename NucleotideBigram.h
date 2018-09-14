#ifndef NUCLEOTIDEBIGRAM_H
#define NUCLEOTIDEBIGRAM_H

#include <string>
#include "Dna.h"

class NucleotideBigram : public Dna
{
public:
    /**
     * default constructor
     * @param aa - number of aa nucleotide bigrams
     * @param ac - number of ac nucleotide bigrams
     * @param at - number of at nucleotide bigrams
     * @param ag - number of ag nucleotide bigrams
     * @param ca - number of ca nucleotide bigrams
     * @param cc - number of cc nucleotide bigrams
     * @param ct - number of ct nucleotide bigrams
     * @param cg - number of cg nucleotide bigrams
     * @param ta - number of ta nucleotide bigrams
     * @param tc - number of tc nucleotide bigrams
     * @param tt - number of tc nucleotide bigrams
     * @param tg - number of tg nucleotide bigrams
     * @param ga - number of ga nucleotide bigrams
     * @param gc - number of gc nucleotide bigrams
     * @param gt - number of gt nucleotide bigrams
     * @param gg - number of gg nucleotide bigrams
     */
    explicit NucleotideBigram(int aa = 0, int ac = 0, int at = 0, int ag = 0,
            int ca = 0, int cc = 0, int ct = 0, int cg = 0,
            int ta = 0, int tc = 0, int tt = 0, int tg = 0,
            int ga = 0, int gc = 0, int gt = 0, int gg = 0, int total = 0, int bigramCount = 0);

    /**
     * copy constructor
     * @param nucleotideBigram - nucleotide bigram object to be copied
     */
    NucleotideBigram(const NucleotideBigram& nucleotideBigram);

    /**
     * destructor
     * NOTE: trivial
     */
    ~NucleotideBigram() override;

    /**
     * increments specified nucleotide bigram by one
     */
    void incrementAA();
    void incrementAC();
    void incrementAT();
    void incrementAG();

    void incrementCA();
    void incrementCC();
    void incrementCT();
    void incrementCG();

    void incrementTA();
    void incrementTC();
    void incrementTT();
    void incrementTG();

    void incrementGA();
    void incrementGC();
    void incrementGT();
    void incrementGG();


    /**
     * accessors
     */
    int getAa();
    int getAc();
    int getAt();
    int getAg();

    int getCa();
    int getCc();
    int getCt();
    int getCg();

    int getTa();
    int getTc();
    int getTt();
    int getTg();

    int getGa();
    int getGc();
    int getGt();
    int getGg();

    /**
     * mutator
     */
     void setBigramCount(int bigramCount);

private:
    int aa, ac, at, ag, ca, cc, ct, cg, ta, tc, tt, tg, ga, gc, gt, gg; // number of nucleotide bigrams
    double probAA, probAC, probAT, probAG; // probability of each nucleotide bigram
    double probCA, probCC, probCT, probCG;
    double probTA, probTC, probTT, probTG;
    double probGA, probGC, probGT, probGG;

    int bigramCount;

    /**
     * calculates total number of nucleotide bigrams
     */
    void calculateTotal() override;
};


#endif // NUCLEOTIDEBIGRAM_H
