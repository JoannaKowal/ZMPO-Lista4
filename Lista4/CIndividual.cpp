#include "CIndividual.h"

CIndividual::CIndividual(int numberOfBits)
{
	this->numberOfBits = numberOfBits;
	randomize();
}

double CIndividual::evaluate(CKnapsackProblem * problem)
{
	this->fitness = problem->calculateFitness(this->genotype);
	return this->fitness;
}

void CIndividual::mutate(int mutProb)
{
	
	for (int i = 0; i < numberOfBits; i++)
	{
		int mutation = rand() % MAX_PROB;
		if (mutation < mutProb)
		{
			bitFlip(i);
		}
	}
}

std::vector<CIndividual*> CIndividual::crossover(CIndividual* other)
{
	CIndividual* child1 = new CIndividual(numberOfBits);
	CIndividual* child2 = new CIndividual(numberOfBits);
	std::vector<CIndividual*> children;
	int index = rand() % (numberOfBits - 1) + 1;
	for (int i = 0; i < index; i++)
	{
		child1->genotype[i] = genotype[i];
		child2->genotype[i] = other->genotype[i];
	}
	for (int i = index; i < numberOfBits; i++)
	{
		child1->genotype[i] = other->genotype[i];
		child2->genotype[i] = genotype[i];
	}
	children.push_back(child1);
	children.push_back(child2);
	return children;
}

double CIndividual::getFitness()
{
	return fitness;
}

void CIndividual::print()
{
	for (int i = 0; i < numberOfBits; i++) {
		std::cout << genotype[i];
	}
	std::cout << std::endl;
}

void CIndividual::randomize()
{
	for (int i = 0; i < numberOfBits; i++)
	{
		int bit =  rand() % 2;
		genotype.push_back(bit);
	}
}

void CIndividual::bitFlip(int index)
{
	genotype[index] = 1 - genotype[index];
}
