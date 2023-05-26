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
	newNode->name = nm; //step 2

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

