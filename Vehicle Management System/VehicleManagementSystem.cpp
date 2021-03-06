//Chris Harris 
//CSC 330 Project 1 

#include <iostream>
#include "Menu.h"
int main()
{
	Menu m;
	bool goOn = true;
	char val;

	//fill in vectors from database(txt file)
	m.readInVehicle();
	m.readInEmployee();
	m.readInPassengers();
	//loop for menu operations 
	while (goOn) {
		m.displayOpeningScreen();
		cout << "Would you like to continue? (Y/N): ";
		cin >> val;
		if (val == 'N' || val == 'n') {
			goOn = false;
			cout << "Thank you for using the Vehicle Management System!" << endl;
		}
	}
	//write back to database(txt file) with updated info
	m.outputVehicle();
	m.outputEmployee();
	m.outputPassengers();

}


