/*****************************************************************************
Programmer: Hyeon Su Jeon
	Date Written : 11 / 4 / 2017
	Purpose : Program Battleships Assignment (Resubmission)

	CONSTRUCTORS & DESTRUCTOR
	- Default constructor that initializes its members

	MUTATOR MEMBERS
	void set - will pass the passed arguments to the matching setters and then
		will assign locations to the ship based on its orientation and size
	void setShip - will set the ship's name and size
	void setStartingLoc - will set the starting location
	void setOrientation - will set its orientation

	ACCESSOR MEMBERS
	unsigned short getStartingLoc - will return startingLocation
	unsigned short getShipSize - will return size
	unsigned short getShipLoc- return the pointer pointing at the array of the ship's locations
	string getName - will return name
	bool isVertical - will return a boolean of the orientaition
	bool isSunk - will return a boolean of whether the ship is sunk or not

	Non-member function
	unsigned short converter - will convert a string of coordinates and return
		the numeric value of the coordinate
****************************************************************************/
#pragma once
#include <string>
#include <cassert>
class bsShip
{
public:
	static const std::string SHIPNAME[5];
	static const unsigned short SHIPSIZE[5];
	static const unsigned short numOfShips;
	static const unsigned short TEN;
	bsShip();
	~bsShip();
	void set(const unsigned short shipIndex, const unsigned short locIn, const bool isVert);
	void setShip(const unsigned short index);
	void setStartingLoc(const unsigned short locIn);
	void setOrientation(const bool orIn);
	unsigned short getStartingLoc()const;
	unsigned short getShipSize()const;
	unsigned short* getShipLoc()const;
	std::string getName()const;
	bool isVertical()const;
	bool shot(const std::string& coordIn);
	bool isSunk()const;
private:
	std::string name;
	unsigned short startingLocation;
	unsigned short size;
	unsigned short hitCtr;
	unsigned short* shipLoc;
	bool vertical;

};
	unsigned short converter(const std::string& coordIn);