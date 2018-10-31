//Chris Harris 
//CSC 330 Project 1 

#include"Vehicle.h"
#include"Passengers.h"

#ifndef PERSONAL_VEHICLE
#define PERSONAL_VEHICLE

class PersonalUseVehicle : public Vehicle , public Passengers{  //public Inheritance
private:
	string insuranceCompany;
	int policyNumber;
public:
	PersonalUseVehicle(int usage, int ID, int miles, double mpg, bool status, string name, string time, string date, string insuranceCo, int polNum);
	string getInsuranceCompany();
	void setInsuranceCompany(string s);
	int getPolicyNum();
	void setPolicyNum(int n);
	virtual void print();
	virtual void writeToFile(ofstream&);
	virtual void writeToPassengersFile(ofstream&);
};

#include "PersonalUseVehicle.cpp"
#endif 
