#pragma once
#include "Country.h"
#include "Gene.h"
#include <vector>
#include "country.h"
class Factory
{
public:
	Factory(int _SizePopulation);
	~Factory();
	Gene CreateRandomGene(Country *country);
	void Initialize();
	void DisplayPopulation(vector<Gene> population);
	Gene GetBestGene(int sizePopulation);
	void SortPopulation();
	void CreateNewPopulation();
	Gene RandomMutation(Gene gene);
	Gene CrossOverBetween(Gene gene1, Gene gene2);
	vector<Gene> population;
	vector<Gene> oldPopulation;
private:
	int sizePopulation;
	Country* country = Country::getInstance();
	
};

