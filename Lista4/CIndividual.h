#pragma once
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <vector>
#include "CKnapsackProblem.h"
#include "Constants.h"
#include "iostream"
class CIndividual
{
public:
	CIndividual(int numberOfBits);
	double evaluate(CKnapsackProblem* problem);
	void mutate(int mutProb);
	std::vector<CIndividual*> crossover(CIndividual* other);
	double getFitness();
	void print();
private:
	int numberOfBits;
	double fitness;
	std::vector<int> genotype;
	void randomize();
	void bitFlip(int index);

};
