#pragma once
#include <vector>
#include "Town.h";
#include "country.h";
class Gene
{
public:
	Gene();
	~Gene();
	std::vector<Town> sequence;
	float GetFitness();
	float ComputeFitness();
	void DisplaySequence();
	bool Contains(Town town);
private:
	Country* country = Country::getInstance();
	float fitness;
};

