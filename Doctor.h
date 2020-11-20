#pragma once
#include "IUser.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Record.h"
#include "fileNames.h"
class Doctor :
    public IUser
{
	
public:
	static const char* baseOfUsersFile;
	std::vector<Record> readVectorOfRecords();
	void viewRecords();
	void addRecord();
	void redactRecord();
	void deleteRecord();
	void serchRecord();
	void sortRecords();
	void filterRecords();
};

