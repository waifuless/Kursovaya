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
	string newData;
	vector<Record> records;
	records = readVectorOfRecords();
	for (int i = 0; i < records.size(); i++) {
		cout << i + 1 << ')';
		records[i].print();
	}
	cout << "Введите номер записи ";
	cin >> choiceOfRecord;
	cout << endl << "Какое поле необходимо изменить?"
		<<endl<<"1) ФИО"
		<<endl<<"2) Дату приема"<<endl;
	cin >> choiceOfField;
	cout << "Введите новые данные: "<<endl;
	cin.get();
	getline(cin, newData);
	switch (choiceOfField) {
	case 1: records[choiceOfRecord - 1].setFullName(newData);
		break;
	case 2: records[choiceOfRecord - 1].setDate(newData);
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

void Admin::serchRecord() {
	vector<Record> records;
	records = readVectorOfRecords();
	vector<Record> foundRecords;
	int i, choiceOfField = 0;
	string searchData, currentData;
	cout << endl << "По какому полю необходимо произвести поиск?"
		<< endl << "1) ФИО"
		<< endl << "2) Дату приема" << endl;
	cin >> choiceOfField;
	cout << endl << "Введите данные для поиска" << endl;
	cin.get();
	getline(cin, searchData);
	regex searchRegex("([\\w- ])*(^|-|\\b|_)(" + searchData + ")($|-|\\b|_)([\\w- ])*");
	switch (choiceOfField) {
	case 1:
		for (i = 0; i < records.size(); i++) {
			currentData = records[i].getFullName();
			if (regex_match(currentData.begin(), currentData.end(), searchRegex))
				foundRecords.push_back(records[i]);
		}
		break;
	case 2:
		for (i = 0; i < records.size(); i++) {
			currentData = records[i].getDate();
			if (regex_match(currentData.begin(), currentData.end(), searchRegex))
				foundRecords.push_back(records[i]);
		}
		break;
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
	records = readVectorOfRecords();
	cout << endl << "По какому полю необходимо сортировать?"
		<< endl << "1) ФИО"
		<< endl << "2) Дату приема" << endl;
	cin >> choiceOfField;
	cout << endl << "Каким образом?"
		<< endl << "1) По возрастанию"
		<< endl << "2) По убыванию" << endl;
	cin >> choiceOfSort;
	switch(choiceOfField) {
	case 1:
		if (choiceOfSort == 1) {
			sort(records.begin(), records.end(), [](Record a, Record b) {
				return a.getFullName() < b.getFullName();
				});
		}
		else {
			sort(records.begin(), records.end(), [](Record a, Record b) {
				return a.getFullName() > b.getFullName();
				});
		}
		break;
	case 2:
		if (choiceOfSort == 1) {
			sort(records.begin(), records.end(), [](Record a, Record b) {
				return a.getDate() < b.getDate();
				});
		}
		else {
			sort(records.begin(), records.end(), [](Record a, Record b) {
				return a.getDate() > b.getDate();
				});
		}
		break;
	}
	ofstream out(baseOfPatientsFile);
	for (int i = 0; i < records.size(); i++) {
		out << records[i];
	}
	out.close();
}

void Admin::filterRecords() { //placeholder можно потом фильтровать по врачу, например
	vector<Record> records;
	records = readVectorOfRecords();
	vector<Record> foundRecords;
	int i, choiceOfField = 0;
	string searchData, currentData;
	cout << endl << "По какому полю необходимо произвести фильрацию?"
		<< endl << "1) ФИО"
		<< endl << "2) Дату приема" << endl;
	cin >> choiceOfField;
	cout << endl << "Введите данные для поиска" << endl;
	cin.get();
	getline(cin, searchData);
	regex searchRegex("([\\w- ])*(^|-|\\b|_)(" + searchData + ")($|-|\\b|_)([\\w- ])*");
	switch (choiceOfField) {
	case 1:
		for (i = 0; i < records.size(); i++) {
			currentData = records[i].getFullName();
			if (regex_match(currentData.begin(), currentData.end(), searchRegex))
				foundRecords.push_back(records[i]);
		}
		break;
	case 2:
		for (i = 0; i < records.size(); i++) {
			currentData = records[i].getDate();
			if (regex_match(currentData.begin(), currentData.end(), searchRegex))
				foundRecords.push_back(records[i]);
		}
		break;
	}
	cout << endl << "количество объектов - " << foundRecords.size() << endl;
	for (i = 0; i < foundRecords.size(); i++) {
		cout << i + 1 << ')';
		foundRecords[i].print();
	}
}