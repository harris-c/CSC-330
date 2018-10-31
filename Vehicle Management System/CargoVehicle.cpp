//Chris Harris
//CSC 330 Project 1

#include "CargoVehicle.h"

CargoVehicle::CargoVehicle(int usage, int ID, int miles, double mpg, bool status,string name,string time, string date, string cargo, int quantity) 
	:Vehicle(usage, ID, miles, mpg, status, name, time, date) {
	this->cargoName = cargo;
	this->cargoQuantity = quantity;
}
string CargoVehicle::getCargoName() {
	return this->cargoName;
}
void CargoVehicle::setCargoName(string n) {
	this->cargoName = n;
}
int CargoVehicle::getCargoQuantity() {
	return this->cargoQuantity;
}
void CargoVehicle::setCargoQuantity(int q) {
	this->cargoQuantity = q;
}

void CargoVehicle::print(){
	Vehicle::print();
	cout << "Cargo Name: " << cargoName << endl;
	cout << "Cargo Quantity: " << cargoQuantity << endl;
}
void CargoVehicle::writeToFile(ofstream& outFile) {
	Vehicle::writeToFile(outFile);
	outFile << cargoName << " " << cargoQuantity << endl;
}

void CargoVehicle::writeToPassengersFile(ofstream & outFile){
	outFile << "1 0" << endl;
}
