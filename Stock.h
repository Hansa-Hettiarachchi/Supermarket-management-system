#pragma once
#include<iostream>
#include<string>

using namespace std;
class Inventory
{
private:

protected:
	int ProductNumber;
	float ProductPrice;
	int Quantity;
	float ProductDiscount;
	float FinalPrice;
	char ProductName[10];
	string Catergory;

public:
	static int i;
	void Stock();
	void Supply();
	void Staff();
	void IncreaseQty();
	void AddItem(string C);
	void DisplayRecords();
	//void RemoveItem();
	int getCode()
	{
		return ProductNumber;
	}

	void IncQty(int num)
	{
		Quantity = Quantity + num;
	}

	void DecQty(int num)
	{
		//if (Quantity > num)
		//{
		Quantity = Quantity - num;
		//}

	}
	//void IncreaseItem();
	//void DecreaseItem();
};