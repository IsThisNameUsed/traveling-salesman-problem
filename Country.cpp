#include "pch.h"
#include "Country.h"

Country *Country::country = nullptr;

Country::Country()
{
	townNumber = 0;
}

Country::~Country()
{
}

void Country::AddTown(string name,int id)
{
	tabTown.push_back(Town(name, id));
	townNumber += 1;
}

void Country::InitializeCountry()
{
	distanceTab = new int*[townNumber];
	for (int i = 0; i < townNumber; i++)
	{
		distanceTab[i] = new int[townNumber];
	}

	for (int i = 0; i < townNumber; i++)
	{
		for (int j = i; j < townNumber; j++)
		{
			if (i == j) distanceTab[i][j] = -1;
			else {
				distanceTab[i][j] = rand() % 10;
				distanceTab[j][i] = distanceTab[i][j];
			}
		}
	}
}

void Country::DisplayCountry()
{
	for (int i = 0; i < townNumber; i++)
	{
		for (int j = 0; j < townNumber; j++)
		{
			cout << distanceTab[i][j] << " ";
		}
		cout << endl;
	}
}

int Country::IndexOfTown(Town town)
{
	for (int i = 0; i < tabTown.size(); i++)
	{
		if (tabTown[i].getName() == town.getName()) return i;
		else continue;
	}
	return -1;
}

int Country::DistanceBetween(Town town1, Town town2)
{
	return distanceTab[town1.id][town2.id];
}


