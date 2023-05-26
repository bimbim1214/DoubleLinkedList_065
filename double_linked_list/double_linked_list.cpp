#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string nama;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START = NULL;
public:
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void ltraverse();
	void revtaverse();
	void hapus();
	void searchData();
};

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nenter the roll number of thr student : ";
	cin >> nim;
	cout << "\nenter thr name of the student : ";
	cin >> nm;

	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim; //step 2
	newNode->nama = nm; //step 2

	/*insert a node in the begining of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nduplicate number not allowed" << endl;
			return;

		}
		newNode->next = START; //STEP3
		if (START != NULL)
			START->prev = newNode;
		newNode->prev = NULL;
		START = newNode;
		return;
	}

	/*inserting a Node between two nodes in the list*/
	Node* current = START;
	Node* previous = NULL;
	while (current->next != NULL && current->next->noMhs < nim) { // step 1.c

		previous = current;
		current = current->next;
	}

	if (current->next != NULL && nim == current->noMhs) {
		cout << "\nduplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;
	newNode->prev = current;
	if (current->next != NULL)
		current->next->prev = newNode;
	current->next = newNode;
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL;
	*current = START;
	while (*current != NULL && (*current)->noMhs != rollNo) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}


bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;
}


