#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "Hashtable.h"

using namespace std;

int main() {
	SinglyLinkedList<int> sll;
	sll.addFirst(5);
	sll.addFirst(25);
	sll.addFirst(55);
	sll.printList();
	Hashtable<int, std::string> ht;
	ht.insert(3, "something");
	ht.insert(5, "5");
	ht.insert(7, "Nain");
	ht.insert(9, "7");
	ht.insert(125, "Twentyfive");
	string* str = ht.search(3);
	cout << "Hashtable - nelems: " << ht.getNelems() << endl;
	cout << "num: " << *str << " at pos 3" << endl;
	ht.printHashTable();
}