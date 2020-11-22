#include "Record.h"

Record::Record(std::string fullName, std::string cardNumber, std::string date, std::string time, std::string doctorName,
	std::string doctorOffice)
{
	this->fullName = fullName;
	this->cardNumber = cardNumber;
	this->date = date;
	this->time = time;
	this->doctorName = doctorName;
	this->doctorOffice = doctorOffice;
}

Record::Record() {
	this->fullName ="unknown";
	this->cardNumber ="unknown";
	this->date ="unknown";
	this->time ="unknown";
	this->doctorName ="unknown";
	this->doctorOffice ="unknown";
}

void Record::print() { //������� ��� ������ �� ����� ���������� �� �������
	std::cout << "������ ��� : " <<fullName << std::endl;
	std::cout << "����� ����� : "<<cardNumber << std::endl;
	std::cout << "���� ������ : "<<date << std::endl;
	std::cout << "����� : " <<time<< std::endl;
	std::cout << "��� ����� : "<<doctorName << std::endl;
	std::cout << "������� : "<<doctorOffice << std::endl;
	return;
}

void Record::create() { //������� ���������� ����� �������, ������������ ������ ��� ������ � ����������
	std::regex dataRegex("\\d{4}-\\d{2}-\\d{2}");//� ������� ����������� ��������� �������������� ��������, ����� ������������ ���� ������ � ���������� �������
	std::regex timeRegex("\\d{2}-\\d{2}");
	char data[150];
	std::cout << "������� ������ ��� " << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);  ///������������� ����������, �.�. �������� � ����������.
	fullName = data;
	std::cout << "������� ����� �����" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data); ///������������� ����������, �.�. �������� � ����������.
	cardNumber = data;
	do {
		std::cout << "������� ���� ������(� ����� : 20��-��-��, ��� ���������� ������)" << std::endl;
		std::cin.getline(data, 150);
		OemToCharA(data, data);
	} while (!std::regex_match(data, dataRegex));
	date = data;
	do {
		std::cout << "������� �����(� ����� : ��-��, ��� ���������� ������)" << std::endl;
		std::cin.getline(data, 150);
		OemToCharA(data, data);
	} while (!std::regex_match(data, timeRegex));
	time = data;
	std::cout << "������� ��� �����" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	doctorName = data;
	std::cout << "������� �������" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	doctorOffice = data;
}

void Record::setFullName(std::string fullName) {
	this->fullName=fullName;
}

void Record::setDate(std::string date) { //����� ��� ���������� ���� ������������ ������ ������, ���������� �������� 
	std::regex dataRegex("\\d{4}-\\d{2}-\\d{2}"); //� ������� ����������� ���������
	if (!std::regex_match(date, dataRegex)) {
		do {
			std::cout << "������� ���� ������(� ����� : 20��-��-��, ��� ���������� ������)" << std::endl;
			std::getline(std::cin, date);
		} while (!std::regex_match(date, dataRegex));
	}
	this->date=date;
}

void Record::setCardNumber(std::string cardNumber) {
	this->cardNumber = cardNumber;
}

void Record::setTime(std::string time){
	std::regex timeRegex("\\d{2}-\\d{2}");
	if (!std::regex_match(time, timeRegex)) {
		do {
			std::cout << "������� ���� ������(� ����� : 20��-��-��, ��� ���������� ������)" << std::endl;
			std::getline(std::cin, time);
		} while (!std::regex_match(time, timeRegex));
	}
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


std::ostream& operator<< (std::ostream& out, const Record& record) ////������������ ��� ������ � �������, ���������� �����, ������� ��������� � ����
{
	out << record.fullName << std::endl;
	out << record.cardNumber << std::endl;
	out << record.date << std::endl;
	out << record.time << std::endl;
	out << record.doctorName << std::endl;
	out << record.doctorOffice << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Record& record)  //������������ ��� ������ � �������, ������ �� ������ in ���������� � ������
{
	getline(in, record.fullName);
	getline(in, record.cardNumber);
	getline(in, record.date);
	getline(in, record.time);
	getline(in, record.doctorName);
	getline(in, record.doctorOffice);
	return in;
}
