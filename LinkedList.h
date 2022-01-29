// Author:       Great Canadian Moose
// Last edit:    April 23rd, 2021

// I lightly modified this from the original
// This was for my Data Structures course, and I'm using this as a temporary solution since creating a linked list is more familiar to me
// than file IO...
// However I consider this a perfectly functional solution since I intend to run this on systems that can only afford to spare 500KB of RAM,
// and since the standard (non-customizeed, non-shortened, with modifier) youtube channel URL is 64 characters long (65 with the newline)
// That means that 7962 URLs can comfortable live entirely within the RAM of an absolutely ancient computer.
// There will be far more overhead from youtube-dl and the SSH/FTP commands

// One more thing to note, wherever I say integer, I mean string, since this program was originally coded with integers.
// I also do not have any need to make multiple intitializers so I don't

#ifndef LinkedList_H
#define LinkedList_H
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
public:
	string data;				//the integer stored in this node.
	Node* next = nullptr;	//the next pointer is used to iterate over the linked list.
};

class LinkedList {
private:

public:
	Node* head = nullptr;
	bool isIn(string search);				//display the linked list by printing onto the console window.
	void insertHead(string val);				//create a new node and properly insert it into the linked list.
	void insertEnd(string val);				//create a new node and insert it at the end of the linked list.
	void insertAt(string val, int pos);			//insert into a position within the liked list. Assume 0 indexing.
	void deleteHead();					//delete the first node in the linked list.
	void deleteEnd();					//delete the last node in the linked list.
	void deleteAt(int pos);					//delete a node within the linked list.
	int size();						//count the number of nodes in the linked list.
	string getAt(int position);				//return a value within the linked list.
	LinkedList();						//default constructor.
//	LinkedList(int vals[], int num_vals);	//parameterized constructor. Create a linked list from an array.
	LinkedList(const LinkedList &orig);		//copy constructor.
	~LinkedList();							//destructor.

};

// Name: LinkedList::insertHead(int val)
// Description: Create a new node and properly insert it into the linked list.
// Parameters:
//	val - the value to add to the LinkedList.
// Returns: void
void LinkedList::insertHead(string val) {
	Node* headNode = new Node; // Initialize a first node

	headNode -> next = head; // Point the headNode to the previous head
	headNode -> data = val; // Copy the value over
	head = headNode; 	// Set the head equal to the pointer to headnode
}

// Name: LinkedList::display()
// Description: Display the linked list by printing onto the console window.
// Returns: void
bool LinkedList::isIn(string search) {
	Node* loop = head; // Set our first pointer to be equal to the head

	while(loop != nullptr){ // Loop until you hit the nullptr which is the end of the list.

		if((*loop).data == search){return true;}
		cout << (*loop).data << endl;
		loop = (*loop).next;


	}

	return false;

}

// Name: LinkedList::insertEnd(int val)
// Description: Create a new node and insert it at the end of the linked list.
// Parameters:
//	val - The value to place at the end of the linked list.
// Returns: void
void LinkedList::insertEnd(string val){

	if(size() > 0){ // This is just to keep the function able to handle an empty list
		// Setting up our new node
		Node* tailNode = new Node;
		tailNode -> data = val;  // New nodes have their next pointer initialized to nullptr so I don't need to set it
		Node* loop = head; // This is our loop pointer
		bool continueLoop = true; // I implemented it like this because I want to make my life easy... plz don't dock points
		while(continueLoop){
			if((*loop).next == nullptr){ // If you see the nullptr in next, change the next to point to our tailNode
				continueLoop = false; // Break from the loop
				loop -> next = tailNode;
			}else{
				loop = (*loop).next; // Increment down the list
			}
		}
	}else{
		insertHead(val);

	}
}

