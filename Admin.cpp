#include "Admin.h"
const char* baseOfPatientsFile = "baseOfPatients.txt";

using namespace std;

void Admin::viewRecords() {
	Record readRecord;
	int number = 0;
	ifstream in(baseOfPatientsFile, ios::binary);
	if (in.is_open()) {
		while(!in.eof()){
			in.read((char*)&readRecord, sizeof(Record));
			if(!in.eof()){
				number++;
				cout << number << ')';
				readRecord.print();
			}
		}
	}
	in.close();
	return;
	}

void Admin::addRecord() {
	char fullName[100], date[100];
	cin.get();
	cout << "¬ведите полное им€:"<<endl;
	cin.getline(fullName, 100);
	cout << "¬ведите дату приема:"<<endl;
	cin.getline(date, 100);
	Record newRecord(fullName, date);
	ofstream out(baseOfPatientsFile, ios::binary | ios::app);
	if (out.is_open()) {
		out.write((char*)&newRecord, sizeof(Record));
	}
	out.close();
	return;
	}

void Admin::redactRecord() {
		//friend
	}
void Admin::deleteRecord() {
		//
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