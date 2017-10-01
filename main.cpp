#include<iostream>
#include"Node.h"
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<vector>
#include<cstdlib>
#include<SDL2\SDL.h>
#include<gl\glew.h>
#include"display.h"

using namespace std;
int menu();
class Tree
{
public:
	Node* root;
	Node* ptr;		//current position of pointer
	Node* parent;	//parent node of ptr
	Node* Lchild;	//left child node of ptr
	Node* Rchild;	//right child node of ptr
	
	vector<Node*> inorderArray;
	int i;
	Tree() {
		root = NULL;
		ptr = root;
		
	}
	~Tree() {
		cout << "tree destroyed";
	}

	void insert(int data) {
		

		cout << "\n\n\n\t\t" << "~~~~~~~~~~~~~~ADDITION~~~~~~~~~~~~~~" << endl;
		cout << "\n\n\t\t\t" << "Inserting " << data << " in tree" << endl;
		
		
		if (root == NULL) {
			cout << "\n\n\t\t\t" << "Tree is empty ";
			cout << "\n\t\t\t" <<data<< " is added as first element of tree\n\n";
			cout << "->" << data;
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
						cout << ptr->value<<"->";
						ptr = ptr->left;
						continue;
						// if the current node has no left child
						// so we create it with the new value
					}
					else {
						ptr->left = new Node(data);
						cout <<"("<< ptr->left->value<<")" << "\t <<-(new node added here)";
						cout << "\n\n\n\n\t\t\t" << data << " succesfully inserted in tree";
						return;
					}
				}
				else {
					// similarly for the value that should be inserted into
					// right subtree
					if (NULL != ptr->right) {
						cout << ptr->value << "->";
						ptr = ptr->right;
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
	int search(int data) {				
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
			cout<<"\n\t\t\t"<< data << " found " << endl;
			cout << "\n\t\t "<< data << " is root of tree ";
			return 3;
		}
		else
		{
			
			ptr = root;
			Lchild = ptr->left;
			Rchild = ptr->right;
			parent = ptr;
			while (ptr!=nullptr) {
				if (ptr->value == data) {				/////COMPARE given value with 'ptr' node of tree
					found = true;
					Lchild = ptr->left;
					Rchild = ptr->right;
					cout << ptr->value;
					cout << "\n\n\n\t\t\tSearch completed :) \n"; 
					cout << "\n\t\t\t" << data << " found " << endl;
					cout << "\n\t\t\t Parent of  " << data << " is " << parent->value;
					if(Lchild!=nullptr)
					cout<< "\n\t\t\t Left child of  " << data << " is " << Lchild->value;
					if (Rchild != nullptr)
					cout<< "\n\t\t\t Right child of  " << data << " is " << Rchild->value;
					return dir;

				}
				else
					if (data < ptr->value) {			/////if value to be searched is less than current node value then
					
					if (ptr->left != nullptr) {
						parent = ptr;
						cout << ptr->value<<"->";
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
					if(data>ptr->value){		/////if value to be searched is greater than current node value then
					
					if (ptr->right != nullptr ) {
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
	int del(int data) {
		int status = search(data);
		
		//element not found
		if (status == 2) {
			return 0;
		}else{
			cout << "\n\n\n\t\t" << "~~~~~~~~~~~~~~DELETION~~~~~~~~~~~~~~" << endl;
			cout << "\n\n\t\t\t" << "deleting " << data << " from tree" << endl;
		}
		//case 1:node has no child
		if (ptr->left == nullptr && ptr->right == nullptr) {
			cout << "\n\n\t\t\t"<<" Entered node has no child. \n\t\t\t Hence deleting directly.....\n";
			if (status == 0) {
				delete(ptr);
				parent->left = nullptr;
				return 1;
			}
			else if (status == 1) {
				delete(ptr);
				parent->right = nullptr;
				return 1;
			}
		}
		//case 2: node has one child
		else if ((ptr->left == nullptr) ^ (ptr->right == nullptr)) {  // ^ means binary xor operation  
			cout << "\n\n\t\t\t" << " Entered node has one child. \n Hence chid node replaces parent node.....\n";
			if (status == 0) {
				if (Lchild != nullptr) {
					parent->left = Lchild;

				}
				else if (Rchild != nullptr) {
					parent->left = Rchild;

				}

			}
			else if (status == 1) {
				if (Lchild != nullptr) {
					parent->right = Lchild;
				}
				else if (Rchild != nullptr) {
					parent->right = Rchild;
				}

			}
			delete ptr;
			return 0;
		}
		//case 3: node has two child
		else if ((ptr->left != nullptr) && (ptr->right != nullptr)) {

			cout << "\n\n\t\t\t" << " Entered node has two child. \n Hence finding inorder and replacing parent with its inorder sucessor.....\n";
			
			inorderArray.erase(inorderArray.begin(), inorderArray.end());
			cout << "\n\n" << "Inorder of the tree about node " << ptr->value << " is::\n";
			inorder(ptr);
			
			int pos;
			for (int i = 0; i < inorderArray.size(); i++) {
				
				if (inorderArray[i]->value == data) {
					
					cout << "\n\n" << data << " is at pos: " << i+1;
					pos = i;
					break;
				}
			}
			int succesor_value = inorderArray[pos+1]->value;
			cout << "\n\nAnd its sucessor is:::" << succesor_value;
			cout << "\n\n\t\t Therefore copying the value of succesor " << succesor_value << " in " << ptr->value;
			cout << "\n\t\t And deleting the sucessor " << succesor_value<<"\n";
			cout << "\n\n*****************************************************************************************************";
			cout << "\n*****************************************************************************************************";
			cout << "\n*****************************************************************************************************\n\n";
			del(inorderArray[pos + 1]->value);
			inorderArray[pos]->value = succesor_value;
			
			
		}
		return 1;
	}


		void inorder(Node *node) {
			if (node != NULL) {
				inorder(node->left);
				cout << node->value<< "-->";
				inorderArray.push_back(node);
				inorder(node->right);
			}
		}

		void preorder( Node *root) {

			if (root != NULL) {
				cout << root->value <<"-->";
				preorder(root->left);
				preorder(root->right);
			}
		}

		void postorder( Node *root) {
			if (root != NULL) {
				postorder(root->left);
				postorder(root->right);
				cout << root->value << "--> ";
			}
		}

		Node* getroot() {
			return root;
		}

	
};

Tree binary;

BOOL gotoxy(const WORD x, const WORD y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}


COORD getsize() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	COORD xy;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	xy.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	xy.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	cout << "window size is: " << endl << "X:" << xy.X << endl << "Y:" << xy.Y << endl;
	return xy;
}

void printVector(vector<int> v) {
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\t';
}

void addNode() {
	system("cls");
	cout << "\n NODE ADDITION MENU ::\n\n";
	cout << "\n ENTER THE NODE's DATA:\t";
	int data;
	cin >> data;
	binary.insert(data);
	cout << "\n\n\t\t Do you wish to insert more node?(y/n)\n\n";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		addNode();
	}
	else {
		menu();
	}
}
void searchNode() {
	system("cls");
	cout << "\n NODE SEARCH MENU ::\n\n";
	cout << "\n ENTER THE NODE TO BE SEARCHED:\t";
	int data;
	cin >> data;
	binary.search(data);
	cout << "\n\n\tdo you wish to search another node?(y/n)\n\n";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		searchNode();
	}
	else {
		menu();
	}

}
void deleteNode() {
	system("cls");
	cout << "\n NODE DELETION MENU ::\n\n";
	cout << "\n ENTER THE NODE TO BE DELETED:\t";
	int data;
	cin >> data;
	int status=binary.del(data);
	if (status == 1) {
		cout << "\n\n\t" << data << " succesfully deleted from tree";
		cout << "\n\n\t\t do you wish to delete another node?(y/n)\n\n";
	}
	else {
		cout << "\n\n\t\t do you wish to delete another node?(y/n)\n\n";
	}
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		deleteNode();
	}
	else {
		menu();
	}

}
void printNode() {
	system("cls");
	cout << "IN WHICH FORM DO YOU WISH TO SEE OUTPUT:";
	cout << "\n\t 1. PREORDER";
	cout << "\n\t 2. INORDER";
	cout << "\n\t 3. POSTORDER";
	cout << "\n\t 4. ALL THE ABOVE";
	cout << "\n\t 5. RETURN";
	int order;
	cin >> order;
	system("cls");
	cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TREE TRAVERSAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n\n\n\n";
	switch (order) {
	case 1:
		cout << endl << endl << "PREORDER TRAVERSAL::" << endl;
		binary.preorder(binary.root);
		cout << "NULL";
		_getch();
		printNode();
		break;
	case 2:
		cout << endl << endl << "INORDER TRAVERSAL:::" << endl;
		binary.inorder(binary.root);
		cout << "NULL";
		_getch();
		printNode();
		break;
	case 3:
		cout << endl << endl <<"POSTORDER TRAVERSAL::" << endl;
		binary.postorder(binary.root);
		cout << "NULL";
		_getch();
		printNode();
		break;
	case 4:
		cout << endl << endl << "PREORDER TRAVERSAL::" << endl;
		binary.preorder(binary.root);
		cout << "NULL";
		cout << endl<<endl << "INORDER TRAVERSAL:::" << endl;
		binary.inorder(binary.root);
		cout << "NULL";
		cout << endl << endl << "POSTORDER TRAVERSAL::" << endl;
		binary.postorder(binary.root);
		cout << "NULL";
		_getch();
		printNode();
		break;
	case 5:
		menu();
		break;
	default:
		cout << "\n\n\n\n\t\t\t\t\t\t\t\t *_* *_* *_* *_* *_*";
		cout << "\n\t\t\t\t\t\t\t\t Oops WRONG CHOICE!!";
		cout << "\n\t\t\t\t\t\t\t\t      Try again!";
		cout << "\n\t\t\t\t\t\t\t\t *_* *_* *_* *_* *_*";
		_getch();
		printNode();
		break;
		


	}

}
void operation(int choice) {
	switch (choice) {
	case 1:
		addNode();
		break;
	case 2:
		deleteNode();
		//cout << "\n\n\n\n\n\t\t\t\t\t\t\t WORK IN PROGRESS";
		//cout << "\n\t\t\t\t\t\t\t WILL BE IMPLEMENTED SOON";
		//menu();
		break;
	case 3:
		printNode();
		break;
	case 4:
		searchNode();
		break;
	case 5:
		cout << "\n\n\n\n\n\t\t\t\t\t\t\t PRESS ANY KEY TO EXIT !";
		_getch();
		return;
		break;
	default:
		cout << "\n\n\n\n\t\t\t\t\t\t *_* *_* *_* *_* *_*";
		cout << "\n\t\t\t\t\t\t Oops WRONG CHOICE!!";
		cout << "\n\t\t\t\t\t\t   Try again!";
		cout << "\n\t\t\t\t\t\t *_* *_* *_* *_* *_*";
		_getch();
		menu();
		break;
	}
}
int menu() {

	system("cls");
	COORD xy = getsize();
	//gotoxy(xy.X / 2 - 10, xy.Y / 3);
	cout << "\n\n\n";
	cout << "BINARY TREE MENU" << endl;
	cout << "\t 1. add node" << endl;
	cout << "\t 2. delete node" << endl;
	cout << "\t 3. show nodes" << endl;
	cout << "\t 4. search element" << endl;
	cout << "\t 5. exit" << endl;
	int choice;
	cin >> choice;
	operation(choice);
	return 0;
}

int window() {
	int a;
	Display display(400, 400, "OpenGL");
	while (!display.isClosed()) {
		glClearColor(0.0f, 0.5f, 0.6f, 1.9f);
		glClear(GL_COLOR_BUFFER_BIT);
		display.Update();

		std::cin >> a;
		return 0;
	}
}
int main(int argc, char **argv) {
	bool dis = true;
	
	window();
	
	bool debugging = true;
	if (!debugging) {
		menu();
	}
	else {
		vector<int> values;
		values= { 25,15,10,4,12,22,18,24,50,70,66,90,35,31,44 }; //example 1 image included in source
		//values = { 43,15,8,30,20,35,60,50,82,70 };  //example 2  image included in source

		for (int i = 0; i < values.size(); i++) {

			binary.insert(values[i]);
			//cout <<sizeof(v)<<"::"<< v[i]<<endl;
		}

		cout << endl << "entered data::" << endl;
		printVector(values);
		cout << endl << "inorder is::" << endl;
		binary.inorder(binary.root);
		cout << endl << "preorder is::" << endl;
		binary.preorder(binary.root);
		cout << endl << "postorder is::" << endl;
		binary.postorder(binary.root);
		menu();
		_getch();
	}

	
	return 0;
}

