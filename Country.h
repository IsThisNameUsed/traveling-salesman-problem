#pragma once
#include "Town.h"
#include <vector>
#include <iostream>

class Country
{
	static Country *country;
	Country();
	
public:
	~Country();
	static Country *getInstance() {
		if (!country)
			country = new Country;
		return country;
	}
	Country(const Country&) = delete;
	Country& operator=(const Country&) = delete;

	std::vector<Town> tabTown;
	int **distanceTab;
	void AddTown(string name,int id);
	int IndexOfTown(Town town);
	void InitializeCountry();
	int DistanceBetween(Town town1, Town town2);
	void DisplayCountry();
	int townNumber;
};

