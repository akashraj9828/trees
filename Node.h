#pragma once
#include<Windows.h>
class Node
{
public:

	int value;
	int level;
	int gap;
	COORD pos;
	Node *left;
	Node *right;
	Node(int data);
	virtual ~Node();
	
	
};

