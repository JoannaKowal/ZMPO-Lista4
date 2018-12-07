#include "CIndividual.h"

CIndividual::CIndividual()
{
	
}

CIndividual::CIndividual(int numberOfBits)
{
	this->numberOfBits = numberOfBits;
	genotype = randomize();
}

double CIndividual::fitness(CKnapsackProblem * problem)
{
	double fitness;
	double weight;
	std::vector<double> values = problem->getValues();
	std::vector<double> weights = problem->getWeights();
	for (int i = 0; i < numberOfBits; i++)
	{
		weight += (genotype[i] * weights[i]);
		if (weight > problem->getCapacity())
		{
			return 0.0;
		}
		fitness += (genotype[i] * values[i]);
	}
	return fitness;
}

std::vector<int> CIndividual::randomize()
{
	std::vector<int> genotype;
	srand(time(NULL));
	for (int i = 0; i < numberOfBits; i++)
	{
		int bit =  rand() % 1;
		genotype.push_back(bit);
	}
	return genotype;
}
