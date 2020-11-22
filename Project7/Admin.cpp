#include "Admin.h"

const char* baseOfPatientsFile = "baseOfPatients.txt";
const char* Admin::baseOfUsersFile = "baseOfAdmins.txt";

using namespace std;

vector<Record> Admin::readVectorOfRecords() { //Читает из файла все строки и записывает в вектор объектов Record
	Record readRecord;
	vector<Record> records;
	ifstream in(baseOfPatientsFile);
		if (in.is_open()) {
			while (!in.eof()) {
				in >> readRecord;
				if (!in.eof()) {
					records.push_back(readRecord);
				}
			}
		}
		in.close();
		return records; //потом возвращает вектор
}

void Admin::viewRecords() { //Выводит все записи пользователю
	vector<Record> records;
	records = readVectorOfRecords();
	for (int i = 0; i < records.size(); i++) {
		cout << i + 1 << ')';
		records[i].print();
	}
	if (records.size() == 0) {
		cout << endl << "Записей не существует";
	}
	}

void Admin::addRecord() { //Создает новый объект, вызывает метод Create, чтобы заполнить поля, после чего записывает объект в файл
	Record newRecord;
	newRecord.create();
	ofstream out(baseOfPatientsFile, ios::app);
	if (out.is_open()) {
		out << newRecord;
	}
	out.close();
	return;
	}

void Admin::redactRecord() { //функция читает все объекты из файла, и изменяет поле одного из объектов на выбор пользователя, 
	//после чего записывает в файл измененные объекты 
	int choiceOfRecord = 0, choiceOfField = 0;
	char newData[150];
	vector<Record> records;
	records = readVectorOfRecords();
	if (records.size() == 0) {
		cout << endl << "Записей не существует";
		return;
	}
	for (int i = 0; i < records.size(); i++) {
		cout << i + 1 << ')';
		records[i].print();
	}
	cout << "Введите номер записи ";
	cin >> choiceOfRecord;
	if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{
		std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
		std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		std::cout<<endl << "Неправильно введены данные.\n";
		return;
	}
	else { std::cin.ignore(32767, '\n'); } // удаляем лишние значения, на случай, если они есть
	if (choiceOfRecord > records.size()||choiceOfRecord<0) {
		cout <<endl<< "Запись под таким номером отсутствует";
		return;
	}
	cout << endl << "Какое поле необходимо изменить?"
		<< endl << "1) ФИО"
		<< endl << "2) Номер карты"
		<< endl << "3) Дату приема"
		<< endl << "4) Время приема"
		<< endl << "5) ФИО врача"
		<< endl << "6) Кабинет" << endl;
	cin >> choiceOfField;
	if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{
		std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
		std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		std::cout<<endl << "Неправильно введены данные.\n";
		return;
	}
	else { std::cin.ignore(32767, '\n'); } // удаляем лишние значения, на случай, если они есть
	cout << "Введите новые данные: "<<endl;
	std::cin.getline(newData, 150);
	OemToCharA(newData, newData);  //функция перекодирует строку, эт необходимо, т.к. работаем с кирилицей
	switch (choiceOfField) {
	case 1: records[choiceOfRecord - 1].setFullName(newData);
		break;
	case 2: records[choiceOfRecord - 1].setCardNumber(newData);
		break;
	case 3: records[choiceOfRecord - 1].setDate(newData);
		break;
	case 4: records[choiceOfRecord - 1].setTime(newData);
		break;
	case 5: records[choiceOfRecord - 1].setDoctorName(newData);
		break;
	case 6: records[choiceOfRecord - 1].setDoctorOffice(newData);
		break;
	default: cout<<endl << "Такого поля не существует";
		return;
		break;
	}
	ofstream out(baseOfPatientsFile);
	for (int i = 0; i < records.size(); i++) {
		out << records[i];
	}
	out.close();
}

