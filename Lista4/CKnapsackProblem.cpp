#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem()
{
}

CKnapsackProblem::CKnapsackProblem(int numberOfItems, double capacity, std::vector<double> values, std::vector<double> weights)
{
	this->numberOfItems = numberOfItems;
	this->capacity = capacity;
	this->values = values;
	this->weights = weights;
}

int CKnapsackProblem::getNumberOfItems()
{
	return numberOfItems;
}

double CKnapsackProblem::getCapacity()
{
	return capacity;
}

std::vector<double> CKnapsackProblem::getValues()
{
	
	return values;
}

std::vector<double> CKnapsackProblem::getWeights()
{
	return weights;
}
