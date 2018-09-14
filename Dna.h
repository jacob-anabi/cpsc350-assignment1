#ifndef DNA_H
#define DNA_H

class Dna
{
public:
    /**
    * default constructor
    * @param total - total number of nucleotides
    */
    explicit Dna(int total = 0);

    /**
    * copy constructor
    * @param dna - dna object to be copied
    */
    Dna(const Dna& dna);

    /**
    * destructor
    * NOTE: trivial
    */
    virtual ~Dna();

protected:
    int total; // total number of nucleotides

private:
    /**
     * calculate total number of nucleotides
     */
    virtual void calculateTotal() = 0;
};


#endif // DNA_H
