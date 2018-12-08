#include "CGeneticAlgorithm.h"
#include "CKnapsackProblem.h"
#include "CIndividual.h"
int main()
{
	int capacity = 165;
	std::vector<double> weights{ 23, 31, 29, 44, 53, 38, 63, 85, 89, 82 };
	std::vector<double> values{ 92, 57, 49, 68, 60, 43, 67, 84, 87, 72 };
	CKnapsackProblem problem;
	problem.initialize(capacity, values, weights);
	CGeneticAlgorithm algorithm;
	algorithm.initialize(20, 0.9, 0.05, &problem);
	algorithm.run(1000);

	int i;
	std::cin >> i;
}