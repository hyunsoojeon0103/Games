#include "bsShip.h"
const unsigned short bsShip::numOfShips = 5;
const unsigned short bsShip::TEN = 10;
const unsigned short bsShip::SHIPSIZE[numOfShips] = { 5,4,3,3,2 };
const std::string bsShip::SHIPNAME[numOfShips] = { "Carrier","Battleship","Cruiser","Submarine","Destroyer" };

//pre: none
//pre: will initialize the member variables
bsShip::bsShip():startingLocation(-1),size(0),hitCtr(0), shipLoc(nullptr),vertical(false)
{
}

//pre: none
//post: will delete shipLoc
bsShip::~bsShip()
{
	delete[]shipLoc;
}

//pre: the passed locaition must not collide with other ships on board
//post: will assign locations tothe ship based on its size and orientation
void bsShip::set(const unsigned short shipIndex, const unsigned short locIn, const bool orIn)
{	// locIn is already tested and will not collide with other ships and will not go off the grid
	setShip(shipIndex);
	setStartingLoc(locIn);
	setOrientation(orIn);
	shipLoc = new unsigned short[size];
	for (unsigned short i = 0; i < size; ++i)
	{
		if (vertical)
			shipLoc[i] = startingLocation + i * TEN;
		else
			shipLoc[i] = startingLocation + i;
	}
}

//pre: index must be valid
//post: name and size will be assigned its name and size
void bsShip::setShip(const unsigned short index)
{
	assert(index >= 0 && index < numOfShips);
	name = SHIPNAME[index];
	size = SHIPSIZE[index];
}

//pre: locIn must be within the 10 by 10 board
//post: locIn will be assigned to startingLocation
void bsShip::setStartingLoc(const unsigned short locIn)
{
	assert(locIn >= 0 && locIn < TEN*TEN);
	startingLocation = locIn;
}

//pre: none
//post: orientation will be assigned
void bsShip::setOrientation(const bool orIn)
{
	vertical = orIn;
}

//pre: none
//post: will return startingLocation
unsigned short bsShip::getStartingLoc()const
{
	return startingLocation;
}

//pre: none
//post: will return size
unsigned short bsShip::getShipSize()const
{
	return size;
}

//pre: none
//post: will return shipLoc
unsigned short* bsShip::getShipLoc()const
{
	return shipLoc;
}

//pre: none
//post: will return name
std::string bsShip::getName()const
{
	return name;
}

//pre: none
//post: will return true if vertical, false if horizontal
bool bsShip::isVertical()const
{
	return vertical;
}

//pre: coordIn must be valid(0 <= coord < 100) when converted
//post: if there is a block of a ship on the spot, it will return true and increment
	// hitCtr
bool bsShip::shot(const std::string& coordIn)
{
	unsigned short coord = converter(coordIn);
	for (unsigned short i = 0; i < size; ++i)
		if (shipLoc[i] == coord)
		{
			++hitCtr;
			return true;
		}
	return false;
}

//pre: none
//post: will return a boolean of whether if the ship is sunk
bool bsShip::isSunk()const
{
	return hitCtr == size;
}

//pre: the first character must be valid('A' <= coordIn <= 'J'
//	and length must be 2 characters long
//post: will return the numeric value of the passed string
unsigned short converter(const std::string& coordIn)
{
	assert(coordIn.length() == 2);
	char firstChar = toupper(coordIn.at(0));
	char secondChar = coordIn.at(1);
	assert(firstChar >= 'A' && firstChar <= 'J');
	unsigned short first;
	unsigned short second;
	for (unsigned short i = 0; i < bsShip::TEN; ++i)
		if ('A'+i == firstChar)
			first = i;
	if (secondChar == '0')
		second = bsShip::TEN;
	else
		second = secondChar - '0';
	return (first * bsShip::TEN + second - 1);
}