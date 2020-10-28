#include "Viewer.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Record.h"
#include "fileName.h"
using namespace std;

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
		cout << endl << "Ќет доступа к данной операции в режиме просмотра";
	}
void Viewer::redactRecord() {
		cout << endl << "Ќет доступа к данной операции в режиме просмотра";
	}
void Viewer::deleteRecord() {
		cout << endl << "Ќет доступа к данной операции в режиме просмотра";
	}
void Viewer::serchRecord() {
		//addCod
	}
void Viewer::sortRecords() {
		cout << endl << "Ќет доступа к данной операции в режиме просмотра";
	}
void Viewer::filterRecords() {
		//add
	}