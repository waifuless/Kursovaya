#include <iostream>
#include <clocale>
#include "IUser.h"
#include "Admin.h"
#include "Viewer.h"
#include "Doctor.h"
#include "sha256.h" //���� ��� ����������
#include "Authorization.h";

using namespace std;

int menu(void);


int main() {
	setlocale(LC_CTYPE, "rus");
	IUser* user=NULL;
	bool stillWork;
	int choice = 0, choiceUser=0;
	string choosenFile;
	if (!Authorization::isUserExist(Admin::baseOfUsersFile)) { //�������� ��� ������ ����� � �������
		cout << "���������� ������� ��������������" << endl;
		if (Authorization::createAccount(Admin::baseOfUsersFile) == false) {
			cout << endl << "�� ������� ������� ��������������";
			return 0;
		}
	}
	while (1) {
		while (1) {  //���� �����������, ���� ������������ �� ������� �����
			stillWork = true;
			cout <<endl<< "�������� ����� ������: " << endl
				<< "1 - ��������(�������� ������ �������� � �����)" << endl
				<< "2 - �������������(�������� ��� �������)" << endl
				<< "3 - ������(��������, �����, ����������)" << endl
				<< "4 - ������� ������ ������������" << endl
				<< "5 - �����" << endl;
			cin >> choice;
			if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
			{
				std::cin.clear(); // �� ���������� cin � '�������' ����� ������
				std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
				std::cout << "����������� ������� ������.\n";
				continue;
			}
			else { std::cin.ignore(32767, '\n'); } // ������� ������ ��������, �� ������, ���� ��� ����
			if (choice > 5 || choice < 1) cout << "����������� ������ ����� �������" << endl;
			else break;
		}
		switch (choice) { //��������� ����� ���������� �������
		case 1: user = new Viewer; break;
		case 2: 
			if (Authorization::singIn(Admin::baseOfUsersFile)) {//���� ������
				user = new Admin;
			}
			else continue;
			break;
		case 3: 
			if (!Authorization::isUserExist(Doctor::baseOfUsersFile)) {
				cout << "������������� � �������� \"������\" �� ����������" << endl;
				continue;
			}
			if (Authorization::singIn(Doctor::baseOfUsersFile)) {//���� ������
				user = new Doctor;
			}
			else continue;
			break;
		case 4:
			cout <<endl<< "��� ���������� ������������ ���������� �������������� ��� �������������";
			if (!Authorization::singIn(Admin::baseOfUsersFile)) {//���� ������
				cout << endl << "��������� ��������������" << endl;
				continue;
			}
			cout << endl << "1 - �������� �������������� "
				<< endl << "2 - �������� ������� "<<endl;
			cin >> choiceUser;
			if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
			{
				std::cin.clear(); // �� ���������� cin � '�������' ����� ������
				std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
				std::cout << "����������� ������� ������.\n";
				continue;
			}
			else { std::cin.ignore(32767, '\n'); }
			if (choiceUser > 2 || choiceUser < 1) {
				std::cout << std::endl << "����� ������������ �����������";
				continue;
			}
			if (choiceUser == 1) {
				choosenFile = Admin::baseOfUsersFile;
			}
			if (choiceUser == 2) {
				choosenFile = Doctor::baseOfUsersFile;
			}
			if (Authorization::createAccount(choosenFile.c_str()) == false) {
				cout << endl << "�� ������� ������� ������������";
				continue;
			}
			continue;
			break;
		case 5: if (user != NULL) {
			delete user;
			user = NULL;
		}
			return 0;//�������
			break;
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
			case 5:user->searchRecord();
				break;
			case 6: user->sortRecords();
				break;
			case 7:	user->filterRecords();
				break;
			case 8: stillWork = false;
				if (user != NULL) {
					delete user;//������� ������
					user = NULL;
				}
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
	if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
	{
		std::cin.clear(); // �� ���������� cin � '�������' ����� ������
		std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
		return 0;
	}
	else { std::cin.ignore(32767, '\n'); } // ������� ������ ��������, �� ������, ���� ��� ����
	return choice;
}