#pragma once
#include <vector>
class CKnapsackProblem
{
public:
	CKnapsackProblem();
	CKnapsackProblem(int numberOfItems, double capacity, std::vector<double> values, std::vector<double> weights);
	int getNumberOfItems();
	double getCapacity();
	std::vector<double> getValues();
	std::vector<double> getWeights();
private:
	int numberOfItems;
	double capacity;
	std::vector<double> values;
	std::vector<double> weights;
};
