// AlgoGenPVC.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "Country.h"
#include "Factory.h"


int main()
{
	srand(time(NULL));
	int SizePopulation = 4;
	Factory factory(SizePopulation);
	Country* country = Country::getInstance();
	Country::getInstance()->addTown("a",0);
	Country::getInstance()->addTown("b",1);
	Country::getInstance()->addTown("c",2);
	Country::getInstance()->addTown("d",3);
	Country::getInstance()->addTown("e",4);
	Country::getInstance()->addTown("f",5);
	Country::getInstance()->addTown("g", 6);
	Country::getInstance()->addTown("h", 7);
	Country::getInstance()->addTown("i", 8);
	Country::getInstance()->addTown("j", 9);
	Country::getInstance()->addTown("k", 10);
	Country::getInstance()->addTown("l", 11);
	Country::getInstance()->InitializeCountry();
	Country::getInstance()->displayCountry();
	cout << "ab=" << country->DistanceBetween(country->tabTown[0], country->tabTown[1]) << endl;
	
	int count = 0;
	factory.Initialize();	
	while (count < 200)
	{
		factory.CreateNewPopulation();
		if (count == 0)
		{
			system("PAUSE");
		}
		count += 1;
	}

	cout << "//////////////////////////////" << endl << endl;
	count = 0;
	factory.Initialize();
	while (count < 1000)
	{
		factory.CreateNewPopulation();
		if (count == 0)
		{
			system("PAUSE");
		}
		count += 1;
	}
}

