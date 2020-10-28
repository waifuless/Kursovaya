#pragma once
#include "IUser.h"
class Admin :
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

