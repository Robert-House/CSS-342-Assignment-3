#ifndef BIRD_H
#define BIRD_H

#include <string>
#include <ostream>
#include <iostream>
#include <istream>

using namespace std;

class Bird
{
public:
	Bird();
	Bird(string name, int id);
	~Bird();
	string getName() const;
	int getID() const;

	bool operator<(const Bird &source) const;
	bool operator>(const Bird &source) const;
	bool operator==(const Bird &source) const;
	bool operator!=(const Bird &source) const;
	friend ostream& operator<<(ostream &out, const Bird &source);
	friend istream& operator>>(istream &in, Bird &source);

public:
	string pName;
	int pID;
};
#endif