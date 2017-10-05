#pragma once
#include<iostream>
#include"Node.h"
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<vector>
#include<cstdlib>

using namespace std;

class Tree
{
public:
	Node* root;		//root of tree //first element
	Node* ptr;		//current position of pointer
	Node* parent;	//parent node of ptr
	Node* Lchild;	//left child node of ptr
	Node* Rchild;	//right child node of ptr;
	vector<Node*> inorderArray;		//a vector that contains inorder traversal of tree (used when deleting node with 2 child)
	
	int depth;	//depth of tree for only root depth ==0
	int total_node;
	BOOL duplicate = false;
	Tree();
	~Tree();


	//return code for insert:
	//0 :element added as left child
	//1 :element added as right child
	//2 :element added as root
	//3 :duplicate found
	int insert(int data);			//inserts node with value=data to tree


	//return codes for search
	//0-element found on left link of parent
	//1-element found on right link of parent
	//2-element not found
	//3-element found at root
	int search(int data);		//search for node whose value=data and sets ptr*=(that node) and parent*=(that node's parent)



	//return code for delete
	//	0- sucessfully deleted
	//	1- element not found
	int del(int data);		//deletes node with its value=data



	void inorder(Node *node);		//prints inorder traversal
	void preorder(Node *node);		//prints preorder traversal
	void postorder(Node *node);		//prints post order of tree 
	void setPos(Node *node);		//sets (x,y) coordinates for each node
	void clearPos(Node *node);		//resets/clears (x,y) coordinates of each node
	void plot(Node *node);			//plots all the nodes in console based on their coordinate(x,y)
	void line(COORD p1, COORD p2,int dir);		//draws dotted line from p1 to p2
	void delete_all(Node *node);

}; extern Tree binary;