void Admin::deleteRecord() {//Функция удаляет один объект, либо все, на выбор пользователя
	int choice = 0;
	vector<Record> records;
	ofstream out;
	cout << endl<<"Выберите действие :"
		<<endl<< "1 - удалить одну запись"
		<< endl << "2 - удалить все записи"<<endl;
	cin >> choice;
	if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{
		std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
		std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		std::cout <<endl<< "Неправильно введены данные.\n";
		return;
		
	}
	else { std::cin.ignore(32767, '\n'); } // удаляем лишние значения, на случай, если они есть
	switch (choice) {
	case 1:
		records = readVectorOfRecords();
		if (records.size() == 0) {
			cout << endl << "Записей не существует";
			return;
		}
		for (int i = 0; i < records.size();i++) {
			cout << i + 1 << ')';
			records[i].print();
		}
		cout << "Введите номер записи ";
		cin >> choice;
		out.open(baseOfPatientsFile);
		for (int i = 0; i < records.size(); i++) {  //После считывания объектов из файла мы записываем обратно все, коме того, который 
			if (i != choice - 1) {  //пользователь захотел удалить
				out << records[i];
			}
		}
		out.close();
		break;
	case 2:
		out.open(baseOfPatientsFile, ios::trunc); //открываем файл и trunc чистит его
		out.close();
		cout << endl << "Все записи удалены";
		break;
	default: cout << endl << "Такого действия не существует";
		return;
		break;
	}
	
}

void Admin::searchRecord() {  //метод ищет записи по тому, что запишет пользователь, используются регулярные выражения
	vector<Record> records;
	records = readVectorOfRecords();
	if (records.size() == 0) {
		cout << endl << "Записей не существует";
		return;
	}
	vector<Record> foundRecords;
	int i, choiceOfField = 0;
	string searchData, currentData;
	char buffData[150];
	std::string(Record::*getSomeData)()=NULL; //указатель на метод класса Record
	cout << endl << "По какому полю необходимо произвести поиск?"
		<< endl << "1) ФИО"
		<< endl << "2) Номер карты"
		<< endl << "3) Дату приема"
		<< endl << "4) Время приема"
		<< endl << "5) ФИО врача"
		<< endl << "6) Кабинет" << endl;
	cin >> choiceOfField;
	if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{
		std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
		std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		std::cout <<endl<< "Неправильно введены данные.\n";
		return;
	}
	else { std::cin.ignore(32767, '\n'); }
	cout << endl << "Введите данные для поиска" << endl;
	std::cin.getline(buffData, 150);
	OemToCharA(buffData, buffData);
	searchData = buffData;
	regex searchRegex("([\\w- ])*(^|-|\\b|_)(" + searchData + ")($|-|\\b|_)([\\w- ])*");
	switch (choiceOfField) {
	case 1:
		getSomeData = &Record::getFullName;  //принимает указатель на метод, по которому потом будем искать совпадения
		break;
	case 2:
		getSomeData = &Record::getCardNumber;
		break;
	case 3:
		getSomeData = &Record::getDate;
		break;
	case 4:
		getSomeData = &Record::getTime;
		break;
	case 5:
		getSomeData = &Record::getDoctorName;
		break;
	case 6:
		getSomeData = &Record::getDoctorOffice;
		break;
	default: cout << endl << "Такого поля не существует";
		return;
		break;
	}
	for (i = 0; i < records.size(); i++) {
		currentData = (&records[i]->*getSomeData)();  //Достаем инфу из объекта с помощью одного з геттеров, который ранее попал в указатель на метод
		if (regex_match(currentData.begin(), currentData.end(), searchRegex))
			foundRecords.push_back(records[i]);
	}
	cout << endl << "количество объектов - " << foundRecords.size() << endl;
	for (i = 0; i < foundRecords.size(); i++) {
		cout << i + 1 << ')';
		foundRecords[i].print();
	}
}

