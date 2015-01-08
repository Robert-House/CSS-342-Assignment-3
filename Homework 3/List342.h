#ifndef LIST342_H
#define LIST342_H

#include <string>
#include <ostream>
#include <fstream>

using namespace std;

template <class ItemType> class List342;
template <class ItemType> ostream& operator<< <>(ostream &out, const List342<ItemType> &source);
template<class ItemType> struct Node
{
	ItemType *data = NULL;
	Node *next = NULL;
};

template <class ItemType> class List342
{
public:
	List342(); // Empty list
	List342(string FileName);
	List342(List342<ItemType> &source); // Copy Constructor
	~List342();

	bool BuildList(string FileName); // Not imp
	bool Insert(ItemType *obj);
	bool Remove(ItemType target, ItemType &result);
	bool Peek(ItemType target, ItemType &result) const;
	bool isEmpty() const;
	int getCount() const;
	void ClearList();
	bool Merge(List342<ItemType> &list1, List342<ItemType> &list2); // not imp

	// Operator overloads
	friend ostream& operator<< <>(ostream &out, const List342<ItemType> &source);
	List342 operator+(const List342 &sourceR) const;
	List342& operator+=(const List342 &source);
	bool operator==(const List342 &source) const;
	bool operator!=(const List342 &source) const;
	void operator=(const List342 &source);


private:
	int count = 0;
	Node<ItemType> *head;
	bool setCount(int x);
	Node<ItemType>* recursiveMerge(Node<ItemType> *node1, Node<ItemType> *node2);
	Node<ItemType>* recursiveMerge(Node<ItemType> *node1, Node<ItemType> *node2,
		Node<ItemType> *node3);
};

#endif

template <class ItemType>
List342<ItemType>::List342()
{
	this->head = NULL;
}

template <class ItemType>
List342<ItemType>::List342(string FileName)
{
	BuildList(FileName);
}

template <class ItemType>
List342<ItemType>::List342(List342<ItemType> &source)
{
	this->head = NULL;
	*this = source;
}

template <class ItemType>
List342<ItemType>::~List342() {}

template <class ItemType>
bool List342<ItemType>::BuildList(string FileName)
{
	ifstream fin;
	string tempstr = "";

	fin.open(FileName);

	while (!fin.eof())
	{
		ItemType *temp = new ItemType();
		fin >> *temp;
		Insert(temp);
	}
	
	return false;
}

template <class ItemType>
bool List342<ItemType>::Insert(ItemType *obj)
{
	Node<ItemType> *newNode = new Node<ItemType>;
	Node<ItemType> *currNode;
	Node<ItemType> *prevNode;

	// Assign object pointer to the new node
	newNode->data = obj;

	// Check for invalid input
	if (obj == NULL)
	{
		return false;
	}

	// Check if list is empty
	if (isEmpty())
	{
		head = newNode;
		count++;
		return true;
	}

	if (*obj < *head->data)
	{
		newNode->next = head;
		head = newNode;
		count++;

		// Found our place, return.
		return true;
	}

	// Head is > new node
	currNode = head->next;
	prevNode = head;

	// Sorts from least to greatest
	while (currNode != NULL)
	{
		if (*obj < *currNode->data)
		{
			newNode->next = currNode;
			prevNode->next = newNode;
			count++;

			// Found our place, return.
			return true;
		}

		prevNode = currNode;
		currNode = currNode->next;
	}

	// List is sorted but the node we want to add is
	// going to be in the last place. place node there.
	if (prevNode != NULL)
	{
		prevNode->next = newNode;
		count++;
		return true;
	}

	// Somehow this failed
	return false;
}

// NOTE: REMOVES FIRST INSTANCE ONLY!!!!!
template <class ItemType>
bool List342<ItemType>::Remove(ItemType target, ItemType &result)
{
	Node<ItemType> *prevNode;
	Node<ItemType> *currNode;

	// Check to see if list is empty
	if (isEmpty())
	{
		// Just return false; We are done here.
		return false;
	}

	// Check to see if the first node is the target
	if (target == *head->data)
	{
		// Assign next node so we don't lose our list
		currNode = head->next;

		result = *head->data;

		// Remove node
		head = currNode;
		count--;

		return true;
	}

	// We have ruled out the two fringe cases, now we can loop though the rest of the list and remove
	// the first instance of our target
	prevNode = head;
	currNode = head->next;

	while (currNode != NULL)
	{
		// Check to see if the next node is our target
		if (target == *currNode->data)
		{
			// We have found our target
			result = *currNode->data;

			// Remove Node
			prevNode->next = currNode->next;

			//============ NOTE TO SELF: Test to see if this will cause any problems if currNode is the last node in the list////////////////////////////////////////////////////////////////////////
			//currNode = NULL;

			count--;

			return true;
		}

		// Assign this node as the previous node
		prevNode = currNode;
		// Grab next node in the list
		currNode = currNode->next;
	}

	// If this member has reached this line, the target was NOT found
	return false;
}

template <class ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType &result) const
{
	Node<ItemType> *currNode = head;

	// Handle fringe case of list being empty. Fail early!
	if (currNode == NULL)
	{
		return false;
	}

	// Loop through list while we still have nodes
	while (currNode != NULL)
	{
		if (*currNode->data == target)
		{
			result = *currNode->data;
			return true;
		}

		currNode = currNode->next;
	}

	// Target not found
	return false;
}

