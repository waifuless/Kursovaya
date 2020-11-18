#include "Viewer.h"
using namespace std;

vector<Record> Viewer::readVectorOfRecords() {
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

void Viewer::viewRecords() {
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

void Viewer::addRecord() {
		cout << endl << "��� ������� � ������ �������� � ������ ���������";
	}
void Viewer::redactRecord() {
		cout << endl << "��� ������� � ������ �������� � ������ ���������";
	}
void Viewer::deleteRecord() {
		cout << endl << "��� ������� � ������ �������� � ������ ���������";
	}
void Viewer::serchRecord() {
		//addCod
	}
void Viewer::sortRecords() {
		cout << endl << "��� ������� � ������ �������� � ������ ���������";
	}
void Viewer::filterRecords() {
		//add
	}