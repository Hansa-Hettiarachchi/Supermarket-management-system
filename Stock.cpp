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

using namespace std;
fstream file;


int Inventory::i = 0;

Inventory I;

void IncreaseQty()
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
//show stock record
void ShowRecords(void)
{
	cout << "------------------------------------------\n";
	cout << setw(15) << "Product Number"
		<< setw(15) << "Product Name"
		<< setw(15) << "Catergory"
		<< setw(15) << "Quantity"
		<< setw(15) << "Product Price"
		<< setw(15) << "Product Discount"
		<< setw(15) << "Final Price" << endl;
	cout << "------------------------------------------\n";
	file.open("Stock.dat", ios::in | ios::binary);
	if (!file)
	{
		cout << "File Not Found";
		exit(0);
	}
	else
	{
		file.read((char*)&I, sizeof(I));
		while (!file.eof()) //While end of File
		{
			I.DisplayRecords();
			file.read((char*)&I, sizeof(I));
		}
	}
	file.close();
}
void DecreseQty()
{
	int no, num;
	cout << "Enter the Product Number: ";
	cin >> no;
	cout << "Enter the Number of Items Need to Decrease; ";
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
			I.DecQty(num);
			//move to the current position -1
			int pos = sizeof(I);
			file.seekp(-pos, ios::cur);
			file.write((char*)&I, sizeof(I));
		}
	}
	file.close();
}
//stock


//Add stock record
void AddRecord(string catr)
{
	char ch = 'y';
	file.open("Stock.dat", ios::app | ios::binary);
	while (ch == 'y' || ch == 'Y')
	{
		I.AddItem(catr);
		file.write((char*)&I, sizeof(I));
		cout << "Add more records (y/n)?";
		cin >> ch;
	}
	file.close();
}



//delete stock record
void DeleteRecord()
{
	int no;
	cout << "Enter the Item Number You want to Remove:";
	cin >> no;

	ofstream file2;

	file2.open("new.dat", ios::out | ios::binary);
	file.open("Stock.dat", ios::in | ios::binary);

	if (!file)
	{
		cout << "File Not Found";
		exit(0);
	}
	else
	{
		file.read((char*)&I, sizeof(I));
		while (!file.eof())
		{
			if (no != I.getCode())
			{
				file2.write((char*)&I, sizeof(I));
			}
			file.read((char*)&I, sizeof(I));
		}
	}
	file2.close();
	file.close();
	remove("Stock.dat");
	rename("new.dat", "Stock.dat");
}


void GeneralStock(string Cat)
{

	//Inventory I;
	int S1;
	cout << "1. Add an Item." << endl;
	cout << "2. Remove an Item." << endl;
	cout << "3. Increase an Item in the Stock." << endl;
	cout << "4. Decrease an Item in the Stock" << endl;
	cout << "5. Show Item" << endl;

	cout << "Enter Your Selection: ";
	cin >> S1;

	switch (S1)
	{
	case 1:AddRecord(Cat); break;
	case 2:DeleteRecord(); break;
	case 3:IncreaseQty(); break;
	case 4:DecreseQty(); break;
	case 5:ShowRecords(); break;
	default: cout << "Invalid Input" << endl;
	}
}
void Inventory::Stock()
{
	int CatergoryNo;

	cout << "Select the Catergory" << endl;
	cout << "1. Produce" << endl;
	cout << "2. Meat & Seafoods" << endl;
	cout << "3. Bakery Products" << endl;
	cout << "4. Frozen Foods" << endl;
	cout << "5. Dairy Products" << endl;
	cout << "6. Snacks and Sweets" << endl;
	cout << "7. Beverages" << endl;
	cout << "8. Health & Beauty" << endl;
	cout << "9. Grains" << endl;
	cout << "10. Condiments & Spices" << endl;

	cout << "Enter the Catergory Number: ";
	cin >> CatergoryNo;



	switch (CatergoryNo)
	{
	case 1:GeneralStock("Produce"); break;
	case 2:GeneralStock("Meat & Seafoods"); break;
	case 3:GeneralStock("Bakery Products"); break;
	case 4:GeneralStock("Frozen Foods"); break;
	case 5:GeneralStock("Dairy Products"); break;
	case 6:GeneralStock("Snacks and Sweets"); break;
	case 7:GeneralStock("Beverages"); break;
	case 8:GeneralStock("Health & Beauty"); break;
	case 9:GeneralStock("Grains"); break;
	case 10:GeneralStock("Condiments & Spices"); break;
	default: cout << "Invalid Input" << endl;
	}
}
//Add stock item
void Inventory::AddItem(string cat2)
{
	Catergory = cat2;

	cout << "Enter the Product Number: ";
	cin >> ProductNumber;
	cout << endl;

	fflush(stdin);

	cout << "Enter the Product Name: ";
	cin >> ProductName;
	cout << endl;

	cout << "Enter the Product Price: Rs";
	cin >> ProductPrice;
	cout << endl;

	cout << "Enter the Product Quantity: ";
	cin >> Quantity;
	cout << endl;

	cout << "Any Discounts (%): ";
	cin >> ProductDiscount;
	cout << endl;

	cout << "Final Price: ";
	FinalPrice = ProductPrice + (ProductPrice * ProductDiscount) / 100;
	cout << FinalPrice << endl;

}

//display stocks
void Inventory::DisplayRecords()
{
	cout << setw(15) << ProductNumber
		<< setw(15) << ProductName
		<< setw(15) << Catergory
		<< setw(15) << Quantity
		<< setw(15) << ProductPrice
		<< setw(15) << ProductDiscount
		<< setw(15) << FinalPrice << endl;
}

