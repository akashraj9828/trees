#include<iostream>
#include"Node.h"
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<vector>
#include<cstdlib>
#include"Tree.h"

using namespace std;


Tree::Tree() {
	root = NULL;
	ptr = root;

}
Tree::~Tree() {
	cout << "\t\t\t\t***************** Tree destroyed *****************";
	cout << "\n\n\n\t\t\t\t\t   PRESS ANY KEY TO EXIT !";
	_getch();
}

void Tree::insert(int data) {


	cout << "\n\n\n\t\t" << "~~~~~~~~~~~~~~ADDITION~~~~~~~~~~~~~~" << endl;
	cout << "\n\n\t\t\t" << "Inserting " << data << " in tree" << endl;


	if (root == NULL) {
		cout << "\n\n\t\t\t" << "Tree is empty ";
		cout << "\n\t\t\t" << data << " is added as first element of tree\n\n";
		cout << "\n\t\t\tPath:  ->" << data;
		cout << "\n\t\t\t ";
		Node *temp = new Node(data);
		root = temp;
	}
	else {
		cout << "\n\t\t\t Path:";
		cout << root->value << "->";
		ptr = root;
		while (true) {
			if (data < ptr->value) {
				// if the current node already has left child
				// so we concern it further
				if (ptr->left != NULL) {
					ptr = ptr->left;
					cout << ptr->value << "->";
					continue;
					// if the current node has no left child
					// so we create it with the new value
				}
				else {
					ptr->left = new Node(data);
					cout << "(" << ptr->left->value << ")" << "\t <<-(new node added here)";
					cout << "\n\n\n\n\t\t\t" << data << " succesfully inserted in tree";
					return;
				}
			}
			else {
				// similarly for the value that should be inserted into
				// right subtree
				if (NULL != ptr->right) {
					ptr = ptr->right;
					cout << ptr->value << "->";
					continue;
				}
				else {
					ptr->right = new Node(data);
					cout << "(" << ptr->right->value << ")" << "\t <<-(new node added here)";
					cout << "\n\n\n\n\t\t\t" << data << " succesfully inserted in tree";
					return;
				}
			}
		}
	}
}
//return codes for search
//0-element found on left link of parent
//1-element found on right link of parent
//2-element not found
//3-element found at root
int Tree::search(int data) {
	int dir;
	bool found = false;

	cout << "\n\n\n\t\t" << "~~~~~~~~~~~~~~SEARCHING~~~~~~~~~~~~~~" << endl;
	cout << "\n\n\t\t\t" << "Searching for " << data << " in tree" << endl;
	cout << "\n\t\t\t Path:";
	if (root == NULL) {
		cout << "\n\n\n\n\t\t\t\t Tree is empty :(";
		return 2;
	}
	else if (root->value == data) {
		ptr = root;
		parent = ptr;
		Rchild = ptr->right;
		Lchild = ptr->left;
		cout << "\n\n\n\t\t\tSearch completed :)";
		cout << "\n\t\t\t" << data << " found " << endl;
		cout << "\n\t\t " << data << " is root of tree ";
		return 3;
	}
	else
	{

		ptr = root;
		Lchild = ptr->left;
		Rchild = ptr->right;
		parent = ptr;
		while (ptr != nullptr) {
			if (ptr->value == data) {				/////COMPARE given value with 'ptr' node of tree
				found = true;
				Lchild = ptr->left;
				Rchild = ptr->right;
				cout << ptr->value;
				cout << "\n\n\n\t\t\tSearch completed :) \n";
				cout << "\n\t\t\t" << data << " found " << endl;
				cout << "\n\t\t\t Parent of  " << data << " is " << parent->value;
				if (Lchild != nullptr)
					cout << "\n\t\t\t Left child of  " << data << " is " << Lchild->value;
				if (Rchild != nullptr)
					cout << "\n\t\t\t Right child of  " << data << " is " << Rchild->value;
				return dir;

			}
			else
				if (data < ptr->value) {			/////if value to be searched is less than current node value then

					if (ptr->left != nullptr) {
						parent = ptr;
						cout << ptr->value << "->";
						ptr = ptr->left;				//////set current node to node in its left
						dir = 0;
						continue;
					}
					else {
						cout << ptr->value << "->NULL";
						cout << "\n\n\n\t\t\t Element not found in tree";
						return 2;
					}
				}
				else
					if (data > ptr->value) {		/////if value to be searched is greater than current node value then

						if (ptr->right != nullptr) {
							parent = ptr;
							cout << ptr->value << "->";
							ptr = ptr->right;				//////set current node to node in its right
							dir = 1;
							continue;
						}
						else {
							cout << ptr->value << "->NULL";
							cout << "\n\n\n\t\t\t Element not found in tree";
							return 2;
						}

					}


		}

	}

	return 2;

}

