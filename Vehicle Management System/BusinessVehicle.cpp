//Chris Harris 
//CSC 330 Project 1 

#include "BusinessVehicle.h"

BusinessVehicle::BusinessVehicle(int usage, int ID ,int miles, double mpg, bool status, string name,string time, string date,string purpose)
:Vehicle(usage, ID, miles, mpg, status, name, time, date) {   //use base class constructor
	this->purposeOfTrip = purpose;
}
string BusinessVehicle::getPurpose() {
	return this->purposeOfTrip;
}
void BusinessVehicle::setPurpose(string p) {
	this->purposeOfTrip = p;
}

void BusinessVehicle::print() {
	Vehicle::print();
	cout << "Reason for Trip: " << purposeOfTrip << endl;
	cout << "Passengers: ";
	if (getNumPass() == 0) {
		cout << "There are no passengers";
	}
	else {
		for (int i = 0; i < getNumPass(); i++) {
			cout << getPassengerAt(i) << " ";
		}
	}
	cout << endl;
}
void BusinessVehicle::writeToFile(ofstream& outFile) {
	Vehicle::writeToFile(outFile);
	outFile << purposeOfTrip << endl;
}

void BusinessVehicle::writeToPassengersFile(ofstream & outFile){
	if (getNumPass() == 0) {
		outFile << "2 0";
	}
	else {
		outFile << "2 ";
		for (int i = 0; i < getNumPass(); i++) {
			outFile << getPassengerAt(i) << " ";
		}
	}
	outFile << endl;
}
