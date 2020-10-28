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
	cout << "Выберите режим работы: " << endl
		<< "1 - просмотр(доступны только просмотр и поиск)" << endl
		<< "2 - администратор(доступны все функции)" << endl;
	cin >> choice;
	switch (choice) {
		case 1: user = new Viewer; break;
		case 2: //Ввод пароля
			user = new Admin; 
			break;
	}
	if(user!=NULL) user->addRecord();
	return 0;
}