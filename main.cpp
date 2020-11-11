#include <iostream>
#include <clocale>
#include "IUser.h"
#include "Admin.h"
#include "Viewer.h"
#include "Doctor.h"
#include "sha256.h" //���� ��� ����������

using namespace std;

int menu(void);


int main() {
	setlocale(LC_CTYPE, "rus");
	IUser* user=NULL;
	bool stillWork;
	int choice = 0;
	//�������� ������� ������ �����
	while (1) {
		while (1) {  //���� �����������, ���� ������������ �� ������� �����
			stillWork = true;
			cout << "�������� ����� ������: " << endl
				<< "1 - ��������(�������� ������ �������� � �����)" << endl
				<< "2 - �������������(�������� ��� �������)" << endl
				<< "3 - ������(��������, �����, ����������)" << endl
				<< "4 - �����" << endl;
			cin >> choice;
			if (choice > 4 || choice < 1) cout << "����������� ������ ����� ������" << endl;
			else break;
		}
		switch (choice) { //��������� ����� ���������� �������
		case 1: user = new Viewer; break;
		case 2: //���� ������
			user = new Admin;
			break;
		case 3: user = new Doctor; break;
		case 4: return 0;//�������
		}  
		while (stillWork) {
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
			case 8: stillWork = false;
				delete user;//������� ������
				user = NULL;
				break;
			default: cout << endl << "������ ������������ ����� ��������";
				break;
			}
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
		<< "8 - � ���� �����������" << endl;
	cin >> choice;
	return choice;
}