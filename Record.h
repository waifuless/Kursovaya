#pragma once
#include <string>

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
	void setDate(std::string date);
	std::string getFullName();
	std::string getDate();
	friend std::ostream& operator<< (std::ostream& out, const Record& record);
	friend std::istream& operator>> (std::istream& in, Record& record);
};

