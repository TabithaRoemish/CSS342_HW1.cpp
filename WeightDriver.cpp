//WeightDriver.cpp
// Functions: main()
// Programmer: Tabitha Roemish
// Date: October 8, 2017

#include "Weight.h"
#include <iostream>
void createnDestroy();
using namespace std;

int main()
{
	Weight wt1(5, 8);
	Weight wt2(9, 7);
	Weight wt3;

	//Sample variables
	cout << "Here are some sample weights." << endl;
	cout << "wt1: " << wt1 << endl;
	cout << "wt2: " << wt2 << endl;
	cout << endl;

	//Test arithmetic operators(+, =+, *)
	cout << "wt1 + wt2: "<< wt1 + wt2 << endl;
	wt1 += wt2;
	cout << "wt1 += wt2: (wt1 = " << wt1 << ")" << endl;
	cout << "wt2 * 3: " << wt2 * 3 << endl;
	cout << endl;

	//Get Weight input
	cout << "Please enter a weight in pounds and ounces. ";
	cout << "Enter two numbers separated by a space.Ex) 5 8\n";
	readInput(wt3); //loops if bad input, asks for good input
	cout << "You entered " << wt3 << endl;

	//Test comparison operators (>, =, <)
	if (wt3 > wt1)
		cout << "This weight is larger than wt1: " << wt1;
	else if (wt3 == wt1)
		cout << "This weight is equal to wt1: " << wt1;
	else
		cout << "This weight is smaller than wt1: " << wt1 << endl;


	//End of program
	cout << endl;
	cout << "This is the end of the program. Thanks.";
	cin.get();
	cin.get(); //hold window open

	return 0;
}

void createnDestroy()
{
	Weight x;
}