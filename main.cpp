#include <iostream>
#include <clocale>
#include "IUser.h"
#include "Admin.h"
#include "Viewer.h"
#include "Doctor.h"
#include "sha256.h" //файл для шифрования
#include "Authorization.h";

using namespace std;

int menu(void);


int main() {
	setlocale(LC_CTYPE, "rus");
	IUser* user=NULL;
	bool stillWork;
	int choice = 0, choiceUser=0;
	string choosenFile;
	if (!Authorization::isUserExist(Admin::baseOfUsersFile)) { //создание при первом входе в систему
		cout << "Необходимо создать администратора" << endl;
		if (Authorization::createAccount(Admin::baseOfUsersFile) == false) {
			cout << endl << "Не удалось создать администратора";
			return 0;
		}
	}
	while (1) {
		while (1) {  //Цикл выполняется, пока пользователь не выберет выход
			stillWork = true;
			cout <<endl<< "Выберите режим работы: " << endl
				<< "1 - просмотр(доступны только просмотр и поиск)" << endl
				<< "2 - администратор(доступны все функции)" << endl
				<< "3 - доктор(просмотр, поиск, добавление)" << endl
				<< "4 - создать нового пользователя" << endl
				<< "5 - выход" << endl;
			cin >> choice;
			if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
			{
				std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
				std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
				std::cout << "Неправильно введены данные.\n";
				continue;
			}
			else { std::cin.ignore(32767, '\n'); } // удаляем лишние значения, на случай, если они есть
			if (choice > 5 || choice < 1) cout << "Неправильно введен номер команды" << endl;
			else break;
		}
		switch (choice) { //Создается объет выбранного доступа
		case 1: user = new Viewer; break;
		case 2: 
			if (Authorization::singIn(Admin::baseOfUsersFile)) {//Ввод пароля
				user = new Admin;
			}
			else continue;
			break;
		case 3: 
			if (!Authorization::isUserExist(Doctor::baseOfUsersFile)) {
				cout << "Пользователей с доступом \"Доктор\" не существует" << endl;
				continue;
			}
			if (Authorization::singIn(Doctor::baseOfUsersFile)) {//Ввод пароля
				user = new Doctor;
			}
			else continue;
			break;
		case 4:
			cout <<endl<< "Для добавления пользователя необходимо авторизоваться как администратор";
			if (!Authorization::singIn(Admin::baseOfUsersFile)) {//Ввод пароля
				cout << endl << "Неудалось авторизоваться" << endl;
				continue;
			}
			cout << endl << "1 - Добавить администратора "
				<< endl << "2 - Добавить доктора "<<endl;
			cin >> choiceUser;
			if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
			{
				std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
				std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
				std::cout << "Неправильно введены данные.\n";
				continue;
			}
			else { std::cin.ignore(32767, '\n'); }
			if (choiceUser > 2 || choiceUser < 1) {
				std::cout << std::endl << "Такой пользователь отсутствует";
				continue;
			}
			if (choiceUser == 1) {
				choosenFile = Admin::baseOfUsersFile;
			}
			if (choiceUser == 2) {
				choosenFile = Doctor::baseOfUsersFile;
			}
			if (Authorization::createAccount(choosenFile.c_str()) == false) {
				cout << endl << "Не удалось создать пользователя";
				continue;
			}
			continue;
			break;
		case 5: if (user != NULL) {
			delete user;
			user = NULL;
		}
			return 0;//Очситка
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
					delete user;//очищаем память
					user = NULL;
				}
				break;
			default: cout << endl << "Выбран неправильный номер действия";
				break;
			}
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
		<< "8 - К меню авторизации" << endl;
	cin >> choice;
	if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{
		std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
		std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		return 0;
	}
	else { std::cin.ignore(32767, '\n'); } // удаляем лишние значения, на случай, если они есть
	return choice;
}