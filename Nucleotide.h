#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H

#include <string>
#include "Dna.h"

class Nucleotide : public Dna
{
public:
    /**
     * default constructor
     * @param a - number of a nucleotides
     * @param c - number of c nucleotides
     * @param t - number of t nucleotides
     * @param g - number of g nucleotides
     * @param total - total number of nucleotides
     */
    explicit Nucleotide(int a = 0, int c = 0, int t = 0, int g = 0, int total = 0);

    /**
     * copy constructor
     * @param nucleotide - nucleotide object to be copied
     */
    Nucleotide(const Nucleotide& nucleotide);

    /**
     * destructor
     * NOTE: trivial
     */
    ~Nucleotide() override;

    /**
     * increments specified nucleotide by one
     * @param nucleotide - represents nucleotide to increment
     */
    void increment(char nucleotide);

    /**
     * Accessors
     */
    int getA();
    int getC();
    int getT();
    int getG();

    double getProbA();
    double getProbC();
    double getProbT();
    double getProbG();
private:
    int a, c, t, g; // number of nucleotides
    double probA, probC, probT, probG; // probability of each nucleotide

    /**
     * calculate total number of nucleotides
     */
    void calculateTotal() override;
};


#endif // NUCLEOTIDE_H
