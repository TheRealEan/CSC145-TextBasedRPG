#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

template <typename T> 
class Node {
public:
	T data;
	Node<T>* prevNode;
	Node<T>* nextNode;

	Node(T info) : data(info), prevNode(nullptr), nextNode(nullptr) {}
	Node(T info, Node* next) : data(info), prevNode(nullptr), nextNode(next) {}
	Node(T info, Node* prev, Node* next) : data(info), prevNode(prev), nextNode(next) {}
};

template <typename T>
class LinkedList {
public:
	Node<T>* head;
	Node<T>* index;
	Node<T>* tail;

	LinkedList() : head(nullptr), tail(nullptr), index(nullptr) {}
	LinkedList(Node<T>* h) : head(h), tail(h), index(h) {}
	LinkedList(Node<T>* h, Node<T>* t) : head(h), tail(t), index(h) {}
	LinkedList(Node<T>* h, Node<T>* t, Node<T>* in) : head(h), tail(t), index(in) {}

	Node<T>* getCurrent() { return index; }
	Node<T>* getFirst() { return head; }
	Node<T>* getLast() { return tail; }

	Node<T>* getIndex() { return index; }
	Node<T>* getHead() { return head; }
	Node<T>* getTail() { return tail; }

	void setIndex(Node<T>* node) { index = node; }

	Node<T>* popBack() {
		if (!tail) return nullptr;
		if (head == tail) { // Only one node
			Node<T>* current = tail;
			if (index == tail) {
				index = nullptr;
			}
			head = nullptr;
			tail = nullptr;
			return current;
		}
		Node<T>* current = tail;
		tail = tail->prevNode;
		tail->nextNode = nullptr;
		if (index == current) {
			index = nullptr;
		}
		return current;
	}

	Node<T>* popFront() {
		if (!head) return nullptr;
		if (head == tail) { // Only one node
			Node<T>* current = head;
			if (index == head) {
				index = nullptr;
			}
			head = nullptr;
			tail = nullptr;
			return current;
		}
		Node<T>* current = head;
		head = head->nextNode;
		head->prevNode = nullptr;
		if (index == current) {
			index = head;
		}
		return current;
	}

	void pushBack(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (!head) { // List is empty
			head = newNode;
			tail = newNode;
			if (!index) {
				index = newNode;
			}
		}
		else {
			newNode->prevNode = tail;
			tail->nextNode = newNode;
			tail = newNode;
		}
	}

	void pushFront(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (!head) {
			head = newNode;
			tail = newNode;
			if (!index) {
				index = newNode;
			}
		}
		else {
			newNode->nextNode = head;
			head->prevNode = newNode;
			head = newNode;
		}
	}

	void insertAfter(Node<T>* prevNode, T data) {
		if (!prevNode) return;
		Node<T>* newNode = new Node<T>(data);
		newNode->prevNode = prevNode;
		newNode->nextNode = prevNode->nextNode;
		prevNode->nextNode = newNode;
		if (newNode->nextNode) {
			newNode->nextNode->prevNode = newNode;
		}
		if (!newNode->nextNode) { // Update tail if inserted at end.
			tail = newNode;
		}
		if (!index) {
			index = newNode;
		}
	}

	void deleteCurrent() {
		if (!index) return;
		Node<T>* current = index;

		// Unlinks from the previous node.
		if (current->prevNode) {
			current->prevNode->nextNode = current->nextNode;
		}
		else { // Update head if inserted at beginning.
			head = current->nextNode;
		}

		// Unlinks from the next node.
		if (current->nextNode) {
			current->nextNode->prevNode = current->prevNode;
		}
		else { // Update tail if inserted at end.
			tail = current->prevNode;
		}
		
		index = current->nextNode;
		delete current;
	}

	void printList() const {
		Node<T>* current = head;
		while (current) {
			if (current->data.getName()) {
				std::cout << current->data.getName() << std::endl;
			}
			current = current->nextNode;
		}
	}
};

#endif