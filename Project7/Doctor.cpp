#include "Doctor.h"

const char* Doctor::baseOfUsersFile = "baseOfDoctors.txt";

using namespace std;


vector<Record> Doctor::readVectorOfRecords() {
	Admin admin;
	return admin.readVectorOfRecords();
}

void Doctor::viewRecords() {
	Admin admin;
	admin.viewRecords();
}

void Doctor::addRecord() {
	Admin admin;
	admin.addRecord();
}

void Doctor::redactRecord() {
	cout << endl << "��� ������� � ������ �������� � ������ �����";
}
void Doctor::deleteRecord() {
	cout << endl << "��� ������� � ������ �������� � ������ �����";
}
void Doctor::searchRecord() {
	Admin admin;
	admin.searchRecord();
}
void Doctor::sortRecords() {
	cout << endl << "��� ������� � ������ �������� � ������ �����";
}
void Doctor::filterRecords() {
	Admin admin;
	admin.filterRecords();
}