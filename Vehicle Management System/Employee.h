//Chris Harris
//CSC 330 Project 1 
#include<string>
#include<vector>  //STL
using namespace std;

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee {
private:
	string name;
	int employeeID;
	vector<string> vehicleHistory;
public:
	Employee() { name = ""; employeeID = -1; }
	//pastVehicles ia string where 
	//every digit represents an ID of a vehicle that employee checked out in the past
	Employee(string n, int ID, string pastVehicles) {
		name = n; 
		employeeID = ID; 
		for (int i = 0; i < pastVehicles.length(); i++) {
			vehicleHistory.push_back(string(1,(pastVehicles[i])));
		}
	}
	string getName() { return name; }
	void setName(string n) { name = n; }
	int getID() { return employeeID; }
	void setID(int ID) { employeeID = ID; }
	void addVehicle(string ID) { vehicleHistory.push_back(ID); }
	//this function without parameter is used to display the vehicle history to the screen 
	void displayHistory() {
		for (int i = 0; i < vehicleHistory.size(); i++) {
			cout << "This employee has used a vehicle with ID: " << vehicleHistory.at(i) << " ";
		}
	}
	//this function with a parameter is used to write vehicle history to the output file 
	//in the proper format to be read back in on next use 
	void displayHistory(ofstream& outFile) {
		for (int i = 0; i < vehicleHistory.size(); i++) {
			outFile << vehicleHistory.at(i);
		}
		outFile << endl;
	}
};

#endif 
