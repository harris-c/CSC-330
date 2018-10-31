//Chris Harris
//CSC 330 Project 1 

#ifndef PASSENGERS
#define PASSENGERS

#include<vector>  //STL
#include<string>
using namespace std;
//Passengers is used to hold a list of all passengers who travel in a business or personal use vehicle 
class Passengers {
private:
	vector<string> passList;
	int numPass;
public:
	void addPassenger(string s);
	void removePassenger(string s);
	int getNumPass();
	void updateNumPass();
	string getPassengerAt(int i);
};
#include"Passengers.cpp"
#endif