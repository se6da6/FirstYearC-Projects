#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

//Name:Seda Dadak
//Purpose:To write a program which shows ABC grocery store's receipts for every customer and total number of customer

//prototypes:
char getValidMeat();
double validateWeight(double);
double determineMeatCost(char);
double getValidCost();
void printBill(char/*meatType*/,double/*totalCost*/, double/*dairyCost*/, double/*miscellaneousCost*/, double /*grossTotal*/);

int main()
{
	
	char meatType;
	double meatCost, dairyCost = 0.0, miscellaneousCost=0.0, meatWeight = 0.0, totalCost = 0.0, grossTotal;
	int customerNo = 0;
	string nextCustomer;
	do
	{
		meatType = getValidMeat();
		meatWeight = validateWeight(meatWeight);
		cout << "Enter dairy cost. ";
		dairyCost = getValidCost();
		cout << "Enter miscellaneous cost. " ;
		miscellaneousCost = getValidCost();
		meatCost = determineMeatCost(meatType);
		totalCost = meatWeight * meatCost;
		grossTotal = totalCost + dairyCost + miscellaneousCost;
		printBill(meatType, totalCost, dairyCost, miscellaneousCost, grossTotal);
		customerNo++;
		cout << "Press enter to handle next customer or press ctrl z to close system "<<endl;
		cin.ignore(80, '\n');
		getline(cin, nextCustomer);
		
	} while (!cin.eof());

	cout << "Number of customers =  " << customerNo << endl;

	system("pause");
}

char getValidMeat()
{
	char kindOfMeat;
	cout << "Please enter meat type. " ;
	cin >> kindOfMeat;
	kindOfMeat = toupper(kindOfMeat);
	if (!cin.eof())
	{
		while (kindOfMeat != 'B' && kindOfMeat != 'C' && kindOfMeat != 'F')
		{
			cout << "Invalid meat type. Please  re-enter. Meat type can be (B),(C) or(F). " ;
			cin >> kindOfMeat;
			kindOfMeat = toupper(kindOfMeat);
		}
	}
	return kindOfMeat;
}

double validateWeight(double passedWeight)
{
	cout << "Please enter meat weigth. ";
	cin >> passedWeight;
	if (passedWeight < 0 || passedWeight>100 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Invalid weight. Weigth should be between 0-100. ";
		cin >> passedWeight;
	}
	return passedWeight;
}

double determineMeatCost(char passedMeatType)
{
	double meatPrice;
	switch (passedMeatType)
	{
		case'B':
			meatPrice = 8.80;
			break;
		case'C':
			meatPrice = 5.49;
			break;
		case'F':
			meatPrice = 6.59;
			break;
		default:
			meatPrice = 0.0;
			break;
	}
	
	return meatPrice;
}

double getValidCost()
{
	double cost;
	cin >> cost;
	while (cost < 0 || cost>1000 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Please re-enter your cost. It must be between 0-1000. ";
		cin >> cost;
	}
	return cost;
}

void printBill(char passedMeatType, double passedTotalCost, double passedDairyCost, double passedMiscellaneousCost, double passedGrossTotal)
{

	ofstream fout("receipt.txt");
	if (!fout.is_open())
	{
		cout << "The file didn't open properly. Please try again.";
		system("pause");
		exit(666);
	}
	fout << setprecision(2) << fixed<<endl;
	fout << "ABC Grocery Store " << endl << endl
		<< "Items bougt: " << endl << endl;
	if (passedMeatType == 'B')
		fout << left<< setw(25) << "MeatBeef @ $8.80/kgs " <<right <<setw(6)<<passedTotalCost<<endl;
	else if (passedMeatType == 'C')
		fout << left << setw(25) << "Meat Chicken @ $5.49/kgs " << right << setw(6) << passedTotalCost<<endl;
	else
		fout << left << setw(25) << "Meat Fish @ $6.59/kgs " << right << setw(6) << passedTotalCost << endl;
	fout << left << "Dairy Products " << right << setw(16) << passedDairyCost << endl;
	fout << left << "Miscellaneous " << right << setw(17) << passedMiscellaneousCost << endl<<endl;
	fout << setw(31) << passedGrossTotal<<endl;
	fout << setw(15) << "THANK YOU!" << endl << endl;


	system("Type receipt.txt");
}
/*Please enter meat type. d
Invalid meat type. Please  re-enter. Meat type can be (B),(C) or(F). b
Please enter meat weigth. -5.0
Invalid weight. Weigth should be between 0-100. 2.83
Enter dairy cost. -6.0
Please re-enter your cost. It must be between 0-1000. 8.21
Enter miscellaneous cost. -1.5
Please re-enter your cost. It must be between 0-1000. 3.48

ABC Grocery Store

Items bougt:

MeatBeef @ $8.80/kgs      24.90
Dairy Products             8.21
Miscellaneous              3.48

                          36.59
     THANK YOU!

Press enter to handle next customer or press ctrl z to close system

Please enter meat type. c
Please enter meat weigth. 2.5
Enter dairy cost. 8.21
Enter miscellaneous cost. 3.48

ABC Grocery Store

Items bougt:

Meat Chicken @ $5.49/kgs  13.73
Dairy Products             8.21
Miscellaneous              3.48

                          25.42
     THANK YOU!

Press enter to handle next customer or press ctrl z to close system

Please enter meat type. f
Please enter meat weigth. 4.5
Enter dairy cost. 8.21
Enter miscellaneous cost. 3.5

ABC Grocery Store

Items bougt:

Meat Fish @ $6.59/kgs     29.66
Dairy Products             8.21
Miscellaneous              3.50

                          41.37
     THANK YOU!

Press enter to handle next customer or press ctrl z to close system
^Z
Number of customers =  3
Press any key to continue . . .*/