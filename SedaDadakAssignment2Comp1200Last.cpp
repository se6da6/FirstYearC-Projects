#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Name:Seda Dadak
//Purpose: To create a program for a realtor company to save their homes's records to sale.

int loadArrays(string[], double[]);
int findHighest(const double[], int);
double validatePrice(double);
int addHome(string[], double[], int);
int removeHome(string[], double[], int);
void printHomes(const string[], const double[], int);

const int SIZE = 20;
int main()
{
	string address[SIZE];
	double price[SIZE];
	int noRecords = 0;
	cout << "\nDelete an empty list:\n\n" << endl;
	printHomes(address, price, noRecords);
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nInitial array load:\n\n" << endl;
	noRecords = loadArrays(address, price);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a new home:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd the same home:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a home to the beginning of the array:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a home to the end of the array:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a home to middle of array:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete a home from start of array:\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete the same home\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete a home from middle of array:\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete a home from the end of the array:\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nProgram ended successfully" << endl;
	system("type homes.txt");
	system("pause");
}

int loadArrays(string address[], double price[])
{
	ifstream fin;
	fin.open("homes.txt");
	if (!fin.is_open())
	{
		cout << "error opening employee file";
		system("pause");
		exit(-1);
	}
	int lenght = 0;
	for (; lenght < SIZE; lenght++)
	{
		getline(fin, address[lenght]);
		if (fin.eof() || lenght == SIZE)
			break;
		fin >> price[lenght];
		fin.ignore(80, '\n');
	}

	return lenght;
}

int findHighest(const double price[], int noRecords)
{
	int highest = 0;

	for (int index = 1; index < noRecords; index++)
	{
		if (price[index] > price[highest])
			highest = index;
	}
	return highest;
}

void printHomes(const string address[], const double price[], int noRecords)
{

	int highest = findHighest(price, noRecords);
	cout << left << setw(25) << "Address "
		<< right << setw(15) << "Price" << endl << endl;
	for (int index = 0; index < noRecords; index++)
	{
		if (price[index] == price[highest])
		{
			cout << left << setw(25) << address[index]
				<< right << setw(15) << price[index] << "*** Highest price!***"
				<< endl;
		}
		else
		{
			cout << left << setw(25) << address[index]
				<< right << setw(15) << price[index] << endl;
		}

	}
	cout << endl;
	cout << left << setw(15) << "Number of homes = " << noRecords << endl;
}

double validatePrice(double price)
{
	while (price < 0.0 || price > 10000000.0 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "must be a number from 0.0 to 10000000.0, enter again ";
		cin >> price;
	}
	return price;
}

int addHome(string address[], double price[], int noRecords)
{
	if (noRecords < SIZE)
	{
		string newAddress;
		double newPrice = 0.0;
		int position = 0;
		cout << "Please enter new home address. " << endl;
		getline(cin, newAddress);
		for (; position < noRecords; position++)
		{
			if (address[position] >= newAddress)
				break;
		}
		cout << "Please enter price of new home. " << endl;
		cin >> newPrice;
		cin.ignore(80, '\n');
		newPrice = validatePrice(newPrice);
		if (address[position] == newAddress && position < noRecords)
			cout << "Can't add, home already exists " << endl;
		else
		{
			for (int index = noRecords; index > position; index--)
			{
				address[index] = address[index - 1];
				price[index] = price[index - 1];
			}
			address[position] = newAddress;
			price[position] = newPrice;
			noRecords++;
		}
	}
	return noRecords;
}


int removeHome(string address[], double price[], int noRecords)
{
	int position = 0;
	string removingHomeAddress;

	if (noRecords > 0)
	{
		cout << "Please enter home address that you would like to remove. ";
		getline(cin, removingHomeAddress);
		for (; position < noRecords; position++)
		{
			if (address[position] == removingHomeAddress)
				break;
		}
		if (position == noRecords || noRecords == 0)
			cout << "Home Address not found or the array is empty " << endl;
		noRecords--;
		for (; position < noRecords; position++)
		{
			address[position] = address[position + 1];
			price[position] = price[position + 1];
		}
	}

	return noRecords;
}

/*
Delete an empty list:


Address                            Price


Number of homes = 0
Address                            Price


Number of homes = 0
# homes = 0

Initial array load:


Address                            Price

1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000

Number of homes = 8
# homes = 8

Add a new home:


Please enter new home address.
8 Ellesmeer Avenue
Please enter price of new home.
450000.0

Address                            Price

1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000
8 Ellesmeer Avenue                450000

Number of homes = 9
# homes = 9

Add the same home:


Please enter new home address.
8 Ellesmeer Avenue
Please enter price of new home.
450000.0

Can't add, home already exists
Address                            Price

1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000
8 Ellesmeer Avenue                450000

Number of homes = 9
# homes = 9

Add a home to the beginning of the array:


Please enter new home address.
1 Age Street
Please enter price of new home.
300000.0

Address                            Price

1 Age Street                      300000
1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000
8 Ellesmeer Avenue                450000

Number of homes = 10
# homes = 10

Add a home to the end of the array:


Please enter new home address.
9 True Street
Please enter price of new home.
330000.0

Address                            Price

1 Age Street                      300000
1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000
8 Ellesmeer Avenue                450000
9 True Street                     330000

Number of homes = 11
# homes = 11

Add a home to middle of array:


Please enter new home address.
5 Good Street
Please enter price of new home.
95000.0

Address                            Price

1 Age Street                      300000
1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Good Street                      95000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000
8 Ellesmeer Avenue                450000
9 True Street                     330000

Number of homes = 12
# homes = 12

Delete a home from start of array:


Please enter home address that you would like to remove. 1 Age Street
Address                            Price

1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Good Street                      95000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000
8 Ellesmeer Avenue                450000
9 True Street                     330000

Number of homes = 11
# homes = 11

Delete the same home


Please enter home address that you would like to remove. 1 Age Street
Home Address not found or the array is empty
Address                            Price

1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Good Street                      95000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000
8 Ellesmeer Avenue                450000

Number of homes = 10
# homes = 10

Delete a home from middle of array:


Please enter home address that you would like to remove. 5 Good Street
Address                            Price

1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000
8 Ellesmeer Avenue                450000

Number of homes = 9
# homes = 9

Delete a home from the end of the array:


Please enter home address that you would like to remove. 8 Ellesmeer Avenue
Address                            Price

1 Princess Street                 800000*** Highest price!***
100 Main Street                    10000
2 Pine Street                      89888
3 Johnson Street                  650000
4 Hudson Drive                    640000
5 Jennifer Court                  550000
6 King Street                     400000
7 Princess Street                 300000

Number of homes = 8
# homes = 8

Program ended successfully
1 Princess Street
800000.00
100 Main Street
10000.00
2 Pine Street
89888.00
3 Johnson Street
650000.00
4 Hudson Drive
640000.00
5 Jennifer Court
550000.00
6 King Street
400000.00
7 Princess Street
300000.00Press any key to continue . . .*/



