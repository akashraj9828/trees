#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<vector>
#include<cstdlib>
#include<ctime>
#include"Tree.h"
#include"Node.h"
//#include<SDL2\SDL.h>
//#include<gl\glew.h>
//#include"Display.h"
#define RAND_MAX 200

using namespace std;
int main(int argc, char **argv);
int menu();
vector<int> values;


Tree binary;
//moves cursor to (x,y) 
BOOL gotoxy1(const WORD x, const WORD y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

//returns size of console window
COORD getsize1() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	COORD xy;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	xy.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	xy.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	//cout << "window size is: " << endl << "X:" << xy.X << endl << "Y:" << xy.Y << endl;
	return xy;
}
COORD xy = getsize1(); //xy.X=no of coloumns  xy.Y=no of rows

void printVector(vector<int> v) {

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\t';
}

void addNode() {
	system("cls");
	cout << "\n NODE ADDITION MENU ::\n\n";
	cout << "\n ENTER THE NODE's DATA:\t";
	int data, status;
	cin >> data;
	status = binary.insert(data);  //=0(added to let of ptr)  ==1(added right to ptr)  ==2(added as root)  ==3(duplicate)
	cout << "\n\n\t\t Do you wish to insert more node?(y/n)\n\n";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		addNode();
	}
	else {
		cout << "\n\n\t\t Do you wish see the tree?(y/n)\n\n";
		cin >> c;
		if (c == 'y' || c == 'Y') {
			Node* pointer;
			cout << "\n\n\n\t\t\t~~~~~~~~~~~~~~ SETTING COORDINATES ~~~~~~~~~~~~~~";
			binary.setPos(binary.root);
			_getch();
			system("cls");
			cout << "\n\n\t\t SHOWING 3 LEVEL AT A TIME:-";
			binary.plot(binary.root);
			_getch();
			if (status == 0) {
				pointer = binary.ptr->left;
			}
			else if (status == 1) {
				pointer = binary.ptr->right;
			}
			else if (status == 2) {
				pointer = binary.root;
			}
			else if (status == 3) {
				pointer = binary.ptr;
			}
			gotoxy1(pointer->pos.X + 2, pointer->pos.Y);
			cout << "<--(node inserted)";
			binary.clearPos(binary.root);
			getch();
			c = 'n';
			menu();
		}
		else {
			menu();
		}
	}
}
void searchNode() {
	system("cls");
	cout << "\n NODE SEARCH MENU ::\n\n";
	cout << "\n ENTER THE NODE TO BE SEARCHED:\t";
	int data;
	cin >> data;
	binary.search(data);
	cout << "\n\n\t\t" << "~~~~~~~~~~~~~~SEARCH-COMPLETE~~~~~~~~~~~~~~" << endl;
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
	
	


	
	binary.setPos(binary.root);
	system("cls");
	cout << "\n NODE DELETION MENU ::\n\n";
	cout << "\n\n\t FRAME OF REFFERENCE : ROOT(" << binary.root->value << ")";
	cout << "\n\n\t SHOWING 4 LEVEL AT A TIME:-";
	binary.plot(binary.root);
	binary.clearPos(binary.root);

	gotoxy1(2,xy.Y-2);
	cout << "\n ENTER THE NODE TO BE DELETED:\t";
	int data;
	cin >> data;
	int status = binary.del(data);
	_getch();
	if (status == 0) {
		

		binary.setPos(binary.root);
		system("cls");
		cout << "\t\t After deletion of " << data;
		cout << "\n\n\t FRAME OF REFFERENCE : ROOT(" << binary.root->value << ")";
		cout << "\n\n\t SHOWING 4 LEVEL AT A TIME:-";
		binary.plot(binary.root);
		binary.clearPos(binary.root);

		gotoxy1( 2, xy.Y - 2);
		 cout<< "\t\t" << data << " succesfully deleted from tree";
		cout << "\n\n\t\t do you wish to delete another node?(y/n)\n\n";

	}
	else {

		binary.setPos(binary.root);
		system("cls");
		cout << "\t\t After deletion of " << data;
		cout << "\n\n\t FRAME OF REFFERENCE : ROOT(" << binary.root->value << ")";
		cout << "\n\n\t SHOWING 4 LEVEL AT A TIME:-";
		binary.plot(binary.root);
		binary.clearPos(binary.root);
		gotoxy1( 2, xy.Y - 2);
		cout << "\t\t do you wish to delete another node?(y/n)\n\n";
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
void traverse() {
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
		traverse();
		break;
	case 2:
		cout << endl << endl << "INORDER TRAVERSAL:::" << endl;
		binary.inorder(binary.root);
		cout << "NULL";
		_getch();
		traverse();
		break;
	case 3:
		cout << endl << endl << "POSTORDER TRAVERSAL::" << endl;
		binary.postorder(binary.root);
		cout << "NULL";
		_getch();
		traverse();
		break;
	case 4:
		cout << endl << endl << "PREORDER TRAVERSAL::" << endl;
		binary.preorder(binary.root);
		cout << "NULL";
		cout << endl << endl << "INORDER TRAVERSAL:::" << endl;
		binary.inorder(binary.root);
		cout << "NULL";
		cout << endl << endl << "POSTORDER TRAVERSAL::" << endl;
		binary.postorder(binary.root);
		cout << "NULL";
		_getch();
		traverse();
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
		traverse();
		break;



	}

}
void printNode() {
	system("cls");
	cout << "FORM WHICH NODE DO YOU WISH TO SEE TREE:";
	cout << "\n\t 1. ROOT";
	cout << "\n\t 2. CUSTOM ENTRY";
	cout << "\n\t 3. RETURN";
	int choice;
	cin >> choice;
	system("cls");
	cout << "\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TREE VISUALIZATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n\n\n\n";
	switch (choice) {
	case 1:
		if (binary.root == NULL)
			return;
		cout << "\n\n\n\t\t\t~~~~~~~~~~~~~~ SETTING COORDINATES ~~~~~~~~~~~~~~";
		binary.setPos(binary.root);
		_getch();
		system("cls");
		cout << "\n\n\t\t FRAME OF REFFERENCE : ROOT(" << binary.root->value << ")";
		cout << "\n\n\t\t SHOWING 4 LEVEL AT A TIME:-";

		binary.plot(binary.root);
		_getch();
		binary.clearPos(binary.root);
		printNode();
		break;
	case 2:
		cout << "Enter the node from where you want to view tree:";
		int data;
		cin >> data;
		int status;
		status = binary.search(data);
		if (status != 2) {   //status=2 means element not found
			binary.setPos(binary.ptr);
			_getch();
			system("cls");

			cout << "\n\n\t\t FRAME OF REFFERENCE : NODE(" << binary.ptr->value << ")";
			cout << "\n\n\t\t SHOWING 4 LEVEL AT A TIME:-";
			binary.plot(binary.ptr);
		}
		_getch();
		binary.clearPos(binary.root);
		printNode();

		break;
	case 3:
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
	binary.setPos(binary.root->left);
	_getch();
	system("cls");
	binary.plot(binary.root->left);
}
void randomNode() {
	int max, n;
	cout << "\n RANDOM NODE ADDITION MENU ::\n\n";
	cout << "\n ENTER THE NUMBER OF NODE TO ADD :\t";
	cin >> n;
	cout << "\n ENTER THE MAX VALUE OF NODE :\t";
	cin >> max;
	srand((int)time(0));
	int random_val;
	values.clear();
	for (int i = 0; i < n; i++) {//

		random_val = rand() % max;
		values.push_back(random_val);
		binary.insert(values[i]);
	}

	cout << endl << "entered data::" << endl;
	printVector(values);
	getch();
}
void operation(int choice) {
	switch (choice) {
	case 1:
		addNode();
		break;
	case 2:
		deleteNode();
		break;
	case 3:
		traverse();
		break;
	case 4:
		searchNode();
		break;
	case 5:
		printNode();
		_getch();
		menu();
		break;
	case 6:
		randomNode();
		menu();
		break;
	case 7:
		binary.delete_all(binary.root);
		menu();
		break;
	case 8:
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
	//gotoxy(xy.X / 2 - 10, xy.Y / 3);
	cout << "\n\n\n";
	cout << "BINARY TREE MENU" << endl;
	cout << "\t 1. add node" << endl;
	cout << "\t 2. delete node" << endl;
	cout << "\t 3. show nodes" << endl;
	cout << "\t 4. search element" << endl;
	cout << "\t 5. show tree" << endl;
	cout << "\t 6. fill in random nodes" << endl;
	cout << "\t 7. delete all nodes" << endl;
	cout << "\t 8. exit" << endl;
	gotoxy1(xy.X - 20, xy.Y);
	cout << "Total nodes :: " << binary.total_node;
	int choice;
	cin >> choice;
	operation(choice);
	return 0;
}

//int window() {
//	Display display(400, 400, "OpenGL");
//	while (!display.isClosed()) {
//		glClearColor(0.8f, 0.9f, 0.2f, 1.9f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		display.Update();
//	}
//	getch();
//	return 0;
//}
int main(int argc, char **argv) {


	bool debugging = false;
	//bool opengl = false;




	//if(opengl)
	//window();


	if (!debugging) {
		menu();
	}
	else {

		values = { 25,15,10,4,12,22,18,24,50,70,66,90,35,31,44 }; //example 1 image included in source
		//values = { 25,15,10,12,22,18,50,70,6,90,35,31,17, 9, 5, 21, 19, 6, 59, 4, 29, 28, 25, 26, 14	};  //random
		//values = { 43,15,8,30,20,35,60,50,82,70 };  //example 2  image included in source

		srand((int)time(0));

		for (int i = 0; i < values.size(); i++) {
			binary.insert(values[i]);
		}

		cout << endl << "entered data::" << endl;
		printVector(values);
		cout << endl << "inorder is::" << endl;
		binary.inorder(binary.root);
		cout << endl << "preorder is::" << endl;
		binary.preorder(binary.root);
		cout << endl << "postorder is::" << endl;
		binary.postorder(binary.root);
		_getch();
		menu();

	}


	return 0;
}

