#include "bsOcean.h"
#include "bsShip.h"
#include <iostream>
int main()
{
	bsOcean ocean;
	ocean.randPlaceBs();
	std::string location;
	while (!ocean.isAllSunk())
	{
		ocean.display();
		std::cout << std::endl;

		std::cout << "Please enter the location to fire at (A1 to J0): ";
		std::cin >> location;
		ocean.shot(location);
	}
	ocean.display();
	std::cout << std::endl;
	std::cout << "All ships are sunk. You Win!";
	return 0;
}