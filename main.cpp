#include<iostream>
#include "Node.h"
#include <windows.h>
#include<conio.h>
#include<stdio.h>
#include<vector>
///////////////////////GLOBAL VARIABLES//////////////////////////////
vector<Node> nodesArray;
int i = 100;
int counter = 0;

/////////////////////FUNCTION PROTOTYPES////////////////////////////
BOOL gotoxy(const WORD x, const WORD y);
int menu();
void setPos(Node node);


using namespace std;
int main() {
	
	
	menu();
	return 0;
}

int menu() {
	int a;
	int data;
	system("cls");
	gotoxy(20, 2);
	cout << "MENU" << endl;
	cout << "1.add node"<<endl;
	cout << "2.delete node"<<endl;
	cout << "3.show nodes"<<endl;
	cout << "4.exit"<<endl;
	int choice;
	cin >> choice;
	cout << endl;
	


	
	if (choice == 1) {
		
		cout << "enter data:";
		cin >> data;
		Node temp(data);
		nodesArray.push_back(temp);
		cout << "sucessfully entered";
		getch();
		menu();
		}else if (choice == 3) {
		
		for (int i = 0; i < nodesArray.size(); i++) {
			cout <<"value "<<i<<" is: "<< nodesArray[i].returnValue() << endl;	
		}
		getch();
		menu();
		}else if (choice == 4) {
			getch();
			return 0;
	}
		
	
}

void setPos(Node node)
{
	/*Node root = nodesArray[0];
	for (int i = 0; i < nodesArray.size(); i++) {
		if (node.value < root.value) {
			
		}

	}*/
}


// function to move cursor around
BOOL gotoxy(const WORD x, const WORD y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
