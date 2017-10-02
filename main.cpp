#include<iostream>
#include"Node.h"
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<vector>
#include<cstdlib>
#include<SDL2\SDL.h>
#include<gl\glew.h>
#include"Display.h"
#include"Tree.h"

using namespace std;
int menu();

Tree binary;




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
	cout << "\n NODE DELETION MENU ::\n\n";
	cout << "\n ENTER THE NODE TO BE DELETED:\t";
	int data;
	cin >> data;
	int status=binary.del(data);
	if (status == 1) {
		cout << "\n\n\t\t" << data << " succesfully deleted from tree";
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
		binary.setPos(binary.root);
		_getch();
		system("cls");
		binary.plot(binary.root);
		_getch();
		menu();
		break;
	case 6:
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
	cout << "\t 5. show graphical" << endl;
	cout << "\t 6. exit" << endl;
	int choice;
	cin >> choice;
	operation(choice);
	return 0;
}

int window() {
	Display display(400, 400, "OpenGL");
	while (!display.isClosed()) {
		glClearColor(0.8f, 0.9f, 0.2f, 1.9f);
		glClear(GL_COLOR_BUFFER_BIT);
		display.Update();
	}
	getch();
	return 0;
}
int main(int argc, char **argv) {
	bool opengl = false;

	if(opengl)
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
		_getch();
		menu();
		
	}

	
	return 0;
}

