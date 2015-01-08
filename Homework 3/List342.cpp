//#include "List342.h"

//template <class ItemType>
//List342<ItemType>::List342()
//{
//	this->head = new Node<ItemType>;
//}
//
//template <class ItemType>
//List342<ItemType>::List342(List342<ItemType> &source)
//{
//	this->head = NULL;
//	*this = source;
//}
//
//template <class ItemType>
//List342<ItemType>::~List342() {}
//
//template <class ItemType>
//bool List342<ItemType>::BuildList(string FileName)
//{
//	return false;
//}
//
//template <class ItemType>
//bool List342<ItemType>::Insert(ItemType *obj)
//{
//	Node<ItemType> *newNode = new Node<ItemType>;
//	Node<ItemType> *currNode;
//	Node<ItemType> *prevNode;
//
//	// Assign object pointer to the new node
//	newNode->data = obj;
//
//	// Check for invalid input
//	if (obj == NULL)
//	{
//		return false;
//	}
//
//	// Check if list is empty
//	if (isEmpty())
//	{
//		head = newNode;
//		count++;
//		return true;
//	}
//
//	if (*obj < *head->data)
//	{
//		newNode->next = head;
//		head = newNode;
//		count++;
//
//		// Found our place, return.
//		return true;
//	}
//
//	// Head is > new node
//	currNode = head->next;
//	prevNode = head;
//
//	// Sorts from least to greatest
//	while (currNode != NULL)
//	{
//		if (*obj < *currNode->data)
//		{
//			newNode->next = currNode;
//			prevNode->next = newNode;
//			count++;
//
//			// Found our place, return.
//			return true;
//		}
//
//		prevNode = currNode;
//		currNode = currNode->next;
//	}
//
//	// List is sorted but the node we want to add is
//	// going to be in the last place. place node there.
//	if (*obj > *prevNode->data)
//	{
//		prevNode->next = newNode;
//		count++;
//		return true;
//	}
//
//	// Somehow this failed
//	return false;
//}
//
//// NOTE: REMOVES FIRST INSTANCE ONLY!!!!!
//template <class ItemType>
//bool List342<ItemType>::Remove(ItemType target, ItemType &result)
//{
//	Node<ItemType> *prevNode;
//	Node<ItemType> *currNode;
//
//	// Check to see if list is empty
//	if (isEmpty())
//	{
//		// Just return false; We are done here.
//		return false;
//	}
//
//	// Check to see if the first node is the target
//	if (target == *head->data)
//	{
//		// Assign next node so we don't lose our list
//		currNode = head->next;
//
//		result = *head->data;
//
//		// Remove node
//		head = currNode;
//		count--;
//
//		return true;
//	}
//
//	// We have ruled out the two fringe cases, now we can loop though the rest of the list and remove
//	// the first instance of our target
//	prevNode = head;
//	currNode = head->next;
//
//	while (currNode != NULL)
//	{
//		// Check to see if the next node is our target
//		if (target == *currNode->data)
//		{
//			// We have found our target
//			result = *currNode->data;
//
//			// Remove Node
//			prevNode->next = currNode->next;
//
//			//============ NOTE TO SELF: Test to see if this will cause any problems if currNode is the last node in the list////////////////////////////////////////////////////////////////////////
//			//currNode = NULL;
//
//			count--;
//
//			return true;
//		}
//
//		// Assign this node as the previous node
//		prevNode = currNode;
//		// Grab next node in the list
//		currNode = currNode->next;
//	}
//
//	// If this member has reached this line, the target was NOT found
//	return false;
//}
//
//template <class ItemType>
//bool List342<ItemType>::Peek(ItemType target, ItemType &result) const
//{
//	Node<ItemType> *currNode = head;
//
//	// Handle fringe case of list being empty. Fail early!
//	if (currNode == NULL)
//	{
//		return false;
//	}
//
//	// Loop through list while we still have nodes
//	while (currNode != NULL)
//	{
//		if (*currNode->data == target)
//		{
//			result = *currNode->data;
//			return true;
//		}
//
//		currNode = currNode->next;
//	}
//
//	// Target not found
//	return false;
//}
//
//template <class ItemType>
//bool List342<ItemType>::isEmpty() const
//{
//	if (count == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//template <class ItemType>
//void List342<ItemType>::ClearList()
//{
//	Node<ItemType> *currNode = head;
//	Node<ItemType> *nextNode;
//
//	while (currNode != NULL)
//	{
//		// Get the first node in the list from the header node
//		nextNode = currNode->next;
//
//		// Null the reference to the current node
//		currNode = NULL;
//
//		// Assign next node to the header
//		currNode = nextNode;
//	}
//
//	// Delete remaining node
//	head = NULL;
//
//	// Set count to 0
//	count = 0;
//}
//
//template <class ItemType>
//bool List342<ItemType>::Merge(List342 &list1, List342 &list2)
//{
//	Node<ItemType> currNode1;
//	Node<ItemType> currNode2;
//	Node<ItemType> currNode3;
//
//	Node<ItemType> prevNode1;
//	Node<ItemType> prevNode2;
//	Node<ItemType> prevNode3;
//
//	currNode1 = head;
//
//	// Handle empty case
//	if (currNode1 == NULL)
//	{
//		Insert(currNode2);
//		Insert(currNode3);
//	}
//
//	// Handle only header case
//
//	// Handle the rest of the cases
//
//	return true;
//}
//
//template <class ItemType>
//ostream& operator<<(ostream &out, const List342<ItemType> &source)
//{
//	Node<ItemType> *currNode = new Node<ItemType>;
//
//	currNode = source.head;
//
//	// Tell User that the list is empty
//	if (source.isEmpty())
//	{
//		out << "List is Empty!" << endl;
//		return out;
//	}
//
//	while (currNode != NULL)
//	{
//		out << *currNode->data << endl;
//		currNode = currNode->next;
//	}
//
//	return out;
//}
//
//template<class ItemType>
//List342<ItemType> List342<ItemType>::operator+(const List342 &source) const
//{
//	return NULL;
//}

