#include "pch.h"
#include "Gene.h"
#include <list>

Gene::Gene()
{
}


Gene::~Gene()
{
}

float Gene::GetFitness()
{
	return fitness;
}

float Gene :: ComputeFitness()
{
	fitness = 0;
	int sequenceSize = country->townNumber;
	for (int i = 0; i < sequenceSize; i++)
	{
		if(i == sequenceSize-1)
			fitness += country->DistanceBetween(sequence[i], sequence[0]);
		else 
			fitness += country->DistanceBetween(sequence[i], sequence[i + 1]);
	}
	return fitness;
}

void Gene::DisplaySequence()
{
	for (Town town : sequence)
	{
		cout << town.getName(); 
	}
	cout << " " << fitness;
}

bool Gene::Contains(Town town)
{
	for (Town geneTown : sequence)
	{
		if (geneTown.id == town.id) return true;
	}
	return false;
}
