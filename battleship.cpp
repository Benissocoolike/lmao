//Benjamin Bartow
//11/03/2017
//Function definitions for battleship program

#include "battleship.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;

void initialize(Ship a[])
{
	for (int i = 0; i < fleetSize; ++i)
	{
		a[i].loc.x = -1;
		a[i].loc.y = '*';
	}	
}

Location pick() 
{
	Location loc;
	switch (rand() % fieldSize)
	{
	case 0: loc.x = 1; break; 
	case 1: loc.x = 2; break; 
	case 2: loc.x = 3; break; 
	case 3: loc.x = 4; break; 
	case 4: loc.x = 5; break; 
	}
	
	switch (rand() % fieldSize)
	{
	case 0: loc.y = 'a'; break; 
	case 1: loc.y = 'b'; break; 
	case 2: loc.y = 'c'; break; 
	case 3: loc.y = 'd'; break; 
	case 4: loc.y = 'e'; break; 
	}
	return loc;
}

Location fire()
{
	Location loc;
	cout << "Input a x coordinate from 1 to 5: ";
	cin >> loc.x;
	cout << "Input a y coordinate from a to e: ";
	cin >> loc.y;
	return loc;
}

bool match(const Ship a, Location l)
{
	if ((a.loc.x == l.x) && (a.loc.y == l.y))
		return true;
	else
		return false;
}

int check(const Ship a[], Location l)
{
	for (int i = 0; i < fleetSize; ++i)
	{
		if (match(a[i], l) == true)
			return i;
	}
	return -1;
}

void deploy(Ship a[])
{
	for (int i = 0; i < fleetSize; ++i)
	{
		Location l = pick();
		while (check(a, l) != -1)
		{
			l = pick();
		}
		a[i].loc = l;
		a[i].sunk = false;
	}
}

void printShip(const Ship a)
{
	cout << "Ship location: " << a.loc.x << a.loc.y << " and is: ";
	if (a.sunk == true)
		cout << "sunk" << endl;
	else
		cout << "afloat" << endl;
}

void printFleet(const Ship a[])
{
	for (int i = 0; i < fleetSize; ++i)
	{
		printShip(a[i]);
	}
}

bool operational(const Ship a[])
{
	for (int i = 0; i < fleetSize; ++i)
	{
		if (a[i].sunk != true) //afloat
		{ return true; }       //operational
		else
		{ continue; }
	}
	return false;
}

void sink(Ship& a) 
{
	a.sunk = true;
}
