#include<iostream>
#include"Node.h"
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<vector>
#include<cstdlib>
#include"Tree.h"

using namespace std;


//moves cursor to (x,y) 
BOOL gotoxy(const WORD x, const WORD y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

//returns size of console window
COORD getsize() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	COORD xy;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	xy.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	xy.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	//cout << "window size is: " << endl << "X:" << xy.X << endl << "Y:" << xy.Y << endl;
	return xy;
}


Tree::Tree() {
	root = NULL;
	ptr = root;
	depth = 0;
	total_node = 0;

}
Tree::~Tree() {
	cout << "\t\t\t\t***************** Tree destroyed *****************";
	cout << "\n\n\n\t\t\t\t\t   PRESS ANY KEY TO EXIT !";
	_getch();
}

//return code for insert:
//0 :element added as left child
//1 :element added as right child
//2 :element added as root
//3 :duplicate found (no insertion)
int Tree::insert(int data) {


	cout << "\n\n\n\t\t" << "~~~~~~~~~~~~~~ADDITION~~~~~~~~~~~~~~" << endl;
	cout << "\n\n\t\t\t" << "Inserting " << data << " in tree" << endl;


	if (root == NULL) {
		cout << "\n\n\t\t\t" << "Tree is empty ";
		cout << "\n\t\t\t" << data << " is added as first element of tree\n\n";
		cout << "\n\t\t\tPath:  ->" << data;
		cout << "\n\t\t\t ";
		Node *temp = new Node(data);
		root = temp;
		total_node++;
		root->pos.X = NULL;
		root->pos.Y = NULL;
		root->level = 0;
		root->gap = 0;
		return 2;
	}
	else {
		cout << "\n\t\t\t Path:";
		cout << root->value << "->";
		ptr = root;
		while (true) {
			if (!duplicate && data == ptr->value) {
				cout << "\n\n\n\n\t\t\t ***************************";
				cout << "\n\t\t\t **Duplicate value entered** ";
				cout << "\n\t\t\t ***************************";
				cout << "\n\n\n\n\t\t\t" << data << " already present in tree ";
				return 3;
			}else if (data < ptr->value) {
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
					total_node++;
					cout << "(" << ptr->left->value << ")" << "\t <<-(new node added here)";
					cout << "\n\n\n\n\t\t\t" << data << " succesfully inserted in tree";
					
					return 0;
				}
			}
			else if(data>ptr->value){
				// similarly for the value that should be inserted into
				// right subtree
				if (NULL != ptr->right) {
					ptr = ptr->right;
					cout << ptr->value << "->";
					continue;
				}
				else {
					ptr->right = new Node(data);
					total_node++;
					cout << "(" << ptr->right->value << ")" << "\t <<-(new node added here)";
					cout << "\n\n\n\n\t\t\t" << data << " succesfully inserted in tree";
					return 1;
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
	//case 0 element is root
	else if (status == 3 && total_node==1) {
		
		root = NULL;
		return 0;
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
		total_node--;
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
		total_node--;
		cout << "\n\n*****************************************************************************************************";
		cout << "\n*****************************************************************************************************";
		cout << "\n*****************************************************************************************************\n\n";
		return 0;
	}
	//case 3: node has two child
	else if ((ptr->left != nullptr) && (ptr->right != nullptr)) {

		Node* toBeDeleted = ptr;				//node to be deleted
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
		cout << "\n\n{ Removing any link of " << succesor_value << " from its parent }";
		if (sucessor_branch == 0) {
			cout << "\n 1. setting " << parent->value << "'s left to NULL";
			parent->left = nullptr;				//here parent = parent of suceesor
		}
		else if (sucessor_branch == 1) {
			cout << "\n 1. setting " << parent->value << "'s right to NULL";
			parent->right = nullptr;
		}
		if (status == 3) {	////entered elemnt is root
			cout << "\n\n{ Entered element is root and has no parents }";
			cout << "{ Therefore " << succesor_value << " will take place of root }";
			cout << "\n 2. Setting root = " << succesor_value;
			root = succesor;
		}
		else if (status != 3) {
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
		total_node--;


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

void Tree::preorder(Node *node) {

	if (node != NULL) {
		cout << node->value << "-->";
		preorder(node->left);
		preorder(node->right);
	}
}

void Tree::postorder(Node *node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		cout << node->value << "-->";
	}
}


int step = 0;
void Tree::setPos(Node * node)
{
	step++;
	cout << endl<<step<<". ";
	
	COORD tempc = getsize();
	if (node == NULL) {
		return;
	}
	if (node->pos.X == NULL && node->pos.Y == NULL) {
		node->pos.X = tempc.X / 2;
		node->pos.Y = tempc.Y / 20;
	}
	if (node->gap == 0) {
		node->gap = tempc.X / 5;
	}
	if (node->left) {
		node->left->pos.X = node->pos.X + 1 - node->gap;
		node->left->pos.Y = node->pos.Y + 6;
		node->left->gap = node->gap / 2;
		node->left->level = node->level + 1;
		if (node->left->level > depth)
			depth = node->left->level;
		cout <<"node: "<<node->left->value << "\t";
		cout <<"coordinate: ("<< node->left->pos.X << " , " << node->left->pos.Y << ") \t\t level: " << node->left->level ;
		setPos(node->left);
	}
	if (node->right) {

		node->right->pos.X = node->pos.X - 1 + node->gap;
		node->right->pos.Y = node->pos.Y +6;
		node->right->gap = node->gap / 2;
		node->right->level = node->level + 1;
		if (node->right->level > depth)
			depth = node->right->level;
		cout << "node: " << node->right->value << "\t";
		cout << "coordinate: (" << node->right->pos.X << " , " << node->right->pos.Y << ") \t\t level: " << node->right->level ;
		setPos(node->right);

	}



}



int lvl=NULL;

void Tree::plot(Node * node)
{
	if (node == NULL)
		return;

	gotoxy(node->pos.X, node->pos.Y);
	cout << node->value;
	if (lvl == NULL) {
		lvl = node->level;
	}
	if (node->left && (node->left->level)<=3+lvl) {
		line(node->left->pos, node->pos, 1);
		plot(node->left);
	}
	else if (node->left) {
		gotoxy(node->pos.X-1, node->pos.Y + 1);
		cout << "|";
		gotoxy(node->pos.X-1, node->pos.Y + 2);
		cout << "|";
		gotoxy(node->pos.X-1, node->pos.Y + 3);
		cout << "V";
	}
	else {
		gotoxy(node->pos.X-1, node->pos.Y + 1);
		cout << "x";
	}


	if (node->right && (node->right->level) <= 3+lvl) {
		line(node->pos, node->right->pos, -1);
		plot(node->right);
	}
	else if (node->right) {
		gotoxy(node->pos.X+1, node->pos.Y + 1);
		cout << "|";
		gotoxy(node->pos.X+1, node->pos.Y + 2);
		cout << "|";
		gotoxy(node->pos.X+1, node->pos.Y + 3);
		cout << "V";
	}
	else {
		gotoxy(node->pos.X+1, node->pos.Y + 1);
		cout << "x";
	}


}
void Tree::clearPos(Node * node)
{	
	if (node == NULL)
		return;


	step = 0;
	lvl = NULL;
	node->pos.X = NULL;
	node->pos.Y = NULL;
	node->gap = 0;
	if (node->left) {
		clearPos(node->left);
	}
	if (node->right) {
		clearPos(node->right);
	}

}
///dir=1 means line frm p1 to p2 is elevating
//di=-1 means line frm p1 to p2 is decending
void Tree::line(COORD p1, COORD p2, int dir)
{
	//my algo
	int dx, dy, x, y;
	dx = p2.X - p1.X;
	dy = p2.Y - p1.Y;
	x = p1.X;
	y = p1.Y - dir;
	float m;
	if (dx == 0)
		return;
	if (dx != 0)
		m = dy / dx;
	while (x != p2.X - 1) {
		dx = p2.X - x;
		dy = p2.Y - y;
		if (dx != 0)
			m = dy / dx;
		if (dx == 0)
			continue;
		else if (m < -1) {
			y--;

		}
		else if (m < 0) {
			y--;
			x++;

		}
		else if (m < 1) {
			x++;

		}
		else if (m > 1) {
			y++;

		}
		else if (m == 1) {
			x++;
			y++;

		}
		gotoxy(x, y);
		cout << ".";
	}
	//////breshnam
	/*int dx, dy, p, x, y;

	dx = (p2.X - p1.X);
	dy = (p2.Y - p1.Y+1);

	x = p1.X;
	y = p1.Y+1;

	p = 2 * dy - dx;

	while (x<p2.X)
	{
		if (p >= 0)
		{


			y = y + 1;
			x = x + 1;
			gotoxy(x, y);
			cout << ".";
			p = p + 2 * dy - 2 * dx;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			x++;

			p = p + 2 * dy;
			gotoxy(x, y);
			cout << ".";
		}

	}*/


	//////DDA
	/*int step;
	int dx = (p2.X - p1.X);
	int dy = (p2.Y - p1.Y+1);

	if (dx >= dy)
	step = dx;
	else
	step = dy;

	dx = dx / step;
	dy = dy / step;

	int x = p1.X;
	int y = p1.Y+1;

	int i = 1;
	while (i <= step)
	{
	gotoxy(x, y);
	cout << ".";
	x = x + dx;
	y = y + dy;
	i = i + 1;
	}*/
}

void Tree::delete_all(Node * node)
{

	if (node == root) {
		root->pos.X = NULL;
		root->pos.Y = NULL;
		root->gap = 0;
		ptr = root;
		depth = 0;
		total_node = 0;
		root = NULL;
		
	}
		


	
	
	if (node->left) {
		delete_all(node->left);
	}
	if (node->right) {
		delete_all(node->right);
	}
}






