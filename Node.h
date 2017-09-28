#pragma once
class Node
{
public:

	int value = 0;
	Node *left = nullptr;
	Node *right = nullptr;
	Node(int data);
	void setLeft(Node *l);
	void setRight(Node *r);
	int returnValue();
	
	virtual ~Node();
private:

	
	
};

