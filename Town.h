#pragma once
#include <string>
#include <vector>
#include <Time.h>

using namespace std;
class Town
{
public:
	Town(string _name, int _id);
	~Town();
	string getName();
	int id;
private:
	string name;
	vector<int> distanceTab;
};

