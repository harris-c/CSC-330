//Chris Harris
//CSC 330 Project 1 
#include "Vehicle.h"

Vehicle::Vehicle(int usage, int ID, int miles, double mpg, bool status, string name, string time, string date) {
	this->usage = usage;
	this->id = ID;
	this->mileage = miles;
	this->fuelEfficency = mpg;
	this->isInGarage = status;
	this->driver = name;
	this->timeOfJourney = time;
	this->date = date;
}
int Vehicle::getId(){
	return this->id;
}
void Vehicle::setID(int ID) {
	this->id = ID;
}
int Vehicle::getMileage() {
	return this->mileage;
}
void Vehicle::setMileage(int miles) {
	this->mileage = miles;
}
double Vehicle::getFuelEfficency() {
	return this->fuelEfficency;
}
void Vehicle::setFuelEfficency(double mpg) {
	this->fuelEfficency = mpg;
}
bool Vehicle::getStatus() {
	return this->isInGarage;
}
void Vehicle::setStatus(bool stat) {
	this->isInGarage = stat;
}
int Vehicle::getUsage() {
	return this->usage;
}
void Vehicle::setUsage(int u) {
	this->usage = u;
}
string Vehicle::getTime() {
	return this->timeOfJourney;
;
}
void Vehicle::setTime(string t) {
	this->timeOfJourney = t;
}
string Vehicle::getDate() {
	return date;
}
void Vehicle::setDate(string d) {
	this->date = d;
}
void Vehicle::setDriver(string d){
	driver = d;
}

string Vehicle::getDriver()
{
	return driver;
}
//this print function prints information relevant to all vehicles 
void Vehicle::print(){
	if (usage == 1){
		cout <<"Cargo Vehicle" <<endl;
	}
	else if (usage == 2) {
		cout << "Business Vehicle " << endl;
	}
	else {
		cout << "Personal Use Vehicle " << endl;
	}
	cout << "ID Number: " << id << endl;
	cout << "Mileage: " << mileage << endl;
	cout << "Fuel Efficiency: " << fuelEfficency<< endl;
	if (isInGarage == true) {
		cout << "In Garage?: yes" << endl;
	} else {
		cout << "In Garage?: no" << endl;
	}
	cout << "Driver: " << driver << endl;
	cout << "Time In/Out:" << timeOfJourney << endl;
	cout << "Date In/Out: " << date << endl;
}
//this writeToFile function outputs information relevant to all vehicles 
void Vehicle::writeToFile(ofstream& outFile) {
	outFile << usage <<" " << id << " " << mileage << " " << fuelEfficency << " " << isInGarage << " " << driver << " " << timeOfJourney << " " << date << " ";
}

void Vehicle::writeToPassengersFile(ofstream & outFile){
}
