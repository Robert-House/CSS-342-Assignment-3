#include "Bird.h"

Bird::Bird()
{
	pID = -1;
	pName = "";
}

Bird::Bird(string name, int id)
{
	pName = name;
	pID = id;
}
Bird::~Bird() {}

string Bird::getName() const
{
	return pName;
}

int Bird::getID() const
{
	return pID;
}

bool Bird::operator<(const Bird &source) const
{
	if (pID < source.pID || pID == source.pID)
	{
		return true;
	}

	return false;
}

bool Bird::operator>(const Bird &source) const
{
	if (pID > source.pID)
	{
		return true;
	}

	return false;
}

bool Bird::operator==(const Bird &source) const
{
	if (pID == source.pID)
	{
		return true;
	}

	return false;
}

bool Bird::operator!=(const Bird &source) const
{
	if (pID != source.pID)
	{
		return true;
	}

	return false;
}

ostream& operator<<(ostream& out, const Bird& source)
{
	out << source.getName() << source.getID();

	return out;
}

istream& operator>>(istream &in, Bird &source)
{
	string name = "";

	in >> name;

	// bind name to the source object. I don't know why I have to do
	// this
	source.pName = name;

	in >> (int)source.pID;

	return in;
}