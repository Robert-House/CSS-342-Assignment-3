// Homework 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "List342.h"
#include "Bird.h"
#include "Child.h"

using namespace std;

void BirdTest();
void ChildTest();

int _tmain(int argc, _TCHAR* argv[])
{
	
	//BirdTest();
	//ChildTest();

	Child c1("ann", "hanlin", 7), c2("pradnya", "dhala", 8); 
	Child c3("bill", "vollmann", 13), c4("cesar", "ruiz", 6); 
	Child c5("piqi", "tang", 7), c6("pete", "rose", 13), c7("hank", "aaron", 3); 
	Child c8("madison", "fife", 7), c9("miles", "davis", 65); 
	Child c10("john", "zorn", 4), c11; 
	List342<Child> class1, class2, soccer, chess; int a = 1, b = -1, c = 13;
	class1.Insert(&c1); class1.Insert(&c2); class1.Insert(&c3);
	class2.Insert(&c4); class2.Insert(&c5); class2.Insert(&c6); class2.Insert(&c7);
	soccer.Insert(&c6); soccer.Insert(&c4); soccer.Insert(&c9);
	chess.Insert(&c10); chess.Insert(&c7);
	cout << "This is class1:  " << class1 << endl; cout << "This is class2:  " << class2 << endl; if (class1 != class2) { cout << "class1 is different than class 2" << endl; }
	if (class1.Peek(c2, c11)) { cout << c11 << " is in class1" << endl; }
	if (class1.Remove(c1, c11)) {
		class2.Insert(&c11);
		cout << c1 << " has been removed from class1 and placed in class2" << endl;
	}
	cout << "This is class2:  " << class2 << endl;
	cout << "This is the chess club: " << chess << endl; chess.ClearList(); chess.Insert(&c9); cout << "this is now the chess club: " << chess << endl; List342<Child> soccer2 = soccer; // Note that the Merge function is probably not as intuitive as we like // but the fact the lists allow duplicates confuse the situation. chess.Merge(soccer, class2); cout << "this is now the chess club: " << chess << endl; if (soccer.isEmpty()) { cout << "The soccer club is now empty" << endl; } cout << "This is the soccer2 club: " << soccer2 << endl;
	List342<int> numbers; numbers.Insert(&a); numbers.Insert(&b); numbers.Insert(&c); cout << "These are the numbers: " << numbers << endl;
	return 0;

	//return 0;
}

void BirdTest()
{
	List342<Bird> list("test.txt");

	cout << list << endl;

	//Bird peekTest("bird is the word", 0);

	//list->Remove(*b3, peekTest);
	//list->Peek(*b1,peekTest);

	//cout << *list << endl;

	//// Test Clear List
	//list->ClearList();

	//cout << *list << endl;

	//// Insert birds again
	//list->Insert(NULL);
	//list->Insert(b2);
	//list->Insert(b4);
	//list->Insert(b3);
	//list->Insert(b1);

	//cout << *list << endl;

	// Copy Constructor Test
	//List342<Bird> list2 = *list;

	//cout <<"LIST1" << endl << list2 << endl;

	//list->ClearList();

	//cout << "List 1 DELETED" << endl;

	//cout << "LIST1" << endl << *list << endl;
	//cout << list->getCount() << endl;

	//cout << "LIST2" << endl << list2 << endl;
	//cout << list2.getCount() << endl;

	//cout << (*list == list2) << endl;

	List342<Bird> list2("test.txt");
	List342<Bird> list3;

	//list3 += list2;
	//list2.ClearList();
	list3.Insert(new Bird("chocobo", 777));
	list3.Insert(new Bird("null", 0));
	list3.Merge(list, list2);
	//list3.Insert(new Bird("tell", 0));

	cout << list3 << endl;
	cout << list3.getCount() << endl;
}


void ChildTest()
{
	List342<Child> clist("testc.txt");

	cout << clist << endl;
}

