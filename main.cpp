#include<iostream>
#include"Node.h"
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

class Tree
{
public:
	Node *root;
	Node *ptr;
	Node *parent;

	Tree() {
		root = NULL;
		ptr = root;
	}

	void insert(int data) {

		if (root == NULL) {
			Node *temp = new Node(data);
			root = temp;
		}
		else {
			ptr = root;
			while (true) {
				if (data<ptr->value) {
					// if the current node already has left child
					// so we concern it further
					if ( ptr->left !=NULL ) {
						ptr = ptr->left;
						continue;
						// if the current node has no left child
						// so we create it with the new value
					}
					else {
						ptr->left = new Node(data);
						return;
					}
				}
				else {
					// similarly for the value that should be inserted into
					// right subtree
					if (NULL != ptr->right) {
						ptr = ptr->right;
						continue;
					}
					else {
						ptr->right = new Node(data);
						return;
					}
				}
			}
		}
		}
	

	void inorder(const Node *root)const {
		if (root != NULL) {
			inorder(root->left);
			cout << root->value << '\t';
			inorder(root->right);
		}
	}

	void preorder(const Node *root)const {
		
		if (root != NULL) {
			cout << root->value << '\t';
			preorder(root->left);
			preorder(root->right);
		}
	}

	void postorder(const Node *root)const {
		if (root != NULL) {
			postorder(root->left);
			postorder(root->right);
			cout << root->value << '\t';
		}
	}

	Node* getroot() {
		return root;
	}

	void inorder() const {
		inorder(root); 
	};
};


int main() {
	int values[] = {25,15,10,4,12,22,18,24,50,70,66,90,35,31,44};
	Tree binary;
	system("cls");
	for (int i = 0; i < sizeof(v)/4; i++) {
		
		binary.insert(v[i]);
		//cout <<sizeof(v)<<"::"<< v[i]<<endl;
	}
	cout << endl << "inorder is::" << endl;
	binary.inorder(binary.root);
	cout << endl << "preorder is::" << endl;
	binary.preorder(binary.root);
	cout << endl << "postorder is::" << endl;
	binary.postorder(binary.root);
	getch();


	return 0;
}

BOOL gotoxy(const WORD x, const WORD y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

















