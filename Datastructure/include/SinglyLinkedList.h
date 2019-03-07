#pragma once

#include <iostream>

template<typename T>
class SinglyLinkedList {
private:
	class Node {
	public:
		T data;
		Node* next;
		Node() : next(nullptr) {};
		Node(T data) : data(data), next(nullptr) {};
		Node(T data, Node* next) : data(data), next(next) {};
	};
	Node* head;
	Node* tail;
	size_t size;
public:
	SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {};
	void addFirst(T data) 
	{
		Node* node = new Node(data, head);
		if (head == nullptr) tail = node;
		head = node;
		size++;
	}
	void addLast(T data) 
	{
		Node* node = new Node(data);
		if (head == nullptr) {
			tail = node;
			head = node;
		}
		else {
			tail->next = node;
			tail = tail->next;
		}
		size++;
	}
	void addAt(T data, size_t index)
	{
		if (index < 0 || index >= size) throw std::invalid_argument("index out of bound");
		Node* current = head;
		Node* prev = nullptr;
		if (!index) addFirst(data);
		else if (index == size - 1) addLast(data);
		while (index != 0)
		{
			prev = current;
			current = head->next;
			index--;
		}
		Node* node = new Node(data, current);
		prev->next = node;
	}
	bool remove(T data)
	{
		Node* prev = nullptr;
		Node* current = head;
		while (current != nullptr)
		{
			if (current->data == data) {
				if (prev == nullptr) head = current->next; // first node contains data
				else prev->next = current->next;
				delete current;
				return true;
			}
			prev = current;
			current = current->next;
		}
		return false;
	}
	T get(size_t index)
	{
		if (index < 0 || index >= size) throw std::invalid_argument("index out of bound");
		Node* current = head;
		while (index != 0) {
			current = current->next;
			index--;
		}
		return current->data;
	}
	inline size_t getSize() { return size; }
	void printList()
	{
		Node* current = head;
		std::cout << "List: ";
		while (current != nullptr) {
			std::cout << "{";
			std::cout << current->data;
			std::cout << "}";
			current = current->next;
		}
		std::cout << std::endl;
	}
	inline T operator[](size_t index) { return get(index); }

};