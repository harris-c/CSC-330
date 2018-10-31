//Chris Harris
//CSC 330 Project 1 

#include "Menu.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<iterator>
using namespace std;

//use global variables to hold this info
//similar to setting a cookie in Web Dev
int employeeID;		//set in verifyEmployeeID
int posOfEmployee;  //set in verifyEmployeeID

void Menu::displayOpeningScreen() {
	int ID;
	cout << "Welcome to the Vehicle Management System!" << endl;
	cout << "Please enter your employee ID to access the system: ";
	cin >> ID;
	cout << endl;
	if (verifyEmployeeID(ID) == true) {
		displayMenu();
	}
	else {
		cout << "Error! Invalid employee ID entered!";
	}
}
void Menu::readInVehicle() {
	ifstream inFile;
	string line;
	inFile.open("vehicles.txt.txt");
	if (inFile.is_open() == false) {
		cout << "Error opening file";
	}

	while (getline(inFile, line)) {
		string temp;

		//break up each line into vector
		//boundary is determined by whitespace 
		istringstream iss(line);
		vector<string> tokens{ istream_iterator<string>(iss), istream_iterator<string>() };
		//convert 1/0 from string to bool
		bool b;
		stringstream(tokens[4]) >> b;
	
		//determines type of Vehicle based on usage 
		// 1 = cargo , 2 = business, 3 = personal

		//test for cargo vehicle
		if (tokens.at(0) == "1") {
		//if the cargo name is composed of multiple words combine into 1 string 
			if (tokens.size() > 10) {
				for (int i = 8; i < tokens.size() - 1; i++) {
					temp += tokens[i] + " ";
				}
			}else {
				temp = tokens[8];
			}
			vehicleList.push_back(new CargoVehicle(1, stoi(tokens[1]), stoi(tokens[2]), stod(tokens[3]), b, tokens[5], tokens[6], tokens[7], temp, stoi(tokens[tokens.size()-1])));
		}
		//test for business vehicle 
		else if (tokens.at(0) == "2") {
			//if the purpose of trip is composed of multiple words combine into 1 string 
			if (tokens.size() > 9) {
				for (int i = 8; i < tokens.size() ; i++) {
					temp += tokens[i] + " ";
				}
			}else {
				temp = tokens[8];
			}
			vehicleList.push_back(new BusinessVehicle(2, stoi(tokens[1]), stoi(tokens[2]), stod(tokens[3]), b, tokens[5], tokens[6], tokens[7],temp));
		}
		///must be personal use vehicle 
		else {
			//if the insurance company name is composed of multiple words combine into 1 string 
			if (tokens.size() > 10) {
				for (int i = 8; i < tokens.size() - 1; i++) {
					temp += tokens[i] + " ";
				}
			}else {
				temp = tokens[8];
			}
			vehicleList.push_back(new PersonalUseVehicle(3, stoi(tokens[1]), stoi(tokens[2]), stod(tokens[3]), b, tokens[5],tokens[6],tokens[7], temp, stoi(tokens[tokens.size()-1])));
		}
	}
	inFile.close();
}
void Menu::readInEmployee() {
	ifstream inFile;
	string line, tempName;
	
	inFile.open("employees.txt");
	while (getline(inFile, line)) {
		//break up each line into vector
		//boundary is determined by whitespace 
		istringstream iss(line);
		vector<string> tokens{ istream_iterator<string>(iss), istream_iterator<string>() };

		tempName = tokens[0] + " " + tokens[1];
		employeeList.push_back(Employee(tempName,stoi(tokens[2]), tokens[3]));
	}
	inFile.close();

}
void Menu::readInPassengers() {
	ifstream inFile;
	string line, tempName;
	
	inFile.open("passengerList.txt");
	while (getline(inFile, line)) {
		//break up each line into vector
		//boundary is determined by whitespace 
		istringstream iss(line);
		vector<string> tokens{ istream_iterator<string>(iss), istream_iterator<string>() };
		//if tokens[1] == 0, then there are no passengers
		if (tokens[1] != "0") {
			int vIndex = getVehicleFromID(stoi(tokens[0]));

			//test for business vehicle 
			if (BusinessVehicle* BV = dynamic_cast<BusinessVehicle*> (vehicleList.at(vIndex))) {
				for (int i = 0; i < tokens.size()-1; i++) {
					static_cast<BusinessVehicle*>(vehicleList.at(vIndex))->addPassenger(tokens[i+1]);
				}
				static_cast<BusinessVehicle*>(vehicleList.at(vIndex))->updateNumPass();
			}

			//test for personal use vehicle
			else if (PersonalUseVehicle* PV = dynamic_cast<PersonalUseVehicle*> (vehicleList.at(vIndex))) {
				for (int i = 0; i < tokens.size()-1; i++) {
					static_cast<PersonalUseVehicle*>(vehicleList.at(vIndex))->addPassenger(tokens[i+1]);
				}
				static_cast<PersonalUseVehicle*>(vehicleList.at(vIndex))->updateNumPass();
			}
		}	
	}
	inFile.close();
}
//write vehicle data to file
void Menu::outputVehicle() {
	ofstream outFile;
	outFile.open("vehicles.txt.txt");
	for (int i = 0; i < vehicleList.size(); i++) {
		vehicleList.at(i)->writeToFile(outFile);
	}
	outFile.close();
}
//write employee data to file 
void Menu::outputEmployee() {
	ofstream outFile;
	outFile.open("employees.txt");

	for (int i = 0; i < employeeList.size(); i++) {
		outFile << employeeList.at(i).getName() << " " << employeeList.at(i).getID() << " ";
		employeeList.at(i).displayHistory(outFile);
	}
	outFile.close();
}
//output passenger data to file 
void Menu::outputPassengers() {
	ofstream outFile;
	outFile.open("passengerList.txt");

	for (int i = 0; i < vehicleList.size(); i++) {
		vehicleList.at(i)->writeToPassengersFile(outFile);
	}
	outFile.close();
}
//show menu options 
void Menu::displayMenu() {
	cout << "Please enter the number of the option you would like" << endl;
	cout << "1. Check out a vehicle" << endl;
	cout << "2. Check in a vehicle" << endl;
	cout << "3. Search for a vehicle" << endl;
	cout << "4. View employee history;" << endl;
	handleMenuOption();
}
//call appropriate function given user input
void Menu::handleMenuOption() {
	int input;
	cin >> input;
	if (input == 1) {
		vehicleCheckOut();
	}else if (input == 2) {
		vehicleCheckIn();
	}else if (input == 3) {
		vehicleSearch();
	}else {
		employeeHistory();
	}
}
//checks to see if a given ID matches up to an employee in the system 
bool Menu::verifyEmployeeID(int ID) {
	for (int i = 0; i < employeeList.size(); i++) {
		if (ID == employeeList.at(i).getID()) {
			employeeID = ID;
			posOfEmployee = i;
			return true;
		}
	}
	return false;
}
//process to check in a vehicle to the garage 
void Menu::vehicleCheckIn() {
	int vehicleID, newMiles, posOfVehicle;
	string date , time;

	//get info for vehicles of all types 
	cout << "Enter the ID of the vehicle you are returning: ";
	cin >> vehicleID;
	cout << "Enter the mileage of the vehicle you are returning: ";
	cin >> newMiles;
	cout << "Enter the current time: ";
	cin >> time;
	cout << "Enter the current date(mm/dd/yy): ";
	cin >> date;

	posOfVehicle = getVehicleFromID(vehicleID);

	// make the vehicle available in the garage 
	//record the new mileage, time and date it was returned, and clear out driver name 
	vehicleList.at(posOfVehicle)->setStatus(true);
	vehicleList.at(posOfVehicle)->setMileage(newMiles);	
	vehicleList.at(posOfVehicle)->setTime(time);
	vehicleList.at(posOfVehicle)->setDate(date);
	vehicleList.at(posOfVehicle)->setDriver("n/a");

	//clear out Vehicle- type specific values 
	//test for cargo vehicles 
	if (CargoVehicle* CV = dynamic_cast<CargoVehicle*> (vehicleList.at(posOfVehicle))) {
		static_cast<CargoVehicle*>(vehicleList.at(posOfVehicle))->setCargoName("n/a");
		static_cast<CargoVehicle*>(vehicleList.at(posOfVehicle))->setCargoQuantity(0);
	} 
	//test for business vehicles 
	else if (BusinessVehicle* BV = dynamic_cast<BusinessVehicle*> (vehicleList.at(posOfVehicle))) {
		static_cast<BusinessVehicle*>(vehicleList.at(posOfVehicle))->setPurpose("n/a");
	}
	//test for personal vehicles 
	else {
		static_cast<PersonalUseVehicle*>(vehicleList.at(posOfVehicle))->setInsuranceCompany("n/a");
		static_cast<PersonalUseVehicle*>(vehicleList.at(posOfVehicle))->setPolicyNum(0);
	}
}
//process to check out a vehicle 
void Menu::vehicleCheckOut( ) {

	int vehicleID;
	string time, date;
	//get info for all vehicles, regardless of type
	cout << "Enter the ID of the vehicle you are taking out: ";
	cin >> vehicleID;
	cout << "Enter the current time: ";
	cin >> time;
	cout << "Enter the current date(mm/dd/yy): ";
	cin >> date;

	int vIndex = getVehicleFromID(vehicleID);

	//set input from user 
	vehicleList.at(vIndex)->setStatus(false);
	vehicleList.at(vIndex)->setTime(time);
	vehicleList.at(vIndex)->setDate(date);
	vehicleList.at(vIndex)->setDriver(employeeList.at(posOfEmployee).getName());
	employeeList.at(posOfEmployee).addVehicle(to_string(vehicleID));

	//test for cargo vehicle 
	if (CargoVehicle* CV = dynamic_cast<CargoVehicle*> (vehicleList.at(vIndex))) {
		//get and set cargo name and quantity
		cout << "Enter the name of the cargo you are transporting: ";
		cin >> time;
		cout << endl;
		static_cast<CargoVehicle*>(vehicleList.at(vIndex))->setCargoName(time);
		cout << "Enter the quantity of the cargo you are transporting: ";
		cin >> vehicleID;
		cout << endl;
		static_cast<CargoVehicle*>(vehicleList.at(vIndex))->setCargoQuantity(vehicleID);
	}
	//test for business vehicles 
	else if (BusinessVehicle* BV = dynamic_cast<BusinessVehicle*> (vehicleList.at(vIndex))) {
		//get and set putpose of trip and passengers 
		cout << "Enter the reason for the business trip: ";
		cin.ignore();
		getline(cin, time);
		static_cast<BusinessVehicle*>(vehicleList.at(vIndex))->setPurpose(time);
		cout << "If there are any passengers traveling with you, enter one name at a time, followed by ENTER" << endl;
		cout << "When you are done entering names, or, if there are no passengers, please enter 0" << endl;
		cout << "Passengers: ";
		cin >> time;
		while (time != "0") {
			static_cast<BusinessVehicle*>(vehicleList.at(vIndex))->addPassenger(time);
			cin >> time;
		}
	} 
	//test for personal use vehicles 
	else {
		//get and set insurance info and passengers 
		cout << "Enter your insurance company: ";
		cin >> time;
		cout << endl;
		static_cast<PersonalUseVehicle*>(vehicleList.at(vIndex))->setInsuranceCompany(time);
		cout << "Enter your insurance policy number: ";
		cin >> vehicleID;
		static_cast<PersonalUseVehicle*>(vehicleList.at(vIndex))->setPolicyNum(vehicleID);
		cout << "If there are any passengers traveling with you, enter one name at a time, followed by ENTER " << endl;
		cout << "When you are done entering names, or, if there are no passengers, please enter 0" << endl;
		cout << "Passengers: ";
		cin >> time;
		while (time != "0") {
			static_cast<PersonalUseVehicle*>(vehicleList.at(vIndex))->addPassenger(time);
			cin >> time;
		}

	}
}
//display info for a vehicle
void Menu::vehicleSearch() {
	int targetVehicle;
	cout << "Enter a vehicle id to search for that vehicle, or enter 0 to search for all vehicles: ";
	cin >> targetVehicle;
	if (targetVehicle > 0) {
		 vehicleList.at(getVehicleFromID(targetVehicle))->print();
	}
	else {
		for (int i = 0; i < vehicleList.size(); i++) {
			vehicleList.at(i)->print();
			cout << endl;
		}
	}
}
//show ID #'s of vehicles this employee has taken out in the past 
void Menu::employeeHistory( ) {
	employeeList.at(posOfEmployee).displayHistory();
}
//return position of vehicle in vehicleList vector given an ID number 
int Menu::getVehicleFromID(int ID) {
	for (int i = 0; i < vehicleList.size(); i++) {
		if (ID == vehicleList.at(i)->getId()) {
			return i;
		}
	}
	return -1;
}