void Admin::sortRecords() { //Функция сортировки работает с шаблонным классом SortForClasses
	vector<Record> records;  //Для сортироки нам нужно прочитать все объекты, передать их нашему методу сортировки
	int choiceOfField = 0, choiceOfSort = 0;  //также необходимо передать указатель на функцию , по которой будет происходить сравнение объектов
	int (*choosenCompare)(Record& a, Record& b) = NULL;  //-указатель на функцию
	records = readVectorOfRecords();
	if (records.size() == 0) {
		cout << endl << "Записей не существует";
		return;
	}
	int arrSize = records.size();
	Record* recordArr = new Record[arrSize];
	for (int i = 0; i < arrSize; i++) {
		recordArr[i] = records[i];
	}
	cout << endl << "По какому полю необходимо сортировать?"
		<< endl << "1) ФИО"
		<< endl << "2) Номер карты"
		<< endl << "3) Дату приема"
		<< endl << "4) Время приема"
		<< endl << "5) ФИО врача"
		<< endl << "6) Кабинет" << endl;
	cin >> choiceOfField;
	if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{
		std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
		std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		std::cout <<endl<< "Неправильно введены данные.\n";
		return;

	}
	else { std::cin.ignore(32767, '\n'); }
	cout << endl << "Каким образом?"
		<< endl << "1) По возрастанию"
		<< endl << "2) По убыванию" << endl;
	cin >> choiceOfSort;
	if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{
		std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
		std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		std::cout <<endl<< "Неправильно введены данные.\n";
		return;

	}
	else { std::cin.ignore(32767, '\n'); }
	if (choiceOfSort > 2 || choiceOfSort < 1) {
		cout <<endl<< "Введен неправильный номер сортировки";
		return;
	}
	switch(choiceOfField) {
	case 1:
		if (choiceOfSort == 1) {
			choosenCompare = RecordCompare::compare_fullName_ASC;  //передаем указатель на функцию сравнения(ASC - по возрастанию, DESC - по убыванию)
		}
		else {
			choosenCompare = RecordCompare::compare_fullName_DESC;
		}
		break;
	case 2:
		if (choiceOfSort == 1) {
			choosenCompare = RecordCompare::compare_cardNumber_ASC;
		}
		else {
			choosenCompare = RecordCompare::compare_cardNumber_DESC;
		}
		break;
	case 3:
		if (choiceOfSort == 1) {
			choosenCompare = RecordCompare::compare_date_ASC;
		}
		else {
			choosenCompare = RecordCompare::compare_date_DESC;
		}
		break;
	case 4:
		if (choiceOfSort == 1) {
			choosenCompare = RecordCompare::compare_time_ASC;
		}
		else {
			choosenCompare = RecordCompare::compare_time_DESC;
		}
		break;
	case 5:
		if (choiceOfSort == 1) {
			choosenCompare = RecordCompare::compare_doctorName_ASC;
		}
		else {
			choosenCompare = choosenCompare = RecordCompare::compare_doctorName_DESC;
		}
		break;
	case 6:
		if (choiceOfSort == 1) {
			choosenCompare = RecordCompare::compare_doctorOffice_ASC;
		}
		else {
			choosenCompare = RecordCompare::compare_doctorOffice_DESC;
		}
		break;
	default: cout << endl << "Такого поля не существует";
		return;
		break;
	}
	SortForClasses<Record>::selection_sort(recordArr, 0, arrSize, choosenCompare); //сортируем
	ofstream out(baseOfPatientsFile); 
	for (int i = 0; i < arrSize; i++) {   ///записываем в файл отсортированный массив объектов
		cout << i + 1 << ')';
		recordArr[i].print();
		out << recordArr[i];
	}
	out.close();
	delete[]recordArr;
}

void Admin::filterRecords() { //фильрация оставляет в базе только записи, моложе заданной даты(тоесть удаляет устаревшие)
	vector<Record> records;
	char data[150];
	string compareData;
	records = readVectorOfRecords();
	if (records.size() == 0) {
		cout << endl << "Записей не существует";
		return;
	}
	cout << endl << "Старше какой даты удалить записи?";
	cout << "Введите дату приема" << std::endl;
	cin.get();
	cin.getline(data, 150);
	OemToCharA(data, data);
	compareData = data;
	ofstream out(baseOfPatientsFile); //При открытии файла, по умолчанию стираются данные в нем
	///проверка
	for (int i = 0; i < records.size(); i++) {
		if (records[i].getDate() > compareData) {
			out << records[i];						//Заново записываем данные, которые нам нужны
		}
	}
	out.close();
}