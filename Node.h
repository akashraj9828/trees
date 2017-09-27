#pragma once
class Node
{
public:
	Node(int data);
	void setLeft(Node *l);
	void setRight(Node *r);
	int returnValue();
	
	virtual ~Node();
private:

	int value=0;
	Node *left=nullptr;
	Node *right=nullptr;
	
};

