#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>

class Record
{
	std::string fullName;
	std::string cardNumber;
	std::string date;
	std::string time;
	std::string doctorName;
	std::string doctorOffice;
public:
	Record(std::string fullName, std::string date);
	Record();
	void print();
	void create();
	void setFullName(std::string fullName);
	void setCardNumber(std::string cardNumber);
	void setDate(std::string date);
	void setTime(std::string time);
	void setDoctorName(std::string doctorName);
	void setDoctorOffice(std::string doctorOffice);
	std::string getFullName();
	std::string getCardNumber();
	std::string getDate();
	std::string getTime();
	std::string getDoctorName();
	std::string getDoctorOffice();
	friend std::ostream& operator<< (std::ostream& out, const Record& record);
	friend std::istream& operator>> (std::istream& in, Record& record);
};

