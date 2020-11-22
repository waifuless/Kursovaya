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

void Record::print() { //Функция для вывода на экран информации об объекте
	std::cout << "Полное имя : " <<fullName << std::endl;
	std::cout << "Номер карты : "<<cardNumber << std::endl;
	std::cout << "Дата приема : "<<date << std::endl;
	std::cout << "Время : " <<time<< std::endl;
	std::cout << "ФИО врача : "<<doctorName << std::endl;
	std::cout << "Кабинет : "<<doctorOffice << std::endl;
	return;
}

void Record::create() { //функция заполнения полей объекта, пользователь вводит все данные с клавиатуры
	std::regex dataRegex("\\d{4}-\\d{2}-\\d{2}");//с помощью регулярного выражения осуществляется проверка, чтобы пользователь ввел данные в правильном формате
	std::regex timeRegex("\\d{2}-\\d{2}");
	char data[150];
	std::cout << "Введите полное имя " << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);  ///перекодировка необходима, т.к. работаем с киррилицей.
	fullName = data;
	std::cout << "Введите номер карты" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data); ///перекодировка необходима, т.к. работаем с киррилицей.
	cardNumber = data;
	do {
		std::cout << "Введите дату приема(в форме : 20ГГ-ММ-ДД, для корректной работы)" << std::endl;
		std::cin.getline(data, 150);
		OemToCharA(data, data);
	} while (!std::regex_match(data, dataRegex));
	date = data;
	do {
		std::cout << "Введите время(в форме : ЧЧ-ММ, для корректной работы)" << std::endl;
		std::cin.getline(data, 150);
		OemToCharA(data, data);
	} while (!std::regex_match(data, timeRegex));
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

void Record::setDate(std::string date) { //Чтобы при перезаписи поля выдерживался нужный формат, проводится проверка 
	std::regex dataRegex("\\d{4}-\\d{2}-\\d{2}"); //с помощью регулярного выражения
	if (!std::regex_match(date, dataRegex)) {
		do {
			std::cout << "Введите дату приема(в форме : 20ГГ-ММ-ДД, для корректной работы)" << std::endl;
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
			std::cout << "Введите дату приема(в форме : 20ГГ-ММ-ДД, для корректной работы)" << std::endl;
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


std::ostream& operator<< (std::ostream& out, const Record& record) ////используется для работы с файлами, возвращает поток, который выводится в файл
{
	out << record.fullName << std::endl;
	out << record.cardNumber << std::endl;
	out << record.date << std::endl;
	out << record.time << std::endl;
	out << record.doctorName << std::endl;
	out << record.doctorOffice << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Record& record)  //используется для работы с файлами, читает из потока in информацию в объект
{
	getline(in, record.fullName);
	getline(in, record.cardNumber);
	getline(in, record.date);
	getline(in, record.time);
	getline(in, record.doctorName);
	getline(in, record.doctorOffice);
	return in;
}
