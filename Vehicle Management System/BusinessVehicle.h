//Chris Harris
//CSC 330 Project 1

#include"Vehicle.h"
#include "Passengers.h"
using namespace std;
#ifndef BUSINESS_VEHICLE
#define BUSINESS_VEHICLE

class BusinessVehicle : public Vehicle, public Passengers {    //Public Inheritence
private:
	string purposeOfTrip;
public:
	BusinessVehicle(int usage, int ID, int miles, double mpg, bool status,string name,string time, string date, string purpose);
	string getPurpose();
	void setPurpose(string p);
	virtual void print();
	virtual void writeToFile(ofstream&);
	virtual void writeToPassengersFile(ofstream&);

};
#include "BusinessVehicle.cpp"
#endif 
