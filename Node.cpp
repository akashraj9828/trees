#include "Node.h"
#include<iostream>



Node::Node(int data)
{
	value = data;
	left = NULL;
	right = NULL;
	pos.X = NULL;
	pos.Y = NULL;
	level = NULL;
	gap = 0;
	
}

Node::~Node()
{	
	std::cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout << "\t~~~~~~~~~~~~~~~node:: " << value << " ::destructed ~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
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


