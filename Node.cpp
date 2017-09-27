#include "Node.h"



Node::Node(int data)
{
	value = data;
	
}

void Node::setLeft(Node * l)
{
	left = l;
}

void Node::setRight(Node * r)
{
	right = r;
}

int Node::returnValue()
{
	return value;
}



Node::~Node()
{
}
