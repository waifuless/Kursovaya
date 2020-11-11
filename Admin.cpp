#include "Admin.h"
const char* baseOfPatientsFile = "baseOfPatients.txt";

using namespace std;

void Admin::viewRecords() {
	int number = 0;
	Record readRecord;
	ifstream in(baseOfPatientsFile);
	if (in.is_open()) {
		while(!in.eof()){
			in >> readRecord;
			number++;
			if (!in.eof()) {
				cout << number << ')';
				readRecord.print();
			}
		}
	}
	in.close();
	return;
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
		//friend
	}

void Admin::deleteRecord() {
	int choice = 0;
	string fullName;
	string date;
	Record readRecord;
	vector<Record> records;
	ifstream in(baseOfPatientsFile);
	ofstream out;
	cout << endl<<"Выберите действие :"
		<<endl<< "1 - удалить одну запись"
		<< endl << "2 - удалить все записи"<<endl;
	cin >> choice;
	switch (choice) {
	case 1:
		if (in.is_open()) {
			while (!in.eof()) {
				in >> readRecord;
				if (!in.eof()) {
					records.push_back(readRecord);
				}
			}
		}
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
	if(in.is_open()) in.close();
}

void Admin::serchRecord() {
		//addCod
	}
void Admin::sortRecords() {
		//
	}
void Admin::filterRecords() {
		//
	}