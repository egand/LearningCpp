#pragma once

#include <iostream>

template <typename K, typename V>
class Hashtable {
private:
	struct Node
	{
		K key;
		V value;
		Node* next;
	};
	Node** table;
	size_t size;
	size_t nelems;

public:
	Hashtable(size_t size = 10) 
	{
		table = new Node* [size];
		for (size_t i = 0; i < size; i++)
			table[i] = nullptr;
		nelems = 0;
		this->size = size;
	}

	void insert(K key, V value)
	{
		if (containsKey(key)) throw std::exception("Already inside");
		std::hash<K> h;
		size_t index = h(key) % size;
		std::cout << "Index: " << index << std::endl;
		
		Node* newNode = new Node{key, value, nullptr};
		if (table[index] == nullptr) table[index] = newNode;
		else {
			Node* tnode = table[index];
			while (tnode->next != nullptr)
			{
				tnode = tnode->next;
			}
			tnode->next = newNode;
		}
		nelems++;
	}

	V* search(K key)
	{
		std::hash<K> h;
		size_t index = h(key) % size;
		Node* tnode = table[index];
		while (tnode != nullptr)
		{
			if (tnode->key == key)
				return &(tnode->value);
			tnode = tnode->next;
		}
		return nullptr;
	}

	void remove(K key)
	{
		std::hash<K> h;
		size_t index = h(key) % size;
		Node* prev = nullptr;
		Node* current = table[index];
		while (current != nullptr)
		{
			if (current->key == key) {
				if (prev == nullptr) table[index] = table[index]->next; // case: first item
				else prev->next = current->next;
				delete current;
				nelems--;
				break;
			}
			prev = current;
			current = current->next;
		}
	}

	bool containsKey(K key)
	{
		std::hash<K> h;
		size_t index = h(key) % size;
		Node* tnode = table[index];
		while (tnode != nullptr)
		{
			if (tnode->key == key) return true;
			tnode = tnode->next;
		}
		return false;

	}
	//bool containsValue(V value);

	bool isEmpty()
	{
		return nelems == 0;
	}

	size_t getNelems()
	{
		return nelems;
	}

	void printHashTable() 
	{
		for (size_t i = 0; i < size; i++)
		{
			Node* tnode = table[i];
			while (tnode != nullptr)
			{
				std::cout << "Elem at index " << i << " - key: " << tnode->key << " value: " << tnode->value << std::endl;
				tnode = tnode->next;
			}
		}
	}

	//V* replace(K key, V value);
};
