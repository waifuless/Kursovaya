#include "Doctor.h"

using namespace std;

vector<Record> Doctor::readVectorOfRecords() {
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

void Doctor::viewRecords() {
	Record readRecord;
	int number = 0;
	ifstream in(baseOfPatientsFile, ios::binary);
	if (in.is_open()) {
		while (!in.eof()) {
			in.read((char*)&readRecord, sizeof(Record));
			if (!in.eof()) {
				number++;
				cout << number << ')';
				readRecord.print();
			}
		}
	}
	in.close();
	return;
}

void Doctor::addRecord() {
	char fullName[100], date[100];
	cin.get();
	cout << "¬ведите полное им€:" << endl;
	cin.getline(fullName, 100);
	cout << "¬ведите дату приема:" << endl;
	cin.getline(date, 100);
	Record newRecord(fullName, date);
	ofstream out(baseOfPatientsFile, ios::binary | ios::app);
	if (out.is_open()) {
		out.write((char*)&newRecord, sizeof(Record));
	}
	out.close();
	return;
}

void Doctor::redactRecord() {
	cout << endl << "Ќет доступа к данной операции в режиме просмотра";
}
void Doctor::deleteRecord() {
	cout << endl << "Ќет доступа к данной операции в режиме просмотра";
}
void Doctor::serchRecord() {
	//addCod
}
void Doctor::sortRecords() {
	cout << endl << "Ќет доступа к данной операции в режиме просмотра";
}
void Doctor::filterRecords() {
	//add
}