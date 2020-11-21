#include "Admin.h"

const char* baseOfPatientsFile = "baseOfPatients.txt";
const char* Admin::baseOfUsersFile = "baseOfAdmins.txt";

using namespace std;

vector<Record> Admin::readVectorOfRecords() {
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
		return records;
}

void Admin::viewRecords() {
	vector<Record> records;
	records = readVectorOfRecords();
	for (int i = 0; i < records.size(); i++) {
		cout << i + 1 << ')';
		records[i].print();
	}
	}

void Admin::addRecord() {
	Record newRecord;
	cin.get();
	newRecord.create();
	ofstream out(baseOfPatientsFile, ios::app);
	if (out.is_open()) {
		out << newRecord;
	}
	out.close();
	return;
	}

void Admin::redactRecord() {
	int choiceOfRecord = 0, choiceOfField = 0;
	char newData[150];
	vector<Record> records;
	records = readVectorOfRecords();
	for (int i = 0; i < records.size(); i++) {
		cout << i + 1 << ')';
		records[i].print();
	}
	cout << "Введите номер записи ";
	cin >> choiceOfRecord;
	cout << endl << "Какое поле необходимо изменить?"
		<< endl << "1) ФИО"
		<< endl << "2) Номер карты"
		<< endl << "3) Дату приема"
		<< endl << "4) Время приема"
		<< endl << "5) ФИО врача"
		<< endl << "6) Кабинет" << endl;
	cin >> choiceOfField;
	cout << "Введите новые данные: "<<endl;
	cin.get();
	std::cin.getline(newData, 150);
	OemToCharA(newData, newData);
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
	}
	ofstream out(baseOfPatientsFile);
	for (int i = 0; i < records.size(); i++) {
		out << records[i];
	}
	out.close();
}

void Admin::deleteRecord() {
	int choice = 0;
	vector<Record> records;
	ofstream out;
	cout << endl<<"Выберите действие :"
		<<endl<< "1 - удалить одну запись"
		<< endl << "2 - удалить все записи"<<endl;
	cin >> choice;
	switch (choice) {
	case 1:
		records = readVectorOfRecords();
		for (int i = 0; i < records.size();i++) {
			cout << i + 1 << ')';
			records[i].print();
		}
		cout << "Введите номер записи ";
		cin >> choice;
		out.open(baseOfPatientsFile);
		for (int i = 0; i < records.size(); i++) {
			if (i != choice - 1) {
				out << records[i];
			}
		}
		out.close();
		break;
	case 2:
		out.open(baseOfPatientsFile, ios::trunc); //trunc чистит файл
		out.close();
	}
}

void Admin::searchRecord() {
	vector<Record> records;
	records = readVectorOfRecords();
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
	cout << endl << "Введите данные для поиска" << endl;
	cin.get();
	std::cin.getline(buffData, 150);
	OemToCharA(buffData, buffData);
	searchData = buffData;
	regex searchRegex("([\\w- ])*(^|-|\\b|_)(" + searchData + ")($|-|\\b|_)([\\w- ])*");
	switch (choiceOfField) {
	case 1:
		getSomeData = &Record::getFullName;
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
	}
	for (i = 0; i < records.size(); i++) {
		currentData = (&records[i]->*getSomeData)();
		if (regex_match(currentData.begin(), currentData.end(), searchRegex))
			foundRecords.push_back(records[i]);
	}
	cout << endl << "количество объектов - " << foundRecords.size() << endl;
	for (i = 0; i < foundRecords.size(); i++) {
		cout << i + 1 << ')';
		foundRecords[i].print();
	}
}

void Admin::sortRecords() {
	vector<Record> records;
	int choiceOfField = 0, choiceOfSort = 0;
	int (*choosenCompare)(Record& a, Record& b) = NULL;
	records = readVectorOfRecords();
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
	cout << endl << "Каким образом?"
		<< endl << "1) По возрастанию"
		<< endl << "2) По убыванию" << endl;
	cin >> choiceOfSort;
	switch(choiceOfField) {
	case 1:
		if (choiceOfSort == 1) {
			choosenCompare = RecordCompare::compare_fullName_ASC;
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
	}
	SortForClasses<Record>::selection_sort(recordArr, 0, arrSize, choosenCompare);
	ofstream out(baseOfPatientsFile);
	for (int i = 0; i < arrSize; i++) {
		cout << i + 1 << ')';
		recordArr[i].print();
		out << records[i];
	}
	out.close();
	delete[]recordArr;
}

void Admin::filterRecords() { //placeholder можно потом фильтровать по врачу, например
	vector<Record> records;
	records = readVectorOfRecords();
	vector<Record> foundRecords;
	int i, choiceOfField = 0;
	string searchData, currentData;
	std::string(Record:: * getSomeData)() = NULL; //указатель на метод класса Record
	cout << endl << "По какому полю необходимо произвести поиск?"
		<< endl << "1) ФИО"
		<< endl << "2) Номер карты"
		<< endl << "3) Дату приема"
		<< endl << "4) Время приема"
		<< endl << "5) ФИО врача"
		<< endl << "6) Кабинет" << endl;
	cin >> choiceOfField;
	cout << endl << "Введите данные для поиска" << endl;
	cin.get();
	getline(cin, searchData);
	regex searchRegex("([\\w- ])*(^|-|\\b|_)(" + searchData + ")($|-|\\b|_)([\\w- ])*");
	switch (choiceOfField) {
	case 1:
		getSomeData = &Record::getFullName;
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
	}
	for (i = 0; i < records.size(); i++) {
		currentData = (&records[i]->*getSomeData)();
		if (regex_match(currentData.begin(), currentData.end(), searchRegex))
			foundRecords.push_back(records[i]);
	}
	cout << endl << "количество объектов - " << foundRecords.size() << endl;
	for (i = 0; i < foundRecords.size(); i++) {
		cout << i + 1 << ')';
		foundRecords[i].print();
	}
}