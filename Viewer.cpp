#include "Viewer.h"
using namespace std;

const char* Viewer::baseOfUsersFile = NULL;

vector<Record> Viewer::readVectorOfRecords() {
	Admin admin;
	return admin.readVectorOfRecords();
}

void Viewer::viewRecords() {
	Admin admin;
	admin.viewRecords();
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
void Viewer::searchRecord() {
	Admin admin;
	admin.searchRecord();
	}
void Viewer::sortRecords() {
		cout << endl << "��� ������� � ������ �������� � ������ ���������";
	}
void Viewer::filterRecords() {
	Admin admin;
	admin.filterRecords();
	}