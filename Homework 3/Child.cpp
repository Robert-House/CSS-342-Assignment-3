#include "Child.h"

Child::Child()
{
	pAge = -1;
	pFirstName = "";
	pLastName = "";
	pNice = true;
}

Child::Child(string firstName, string lastName, int age)
{
	pAge = age;
	pFirstName = firstName;
	pLastName = lastName;
	pNice = true;
}
Child::~Child() {}

string Child::getFirstName() const
{
	return pFirstName;
}

string Child::getLastName() const
{
	return pLastName;
}

int Child::getAge() const
{
	return pAge;
}

bool Child::isNice() const
{
	return pNice;
}

bool Child::operator<(const Child &source) const
{
	if (pLastName < source.pLastName)
	{
		return true;
	}

	return false;
}

bool Child::operator>(const Child &source) const
{
	if (pLastName > source.pLastName)
	{
		return true;
	}

	return false;
}

bool Child::operator==(const Child &source) const
{
	if (pLastName == source.pLastName && pFirstName == source.pFirstName)
	{
		return true;
	}

	return false;
}

bool Child::operator!=(const Child &source) const
{
	if (pLastName != source.pLastName && pFirstName != source.pFirstName)
	{
		return true;
	}

	return false;
}

ostream& operator<<(ostream& out, const Child& source)
{
	out << source.getFirstName() << source.getLastName() << source.getAge() << source.isNice();

	return out;
}

istream& operator>>(istream &in, Child &source)
{
	string name = "";

	in >> name;

	// bind name to the source object. I don't know why I have to do
	// this
	source.pFirstName = name;

	in >> name;
	source.pLastName = name;

	in >> (int)source.pAge;

	return in;
}