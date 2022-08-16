#pragma once
#include<iostream>
#include<string>
#include "Stock.h"

using namespace std;

struct Date {
	int year = 0;
	int month = 0;
	int date = 0;
};

class staff {
protected:
	string firstName = "0";
	string secondName = "0";
	string position = "0";
	Date joinedDate;
	int serialNo = 0;
public:
	//void AddStaffRecord(int Position);
	void AddStaff();
	void displayRecords();
	void AddStaffRecord();
	void ShowStaffRecords();
	int getCode()
	{
		return serialNo;
	}
};
class Manager :public Inventory
{
private:

public:
	void ShowStaffRecords();
	Manager()
	{
		cout << "Select the Division" << endl;
		cout << "1. Stock" << endl;
		cout << "2. Supply" << endl;
		cout << "3. Staff Records" << endl;
	}
};

class Owner :public Inventory
{
private:

public:
	void ShowTranscationRecords();
	Owner()
	{
		cout << "Select the Division" << endl;
		cout << "1. Stock" << endl;
		cout << "2. Supply" << endl;
		cout << "3. Staff" << endl;
		cout << "4. View transactions" << endl;
	}
};

class FlowWorker :public Inventory
{
public:
	void IncreaseQty();
	FlowWorker()
	{
		cout << "Select the Division" << endl;
		cout << "1. Increase the Stock" << endl;
		cout << "2. Supply" << endl;
	}
};

class Cashier :public Inventory
{
public:
	void AddTransactionRecord();
	Cashier()
	{
		//cout << "Decrease the Stock" << endl;
	}
};
