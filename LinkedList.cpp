#include <iostream>
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList()
    :headPtr(nullptr), listSize(0) {
}

bool LinkedList::empty() // returns true if list is empty 
{
    return headPtr == nullptr;
}




bool LinkedList::insertAtFront(char value) // inserts valu
{
     if(headPtr == nullptr) // list is empty so we need to make the head
    {
        headPtr= new Node; // make a new node for the head
        headPtr->data = value; //add the value to the head
        listSize++;
        return true; // make sure user knows it was succesful

    }
    else // the list already exist
    {   Node* currentNodePtr = new Node; //allocate space for new node
        currentNodePtr-> data = value; // add value to new node
        currentNodePtr ->nextPtr = headPtr; // previous head is now the next pointer

        headPtr =currentNodePtr; // the current node is the new head
        listSize++; // to keep size of list growing as list grows
    }
    return true;
}

char LinkedList::getFront() // gets the first node useful for debugging
{
    return headPtr->data;
}

bool LinkedList::deleteAtFront() // deletes starting at the front. Used in deconstructor and the clear function
{
    if (headPtr != nullptr)
    {
        Node* previousPtr = headPtr; // save current headptr
        headPtr = previousPtr->nextPtr; // skip over old headptr
        delete previousPtr; //delete the old headptr
        listSize--; // shorten list size;
        return true; // return true if function is succesful

    }
    
    return false;
}



LinkedList::~LinkedList() // destructor
{
    while(!empty()) // loop will delete nodes until the list is empty
    {   deleteAtFront(); // delete nodes until there is nothing left except a headPtr pointing to null
        listSize--;
    }
}

char LinkedList::getNith(int index) // works like [] when using array based containers will retrive data held in indexed node or reutrn -1 as an error based on c code from https://coderforevers.com/cpp/cpp-program/nth-node-linked-list/
{
    int count = 0; // keep running count of while loop 
    Node* currentPtr = headPtr;
    while(currentPtr != nullptr) //go through list
    {
        if (count == index) // return indexed value 
            return (currentPtr -> data);
        count++; // increase count 
        currentPtr = currentPtr->nextPtr; // set the currentPtr to the next node in the chain 
    }
    return -1; // if value isn't found
}
int LinkedList::getListsize() // alllows user to get the size of the list 
{
    return listSize;
}
void LinkedList::clear() // clears the list 
{
    while(!empty()) // loop will delete nodes until the list is empty
    {   deleteAtFront(); // delete nodes until there is nothing left except a headPtr pointing to null
        listSize--;
    }
}
bool LinkedList::insertBeforePosition(char value, int index) // insert before position based on top answer https://stackoverflow.com/questions/21268034/insert-node-at-a-certain-position-in-a-linked-list-c
{
    int count = 0; //for keeping count 
    Node* addNewNodePtr = new Node; // to hold new value 
    Node* currentNodePtr = headPtr; // to transverse through current list 
    addNewNodePtr->data = value; // add new value to list 
    if (headPtr != nullptr && index <= listSize) // loop if not trying to insert at the head or something not in the list 
    {
        while(currentNodePtr != nullptr) // loop 
        {
           
            if(count == index-2) // insert value before index value 
            {
                addNewNodePtr->nextPtr = currentNodePtr->nextPtr; // make sure to keep list after new value 
                currentNodePtr -> nextPtr = addNewNodePtr; // set the old node pointer to the new node
                listSize++; // keep track of list size 
                return true;
            }
            else if  (index == 0)
            {
                insertAtFront(value); // use the insert at front function 
                std::cout << "Adding to head" << std::endl; // let the user know 
                return true;
            }
            currentNodePtr= currentNodePtr->nextPtr; // go through list 
            count++; //increase count 
        }
    }
    else if ( index == listSize+1) // if user wants to inset at tail 
            {
                insertAtBack(value); // use function 
                std::cout << "Adding to tail" << std::endl; // let user know
                return true;
            }
   else  std::cout << "Invalid value or index" << std::endl; // return if they aren't using a valid value 
        std::cout << "The current size of the list is: " << listSize << std::endl;
    return false;
}
bool LinkedList::insertAtBack(char value) // inserts new nodes at the back 
{
    if(headPtr == nullptr) // list is empty so we need to make the head
    {
        headPtr= new Node; // make a new node for the head
        headPtr->data = value; //add the value to the head
        listSize++; // increase list size 
        return true; // make sure user knows it was succesful

    }
    else
    {
        Node* currentPtr = headPtr; // get the list 
        while(currentPtr-> nextPtr != nullptr) // go through list 
            currentPtr = currentPtr -> nextPtr; 
        Node* newNodePtr = new Node; // create new node to hold new value 
        newNodePtr -> data = value; // place in new data 
        currentPtr-> nextPtr = newNodePtr; //place the new node in the proper place 
        listSize++; // increase list size 
    }
    return true;
}
bool LinkedList::deleteAtBack() // deletes nodes from the tail
{
    Node* currentNodePtr = headPtr; // go to the head
    while(currentNodePtr->nextPtr != nullptr) // go through the node until you get to the tail
        currentNodePtr = currentNodePtr -> nextPtr;
    if(!empty())
    {   delete currentNodePtr; // delete the node before the tail
        listSize--;// update the size of the list
    }
    return true;
}
bool LinkedList::deletePosition(int index) //delete at user selected postion 
{
   
    Node* currentPtr = headPtr; // get the list 
    int count = 0; // set a counter 
    if(headPtr != nullptr && index <= listSize) // if user isn't trying to delete a value that doesn't exist or the head
    {
      while(currentPtr->nextPtr != nullptr)
        {
           
            if (count == index-2) // modified from c code https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
            {  
                Node* nodeNextptr = currentPtr->nextPtr->nextPtr; // save the list from being deleted 
                delete currentPtr->nextPtr; //remove node 
                currentPtr->nextPtr = nodeNextptr; // relink list 
                listSize --;
            }
            else if (index == 0) // use delete at front function if the index as it zero 
            {
                deleteAtFront();
                std::cout << "Deleting from head" << std::endl;
                return true;
            }
            else if ( index == listSize) //use delete from back if user tries to delete from the back of the list 
            {
                deleteAtBack();
                std::cout << "deleting from tail" << std::endl;
            }
            currentPtr= currentPtr->nextPtr;
            count++; // increase count 
        }
        return true;
    }
    std::cout << "value not found" << std::endl; // if index value isn't on the list 
    return false;
}


ostream& operator << (ostream &out, LinkedList &list) // prints out the contents of a list 
{
    for (int a = 0; a < list.getListsize(); a++) // loop goes through node
        out << list.getNith(a) << std::endl; // retrives values from heads to tail and prints them
    return out;
}
