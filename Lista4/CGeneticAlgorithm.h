#pragma once
#include "CIndividual.h"
#include "CKnapsackProblem.h";
const std::string PROBLEM_NOT_INITIALIZED = "Problem must be initialized";
const std::string INCORRECT_MUTPROB = "Incorrect mutProb";
const std::string INCORRECT_CROSSPROB= "Incorrect crossProb";
const std::string INCORRECT_POPSIZE = "Incorrect popSize";
class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm();
	~CGeneticAlgorithm();
	bool initialize(int popSize, double crossProb, double mutProb, CKnapsackProblem* problem);
	void run(int iterations);
	CIndividual* getBestIndividual();
	
private:
	int popSize;
	int crossProb;
	int mutProb;
	CKnapsackProblem* problem;
	CIndividual* bestIndividual;
	bool initialized;
	std::vector<CIndividual*> population;
	void clearPopulation();
	CIndividual* selectParent();
	void saveBest();
	void evaluate();
	void crossover();
	void mutate();
	void initPopulation();
};
