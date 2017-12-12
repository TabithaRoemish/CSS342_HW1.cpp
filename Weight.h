//File: Weight.h
//	File includes class Weight Declaration and Defintions. 
//	Programmer: Tabitha Roemish
//	Date: October 8, 2017
#ifndef WEIGHT_H
#define WEIGHT_H
#include <iostream>

#define OZ_LIMIT 16

using namespace std;
//Class, Weight Declaration
class Weight
{
public:
	Weight(int lbs = 0, int oz = 0);
	virtual ~Weight() { };

	//accessors
	int getPounds() const { return Pounds; };
	int getOunces() const { return Ounces; };
	void setPounds(int num) { Pounds = num; };
	void setOunces(int num);


	//Operator overloads
	Weight operator=(const Weight &wt);
	Weight operator+(const Weight & wt) const;
	Weight& operator+=(const Weight & wt);
	Weight operator*(int num) const;

	bool operator>(const Weight & wt) const;
	bool operator<(const Weight & wt) const;
	bool operator==(const Weight & wt) const;

private:
	int Pounds;
	int Ounces;
};

ostream& operator<<(ostream& out, const Weight &wt)
{
	out << wt.getPounds() << " lbs ";
	out << wt.getOunces() << " oz";
	return out;
}
istream& operator>>(istream& in, Weight &wt)
{
	int lbs = 0;
	int oz = 0;

	if (cin >> lbs)
	{
		wt.setPounds(lbs);
		if (cin >> oz)
			wt.setOunces(oz);
	}
	return in;
}

void readInput(Weight & wt)
{
	while (!(cin >> wt))
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter weight as two numbers separated by a space. ex) 5 8\n";
	}
}
// -------------------------------------------------
// Weight Definitions
//--------------------------------------------------

Weight::Weight(int lbs, int oz)
{
	Pounds = lbs;
	setOunces(oz);
}

void Weight::setOunces(int num)
{
	if (num < 16)
		Ounces = num;
	else
	{
		Pounds += num / OZ_LIMIT;
		Ounces = num % OZ_LIMIT;
	}
}

//Assignment overload
Weight Weight::operator=(const Weight & wt)
{
	if (this != &wt)
	{
		Pounds = wt.Pounds;
		Ounces = wt.Ounces;
	}
	return *this;
}

//Operator Overloads - Arithmetic
Weight Weight::operator+(const Weight & wt) const
{
	Weight value(Pounds+wt.Pounds, Ounces + wt.Ounces);
	return value;
}

Weight& Weight::operator+=(const Weight & wt)
{
	*this = *this + wt;
	return *this;
}

Weight Weight::operator*(int num) const
{
	Weight value(Pounds * num, Ounces * num);
	return value;
}

//Operator Overloads - Comparisons
bool Weight::operator>(const Weight & wt) const
{
	bool value = false;

	if (Pounds > wt.Pounds)
		value = true;
	else if (Pounds == wt.Pounds)
		if (Ounces > wt.Ounces)
			value = true;

	return value;
}

bool Weight::operator<(const Weight & wt) const
{
	bool value = false;

	if (Pounds < wt.Pounds)
		value = true;
	else if (Pounds == wt.Pounds)
		if (Ounces < wt.Ounces)
			value = true;
	return value;
}
bool Weight::operator==(const Weight & wt) const
{
	bool value = false;

	if (Pounds == wt.Pounds && Ounces == wt.Ounces)
		value = true;

	return value;
}

#endif
