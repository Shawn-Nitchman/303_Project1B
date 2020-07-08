//Program by James Ta, Shawn Nitchman, Timothy Hoang
#include <iostream>
#include "priorityQueue.h"
#include "Library.h"

using namespace std;

int main() {

	Library x;

	x.addBook("GEAH");
	x.addBook("red fish, blue fish");

	x.addEmployee("James");
	x.addEmployee("Tim");
	x.addEmployee("Shawn");


	x.circulate("GEAH", Date(2020, 7, 7, US));
	x.circulate("red fish, blue fish", Date(2020, 8, 9, US));

	cout << "Green Eggs and Ham" << endl << endl;
	x.getStats();
	x.passOn("GEAH", Date(2020, 7, 10, US));
	x.getStats();
	x.passOn("GEAH", Date(2020, 7, 12, US));
	x.getStats();
	x.passOn("GEAH", Date(2020, 7, 20, US));
	x.getStats();

	cout << "red fish, blue fish" << endl << endl;
	x.getStats();
	x.passOn("red fish, blue fish", Date(2020, 8, 10, US));
	x.getStats();
	x.passOn("red fish, blue fish", Date(2020, 8, 12, US));
	x.getStats();
	x.passOn("red fish, blue fish", Date(2020, 8, 25, US));
	x.getStats();
	x.passOn("red fish, blue fish", Date(2020, 8, 29, US));
	x.getStats();


	return 0;
}