template <class ItemType>
bool List342<ItemType>::isEmpty() const
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class ItemType>
int List342<ItemType>::getCount() const
{
	return count;
}

template <class ItemType>
void List342<ItemType>::ClearList()
{
	Node<ItemType> *currNode = head;
	Node<ItemType> *nextNode;

	while (currNode != NULL)
	{
		// Get the first node in the list from the header node
		nextNode = currNode->next;

		// Null the reference to the current node
		currNode = NULL;

		// Assign next node to the header
		currNode = nextNode;
	}

	// Delete remaining node
	head = NULL;

	// Set count to 0
	count = 0;
}

// I made the design decision to do two passes though the loop. The time to loop through and place
// nodes is O(2n). This is trivial compared to the time it would take for this programmer to
// implement everything in one pass. I'm behind in a few of my classes so THIS IS A DESIGN DECISION
// to do 2 passes. It saves programmer time and the code is a bit more readable
template <class ItemType>
bool List342<ItemType>::Merge(List342 &list1, List342 &list2)
{
	Node<ItemType> *temp = recursiveMerge(list1.head, list2.head);

	if (this->head == NULL)
	{
		this->head == temp;
	}
	else
	{
		this->head = recursiveMerge(this->head, temp);
	}

	int numEntries = list1.getCount() + list2.getCount() + this->getCount();
	this->setCount(numEntries);
	
	list1.ClearList();
	list2.ClearList();

	return true;
}




//==========================
// Operator Overloads
//==========================

template <class ItemType>
ostream& operator<<(ostream &out, const List342<ItemType> &source)
{
	Node<ItemType> *currNode = source.head;

	// Tell User that the list is empty
	if (source.isEmpty())
	{
		out << "List is Empty!" << endl;
		return out;
	}

	while (currNode != NULL)
	{
		out << *currNode->data << endl;
		currNode = currNode->next;
	}

	return out;
}

template<class ItemType>
List342<ItemType> List342<ItemType>::operator+(const List342 &source) const
{
	List342<ItemType> temp;
	Node<ItemType> *currNode = this->head;

	// Deep Copy LHS
	while (currNode != NULL)
	{
		temp.Insert(currNode->data);
		currNode = currNode->next;
	}

	currNode = source.head;
	
	// Deep copy RHS
	while (currNode != NULL)
	{
		temp.Insert(currNode->data);
		currNode = currNode->next;
	}

	return temp; // done
}

template<class ItemType>
List342<ItemType>& List342<ItemType>::operator+=(const List342 &source)
{
	this->head = recursiveMerge(this->head, source.head);

	return *this;
}

template<class ItemType>
void List342<ItemType>::operator=(const List342 &source)
{
	Node<ItemType> *currNode;
	Node<ItemType> *tempNode;

	if (this == &source) 
	{ 
		return; 
	}

	this->ClearList();
	this->count = 0;

	currNode = source.head;
	this->head = currNode;
	tempNode = this->head->next;

	currNode = currNode->next;
	while (currNode != NULL)
	{
		// Insert new nodes into the list
		tempNode = currNode;
		currNode = currNode->next;
	}

	this->setCount(source.getCount());

	return;
}

template<class ItemType>
bool List342<ItemType>::operator==(const List342<ItemType> &source) const
{
	// Easy Check first, see if the counts are equal
	if (this->count != source.getCount())
	{
		return false;
	}

	Node<ItemType> *currNode = source.head;
	Node<ItemType> *currNode2 = this->head;


	// Check both lists. Because they are even, we can loop through and test
	while (currNode != NULL)
	{
		// If they are not equal without having to implement not equal
		if (currNode->data != currNode2->data)
		{
			return false;
		}

		currNode = currNode->next;
		currNode2 = currNode2->next;
	}

	// If it makes it here, its equal
	return true;
}

template<class ItemType>
bool List342<ItemType>::operator!=(const List342<ItemType> &source) const
{
	// Easy Check first, see if the counts are equal
	if (this->count != source.getCount())
	{
		return true;
	}

	Node<ItemType> *currNode = source.head;
	Node<ItemType> *currNode2 = this->head;


	// Check both lists. Because they are even, we can loop through and test
	while (currNode != NULL)
	{
		// If they are not equal without having to implement not equal
		if (currNode->data != currNode2->data)
		{
			return true;
		}

		currNode = currNode->next;
		currNode2 = currNode2->next;
	}

	// If it makes it here, its false
	return false;
}

template<class ItemType>
bool List342<ItemType>::setCount(int numItems)
{
	count = numItems;
	return true;
}

template<class ItemType>
Node<ItemType>* List342<ItemType>::recursiveMerge(Node<ItemType> *node1, Node<ItemType> *node2)
{
	if (node1 == NULL) return node2;
	if (node2 == NULL) return node1;

	if (*node1->data < *node2->data)
	{
		node1->next = recursiveMerge(node1->next, node2);
		return node1;
	}
	else
	{
		node2->next = recursiveMerge(node2->next, node1);
		return node2;
	}
}