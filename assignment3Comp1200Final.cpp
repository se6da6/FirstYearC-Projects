#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

//Name:Seda Dadak
//Purpose:To produce a program for a wine company to follow their wine sale

const int SIZE = 3;
const int NO_COLM = 4;

void loadArrays(ifstream&, string[], double[][NO_COLM], int&);
void computeSum(double[][NO_COLM], double[], int);
void printReport(ofstream&, const string[], const double[][NO_COLM],
	double[], int, int);
void findWine(double[][NO_COLM], int&, int&, int);
void mostWineSold(double[], int&, int);

int main()
{
	double salesAmt[SIZE][4];  //no need to change your variable names to match mine!
	string wine[SIZE];
	double yearlySales[SIZE] = { 0.00 };
	int noWines;
	int highestRow, highestCol, mostSold;
	cout << fixed << setprecision(2);
	ifstream fin("wines.dat");
	if (!fin.is_open())
	{
		cout << "error opening wines.dat file - contact systems";
		system("pause");
		exit(-1);
	}
	ofstream fout("winesales.rpt");
	if (!fout.is_open())
	{
		cout << "error opening winesales.rpt file - contact systems";
		system("pause");
		exit(-2);
	}
	fout << fixed << setprecision(2);

	cout << "\n\nLoad arrays\n\n";
	loadArrays(fin, wine, salesAmt, noWines);
	cout << "\n\n=======================================================\n\n";

	cout << "\n\nCompute yearly Sale\n\n";
	computeSum(salesAmt, yearlySales, noWines);
	cout << "\n\n=======================================================\n\n";

	cout << "\n\nFind best selling wine and highest sales amount:\n\n";
	findWine(salesAmt, highestRow, highestCol, noWines);
	cout << "\n\n" << wine[highestRow] << " had the highest sales amount = $"
		<< salesAmt[highestRow][highestCol] << endl;
	cout << "\n\n=======================================================\n\n";

	cout << "\n\nFind the most sold wine:\n\n";
	mostWineSold(yearlySales, mostSold, noWines);
	cout << "\n\n Most sold wine is " << wine[mostSold] << endl;

	cout << "\n\n=======================================================\n\n";
	printReport(fout, wine, salesAmt, yearlySales, mostSold, noWines);
	cout << "\n\n=======================================================\n\n";

	cout << "program ended successfully" << endl;
	cout << "\n\n Printing wines.dat file\n\n";
	system("type wines.dat");
	cout << "\n\n Printing winesales.rpt file\n\n";
	system("type winesales.rpt");
	system("pause");
}


void loadArrays(ifstream& fin, string wine[], double saleAmt[][NO_COLM], int& noWines)
{

	for (noWines = 0; noWines < SIZE; noWines++)
	{
		getline(fin, wine[noWines]);
		if (cin.eof() || noWines == SIZE)
			break;
		for (int col = 0; col < NO_COLM; col++)
		{
			fin >> saleAmt[noWines][col];
		}
		fin.ignore(80, '\n');
	}

}
void computeSum(double saleAmt[][NO_COLM], double yearlySales[], int noWines)
{

	for (int row = 0; row < noWines; row++)
	{
		for (int col = 0; col < noWines; col++)
		{
			yearlySales[row] += saleAmt[row][col];
		}
	}


}

void printReport(ofstream& fout, const string wine[], const double saleAmt[][NO_COLM],
	double yearlySales[], int mostSold, int noWines)
{
	double totalSale = 0.0;
	fout << left << setw(10) << "Wine "
		<< right << setw(50) << "Quarterly Sales" << endl;
	fout << left << setw(10) << " "
		<< right << setw(16) << "1st"
		<< setw(16) << "2nd"
		<< setw(16) << "3rd"
		<< setw(16) << "4th"
		<< setw(16) << "Yearly " << endl << endl;

	for (int row = 0; row < noWines; row++)
	{
		yearlySales[row] = 0.0;
		fout << left << setw(10) << wine[row] << '\t';
		int column = 0;
		for (; column < NO_COLM; column++)
		{

			fout << right << setw(12) << saleAmt[row][column] << '\t';
			yearlySales[row] += saleAmt[row][column];
		}

		if (row == mostSold)
		{
			fout << yearlySales[row] << "**most sold**";
		}
		else
			fout << yearlySales[row];
		fout << endl;

		totalSale += yearlySales[row];
	}
	fout << endl;
	fout << "Total Sales Amount $ " << totalSale << endl;
}


void findWine(double saleAmt[][NO_COLM], int& highestRow, int& highestCol, int noWines)
{
	highestRow = 0, highestCol = 0;
	for (int row = 0; row < noWines; row++)
	{
		for (int col = 0; col < NO_COLM; col++)
		{
			if (saleAmt[row][col] > saleAmt[highestRow][highestCol])
			{
				highestCol = col;
				highestRow = row;
			}
		}
	}
}

void mostWineSold(double yearlySales[], int& mostSold, int noWines)
{
	int index = 1;
	mostSold = 0;
	for (; index < noWines; index++)
	{
		if (yearlySales[index] > yearlySales[mostSold])
			mostSold = index;
	}

}
/*

Load arrays



=======================================================



Compute yearly Sale



=======================================================



Find best selling wine and highest sales amount:



White    had the highest sales amount = $300000.00


=======================================================



Find the most sold wine:



 Most sold wine is White


=======================================================



=======================================================

program ended successfully


 Printing wines.dat file

Red
200000  50000   57000   16800
Rose
25000   0       4500    7800
White
300000  4400    23000   5300



 Printing winesales.rpt file

Wine                                         Quarterly Sales
					   1st             2nd             3rd             4th         Yearly

Red                200000.00        50000.00        57000.00        16800.00    323800.00
Rose                25000.00            0.00         4500.00         7800.00    37300.00
White              300000.00         4400.00        23000.00         5300.00    332700.00**most sold**

Total Sales Amount $ 693800.00
Press any key to continue . . .*/


