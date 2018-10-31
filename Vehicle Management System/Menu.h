//Chris Harris
//CSC 330 Project 1

#ifndef MENU
#define MENU

#include "BusinessVehicle.h"
#include "CargoVehicle.h"
#include "Employee.h"
#include "PersonalUseVehicle.h"


class Menu {
private:
	vector<Vehicle*> vehicleList;  //STL
	vector<Employee> employeeList; //STL
public:
	void displayOpeningScreen();
	void readInVehicle();
	void readInEmployee();
	void readInPassengers();
	void outputVehicle();
	void outputEmployee();
	void outputPassengers();
	void displayMenu();
	void handleMenuOption();
	bool verifyEmployeeID(int);
	void vehicleCheckIn();
	void vehicleCheckOut();
	void vehicleSearch();
	void employeeHistory();
	int getVehicleFromID(int);
};

#include"Menu.cpp"
#endif
