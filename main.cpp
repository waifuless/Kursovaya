#include <iostream>
#include <clocale>
#include "IUser.h"
#include "Admin.h"
#include "Viewer.h"

using namespace std;

int menu(void);


int main() {
	setlocale(LC_CTYPE, "rus");
	IUser* user=NULL;
	int choice = 0;
	while (1) {  //���� �����������, ���� ������������ �� ������ 1 ��� 2
		cout << "�������� ����� ������: " << endl
			<< "1 - ��������(�������� ������ �������� � �����)" << endl
			<< "2 - �������������(�������� ��� �������)" << endl
			<< "3 - �����" << endl;
		cin >> choice;
		if (choice > 3 || choice < 1) cout << "����������� ������ ����� ������" << endl;
		else break;
	}
	switch (choice) { //��������� ����� ���������� �������
		case 1: user = new Viewer; break;
		case 2: //���� ������
			user = new Admin; 
			break;
		case 3: return 0;//�������
	}
	while (1) {
		switch (menu()) {
		case 1: user->viewRecords();
			break;
		case 2:	user->addRecord();
			break;
		case 3:user->redactRecord();
			break;
		case 4:	user->deleteRecord();
			break;
		case 5:user->serchRecord();
			break;
		case 6: user->sortRecords();
			break;
		case 7:	user->filterRecords();
			break;
		case 8: return 0; ////������� ������(��������)
			break;
		default: cout << endl << "������ ������������ ����� ��������";
			break;
		}
	}
	return 0;
}

int menu(void) {
	//�������� �����
	int choice = 0;
	cout <<endl<< "�������� ��������: " << endl
		<< "1 - �������� �������" << endl
		<< "2 - �������� ������ " << endl
		<< "3 - ������������� ������" << endl
		<< "4 - ������� ������" << endl
		<< "5 - ����� ������" << endl
		<< "6 - ����������� ������" << endl
		<< "7 - ������������� ������" << endl
		<< "8 - �����" << endl;
	cin >> choice;
	return choice;
}