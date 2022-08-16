#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include "Staff header.h"
#include "Stock.h"
using namespace std;
fstream file;

staff S;
Inventory I;


class Transaction {
private:
	string cashierName = "o";
	string customer = "o";
	int noOfDifferentItems = 0;
protected:
	int ProductNumber[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int Quantity[10] = { 0,0,0,0,0,0,0,0,0,0 };
public:
	void DisplayRecords();
	void recordTransaction();
};
Transaction T;

//record transaction
void Transaction::recordTransaction()
{
	cout << "Cashier Name" << endl;
	cin >> cashierName;
	cout << "customer name" << endl;
	cin >> customer;
	cout << "no of different items puchased(<10)" << endl;
	cin >> noOfDifferentItems;
	for (int i = 0; i < noOfDifferentItems; i++) {
		cout << "Product NUmber" << endl;
		cin >> ProductNumber[i];
		cout << "Quantity" << endl;
		cin >> Quantity[i];
		//DecreseQtyTransaction(ProductNumber[i], Quantity[i]);
	}
}

//display transactions
void Transaction::DisplayRecords()
{
	cout << setw(15) << cashierName
		<< setw(15) << customer
		<< setw(15) << ProductNumber[0]
		<< setw(15) << Quantity[0] << endl;
	for (int i = 1; i < 10; i++) {
		cout << setw(45) << ProductNumber[i]
			<< setw(15) << Quantity[i] << endl;
	}

}

//Add transaction record to database
void AddTransactionRecord()
{
	char ch = 'y';
	file.open("Transactions.dat", ios::app | ios::binary);
	while (ch == 'y' || ch == 'Y')
	{
		T.recordTransaction();
		file.write((char*)&T, sizeof(T));
		cout << "Add more records (y/n)?";
		cin >> ch;
	}
	file.close();
}

//display transactions
void ShowTranscationRecords()
{
	cout << "------------------------------------------\n";
	cout << setw(15) << "Cashier"
		<< setw(15) << "Customer"
		<< setw(15) << "Product number"
		<< setw(15) << "Product Quantity" << endl;
	cout << "------------------------------------------\n";
	file.open("Transactions.dat", ios::in | ios::binary);
	if (!file)
	{
		cout << "File Not Found";
		exit(0);
	}
	else
	{
		file.read((char*)&T, sizeof(T));
		while (!file.eof()) //While end of File
		{
			T.DisplayRecords();
			file.read((char*)&T, sizeof(T));
		}
	}
	file.close();
}

//decrease quantity by cashier after transaction ->check
void DecreseQtyTransaction(int no, int num)
{
	/*
	int no, num;
	cout << "Enter the Product Number: ";
	cin >> no;
	cout << "Enter the Number of Items Need to Decrease; ";
	cin >> num;
	*/

	file.open("Stock.dat", ios::in | ios::out | ios::binary);
	if (!file) //if file open fails
	{
		cout << "Transaction stock File not Found";
		exit(0);
	}

	while (file.read((char*)&I, sizeof(I)))
	{
		if (I.getCode() == no)
		{
			I.DecQty(num);
			//move to the current position -1
			int pos = sizeof(I);
			file.seekp(-pos, ios::cur);
			file.write((char*)&I, sizeof(I));
		}
	}
	file.close();
}



//delete staff record
void DeleteStaffRecord()
{
	int no;
	cout << "Enter the Serial Number You want to Remove:";
	cin >> no;

	ofstream file2;

	file2.open("new.dat", ios::out | ios::binary);
	file.open("Staff.dat", ios::in | ios::binary);

	if (!file)
	{
		cout << "File Not Found";
		exit(0);
	}
	else
	{
		file.read((char*)&S, sizeof(S));
		while (!file.eof())
		{
			if (no != S.getCode())
			{
				file2.write((char*)&S, sizeof(S));
			}
			file.read((char*)&S, sizeof(S));
		}
	}
	file2.close();
	file.close();
	remove("Staff.dat");
	rename("new.dat", "Staff.dat");
}


//add staff data
void staff::AddStaff()
{
	cout << "Add staff" << endl;
	cout << "Serial number" << endl;
	cin >> serialNo;
	cout << endl;
	int Position = 0;
	cout << "1->Owner\n2->Manager\n3->Cashier\n4->FLoor worker\nPosition: " << endl;
	cin >> Position;
	switch (Position) {
	case 1: position = "Owner";
	case 2: position = "Manager";
	case 3: position = "Cashier";
	case 4: position = "Floor worker";
	}

	cout << "Full name" << endl;
	cout << "first name" << endl;
	cin >> firstName;
	cout << "second name" << endl;
	cin >> secondName;
	cout << "Joined date:\nYear" << endl;
	cin >> joinedDate.year;
	cout << "month" << endl;
	cin >> joinedDate.month;
	cout << "date" << endl;
	cin >> joinedDate.date;
}

//display staff data
void staff::displayRecords()
{
	cout << setw(15) << serialNo
		<< setw(15) << position
		<< setw(15) << firstName
		<< setw(15) << secondName
		<< setw(15) << joinedDate.year
		<< setw(15) << joinedDate.month
		<< setw(15) << joinedDate.date
		<< endl;
}
//record staff data in database
void  AddStaffRecord()
{
	char ch = 'y';
	file.open("Staff.dat", ios::app | ios::binary);
	while (ch == 'y' || ch == 'Y')
	{
		S.AddStaff();
		file.write((char*)&S, sizeof(S));
		cout << "Add more records (y/n)?";
		cin >> ch;
	}
	file.close();
}

//display staff
void  ShowStaffRecords()
{
	cout << "------------------------------------------\n";
	cout << setw(15) << "Serial No"
		<< setw(15) << "Position"
		<< setw(15) << "First name"
		<< setw(15) << "Second name"
		<< setw(15) << "Joined date"
		<< endl;
	cout << "------------------------------------------\n";
	file.open("Staff.dat", ios::in | ios::binary);
	if (!file)
	{
		cout << "File Not Found";
		exit(0);
	}
	else
	{
		file.read((char*)&S, sizeof(S));
		while (!file.eof()) //While end of File
		{
			S.displayRecords();
			file.read((char*)&S, sizeof(S));
		}
	}
	file.close();
}

void Inventory::Staff()
{
	int select = 0;
	cout << "1->Add staff" << endl;
	cout << "2->Remove staff" << endl;
	cout << "3->Display staff" << endl;

	cout << "Select cateogary" << endl;
	cin >> select;
	switch (select) {
	case 1: AddStaffRecord(); break;
	case 2: DeleteStaffRecord(); break;
	case 3: ShowStaffRecords(); break;
	}

}