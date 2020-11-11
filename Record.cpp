#include "Record.h"
#include <string>
#include <fstream>
#include <iostream>

Record::Record(std::string fullName, std::string date) {
	this->fullName = fullName;
	this->date = date;
}

Record::Record() {
	//fullName; //lol, unknown
	//date;
}

void Record::print() {
	std::cout << "Полное имя : " <<fullName << std::endl;
	std::cout << "Дата : "<< date << std::endl;
	return;
}

void Record::create() {
	std::cout << "Введите полное имя и дату приема" << std::endl;
	std::cin.get();
	std::cin >> *this;
}

void Record::setFullName(std::string fullName) {
	this->fullName=fullName;
}

void Record::setDate(std::string date) {
	this->date=date;
}

std::string Record::getFullName() {
	std::string fullName;
	fullName = this->fullName;
	return fullName;
}

std::string Record::getDate() {
	std::string date;
	date=this->date;
	return date;
}


std::ostream& operator<< (std::ostream& out, const Record& record)
{
	out << record.fullName << std::endl;
	out << record.date << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Record& record)
{
	getline(in, record.fullName);
	getline(in, record.date);
	return in;
}
