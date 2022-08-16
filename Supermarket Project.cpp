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



int main()
{

	int Position;

	do
	{
		//The Other Inputs Should be Included.
		cout << "1->Owner\n2->Manager\n3->Cashier\n4->FLoor worker\nEnter your Position: " << endl;
		cin >> Position;

		//Input Error Corrections
		if (Position == 1)
		{
			Owner O;
			int Selection;
			cout << "\nEnter your Selection: ";
			cin >> Selection;

			switch (Selection)
			{
			case 1:O.Stock(); break;
			case 2:O.Supply(); break;
			case 3:O.Staff(); break;
			//case 4:O.ShowTranscationRecords(); break;
			default:cout << "Invalid Input" << endl; break;
			}
		}
		else if (Position == 2)
		{
			Manager M;
			int Selection;
			cout << "\nEnter your Selection: ";
			cin >> Selection;

			switch (Selection)
			{
			case 1:M.Stock(); break;
			case 2:M.Supply(); break;
			//case 3:ShowStaffRecords(); break;
			default:cout << "Invalid Input" << endl; break;
			}
		}
		else if (Position == 4)
		{
			FlowWorker F;
			int Selection;
			cout << "\nEnter your Selection: ";
			cin >> Selection;

			switch (Selection)
			{
			//case 1:F.IncreaseQty();; break;
			case 2:F.Supply(); break;
			default:cout << "Invalid Input" << endl; break;
			}

		}
		else if (Position == 3)
		{
			Cashier C;
			cout << "Record Transaction and Decrease stock" << endl;
			//C.AddTransactionRecord();

		}
		else
		{
			cout << "Please Re-Enter your Position" << endl;
		}
	} while (Position == 1 || Position == 2 || Position == 3 || Position == 4);


	return 0;
}










