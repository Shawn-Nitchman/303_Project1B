#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "priorityQueue.h"
#include "Library.h"

using namespace std;

int main() {

	/*Employee E("Eric", 1);
	Employee A("Aaron", 2);
	Employee I("Isabelle", 3);
	Employee O("Orion", 4);

	vector<Employee> vectorE;
	vectorE.push_back(E);
	vectorE.push_back(A);
	vectorE.push_back(I);
	vectorE.push_back(O);

	map<int, int> x;
	int size = 4;
	for (int i = 0; i < size; i++) {
		x.emplace(vectorE.at(i), vectorE.at(i).retainTime);
	}

	for (auto const& y : x) {
		cout << y.first << endl;
	}*/


	/*Date a, b;
	a = Date(2020, 1, 1, US);
	b = Date(2020, 1, 5, US);
	cout << b - a << endl;

	a.add_days(400000000);
	cout << a.getMonth() << " " << a.getDay() << " " << a.getYear() << endl;*/

	queue<string> names;
	names.push("Rich");
	names.push("Debbie");
	names.push("Robin");
	names.push("Dustin");
	names.push("Jonathan");

	int temp = names.size();
	for (int i = 0; i < temp; i++) {
		cout << names.front() << " ";
		names.pop();
	}
	return 0;
}




/*
	Date date_1(2013, 2, 10); //add a date with the US format(mm-dd-yyy). The date is Feb 10, 2013
	Date date_2(2014, 5, 1); //add a date with the US format(mm-dd-yyy). The date is May 1, 2014
	Date date_3("5-1-2014"); //add a date with the US format(mm-dd-yyyy), the date is May 1, 2014
	Date date_4("2014-5-1", DateFormat::Standard); //add a date with the standard format(yyyy-mm--dd), the date is May 1, 2014
	date_1.add_days(5); //add 5 days to date_1
	bool larger = date_1 > date_2; //compare if date_1 > date_2
	bool equal = date_1 == date_2; //compare if date_1 == date_2
	string text = date_1.toString(); //conver date_1 to string (the string will be made based on the format
	*/

