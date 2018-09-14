#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Nucleotide.h"
#include "NucleotideBigram.h"

/**
 * processes a passed in file of dna nucleotides by computing sum, mean, variance, and standard deviation of the lines in the file,
 * then it produces a file with lines of lengths from a Gaussian Distribution
 * @param dnaIn - the dna file to process
 * @param toAppend - determines whether to overwrite a file, or append to it
 */
void dnaFileMaker(std::ifstream& dnaIn, bool toAppend = false); // function deceleration

int main(int argc, char** argv)
{
    srand(static_cast<unsigned int>(time(nullptr))); // generating a seed for rand() so each time the program is run, rand() will produce "random" numbers

    if (argc > 1 && argc < 3) // if they pass in only file
    {
        std::ifstream dnaIn(argv[1]);
        if (dnaIn.good()) // if the file actually exists
        {
            dnaFileMaker(dnaIn);
            dnaIn.close();
        }
        else
        {
            std::cout << "File doesn't exist." << std::endl;
            dnaIn.close();
        }
    }
    else
    {
        std::cout << "Only one file allowed." << std::endl;
    }

    std::string choice;
    std::string fileName;

    while (true)
    {
        std::cout << "Would you like to input another list (y/n)?" << std::endl;
        std::cin >> choice;
        if (((std::isupper(choice[0]) ? std::tolower(choice[0]) : choice[0]) == 'y') && choice.size() == 1) // checking if user enters the character 'y'
        {
            std::cout << "Enter a file name below." << std::endl;
            std::cin >> fileName;

            std::ifstream newDnaIn(fileName);

            if (newDnaIn.good()) // if the file actually exists
            {
                dnaFileMaker(newDnaIn, true);
                newDnaIn.close();
            }
            else
            {
                std::cout << "File doesn't exist" << std::endl;
                newDnaIn.close();
            }
        }
        else if (((std::isupper(choice[0]) ? std::tolower(choice[0]) : choice[0]) == 'n') && choice.size() == 1) // checking if the user enters the character 'n'
        {
            break;
        }
        else
        {
            std::cout << "Invalid option. Try again." << std::endl;
        }
    }
    return 0;
}

