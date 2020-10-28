#include "Record.h"
#include <string>
#include <iostream>

Record::Record(char fullName[100], char date[100]) {
	strcpy_s(this->fullName, fullName);
	strcpy_s(this->date,date);
}

Record::Record() {
	fullName[0] = '\0';
	date[0] = '\0';
}

void Record::print() {
	std::cout << "Full name : " <<fullName << std::endl;
	std::cout << "Date : "<< date << std::endl;
	return;
}
