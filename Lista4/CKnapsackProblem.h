#pragma once
#include <vector>
#include <iostream>
#include <string>
const std::string INCORRECT_NUMBER_OF_ITEMS = "Incorrect number of items";
const std::string INCORRECT_CAPACITY= "Incorrect capacity";
class CKnapsackProblem
{
public:
	CKnapsackProblem();
	int getNumberOfItems();
	double getCapacity();
	double calculateFitness(std::vector<int>& genotype);
	bool initialize(double capacity, std::vector<double> values, std::vector<double> weights);
	bool isInitialized();
	
private:
	int numberOfItems;
	double capacity;
	std::vector<double> values;
	std::vector<double> weights;
	bool initialized;
};
