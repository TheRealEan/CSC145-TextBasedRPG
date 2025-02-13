// Filename: "Extra.h"
#include <iostream>

int roll(int numDice, int numOfSides);
Enemy* generateRandomEnemy();

template <typename T> class Node {
public:
	T data;
	Node<T>* prevNode{ nullptr };
	Node<T>* nextNode{ nullptr };

	Node(T info) : data(info), prevNode(nullptr), nextNode(nullptr) {}
	Node(T info, Node* next) : data(info), prevNode(nullptr), nextNode(next) {}
	Node(T info, Node* prev, Node* next) : data(info), prevNode(prev), nextNode(next) {}
};

template <typename T> class LinkedList {
public:
	Node<T>* head;
	Node<T>* index;
	Node<T>* tail;

	LinkedList() : head(nullptr), tail(nullptr), index(nullptr) {};
	LinkedList(Node<T>* h) : head(h), tail(h), index(h) {};
	LinkedList(Node<T>* h, Node<T>* t) : head(h), tail(t), index(h) {};
	LinkedList(Node<T>* h, Node<T>* t, Node<T>* in) : head(h), tail(t), index(in) {};

	Node<T>* getCurrent() {
		return index;
	};
	Node<T>* getFirst() {
		return head;
	};
	Node<T>* getLast() {
		return tail;
	}
	Node<T>* popBack() {
		index = tail->prevNode;
		tail->prevNode = nullptr;
		index->nextNode = nullptr;
		Node* tempIndex = tail;
		tail = index;
		return tempIndex;
	}
	Node<T>* popFront() {
		index = head->nextNode;
		head->nextNode = nullptr;
		index->prevNode = nullptr;
		Node* tempIndex = head;
		head = index;
		return tempIndex;
	}
	void pushBack(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (!head) {
			head = newNode;
			tail = newNode;
			index = newNode;
		}
		else {
			index = tail;
			newNode->prevNode = tail;
			newNode->nextNode = nullptr;
			tail->nextNode = newNode;
			tail = newNode;
		}
	}
	void pushFront(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (!head) {
			head = newNode;
			tail = newNode;
			index = newNode;
		}
		else {
			index = head;
			newNode->prevNode = nullptr;
			newNode->nextNode = head->nextNode;
			head->prevNode = newNode;
			head = newNode;
		}
	}
	void insertAfter(Node<T>* prevNode, T data) {
		if (!prevNode) return;
		Node<T>* newNode = new Node<T>(data);
		index = head;
		while (index != prevNode && index->nextNode != nullptr) {
			index = index->nextNode;
		}
		newNode->prevNode = index;
		newNode->nextNode = index->nextNode;
		index->nextNode = newNode;
		// Move to the new node.
		index = index->nextNode;
	}

	void deleteCurrent() {
		if (!index) return;
		Node<T>* tempIndex = index;
		if (index->prevNode != nullptr) {
			index->prevNode->nextNode = index->nextNode;
		}
		else { // Node is the head node.
			head = index->nextNode;
		}
		if (index->nextNode != nullptr) {
			index->nextNode->prevNode = index->prevNode;
		}
		else { // Node is the tail node.
			tail = index->prevNode;
		}
		index = index->nextNode;
		delete tempIndex;
	}

	void printList() {
		Node<T>* tempIndex = index;
		index = head;
		while (index) {
			std::cout << index->data.getName() << std::endl; // Only works for Characters.
			index = index->nextNode;
		}
		// Reset index to original position.
		index = tempIndex;
	}
};
