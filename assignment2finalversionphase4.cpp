#include <iostream>
#include <fstream> 
#include <iomanip>
#include <string>
using namespace std;

//Purpose:For a butcher shop produce a sales receipt for each customer
//Name:Seda Dadak

int main()
{
	string customerName;
	int noCustomer = 0;
	char meatType;
	double cost, weight, price, totalSale = 0.0, averageSale, salePerCustomer;
	ofstream fout("receipt.data");
	fout << setprecision(2) << fixed;
	if (!fout.is_open())
	{
		cout << "error opening receipt.data";
		system("pause");
		exit(-4);
	}

	cout << "Enter customer name or ^Z ";
	getline(cin, customerName);
	while (!cin.eof())
	{
		cout << "Enter type of meat ";
		cin >> meatType;
		while (!(meatType == 'P' || meatType == 'p' || meatType == 'B' || meatType == 'b' || meatType == 'C' || meatType == 'c'))
		{
			cout << "Meat type should be c. b or p. Please reenter! ";
			cin >> meatType;
		}
		cout << "Enter weight ";
		cin >> weight;
		while (!(weight <= 100 && weight >= 1))
		{
			cout << "Weight must be greater than 1 and less than 100. Please re enter! ";
			cin >> weight;
		}
		if (meatType == 'C' || meatType == 'c')
			price = 5.49;
		else if (meatType == 'P' || meatType == 'p')
			price = 6.80;
		else
			price = 8.80;

		cost = weight * price;
		noCustomer++;
		salePerCustomer = cost;
		totalSale += salePerCustomer;

		fout << left << setw(20) << "Customer "
			<< setw(10) << "Meat "
			<< right << setw(10) << "Weight "
			<< setw(10) << "Cost "
			<< endl << endl;
		fout << left << setw(20) << customerName
			<< setw(10) << meatType
			<< right << setw(9) << weight
			<< setw(10) << cost
			<< endl << endl;

		cout << "Enter customer name or ^Z ";
		cin.ignore(80, '\n');
		getline(cin, customerName);
	}
	fout << "Total sale is " << totalSale << endl << endl;
	if (noCustomer > 0)
		fout << "Average sale is " << totalSale / noCustomer << endl;

	cout << endl << "Program ended successfully" << endl;

	cout << endl << "Printout of receipt.data file" << endl << endl;

	system("type receipt.data");
	system("pause");
}
/*Enter customer name or ^Z J Doe
Enter type of meat c
Enter weight 2.89
Enter customer name or ^Z Seda
Enter type of meat r
Meat type should be c. b or p. Please reenter! B
Enter weight -5.0
Weight must be greater than 1 and less than 100. Please re enter! 5.0
Enter customer name or ^Z Numan
Enter type of meat L
Meat type should be c. b or p. Please reenter! p
Enter weight 101
Weight must be greater than 1 and less than 100. Please re enter! 9.0
Enter customer name or ^Z Asya
Enter type of meat B
Enter weight 4.0
Enter customer name or ^Z ^Z

Program ended successfully

Printout of receipt.data file

Customer            Meat         Weight      Cost

J Doe               c              2.89     15.87

Customer            Meat         Weight      Cost

Seda                B              5.00     44.00

Customer            Meat         Weight      Cost

Numan               p              9.00     61.20

Customer            Meat         Weight      Cost

Asya                B              4.00     35.20

Total sale is 156.27

Average sale is 39.07
Press any key to continue . . .*/
