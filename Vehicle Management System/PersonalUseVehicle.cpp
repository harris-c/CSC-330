//Chris Harris
//CSC 330 Project 1 

#include "PersonalUseVehicle.h"

PersonalUseVehicle::PersonalUseVehicle(int use,int ID, int miles, double mpg, bool status,string name,string time, string date, string insuranceCo, int polNum)
	: Vehicle(use, ID ,miles, mpg, status, name, time, date) {
	this->insuranceCompany = insuranceCo;
	this->policyNumber = polNum;
}
string PersonalUseVehicle::getInsuranceCompany() {
	return this->insuranceCompany;
}
void PersonalUseVehicle::setInsuranceCompany(string s) {
	this->insuranceCompany = s;
}
int PersonalUseVehicle::getPolicyNum() {
	return this->policyNumber;
}
void PersonalUseVehicle::setPolicyNum(int n) {
	this->policyNumber = n;
}

void PersonalUseVehicle::print() {
	Vehicle::print();
	cout << "Insurance Company: " << insuranceCompany << endl;
	cout << "Policy Number: " << policyNumber << endl;
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
void PersonalUseVehicle::writeToFile(ofstream& outFile) {
	Vehicle::writeToFile(outFile);
	outFile << insuranceCompany << " " << policyNumber << endl;
}

void PersonalUseVehicle::writeToPassengersFile(ofstream & outFile){
		if (getNumPass() == 0) {
			outFile << "3 0";
		}
		else {
			outFile << "3 ";
			for (int i = 0; i < getNumPass(); i++) {
				outFile << getPassengerAt(i) << " ";
			}
		}
		outFile << endl;
}
