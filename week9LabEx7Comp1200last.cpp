#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Name:Seda Dadak
//Purpose: Working on arrays and functions, making practice to add a new element to the beginning of the array and print it

//prototypes:
int loadArrays(string[], double[], int);
void printHomes(int, string[], double[]);
int removeHome(int, string[], double[]);
int addAtStart(string[], double[], int, string, double);

const int SIZE = 10;

int main()
{
	string homeAddress[SIZE];
	double homePrice[SIZE];
	int lenght = 0;
	//call loadArrays function
	lenght = loadArrays(homeAddress, homePrice, lenght);
	//print the length
	cout << "length of the arrays is " << lenght << endl;
	//call printHomes function
	cout << "Our Homes' address and price information: " << endl;
	printHomes(lenght, homeAddress, homePrice);
	//call removeHome and printHomes functions
	cout << "One home was removed from the beginning : " << endl;
	lenght = removeHome(lenght, homeAddress, homePrice);
	printHomes(lenght, homeAddress, homePrice);
	//call addAtStart function
	cout << "A new home was added to the beginning of the list: " << endl;
	lenght = addAtStart(homeAddress, homePrice, lenght, "1040 Hudson Drive " , 590000.0);
	printHomes(lenght, homeAddress, homePrice);
	system("pause");
}

int loadArrays(string homeAddress[], double homePrice[], int length)
{
	ifstream fin("homes.txt");
	if (!fin.is_open())
	{
		cout << "error opening employee file";
		system("pause");
		exit(-1);
	}
	for (length = 0; length < SIZE; length++)
	{
		getline(fin, homeAddress[length]);
		if (fin.eof())
			break;
		fin >> homePrice[length];
		fin.ignore(80, '\n');
	}
	system("homes.txt");
	return length;
}

void printHomes(int passedLenght, string passedHomeAddress[], double passedHomePrice[])
{
	for (int index = 0; index < passedLenght; index++)
	{
		cout << passedHomeAddress[index] << passedHomePrice[index] << endl;
	}
}

int removeHome(int passedLength, string passedHomeAddress[], double passedHomePrice[])
{
	if (passedLength == 0)
		cout << "no elements in the array ";
	else
	{
		passedLength--;
		for (int index = 0; index < passedLength; index++)
		{
			passedHomeAddress[index] = passedHomeAddress[index + 1];
			passedHomePrice[index] = passedHomePrice[index + 1];

		}
	}
	return passedLength;

}

// add home to start of the array

int addAtStart(string homeAddress[], double homePrice[], int lenght, string newHomeAddress, double newHomePrice)
{
	if (lenght == SIZE)
		cout << "Array is full ";
	else
	{
		for (int index = lenght; index > 0; index--)
		{
			homeAddress[index] = homeAddress[index - 1];
			homePrice[index] = homePrice[index - 1];
		}
		homeAddress[0] = newHomeAddress;
		homePrice[0] = newHomePrice;
		lenght++;
	}
	return lenght;
}
/*length of the arrays is 5
Our Homes' address and price information:
100 Main Street100000
1 Princess Street10000
2 Pine Street89888
345 Jennifer Court450000
312 Johson 600000
One home was removed from the beginning :
1 Princess Street10000
2 Pine Street89888
345 Jennifer Court450000
312 Johson 600000
A new home was added to the beginning of the list:
1040 Hudson Drive 590000
1 Princess Street10000
2 Pine Street89888
345 Jennifer Court450000
312 Johson 600000
Press any key to continue . . .*/