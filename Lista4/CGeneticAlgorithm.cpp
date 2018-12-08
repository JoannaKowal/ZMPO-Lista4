#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm()
{
	initialized = false;
}

CGeneticAlgorithm::~CGeneticAlgorithm()
{
	clearPopulation();
	if (bestIndividual != nullptr)
	{
		delete bestIndividual;
	}
	
}

bool CGeneticAlgorithm::initialize(int popSize, double crossProb, double mutProb, CKnapsackProblem * problem)
{
	if (popSize > 0)
	{
		if (crossProb >= 0 && crossProb <= 1)
		{
			if (mutProb >= 0 && mutProb <= 1)
			{
				if (problem != nullptr && problem->isInitialized())
				{
					this->popSize = popSize;
					this->crossProb = int(crossProb * MAX_PROB);
					this->mutProb = int(mutProb * MAX_PROB);;
					this->problem = problem;
					initPopulation();
					bestIndividual = nullptr;
					std::srand(time(NULL));
					this->initialized = true;
				}
				else
				{
					std::cout << PROBLEM_NOT_INITIALIZED << std::endl;
				}
			}
			else
			{
				std::cout << INCORRECT_MUTPROB << std::endl;
			}
		}
		else
		{
			std::cout << INCORRECT_CROSSPROB << std::endl;
		}
	}
	else
	{
		std::cout << INCORRECT_POPSIZE << std::endl;
	}
	return this->initialized;
}

void CGeneticAlgorithm::run(int iterations)
{
	if (initialized)
	{
		if (iterations > 0)
		{
			for (int i = 0; i < iterations; i++)
			{
				evaluate();
				saveBest();
				crossover();
				mutate();
			}
		}
		else
		{

		}
	}
	else
	{

	}
}

CIndividual * CGeneticAlgorithm::getBestIndividual()
{
	return bestIndividual;
}

void CGeneticAlgorithm::evaluate()
{
	for (int i = 0; i < population.size(); i++)
	{
		population[i]->evaluate(problem);
	}
}

void CGeneticAlgorithm::crossover()
{
	std::vector<CIndividual*> newPopulation;
	while (newPopulation.size() != popSize)
	{
		CIndividual* parent1;
		CIndividual* parent2;
		std::vector<CIndividual*> children;
		parent1 = selectParent();
		do
		{
			parent2 = selectParent();
		} while (parent1 == parent2);
		int cross = rand() % MAX_PROB;
		if (cross < crossProb)
		{
			children = parent1->crossover(parent2);
			newPopulation.push_back(children[0]);
			newPopulation.push_back(children[1]);
		}
		else
		{
			newPopulation.push_back(new CIndividual(*parent1));
			newPopulation.push_back(new CIndividual(*parent2));
		}
	}
	clearPopulation();
	population = newPopulation;
}

void CGeneticAlgorithm::mutate()
{
	for (int i = 0; i < population.size(); i++)
	{
		population[i]->mutate(mutProb);
	}
}

void CGeneticAlgorithm::initPopulation()
{
	int numberOfBits = problem->getNumberOfItems();
	while (population.size() != popSize)
	{
		population.push_back(new CIndividual(numberOfBits));
	}
}

void CGeneticAlgorithm::clearPopulation()
{
	for (int i = 0; i < population.size(); i++)
	{
		delete population[i];
	}
	population.clear();
}

CIndividual * CGeneticAlgorithm::selectParent()
{
	CIndividual* parent1;
	CIndividual* parent2;
	int index1;
	int index2;
	index1 = rand() % popSize;
	do 
	{
		index2 = rand() % popSize;
	} while (index1 == index2);
	parent1 = population[index1];
	parent2 = population[index2];
	if (parent1->getFitness() > parent2->getFitness())
	{
		return parent1;
	}
	else
	{
		return parent2;
	}
}

void CGeneticAlgorithm::saveBest()
{
	CIndividual* currentBest = population[0];
	for (int i = 1; i < population.size(); i++)
	{
		if (population[i]->getFitness() > currentBest->getFitness())
		{
			currentBest = population[i];
		}
	}
	if (bestIndividual == nullptr)
	{
		bestIndividual = new CIndividual(*currentBest);
	}
	else
	{
		if (currentBest->getFitness() > bestIndividual->getFitness())
		{
			delete bestIndividual;
			bestIndividual = new CIndividual(*currentBest);
		}
	}
	std::cout << "Best: " << bestIndividual->getFitness() << std::endl;
}
