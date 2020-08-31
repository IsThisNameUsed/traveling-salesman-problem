#include "pch.h"
#include "Factory.h"
#include <list>
#include <iostream>

Factory::Factory(int _SizePopulation):SizePopulation(_SizePopulation)
{
}


Factory::~Factory()
{
}

Gene Factory:: CreateRandomGene(Country *country)
{
	Gene gene;
	std::list<Town> townList(country->tabTown.begin(), country->tabTown.end());
	int maxRand = country->tabTown.size();
	while (!townList.empty())
	{
		int random = rand() % maxRand;

		std::list<Town>::iterator it = townList.begin();
		for (int i = 0; i <= random; i++)
		{
			if (i == random)
			{
				gene.sequence.push_back(*it);
				townList.erase(it);
			}
			else it++;
		}
		maxRand -= 1;

	}
	gene.ComputeFitness();
	return gene;
}

void Factory:: Initialize()
{
	population.clear();
	oldPopulation.clear();
	for (int i = 0; i < SizePopulation; i++)
	{
		population.push_back(CreateRandomGene(country));
	}	
}

void Factory::DisplayPopulation(vector<Gene> population)
{
	for (Gene gene : population)
	{
		for (Town town : gene.sequence)
		{
			cout << town.getName();
		}
		cout <<" "<<gene.GetFitness()<< endl;
	}
}

Gene Factory::GetBestGene(int sizePopulation)
{
	int minDistance = population[0].GetFitness();
	Gene bestGene;
	bestGene = population[0];
	int index=0;
	for (int i = 0;i<sizePopulation; i++)
	{
		if (population[i].GetFitness() < minDistance)
		{
			minDistance = population[i].GetFitness();
			bestGene = population[i];
			index = i;
		}
	}
	population.erase(population.begin() + index);
	return bestGene;
}

void Factory::CreateNewPopulation() {

	SortPopulation();
	cout << endl << "new population Creation" << endl;
	//Add best gene to new population
	population.push_back(oldPopulation[0]);
	//Random mutation on random gene
	int random = rand() % SizePopulation;
	cout << endl<< "Mutation on ";
	oldPopulation[random].DisplaySequence();
	population.push_back(RandomMutation(oldPopulation[random]));
	cout << endl;
	population[1].DisplaySequence();
	cout << endl;
	//best et 2d best cross-over
	cout << endl<< "Cross over beteween first and random" << endl;
	random = rand() % SizePopulation;
	population.push_back(CrossOverBetween(oldPopulation[0], oldPopulation[random]));
	oldPopulation[0].DisplaySequence();
	cout << endl << "et ";
	oldPopulation[1].DisplaySequence();
	cout <<endl<< "donne:" << endl;
	population[2].DisplaySequence();
	//best and worst cross over
	cout << endl << "Cross over beteween first and worst" << endl;
	population.push_back(CrossOverBetween(oldPopulation[0], oldPopulation[SizePopulation-1]));
	oldPopulation[0].DisplaySequence();
	cout << endl << "et ";
	oldPopulation[SizePopulation - 1].DisplaySequence();
	cout << endl << "donne:" << endl;
	population[3].DisplaySequence();

	cout << endl << endl << "Ancienne pop:" << endl;
	DisplayPopulation(oldPopulation);
	cout << endl << endl << "Nouvelle pop" << endl;
	DisplayPopulation(population);
	cout << endl;

}

void Factory::SortPopulation()
{
	oldPopulation.clear();
	for (int i = 0; i < SizePopulation; i++)
	{
		oldPopulation.push_back(GetBestGene(SizePopulation - i));
	}
	
	cout << "Population sort:" << endl;
	for (Gene gene : oldPopulation)
	{
		gene.DisplaySequence(); 
		cout << endl;
	}
}


Gene Factory::RandomMutation(Gene gene)
{
	int index2;
	int index1 = rand() % country->townNumber;
	do {
		index2 = rand() % country->townNumber;
	} while (index2 == index1);
	Town temp = gene.sequence[index1];
	gene.sequence[index1] = gene.sequence[index2];
	gene.sequence[index2] = temp;
	gene.ComputeFitness();
	return gene;
}

Gene Factory::CrossOverBetween(Gene gene1, Gene gene2)
{
	int randomIndex = rand() % (country->townNumber -1) +1;
	cout << "sur l'index " << randomIndex << endl;
	Gene newGene;
	int gene1Cursor=0, gene2Cursor=randomIndex;

	for (int i = 0; i < randomIndex; i++)
	{
		newGene.sequence.push_back(gene1.sequence[i]);
		gene1Cursor += 1;
	}
	
	for (int j = randomIndex; j < country->townNumber; j++)
	{
		int next = false;
		while (!next)
		{
			if (!newGene.Contains(gene2.sequence[j]))
			{
				newGene.sequence.push_back(gene2.sequence[j]);
				gene2Cursor++;
				next = true;
			}
			else if (!newGene.Contains(gene1.sequence[gene1Cursor]))
			{
				newGene.sequence.push_back(gene1.sequence[gene1Cursor]);
				gene2Cursor++;
				gene1Cursor++;
				next = true;
			}
			else gene1Cursor++;
		}				
	}
	newGene.ComputeFitness();
	return newGene;
}