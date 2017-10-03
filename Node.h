#pragma once
#include<Windows.h>
class Node
{
public:

	int value;		//data stored in node
	int level;		//indicates the level of node for root level=0
	int gap;		//gap b/w x coordinates of parent and child node {for graphical representation}
	COORD pos;		//coordinates of node {for graphical representaion}
	Node *left;		//left node	
	Node *right;	//right node
	Node(int data);	//create node wtih value=data
	virtual ~Node();	//destructor
	
	
};

