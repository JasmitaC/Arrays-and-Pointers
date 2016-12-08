#include "iostream"
using namespace std;
#include "stdio.h"

/*
Title: Assignment-1
Author: Jasmita Chawla
Objective: Use dynamic memory allocation to make a program that keeps a record of the user’s purchases, allows them to enter new purchases, view their purchases, and to see the maximum and minimum values of their purchases.
Algorithm: 

Variables: num, price, counter, option, purchase, price2, max and min

	Ask user to enter the number of purchases 
	Create a dynamic array of that size

	Loop
		Ask user to select an option
		if(1 is pressed)
			if(counter is less than num)
				Ask user to enter new purchase
				counter goes to price array and is equal to purchase 
				counter++
			else
				Create a new dynamic array (price2) and copy all data from price to price2 
				Free price array
				Set price equal to price2 to make the pointers point to new array
	
		if(2 is pressed)
			Display price array
		
		if(3 is pressed)
			Set max equal to the first index of price array
				if max is less than price
					max is equal to price
				Display most expensive purchase

		if(4 is pressed)
			Set min equal to the first index of price array
				if min is greater than price
					min is equal to price
				Display least expensive purchase

		if(5 is pressed)
			break
*/

int* PurchaseRecord()
{
	int*price; 
	int num = 0;
	cout << "Please enter the number of purchases: ";
	cin >> num;
	price = (int*)malloc(num * sizeof(int));
	int counter = 0;

	while(true)
	{
		int option;
	
		cout << "Please select an option: \n";
		cout << "Press 1 to enter a new purchase \n";
		cout << "Press 2 to see the full list of entered purchases \n";
		cout << "Press 3 to show the value of the most expensive purchase \n";
		cout << "Press 4 to show the value of the least expensive purchase \n";
		cout << "Press 5 to end the program \n";

		cin >> option; 

		if (option == 1)
		{
			int purchase;
			
			if (counter < num)
			{
				cout << "Please enter a new purchase:$ ";
				cin >> purchase;

				price[counter] = purchase;
				counter++;
			}
			else
			{
				int*price2 = (int*)malloc(2 * num * sizeof(int));
				for(int i =0 ; i < num; i++)
				{
					price2[i] = price[i];
				}
				num = num * 2;
				free(price); 
				price = price2; 
			}
		}

		if (option == 2)
		{
			for (int i = 0; i < counter; i++)
			{
				cout << "$" << price[i] << "\n";
			}
		}

		if (option == 3) 
		{
			int max = price[0];
			for (int i =0; i < num; i++)
			{
				if (max < price[i])
				{
					max = price[i];
				}
			}
			cout << "The most expensive purchase is:$" << max << "\n";
		}

		if (option == 4)
		{
			int min = price[0];
			for (int i = 0; i < counter; i++)
			{
				if (price[i] < min )
				{
					min = price[i];
				}
			}
			cout << "The least expensive purchase is:$" << min << "\n";
		}

		if (option == 5)
		{
			break;
		}
	}

	return price;
}

void main()
{
	int * p = PurchaseRecord();
	free(p); 
} 