void dnaFileMaker(std::ifstream& dnaIn, bool toAppend) // function definition
{
    int sum = 0; // sum of dna string length
    double mean = 0.0; // mean of dna string length
    double variance = 0.0; // variance of dna string length
    double standardDeviation; // square root of the variance
    double varianceSum = 0.0; // sum of (string length - mean length)^2

    double c = 0; // standard Gaussian
    double randA = 0.0; // random number
    double randB = 0.0; // random number
    int newDnaStringLength = 0; // length of string that will be added to the file

    const double PI = 3.1415926535897932; // approximate value of pi

    int fileLines = 0; // number of lines in the file
    int bigramCount = 0;

    std::string dnaString = " ";

    Nucleotide* nucleotides = new Nucleotide(); // object containing all of the nucleotides
    NucleotideBigram* nucleotideBigrams = new NucleotideBigram(); // object containing all of the nucleotide bigrams

    while (std::getline(dnaIn, dnaString))
    {
        ++fileLines;
        sum += dnaString.size();

        for (char i : dnaString)
        {
            switch(std::islower(i) ? std::toupper(i) : i) // converting char at i to uppercase
            {
                case 'A':
                    nucleotides->increment('A');
                    break;
                case 'C':
                    nucleotides->increment('C');
                    break;
                case 'T':
                    nucleotides->increment('T');
                    break;
                case 'G':
                    nucleotides->increment('G');
                    break;
                default:
                    delete nucleotides;
                    delete nucleotideBigrams;
                    std::cout << "File contained unusable elements." << std::endl;
                    return;
            }
        }

        if (!(dnaString.empty()) && (dnaString.size() % 2 != 0)) // making the dna string even for the nucleotide bigrams
        {
            dnaString.pop_back();
        }

        for (int i = 0; i < dnaString.size() - 1; i += 2)
        {
            switch (std::islower(dnaString[i]) ? std::toupper(dnaString[i]) : dnaString[i])
            {
                case 'A':
                    switch (std::islower(dnaString[i+1]) ? std::toupper(dnaString[i+1]) : dnaString[i+1])
                    {
                        case 'A':
                            nucleotideBigrams->incrementAA();
                            break;
                        case 'C':
                            nucleotideBigrams->incrementAC();
                            break;
                        case 'T':
                            nucleotideBigrams->incrementAT();
                            break;
                        case 'G':
                            nucleotideBigrams->incrementAG();
                            break;
                        default:
                            break;
                    }
                    break;
                case 'C':
                    switch (std::islower(dnaString[i+1]) ? std::toupper(dnaString[i+1]) : dnaString[i+1])
                    {
                        case 'A':
                            nucleotideBigrams->incrementCA();
                            break;
                        case 'C':
                            nucleotideBigrams->incrementCC();
                            break;
                        case 'T':
                            nucleotideBigrams->incrementCT();
                            break;
                        case 'G':
                            nucleotideBigrams->incrementCG();
                            break;
                        default:
                            break;
                    }
                    break;
                case 'T':
                    switch (std::islower(dnaString[i+1]) ? std::toupper(dnaString[i+1]) : dnaString[i+1])
                    {
                        case 'A':
                            nucleotideBigrams->incrementTA();
                            break;
                        case 'C':
                            nucleotideBigrams->incrementTC();
                            break;
                        case 'T':
                            nucleotideBigrams->incrementTT();
                            break;
                        case 'G':
                            nucleotideBigrams->incrementTG();
                            break;
                        default:
                            break;
                    }
                    break;
                case 'G':
                    switch (std::islower(dnaString[i+1]) ? std::toupper(dnaString[i+1]) : dnaString[i+1])
                    {
                        case 'A':
                            nucleotideBigrams->incrementGA();
                            break;
                        case 'C':
                            nucleotideBigrams->incrementGC();
                            break;
                        case 'T':
                            nucleotideBigrams->incrementGT();
                            break;
                        case 'G':
                            nucleotideBigrams->incrementGG();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    delete nucleotides;
                    delete nucleotideBigrams;
                    std::cout << "File contained unusable elements." << std::endl;
                    return;
            }
            ++bigramCount;
        }
    }
    nucleotideBigrams->setBigramCount(bigramCount);
    mean = static_cast<double>(sum)/fileLines;

    /*
     * Allows reading through the same file twice
     */
    dnaIn.clear();
    dnaIn.seekg(0, dnaIn.beg);

    while (std::getline(dnaIn, dnaString))
    {
        varianceSum += pow((dnaString.size() - mean), 2);
    }

    variance = varianceSum/fileLines;
    standardDeviation = sqrt(variance);

    std::ofstream dnaOut;
    double probability = 0.0; // probability to select a specific nucleotide

    double aProb = nucleotides->getProbA(); // A nucleotide probability
    double cProb = nucleotides->getProbA() + nucleotides->getProbC(); // C nucleotide probability
    double tProb = nucleotides->getProbA() + nucleotides->getProbC() + nucleotides->getProbT(); // T nucleotide probability
    double gProb = nucleotides->getProbA() + nucleotides->getProbC() + nucleotides->getProbT() + nucleotides->getProbG(); // G nucleotide probability


    if (!toAppend)
    {
        dnaOut.open("jacobanabi.out");

        if (dnaOut.good()) // if the file is open and to be accessed
        {
            dnaOut << "Jacob Anabi\n" << "2294644\n" << "CPSC 350\n" << "Assignment 1\n" << std::endl; // name, student id number, class, assignment number

            /*
             * Information regarding the dna strings in the file
             */
            dnaOut << "Sum of DNA string length: " << sum
            << "\n" << "Mean of DNA string length: " << mean << "\n"
            << "Variance of DNA string length: " << variance << "\n"
            << "Standard Deviation of DNA string length: " << standardDeviation << "\n" << std::endl;

            dnaOut << "Nucleotide probabilities:" << "\n"
            << "A probability: " << nucleotides->getProbA() * 100 << "%" << "\n"
            << "C probability: " << nucleotides->getProbC() * 100 << "%" << "\n"
            << "T probability: " << nucleotides->getProbT() * 100 << "%" << "\n"
            << "G probability: " << nucleotides->getProbG() * 100 << "%" << "\n" << std::endl;

            dnaOut << "Nucleotide bigram probabilities:" << "\n"
            << "AA probability: " << static_cast<double>(nucleotideBigrams->getAa()) / bigramCount * 100 << "%" << "\n"
            << "AC probability: " << static_cast<double>(nucleotideBigrams->getAc()) / bigramCount * 100 << "%" << "\n"
            << "AT probability: " << static_cast<double>(nucleotideBigrams->getAt()) / bigramCount * 100 << "%" << "\n"
            << "AG probability: " << static_cast<double>(nucleotideBigrams->getAg()) / bigramCount * 100 << "%" << "\n"
            << "CA probability: " << static_cast<double>(nucleotideBigrams->getCa()) / bigramCount * 100 << "%" << "\n"
            << "CC probability: " << static_cast<double>(nucleotideBigrams->getCc()) / bigramCount * 100 << "%" << "\n"
            << "CT probability: " << static_cast<double>(nucleotideBigrams->getCt()) / bigramCount * 100 << "%" << "\n"
            << "CG probability: " << static_cast<double>(nucleotideBigrams->getCg()) / bigramCount * 100 << "%" << "\n"
            << "TA probability: " << static_cast<double>(nucleotideBigrams->getTa()) / bigramCount * 100 << "%" << "\n"
            << "TC probability: " << static_cast<double>(nucleotideBigrams->getTc()) / bigramCount * 100 << "%" << "\n"
            << "TT probability: " << static_cast<double>(nucleotideBigrams->getTt()) / bigramCount * 100 << "%" << "\n"
            << "TG probability: " << static_cast<double>(nucleotideBigrams->getTg()) / bigramCount * 100 << "%" << "\n"
            << "GA probability: " << static_cast<double>(nucleotideBigrams->getGa()) / bigramCount * 100 << "%" << "\n"
            << "GC probability: " << static_cast<double>(nucleotideBigrams->getGc()) / bigramCount * 100 << "%" << "\n"
            << "GT probability: " << static_cast<double>(nucleotideBigrams->getGt()) / bigramCount * 100 << "%" << "\n"
            << "GG probability: " << static_cast<double>(nucleotideBigrams->getGg()) / bigramCount * 100 << "%" << "\n" << std::endl;

            for (int i = 0; i < 1000; ++i) // adding 1000 lines to the file
            {
                /*
                 * generate two random variables, a and b, uniformly distributed in [0,1)
                 * NOTE: + 1.0 is needed to exclude 1 because RAND_MAX is the maximum value that rand() can return
                 */
                randA = static_cast<double>(rand()) / (RAND_MAX + 1.0);
                randB = static_cast<double>(rand()) / (RAND_MAX + 1.0);

                c = sqrt((-2.0) * log(randA)) * cos(2 * PI * randB); // standard Gaussian
                newDnaStringLength = static_cast<int>(round(standardDeviation * c + mean));

                for (int j = 0; j < newDnaStringLength; ++j) // adding dna strings of the calculated length 1000 times
                {
                    probability = (static_cast<double>(rand()) / RAND_MAX);
                    if (probability < aProb) // probability to choose A nucleotide
                    {
                        dnaOut << "A";
                    }
                    else if ((probability >= aProb) && (probability < cProb)) // probability to choose C Nucleotide
                    {
                        dnaOut << "C";
                    }
                    else if ((probability >= cProb) && (probability < tProb)) // probability to choose T Nucleotide
                    {
                        dnaOut << "T";
                    }
                    else if ((probability >= tProb) && (probability <= gProb)) // probability to choose G Nucleotide
                    {
                        dnaOut << "G";
                    }
                }
                dnaOut << "\n";
            }
            dnaOut << "\n";
        }
        dnaOut.close();
        delete nucleotides;
        delete nucleotideBigrams;
    }
    else
    {
        dnaOut.open("jacobanabi.out", std::ios::app); // append to the file instead of overwriting it

        if (dnaOut.good()) // if the file is open and to be accessed
        {
            /*
             * Information regarding the dna strings in the file
             */
            dnaOut << "Sum of DNA string length: " << sum << "\n"
            << "Mean of DNA string length: " << mean << "\n"
            << "Variance of DNA string length: " << variance << "\n"
            << "Standard Deviation of DNA string length: " << standardDeviation << "\n" << std::endl;

            dnaOut << "Nucleotide probabilities:" << "\n"
            << "A probability: " << nucleotides->getProbA() * 100 << "%" << "\n"
            << "C probability: " << nucleotides->getProbC() * 100 << "%" << "\n"
            << "T probability: " << nucleotides->getProbT() * 100 << "%" << "\n"
            << "G probability: " << nucleotides->getProbG() * 100 << "%" << "\n" << std::endl;

            dnaOut << "Nucleotide bigram probabilities:" << "\n"
            << "AA probability: " << static_cast<double>(nucleotideBigrams->getAa()) / bigramCount * 100 << "%" << "\n"
            << "AC probability: " << static_cast<double>(nucleotideBigrams->getAc()) / bigramCount * 100 << "%" << "\n"
            << "AT probability: " << static_cast<double>(nucleotideBigrams->getAt()) / bigramCount * 100 << "%" << "\n"
            << "AG probability: " << static_cast<double>(nucleotideBigrams->getAg()) / bigramCount * 100 << "%" << "\n"
            << "CA probability: " << static_cast<double>(nucleotideBigrams->getCa()) / bigramCount * 100 << "%" << "\n"
            << "CC probability: " << static_cast<double>(nucleotideBigrams->getCc()) / bigramCount * 100 << "%" << "\n"
            << "CT probability: " << static_cast<double>(nucleotideBigrams->getCt()) / bigramCount * 100 << "%" << "\n"
            << "CG probability: " << static_cast<double>(nucleotideBigrams->getCg()) / bigramCount * 100 << "%" << "\n"
            << "TA probability: " << static_cast<double>(nucleotideBigrams->getTa()) / bigramCount * 100 << "%" << "\n"
            << "TC probability: " << static_cast<double>(nucleotideBigrams->getTc()) / bigramCount * 100 << "%" << "\n"
            << "TT probability: " << static_cast<double>(nucleotideBigrams->getTt()) / bigramCount * 100 << "%" << "\n"
            << "TG probability: " << static_cast<double>(nucleotideBigrams->getTg()) / bigramCount * 100 << "%" << "\n"
            << "GA probability: " << static_cast<double>(nucleotideBigrams->getGa()) / bigramCount * 100 << "%" << "\n"
            << "GC probability: " << static_cast<double>(nucleotideBigrams->getGc()) / bigramCount * 100 << "%" << "\n"
            << "GT probability: " << static_cast<double>(nucleotideBigrams->getGt()) / bigramCount * 100 << "%" << "\n"
            << "GG probability: " << static_cast<double>(nucleotideBigrams->getGg()) / bigramCount * 100 << "%" << "\n" << std::endl;

            for (int i = 0; i < 1000; ++i) // adding 1000 lines to the file
            {
                /*
                 * generate two random variables, a and b, uniformly distributed in [0,1)
                 * NOTE: + 1.0 is needed to exclude 1 because RAND_MAX is the maximum value that rand() can return
                 */
                randA = static_cast<double>(rand()) / (RAND_MAX + 1.0);
                randB = static_cast<double>(rand()) / (RAND_MAX + 1.0);

                c = sqrt((-2.0) * log(randA)) * cos(2 * PI * randB); // standard Gaussian
                newDnaStringLength = static_cast<int>(round(standardDeviation * c + mean));

                for (int j = 0; j < newDnaStringLength; ++j) // adding dna strings of the calculated length 1000 times
                {
                    probability = (static_cast<double>(rand()) / RAND_MAX);
                    if (probability < aProb) // probability to choose A nucleotide
                    {
                        dnaOut << "A";
                    }
                    else if ((probability >= aProb) && (probability < cProb)) // probability to choose C Nucleotide
                    {
                        dnaOut << "C";
                    }
                    else if ((probability >= cProb) && (probability < tProb)) // probability to choose T Nucleotide
                    {
                        dnaOut << "T";
                    }
                    else if ((probability >= tProb) && (probability <= gProb)) // probability to choose G Nucleotide
                    {
                        dnaOut << "G";
                    }
                }
                dnaOut << "\n";
            }
            dnaOut << "\n";
        }
        dnaOut.close();
        delete nucleotides;
        delete nucleotideBigrams;
    }
}