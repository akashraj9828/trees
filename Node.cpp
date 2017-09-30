#include "Node.h"
#include<iostream>



Node::Node(int data)
{
	value = data;
	left = NULL;
	right = NULL;
	
}

Node::~Node()
{
	std::cout <<std::endl<<"\n\n\n\n node:: "<<value<< " ::destructed";
}


//void Node::setLeft(Node * l)
//{
//	left = l;
//}
//
//void Node::setRight(Node * r)
//{
//	right = r;
//}
//
//int Node::returnValue()
//{
//	return value;
//}


