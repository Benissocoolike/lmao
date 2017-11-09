//Definitions for functions in battleship assignment
//Ben
//11/08/2017

#include <iostream>
#include "battleship.h"
using std::cout; using std::cin;

Location::Location() 
{
	x = -1;
	y = '*';
}

void Location::pick()
{
	switch (rand() % fieldSize)
	{
	case 0: x = 1; break;
	case 1: x = 2; break;
	case 2: x = 3; break;
	case 3: x = 4; break;
	case 4: x = 5; break;
	}

	switch (rand() % fieldSize)
	{
	case 0: y = 'a'; break;
	case 1: y = 'b'; break;
	case 2: y = 'c'; break;
	case 3: y = 'd'; break;
	case 4: y = 'e'; break;
	}
}

void Location::fire() 
{
	cout << "Input a x coordinate from 1 to 5: ";
	cin >> x;
	cout << "Input a y coordinate from a to e: ";
	cin >> y;
}

void Location::print() const
{
	cout << x << y;
}

bool compare(const Location& a, const Location& b)
{
	if((a.x == b.x) && (a.y == b.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Ship::Ship()
{
	sunk = false;
}

bool Ship::match(const Location& a) const
{
	return compare(a, loc);
}

void Ship::sink()
{
	sunk = true;
}

void Ship::setLocation(const Location& a)
{
	
}