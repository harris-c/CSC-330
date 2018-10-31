//Chris Harris
//CSC 330

#include "Passengers.h"

void Passengers::addPassenger(string s) {
	passList.push_back(s);
}
void Passengers::removePassenger(string s) {
	for (int i = 0; i < passList.size(); i++) {
		//checking on ID because 2 employees can have same name 
		if (passList.at(i) == s) {
			passList.erase(passList.begin() + i);
		}
	}
}
int Passengers::getNumPass() {
	return this->numPass;
}
void Passengers::updateNumPass() {
	this->numPass = passList.size();
}

string Passengers::getPassengerAt(int i)
{
	return passList.at(i);
}
