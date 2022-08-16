#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include "Stock.h"
#include "Staff header.h"
#include "supply.h"

using namespace std;
fstream file;

supply Sup;
Inventory I;
//record supply data in database

void supply::IncreaseQty()
{
	int no, num;
	cout << "Enter the Product Number: ";
	cin >> no;
	cout << "Enter the Number of Items Need to Increase; ";
	cin >> num;

	file.open("Stock.dat", ios::in | ios::out | ios::binary);
	if (!file) //if file open fails
	{
		cout << "File not Found";
		exit(0);
	}

	while (file.read((char*)&I, sizeof(I)))
	{
		if (I.getCode() == no)
		{
			I.IncQty(num);
			//move to the current position -1
			int pos = sizeof(I);
			file.seekp(-pos, ios::cur);
			file.write((char*)&I, sizeof(I));
		}
	}
	file.close();
}



void AddSupplyRecord()
{
	char ch = 'y';
	file.open("Supply.dat", ios::app | ios::binary);
	while (ch == 'y' || ch == 'Y')
	{
		Sup.AddSupply();
		file.write((char*)&Sup, sizeof(Sup));
		cout << "Add more records (y/n)?";
		cin >> ch;
	}
	file.close();
}

//display supply
void ShowSupplyRecords()
{
	cout << "------------------------------------------\n";
	cout << setw(15) << "Product Name"
		<< setw(15) << "Quantity"
		<< setw(15) << "Local/International"
		<< setw(15) << "Name of origin farm/factory"
		<< setw(15) << "Departure from farm/factory Date:"
		<< setw(15) << "Vehicle"
		<< setw(15) << "origin country"
		<< setw(15) << "Arrival to country date"
		<< setw(15) << "Reg Number"
		<< setw(15) << "Arrival to store date"
		<< setw(15) << "Status" << endl;
	cout << "------------------------------------------\n";
	file.open("Supply.dat", ios::in | ios::binary);
	if (!file)
	{
		cout << "File Not Found";
		exit(0);
	}
	else
	{
		file.read((char*)&Sup, sizeof(Sup));
		while (!file.eof()) //While end of File
		{
			Sup.DisplayRecords();
			file.read((char*)&Sup, sizeof(Sup));
		}
	}
	file.close();
}

void Inventory::Supply()
{
	int select = 0;
	cout << "1->Add supply" << endl;
	cout << "2->Display supply" << endl;

	cout << "Select cateogary" << endl;
	cin >> select;
	switch (select) {
	case 1: AddSupplyRecord(); break;
	case 2: ShowSupplyRecords(); break;
	}
}
//add supply data
void supply::AddSupply()
{
	int LocOrInt = 0;
	int vehicleNo = 0;
	cout << "Add supply" << endl;
	cout << "Product Name" << endl;
	cin >> productName;
	cout << "Quantity" << endl;
	cin >> quantity;
	cout << "1->Local\n2->International" << endl;
	cin >> LocOrInt;
	cout << endl;
	if (LocOrInt == 1) {//Local
		cout << "Name of origin farm/factory" << endl;
		cin >> nameOfOrigin;
		cout << "Departure from farm/factory Date:" << endl;
		cout << "year: ";
		cin >> departureDate.year;
		cout << "month: ";
		cin >> departureDate.month;
		cout << "Date: ";
		cin >> departureDate.date;
		cout << "Vehicle: 1->Large Trucks 2->Small Trucks 3->Vans" << endl;
		cin >> vehicleNo;
		if (vehicleNo == 1) {
			vehicle = "LargeTrucks";
		}
		else if (vehicleNo == 2) {
			vehicle = "SmallTrucks";
		}
		else if (vehicleNo == 3) {
			vehicle = "Vans";
		}
	}
	else if (LocOrInt == 2) { //International
		LocOrInternational = "International";
		cout << "origin country" << endl;
		cin >> originCountry;
		cout << "Arrival to country date" << endl;
		cout << "year: ";
		cin >> arrivalToCountryDate.year;
		cout << "month: ";
		cin >> arrivalToCountryDate.month;
		cout << "Date: ";
		cin >> arrivalToCountryDate.date;
	}
	cout << "Reg Number" << endl;
	cin >> regNo;
	//status = "Pending";
	cout << "Arrival to store date" << endl;
	cout << "year: ";
	cin >> arriveToStoreDate.year;
	cout << "month: ";
	cin >> arriveToStoreDate.month;
	cout << "Date: ";
	cin >> arriveToStoreDate.date;

	int newRec = 0;
	cout << "1->Add new record 2->Increase items 3->end" << endl;
	cin >> newRec;
	if (newRec == 1) {
		status = "Approved";
		I.Stock();
	}
	else if (newRec == 2) {
		status = "Approved";
		IncreaseQty();
	}
	else {
		exit(0);
	}
}

//display supply data
void supply::DisplayRecords()
{
	cout << setw(15) << productName
		<< setw(15) << quantity
		<< setw(15) << LocOrInternational
		<< setw(15) << nameOfOrigin
		<< setw(15) << departureDate.year
		<< setw(15) << departureDate.month
		<< setw(15) << departureDate.date
		<< setw(15) << vehicle
		<< setw(15) << originCountry
		<< setw(15) << arrivalToCountryDate.year
		<< setw(15) << arrivalToCountryDate.month
		<< setw(15) << arrivalToCountryDate.date
		<< setw(15) << regNo
		<< setw(15) << arriveToStoreDate.year
		<< setw(15) << arriveToStoreDate.month
		<< setw(15) << arriveToStoreDate.date
		<< setw(15) << status << endl;
}

