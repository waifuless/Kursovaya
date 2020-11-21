#include "Record.h"

Record::Record(std::string fullName, std::string date) {
	this->fullName = fullName;
	this->date = date;														///???
}

Record::Record() {
	//fullName; //lol, unknown
	//date;
}

void Record::print() {
	std::cout << "Полное имя : " <<fullName << std::endl;
	std::cout << "Номер карты : "<<cardNumber << std::endl;
	std::cout << "Дата приема : "<<date << std::endl;
	std::cout << "Время : " <<time<< std::endl;
	std::cout << "ФИО врача : "<<doctorName << std::endl;
	std::cout << "Кабинет : "<<doctorOffice << std::endl;
	return;
}

void Record::create() {
	char data[150];
	std::cout << "Введите полное имя " << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	fullName = data;
	std::cout << "Введите номер карты" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	cardNumber = data;
	std::cout << "Введите дату приема" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	date = data;
	std::cout << "Введите время" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	time = data;
	std::cout << "Введите ФИО врача" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	doctorName = data;
	std::cout << "Введите кабинет" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	doctorOffice = data;
}

void Record::setFullName(std::string fullName) {
	this->fullName=fullName;
}

void Record::setDate(std::string date) {
	this->date=date;
}

void Record::setCardNumber(std::string cardNumber) {
	this->cardNumber = cardNumber;
}

void Record::setTime(std::string time){
	this->time = time;
}

void Record::setDoctorName(std::string doctorName){
	this->doctorName = doctorName;
}

void Record::setDoctorOffice(std::string doctorOffice){
	this->doctorOffice = doctorOffice;
}


std::string Record::getFullName() {
	std::string fullName;
	fullName = this->fullName;
	return fullName;
}

std::string Record::getCardNumber(){
	std::string cardNumber; 
	cardNumber = this->cardNumber;
	return cardNumber;
	}

std::string Record::getDate() {
	std::string date;
	date = this->date;
	return date;
}

std::string Record::getTime(){
	std::string time; 
	time = this->time;
	return time;
}

std::string Record::getDoctorName(){
	std::string doctorName; 
	doctorName = this->doctorName;
	return doctorName;
}

std::string Record::getDoctorOffice(){
	std::string doctorOffice; 
	doctorOffice = this->doctorOffice;
	return doctorOffice;
}


std::ostream& operator<< (std::ostream& out, const Record& record) ////используется для работы с файлами, осбенности кодировки
{
	out << record.fullName << std::endl;
	out << record.cardNumber << std::endl;
	out << record.date << std::endl;
	out << record.time << std::endl;
	out << record.doctorName << std::endl;
	out << record.doctorOffice << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Record& record)  //используется для работы с файлами, особенности
{
	getline(in, record.fullName);
	getline(in, record.cardNumber);
	getline(in, record.date);
	getline(in, record.time);
	getline(in, record.doctorName);
	getline(in, record.doctorOffice);
	return in;
}
