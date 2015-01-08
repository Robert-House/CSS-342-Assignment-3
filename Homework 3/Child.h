#ifndef CHILD_H
#define CHILD_H

#include <string>
#include <ostream>
#include <istream>

using namespace std;

class Child
{
public:
	Child();
	Child(string firstName, string lastName, int age);
	~Child();
	string getFirstName() const;
	string getLastName() const;
	int getAge() const;
	bool isNice() const;

	bool operator<(const Child &source) const;
	bool operator>(const Child &source) const;
	bool operator==(const Child &source) const;
	bool operator!=(const Child &source) const;
	friend ostream& operator<<(ostream &out, const Child &source);
	friend istream& operator>>(istream &in, Child &source);

public:
	string pFirstName;
	string pLastName;
	int pAge;
	bool pNice;
};
#endif