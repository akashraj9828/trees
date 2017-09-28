#include<iostream>
#include "Node.h"
#include <windows.h>
#include<conio.h>
#include<stdio.h>
#include<vector>

using namespace std;

/*//////////////////////GLOBAL VARIABLES//////////////////////////////*/
int i = 100;
int counter = 0;
vector<Node> nodesArray;
Node *root;

/*////////////////////FUNCTION PROTOTYPES///////////////////////////*/
BOOL gotoxy(const WORD x, const WORD y);
int menu();
void setPos(Node node);
void push();
void print();
void pop(int data);
void inOrder(vector<Node> list);


int main() {


	menu();
	return 0;
}

int menu() {
	
	system("cls");
	gotoxy(20, 2);
	cout << "MENU" << endl;
	cout << "1.add node" << endl;
	cout << "2.delete node" << endl;
	cout << "3.show nodes" << endl;
	cout << "4.exit" << endl;
	int choice;
	cin >> choice;
	cout << endl;



	switch (choice) {
	case 1:
		push();
		menu();
		break;

	case 2:
		//delete fnx;

	case 3:
		print();
		menu();
	
	case 4:
		getch();
		return 0;
			

	}
	

}

void push() {
	int data;
	cout << "enter data:";
	cin >> data;
	Node temp(data);
	nodesArray.push_back(temp);
	cout << "sucessfully entered";
	getch();
}
void setPos(Node node)
{
	/*Node root = nodesArray[0];
	for (int i = 0; i < nodesArray.size(); i++) {
		if (node.value < root.value) {

		}

	}*/
}
void print() {
	for (int i = 0; i < nodesArray.size(); i++) {
		cout << "value " << i << " is: " << nodesArray[i].returnValue() << endl;
	}
	getch();
}
void pop(int data) {
	for (int i = 0; i < nodesArray.size(), i++);
}

void inOrder(vector<Node> list) {


}
// function to move cursor around
BOOL gotoxy(const WORD x, const WORD y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
