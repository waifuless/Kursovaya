#pragma once
class IUser {
public:
	virtual void viewRecords() = 0;
	virtual void addRecord() = 0;
	virtual void redactRecord() = 0;
	virtual void deleteRecord() = 0;
	virtual void serchRecord() = 0;
	virtual void sortRecords() = 0;
	virtual void filterRecords() = 0;
};