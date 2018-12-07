#pragma once
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <vector>
#include "CKnapsackProblem.h"
class CIndividual
{
public:
	CIndividual();
	CIndividual(int numberOfBits);
	double fitness(CKnapsackProblem* problem);
	std::vector<int> mutate();

private:
	int numberOfBits;
	std::vector<int> genotype;
	std::vector<int> randomize();

};
