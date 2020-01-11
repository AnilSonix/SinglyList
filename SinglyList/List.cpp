#include "List.h"
#include<iostream>

using namespace std;

List::List()
{
	start = nullptr;
	length = 0;
}

List::~List()
{
	clear();
}

void List::clear()
{
	while (!isEmpty())
	{
		removeFirst();
	}
}

void List::insertFirst(int newItem)
{
	Node* newNode = new Node(newItem, start);
	start = newNode;
	length++;
}

void List::insertLast(int newItem)
{
	if (isEmpty())
	{
		insertFirst(newItem);
	}
	else {
		Node* lastNode = getLastNode();
		lastNode->next = new Node(newItem);
		length++;
	}
}

int List::removeFirst()
{
	int data = 0;

	if (!isEmpty())
	{
		Node* firstNode = start;
		data = firstNode->data;
		start = firstNode->next;

		delete firstNode;
		length--;
	}

	return data;
}

int List::removeLast()
{
	return 0;
}

void List::insertAt(int newItem, int position)
{
	if (position > 0)
	{
		if (position > getLength())
		{
			insertLast(newItem);
		}
		else {
			Node* prevNode = getNodeAt(position - 1);
			Node* nextNode = prevNode->next;
			prevNode->next = new Node(newItem, nextNode);
			length++;
		}
	}
}

int List::removeFrom(int position)
{
	int data = 0;

	if ((position > 0) && (getLength() > 0) && (position < getLength()))
	{
		Node* prevNode = getNodeAt(position - 1);
		Node* nodeToRemove = prevNode->next;

		data = nodeToRemove->data;
		prevNode->next = nodeToRemove->next;

		delete nodeToRemove;
		length--;
	}

	return data;
}

bool List::isEmpty() const
{
	return length == 0;
}

int List::getLength() const
{
	return length;
}

void List::show() const
{
	for (const Node* i = start; i; i = i->next)
	{
		cout << i->data << " --> ";
	}
	cout << endl;
}

Node* List::getLastNode()
{
	Node* node = start;

	while (node->next)
	{
		node = node->next;
	}

	return node;
}

Node* List::getNodeAt(int position)
{
	int i = 0;
	Node* node = start;

	while (i < position)
	{
		node = node->next;
		i++;
	}

	return node;
}
