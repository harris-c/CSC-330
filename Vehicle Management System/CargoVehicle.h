//Chris Harris
//CSC 330 Project 1 
#include "Vehicle.h"
#ifndef CARGO_VEHICLE
#define CARGO_VEHICLE


class CargoVehicle : public Vehicle {    //public inhertience 
private:
	string cargoName;
	int cargoQuantity;
public:
	CargoVehicle(int usage, int ID, int miles, double mpg, bool status, string name,string time, string date, string cargo, int quantity);
	string getCargoName();
	void setCargoName(string);
	int getCargoQuantity();
	void setCargoQuantity(int);
	virtual void print();
	virtual void writeToFile(ofstream&);
	virtual void writeToPassengersFile(ofstream&);
};
#include "CargoVehicle.cpp"
#endif