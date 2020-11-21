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
		cout << endl << "Ќет доступа к данной операции в режиме просмотра";
	}
void Viewer::redactRecord() {
		cout << endl << "Ќет доступа к данной операции в режиме просмотра";
	}
void Viewer::deleteRecord() {
		cout << endl << "Ќет доступа к данной операции в режиме просмотра";
	}
void Viewer::searchRecord() {
	Admin admin;
	admin.searchRecord();
	}
void Viewer::sortRecords() {
		cout << endl << "Ќет доступа к данной операции в режиме просмотра";
	}
void Viewer::filterRecords() {
	Admin admin;
	admin.filterRecords();
	}