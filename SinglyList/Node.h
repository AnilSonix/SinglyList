#pragma once
class Node
{
public:
	Node(int data = 10, Node* next = nullptr);

	int data;
	Node* next;
};