// Name: LinkedList::insertAt(int val, int pos)
// Description: Insert into a position within the liked list. Assume 0 indexing.
// Parameters:
//	val - The value to insert into the linked list.
//	pos - The position to insert into the LinkedList (0-indexed).
// Returns: void
void LinkedList::insertAt(string val, int pos) {
	// Setting up our new node
	Node* insertNode = new Node;
	insertNode -> data = val;

	int i = 1; // Set i to 1 so that the loop stops at the Node before the one we want to insert
	Node* loop = head;
	while(i < pos){
		loop = (*loop).next;	// Increment our loop
		i ++;
	}

	insertNode -> next = (*loop).next; // make our new node pointing to the next node
	loop -> next = insertNode;	// Make the previous node point to the new one

}

// Name: LinkedList::deleteHead()
// Description: Delete the first node in the list.
// Returns: void.
void LinkedList::deleteHead() {
	Node* temp = head; 	// This is our temporary node
	temp = (*temp).next; // Increment the temp node to point just to the next one
	delete head;		// Delete the old head node, and set the head to the temp
	head = temp;
}

// Name: LinkedList::deleteEnd()
// Description: Delete the last node in the linked list.
// Returns: void
void LinkedList::deleteEnd() {
	Node* loop = head; // This is our loop pointer

	if(size() == 1){delete head;}else{ // Delete the head if there is only one entry in the thingy
	int j = 1;
	while(j < size() - 1){
		loop = (*loop).next; // Loop until you get to the penultimate node, then deallocate the next node, and set the next member
				// of the current node to nullptr
		j ++;
	}

	delete (*loop).next;
	loop -> next = nullptr;}
}

// Name: LinkedList::deleteAt(int pos)
// Description: Delete a node within the linked list.
// Parameters:
//	pos - The position to delete the node.
// Returns: void
void LinkedList::deleteAt(int pos) {
	Node* loop = head;

	if(pos == 0){deleteHead();}else{ // Just to handle the case you decide to use the wrong function
	int i = 1;
	while(i < pos){
		loop = loop -> next;
	}

	Node* temp = (*loop).next;
	loop -> next  = temp -> next;
	delete temp;}

}

// Name: LinkedList::size()
// Description: Count the number of nodes in the linked list.
// Returns: int, the number of nodes in the linked list.
int LinkedList::size() {
	Node* loop = head;

	int i = 0;
	while(loop != nullptr){ // Loop until you hit the end of the loop to find the length
		loop = (*loop).next;
		i++;
	}
	return i;
}

// Name: LinkedList::getAt(int position)
// Description: Return a value within the linked list.
// Parameters:
//	position - Get the value of the node at position (0-based indexing).
string LinkedList::getAt(int position) {
	Node* loop = head;

	int i = 0;
	while(i != position){ // Loop to the right spot, then just return it
	loop = loop -> next;
	i++;
	}

	return (*loop).data;

}

//Name: LinkedList::LinkedList()
//Description: Constructor function.
LinkedList::LinkedList() {
	//Nothing needed.
}

//Name: LinkedList::LinkedList(int vals[], int num_vals)
//Description: Construct a new linked list based on an array.
/*LinkedList::LinkedList(int vals[], int num_vals) {

	int i = 1;
	while(i <= num_vals){
		insertHead(vals[num_vals - i]); // Insert the values backwards just because we want to preserve the order
		i ++;
	}

}*/

//Name: LinkedList::LinkedList(const LinkedList &orig)
//Description: copy constructor, for a deep copy of the LinkedList.
LinkedList::LinkedList(const LinkedList &orig) {
	Node* origLoop = orig.head;

	while(origLoop != nullptr){
		insertEnd(origLoop -> data); // Issue starts here...
		origLoop = (origLoop -> next);
	}

}

//Name: LinkedList::~LinkedList()
//Description: Deallocate each node in the entire linked list.
//Note: A little different than we have seen before.
LinkedList::~LinkedList() {
	int i = 0;
	int len = size();
	while(i < len){
		deleteHead();
		i++;
	}
//	display();
}
#endif
