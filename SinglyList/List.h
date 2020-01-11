#pragma once
#include "Node.h"
class List
{
public:
	List();
	~List();

	void insertFirst(int newItem);
	void insertLast(int newItem);

	int removeFirst();
	int removeLast();

	void insertAt(int newItem, int position);
	int removeFrom(int position);

	void clear();
	bool isEmpty() const;
	int getLength() const;
	void show() const;

private:
	Node* start;
	int length;

	Node* getLastNode();
	Node* getNodeAt(int position);
};
