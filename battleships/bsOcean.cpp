#include "bsOcean.h"
const char bsOcean::CHARACTER[HEIGHT] = { 'A','B','C','D','E','F','G','H','I','J'};//not necessary. it is just used for displaying the board

																				   //Pre: none
//Post: grid will be populated with 'O', ship will be set to nullptr, rand generated
bsOcean::bsOcean():ship(nullptr)
{
	for (unsigned short i = 0; i < WIDTH*HEIGHT; ++i)
		grid[i] = 'O';
	srand((unsigned)time(NULL));
}

//pre: none
//post: ship will be deleted
bsOcean::~bsOcean()
{
	delete[]ship;
}

//pre: non
//post: ships will be placed randomly on board without collision and off-grid
void bsOcean::randPlaceBs()
{
	ship = new bsShip[shipCtr];
	for (unsigned short i = 0; i < shipCtr; ++i)
	{
		unsigned short tempShipIndex;
		unsigned short tempStartingLoc;
		unsigned short tempOrientation;
		do
		{
			tempShipIndex = i;
			tempStartingLoc = rand() % 100;
			tempOrientation = rand() % 2;
		} while (isColliding(tempShipIndex, tempStartingLoc, tempOrientation) // making sure the ship doesn't collide with other ships when placed on the location
			|| isOffGrid(tempShipIndex, tempStartingLoc, tempOrientation)); // making sure the ship doesn't go off the grid

		ship[i].set(tempShipIndex, tempStartingLoc, tempOrientation);
	}
}

//pre: the spot of the passed coordinate must be 'O'
//post: if there is a ship placed on the spot, it will be a hit or a miss otherwise
void bsOcean::shot(const std::string& coordIn)
{
	if (grid[converter(coordIn)] != 'O')
		return;
	else
	{
		for (unsigned short i = 0; i < shipCtr; ++i)
		{
			if (ship[i].shot(coordIn))
			{
				grid[converter(coordIn)] = 'H';
				return;
			}
		}
		grid[converter(coordIn)] = 'M';
	}
}

//pre: none
//post: will display the board
void bsOcean::display()
{
	system("cls");
	std::cout << " ";
	for (unsigned short i = 0; i < WIDTH; ++i)
		std::cout << std::setw(3) << (i+1) % WIDTH;

	std::cout << std::endl;

	for (unsigned short row = 0; row < HEIGHT; ++row)
	{
		for (unsigned short col = 0; col < WIDTH; ++col)
		{
			if (col == 0)
				std::cout << CHARACTER[row];

			std::cout << std::setw(3) << grid[HEIGHT*row+col];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (unsigned short i = 0; i < shipCtr; ++i)
		if (ship[i].isSunk())
			std::cout << ship[i].getName() << " has been sunk!!!" << std::endl;
}

//pre: none
//post: will return a boolean of whether everyship is sunk or not
bool bsOcean::isAllSunk()const
{
	unsigned short sunkCtr = 0;
	for (unsigned short i = 0; i < shipCtr; ++i)
		if (ship[i].isSunk())
			++sunkCtr;
	return sunkCtr == shipCtr;
}

//pre: the passed arguments must be valid
//post: will return if there will be a collision of the tested location with the locations of ships on  board
	// or return false if clear
bool bsOcean::isColliding(const unsigned short index, const unsigned short locIn, const unsigned short orIn)const
{
	bsShip temp;
	temp.set(index, locIn, orIn);
	for (unsigned short i = 0; i < shipCtr; ++i)
		for (unsigned short c = 0; c < ship[i].getShipSize(); ++c)
			for (unsigned short z = 0; z < temp.getShipSize(); ++z)
				if (*(ship[i].getShipLoc() + c) == *(temp.getShipLoc() + z)) //checking the passed location against all the locations of ships on board
					return true;
	return false;
}

//pre: index,locIn,orIn must be valid
//post: return true if the passed location for a ship clears the board, or false otherwise
bool bsOcean::isOffGrid(const unsigned short index, const unsigned short locIn, const unsigned short orIn)const
{
	bsShip temp;
	temp.set(index, locIn, orIn);
	unsigned short tempStartingLoc = temp.getStartingLoc();
	unsigned short tempShipSize = temp.getShipSize();
	if (temp.isVertical())
	{
		if ((tempStartingLoc + tempShipSize * HEIGHT) >= HEIGHT*WIDTH)
			return true;
	}
	else
	{
		if (tempStartingLoc % WIDTH + tempShipSize >= WIDTH )
			return true;
	}
	return false;
}