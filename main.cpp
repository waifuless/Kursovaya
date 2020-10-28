#include <iostream>
#include <clocale>
#include "IUser.h"
#include "Admin.h"
#include "Viewer.h"

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	int choice=0;
	IUser* user=NULL;
	cout << "�������� ����� ������: " << endl
		<< "1 - ��������(�������� ������ �������� � �����)" << endl
		<< "2 - �������������(�������� ��� �������)" << endl;
	cin >> choice;
	switch (choice) {
		case 1: user = new Viewer; break;
		case 2: //���� ������
			user = new Admin; 
			break;
	}
	if(user!=NULL) user->addRecord();
	return 0;
}