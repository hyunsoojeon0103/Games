/*****************************************************************************
Programmer: Hyeon Su Jeon
Date Written : 11 / 4 / 2017
Purpose : Program Battleships Assignment (Resubmission)

CONSTRUCTORS & DESTRUCTOR
- Default constructor that initilizes its members and populate grid(array) with 'O'

MUTATOR MEMBERS
void randPlaceBs - will place battleships randomly on board, avoiding collision 
	and going off grid
void shot - will call shot function of bsShip and change the character on the spot
	to 'H' if true, or 'M' if not

ACCESSOR MEMBERS
bool isAllSunk - will return a boolean of whether or not every ship is sunk
bool isColliding - will return a boolean of whether the ships overlap
bool isOffGrid - will return a boolean of whether the ships are off grid
****************************************************************************/
#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "bsShip.h"
class bsOcean
{
public:
	static const unsigned short HEIGHT=10;
	static const unsigned short WIDTH=10;
	static const unsigned short shipCtr = 5;
	static const char CHARACTER[HEIGHT];
	bsOcean();
	~bsOcean();
	void randPlaceBs();
	void shot(const std::string& coordIn);
	void display();
	bool isAllSunk()const;
private:
	bool isColliding(const unsigned short index,const unsigned short locIn,const unsigned short orIn)const;
	bool isOffGrid(unsigned short index, const unsigned short locIn, const unsigned short orIn)const;
	char grid[HEIGHT*WIDTH];
	bsShip* ship;
};