#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	SinglyLinkedList<int> sll;
	sll.addFirst(5);
	sll.addFirst(25);
	sll.addFirst(55);
	sll.printList();
}