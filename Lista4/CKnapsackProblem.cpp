#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem()
{
	initialized = false;
}

int CKnapsackProblem::getNumberOfItems()
{
	return numberOfItems;
}

double CKnapsackProblem::getCapacity()
{
	return capacity;
}

double CKnapsackProblem::calculateFitness(std::vector<int>& genotype)
{
	double value = 0;
	double weight = 0;
	for (int i = 0; i < numberOfItems; i++)
	{
		if (genotype[i] == 1)
		{
			weight += weights[i];
			value += values[i];
		}
	}
	if (weight > capacity)
	{
		return 0.0;
	}
	return value;
}

bool CKnapsackProblem::initialize( double capacity, std::vector<double> values, std::vector<double> weights)
{
	if (capacity > 0)
	{
		if(values.size() > 0 && values.size() == weights.size())
		{
			bool valuesCorrect = true;
			for (int i = 0; i < values.size() && valuesCorrect; i++)
			{
				if (values[i] <= 0 || weights[i] <= 0)
				{
					valuesCorrect = false;
				}
			}
			if (valuesCorrect)
			{
				this->numberOfItems = values.size();
				this->capacity = capacity;
				this->values = values;
				this->weights = weights;
				this->initialized = true;
			}
		}
		else
		{
			std::cout << INCORRECT_NUMBER_OF_ITEMS << std::endl;
		}
	}
	else
	{
		std::cout << INCORRECT_CAPACITY << std::endl;
	}
	return this->initialized;
}

bool CKnapsackProblem::isInitialized()
{
	return initialized;
}
