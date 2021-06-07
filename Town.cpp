#include "pch.h"
#include "Town.h"
#include <iostream>

using namespace std;

Town::Town(string _name, int _id): name(_name),id(_id)
{

}

Town::~Town()
{
}

string Town::GetName()
{	
  return name;
}