//return code for delete
//	0- sucessfully deleted
//	1- element not found
int Tree::del(int data) {
	int status = search(data);

	//element not found
	if (status == 2) {
		return 1;
	}
	else {
		cout << "\n\n\n\t\t" << "~~~~~~~~~~~~~~DELETION~~~~~~~~~~~~~~" << endl;
		cout << "\n\n\t\t\t" << "deleting " << data << " from tree" << endl;
	}
	//case 1:node has no child
	if (ptr->left == nullptr && ptr->right == nullptr) {
		cout << "\n\n\t\t\t" << " Entered node has no child. \n\t\t\t Hence deleting directly.....\n";
		cout << "\nSteps:\n";
		if (status == 0) {
			cout << "\n 1. Setting " << parent->value << "'s left to NULL. ";
			parent->left = nullptr;	
		}
		else if (status == 1) {
			cout << "\n 1. Setting " << parent->value << "'s right to NULL ";
			parent->right = nullptr;
		}
		cout << "\n 2. Deleting " << ptr->value;
		delete(ptr);
		cout << "\n\n*****************************************************************************************************";
		cout << "\n*****************************************************************************************************";
		cout << "\n*****************************************************************************************************\n\n";

		return 0;
	}
	//case 2: node has one child
	else if ((ptr->left == nullptr) ^ (ptr->right == nullptr)) {  // ^ means binary xor operation  
		cout << "\n\n\t\t\t" << " Entered node has one child. \n\t\t\t Hence chid node replaces parent node.....\n";
		cout << "Steps:";
		if (status == 0) {
			if (Lchild != nullptr) {
				cout << "\n 1. Setting " << parent->value << "'s left to " << Lchild->value;
				parent->left = Lchild;

			}
			else if (Rchild != nullptr) {
				cout << "\n 1. Setting " << parent->value << "'s left to " << Rchild->value;
				parent->left = Rchild;

			}

		}
		else if (status == 1) {
			if (Lchild != nullptr) {
				cout << "\n 1. Setting " << parent->value << "'s right to " << Lchild->value;
				parent->right = Lchild;
			}
			else if (Rchild != nullptr) {
				cout << "\n 1. Setting " << parent->value << "'s right to " << Rchild->value;
				parent->right = Rchild;
			}

		}
		cout << "\n 2. Deleting " << ptr->value;
		delete ptr;
		cout << "\n\n*****************************************************************************************************";
		cout << "\n*****************************************************************************************************";
		cout << "\n*****************************************************************************************************\n\n";
		return 0;
	}
	//case 3: node has two child
	else if ((ptr->left != nullptr) && (ptr->right != nullptr)) {

		Node* toBeDeleted =ptr;				//node to be deleted
		Node* toBeDeleted_Parent = parent;		//parent of node to be deleted
		int pos;								//pos=position of (node to be deleted) in inorderArray 
		cout << "\n\n\t\t\t" << " Entered node has two child. \n Hence finding inorder and replacing parent with its inorder sucessor.....\n";
		inorderArray.clear();					//clear inorder array
		cout << "\n\n" << "Inorder of the tree about node " << toBeDeleted->value << " is::\n";
		inorder(toBeDeleted);					//find inorder pf tree w.r.t (node to be deleted) and fill inorderArray
		
		for (int i = 0; i < inorderArray.size(); i++) {

			if (inorderArray[i]->value == data) {

				cout << "\n\n" << data << " is at pos: " << i + 1;
				pos = i;
				break;
			}
		}
		
		int succesor_value = inorderArray[pos + 1]->value;
		Node* succesor = inorderArray[pos + 1];
		cout << "\n\nAnd its sucessor is:::" << succesor_value;

		//if succesor_branch=0 means its on left link of its parent
		//if succesor_branch=1 means its on right link of its parent
		int sucessor_branch = search(succesor_value);		//by searching again we are resetting ptr and parent according to sucessor
		cout << "\n\nSteps:";
		cout << "\n\n{ Removing any link of "<<succesor_value<<" from its parent }";
		if (sucessor_branch == 0) {
			cout << "\n 1. setting "<<parent->value<<"'s left to NULL";
			parent->left = nullptr;				//here parent = parent of suceesor
		}else if (sucessor_branch == 1) {
			cout << "\n 1. setting " << parent->value << "'s right to NULL";
			parent->right = nullptr;
		}
		if (status == 3) {	////entered elemnt is root
			cout << "\n\n{ Entered element is root and has no parents }";
			cout << "{ Therefore " << succesor_value << " will take place of root }";
			cout << "\n 2. Setting root = " << succesor_value;
			root = succesor;
		}else if (status != 3) {
			cout << "\n\n{ Setting pointers of " << toBeDeleted_Parent->value << " and " << succesor_value << " }";
			cout << "\n{ Then deleting " << toBeDeleted->value << " }";
			if (status == 0) {
				cout << "\n 2. Setting " << toBeDeleted_Parent->value << "'s left to " << succesor->value;
				toBeDeleted_Parent->left = succesor;
			}
			else if (status == 1) {
				cout << "\n 2. Setting " << toBeDeleted_Parent->value << "'s right to " << succesor->value;
				toBeDeleted_Parent->right = succesor;
			}
		}
		
		if (toBeDeleted->left != nullptr) {
			cout << "\n 3. Setting " << succesor->value << "'s left to " << toBeDeleted->left->value;
			succesor->left = toBeDeleted->left;
		}
		else {
			cout << "\n 3. " << succesor->value << "'s left cant be set ";
		}
		if (toBeDeleted->right != nullptr) {
			cout << "\n 4. Setting " << succesor->value << "'s right to " << toBeDeleted->right->value;
			succesor->right = toBeDeleted->right;
		}
		else {
			cout << "\n 3. " << succesor->value << "'s right cant be set ";
		}
		
		cout << "\n 5. Deleting " << toBeDeleted->value;
		delete(toBeDeleted);

		
		cout << "\n\n*****************************************************************************************************";
		cout << "\n*****************************************************************************************************";
		cout << "\n*****************************************************************************************************\n\n";

	}
	return 1;
}


void Tree::inorder(Node *node) {
	if (node != NULL) {
		inorder(node->left);
		cout << node->value << "-->";
		inorderArray.push_back(node);
		inorder(node->right);
	}
}

void Tree::preorder(Node *root) {

	if (root != NULL) {
		cout << root->value << "-->";
		preorder(root->left);
		preorder(root->right);
	}
}

void Tree::postorder(Node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout << root->value << "--> ";
	}
}
