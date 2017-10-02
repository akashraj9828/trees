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
	Node* root;
	Node* ptr;		//current position of pointer
	Node* parent;	//parent node of ptr
	Node* Lchild;	//left child node of ptr
	Node* Rchild;	//right child node of ptr;
	vector<Node*> inorderArray;
	
	int i;
	int maxLevel;
	Tree();
	~Tree();

	void insert(int data);


	//return codes for search
	//0-element found on left link of parent
	//1-element found on right link of parent
	//2-element not found
	//3-element found at root
	int search(int data);



	//return code for delete
	//	0- sucessfully deleted
	//	1- element not found
	int del(int data);



	void inorder(Node *node);
	void preorder(Node *node);
	void postorder(Node *node);
	void setPos(Node *node);
	void plot(Node *node);
	void line(COORD p1, COORD p2,int dir);

}; extern Tree binary;

