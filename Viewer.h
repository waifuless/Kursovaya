#pragma once
#include "IUser.h"
class Viewer :
    public IUser
{
public:
	void viewRecords();
	void addRecord();
	void redactRecord();
	void deleteRecord();
	void serchRecord();
	void sortRecords();
	void filterRecords();
};

