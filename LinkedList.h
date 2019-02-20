#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
using namespace std;

struct Node
{
	char data = 0;
	Node* nextPtr = nullptr; // always set to null in default constructor
};

class LinkedList
{
private:
	Node *headPtr;
    int listSize;
public:
	
    LinkedList();
	~LinkedList();
	bool insertAtFront(char value);
	bool insertBeforePosition(char value, int index); // doesn't exist
	//first Node after headptr is 1
	//false if pos zero or out of range
	bool insertAtBack(char value);
    bool empty(); // find out if linked list is empty
	bool deleteAtFront();
	bool deletePosition(int index);
	//first Node after headptr is 1
	//false if pos zero or out of range
	bool deleteAtBack();
	//false if empty
    char getFront();
	void clear(); //frees memory for entire list
    char getNith(int index); // get nth element of linked list 
    int getListsize(); // get the size of the linked list;
	friend ostream& operator << (ostream &out, LinkedList &list); // prints out all elements of linked list 
};
#endif
