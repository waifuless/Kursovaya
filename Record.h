#pragma once
#include <string>

class Record
{
	char fullName[100];
	char date[100];
public:
	Record(char fullName[100], char date[100]);
	Record();
	void print();
};

