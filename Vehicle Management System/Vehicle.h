//Chris Harris
//CSC 330 Project 1

#include <string>
#include<fstream>
using namespace std;

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
private:
	//general to every vehicle
	int id;
	int mileage;
	double fuelEfficency; //miles per gallon
	bool isInGarage;	 //true if in garage, false otherwise 
	int usage;
	string timeOfJourney;
	string date;
	string driver;
public:
	Vehicle(int,int, int, double, bool, string, string ,string);
	int getId();
	void setID(int);
	int getMileage();
	void setMileage(int);
	double getFuelEfficency();
	void setFuelEfficency(double);
	bool getStatus();
	void setStatus(bool);
	int getUsage();
	void setUsage(int);
	string getTime();
	void setTime(string);
	string getDate();
	void setDate(string d);
	void setDriver(string);
	string getDriver();
	//these 3 functions are declared virtual so that they can be overridden in derived classes
	//via polymorphism 
	virtual void print();    //used to print information to the screen 
	virtual void writeToFile(ofstream&);    //used to output vehicle information to the database file 
	virtual void writeToPassengersFile(ofstream&);  //used to output list of passengers to passenger database file 

};
#include "Vehicle.cpp"
#endif 

