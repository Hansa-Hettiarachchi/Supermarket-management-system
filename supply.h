#pragma once
#include <iostream>
#include <string>

using namespace std;


//struct Date {
//	int year = 0;
//	int month = 0;
//	int date = 0;
//};


class supply {
private:
	string LocOrInternational = "Local";
	//Local
	string productName = "I";
	int quantity = 0;
	string nameOfOrigin = "International";
	Date departureDate;
	//Date arrivalDate;
	string vehicle = "Ship";
	int regNo = 0;
	string status = "Pending";
	//International
	string originCountry = "I";
	//int shipRegNo=0;
	Date arrivalToCountryDate;
	Date arriveToStoreDate;
public:
	void AddSupply();
	void DisplayRecords();
	void IncreaseQty();
};




