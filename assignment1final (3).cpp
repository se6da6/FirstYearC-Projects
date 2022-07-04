#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*Name: Seda Dadak  Student ID:4320699 Section 101 
Assignment 1 purpose is to compute one car rental company's charge for each customer*/
int main()
{
	string customerName;
	int noDays;
	int beginningOdometer, endingOdometer;
	int milesDriven;
	const int COST_PERDAY=15;
	const double COST_PERMILE=0.12;
	double charge;
	int dailyCost;


	cout << fixed << setprecision(2);
	cout << "Please enter customer name! " << endl;
	getline(cin, customerName);
	cout << "Please enter begginning odometer reading. " << endl;
	cin >> beginningOdometer;
	cout << "Please enter ending odometer reading. " << endl;
	cin >> endingOdometer;
	cout << "Please enter the number of days the car was used. " << endl; 
	cin >> noDays;

	milesDriven = endingOdometer - beginningOdometer;
	dailyCost = (15 * noDays);
	charge = (milesDriven * COST_PERMILE) + dailyCost;

	cout << endl << endl;
	cout << setw(39) << right << "Awesome Car Rentals" << endl;
	cout << left << setw(20)<< "Customer Name "
		 << setw(12)<<"# of days"
		 << right << setw(12)<<"Miles Driven "
		 << setw(8) << "Charge "
		 << endl<< endl;
	cout << left << setw(20)<< customerName
		 << setw(12)<<noDays
		 << right << setw(12)<<milesDriven
		 << setw(8) << charge
		 << endl << endl;

		system("pause");
}
/*Please enter customer name!
J.Doe
Please enter begginning odometer reading.
100
Please enter ending odometer reading.
166
Please enter the number of days the car was used.
2


					Awesome Car Rentals
Customer Name       # of days   Miles Driven  Charge

J.DOE              2                     66   37.92

Press any key to continue . . .*/