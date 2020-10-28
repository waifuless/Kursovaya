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
	while (1) {  //Цикл выполняется, пока пользователь не введет 1 или 2
		cout << "Выберите режим работы: " << endl
			<< "1 - просмотр(доступны только просмотр и поиск)" << endl
			<< "2 - администратор(доступны все функции)" << endl
			<< "3 - выход" << endl;
		cin >> choice;
		if (choice > 3 || choice < 1) cout << "Неправильно введен номер режима" << endl;
		else break;
	}
	switch (choice) { //Создается объет выбранного доступа
		case 1: user = new Viewer; break;
		case 2: //Ввод пароля
			user = new Admin; 
			break;
		case 3: return 0;//Очситка
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
		case 8: return 0; ////Очистка памяти(добавить)
			break;
		default: cout << endl << "Выбран неправильный номер действия";
			break;
		}
	}
	return 0;
}

int menu(void) {
	//очистить экран
	int choice = 0;
	cout <<endl<< "Выберите действие: " << endl
		<< "1 - Просмотр записей" << endl
		<< "2 - Добавить запись " << endl
		<< "3 - Редактировать запись" << endl
		<< "4 - Удалить запись" << endl
		<< "5 - Поиск записи" << endl
		<< "6 - Сортировать записи" << endl
		<< "7 - Отфильтровать записи" << endl
		<< "8 - Выход" << endl;
	cin >> choice;
	return choice;
}