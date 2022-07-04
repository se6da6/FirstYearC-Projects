#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
//Name: Seda Dadak
//Purpose: Getting infromation from an input file and write them on an output file

const int SIZE = 25;

int main()
{
	string typeOfBird[SIZE];
	int numberOfSighting;
	int index = 0;
	ifstream fin;
	fin.open("bird.dat");
	if (!fin.is_open())
	{
		cout << "error opening bird file";
		system("pause");
		exit(-1);
	}

	ofstream fout("bird.rpt");
	if (!fout.is_open())
	{
		cout << "error opening bird.rpt";
		system("pause");
		exit(-1);
	}
	
	for (; index < SIZE; index++)
	{
		getline(fin, typeOfBird[index]);
		if (fin.eof() )
			break;
		fout << typeOfBird[index]<<'\t';
		for (int ctr = 0; ctr < 3; ctr++)
		{
			fin >> numberOfSighting;
			fout << numberOfSighting << '\t';
			
		}
		fin.ignore(80, '\n');
		fout << endl;
	}
	
	
	fout << "Number of birds:" << index<<endl;
	system ("type bird.rpt");
	system("pause");
}
/*
Blue Heron      25      50      4
Cardinal        25      0       25
King Fisher     3       44      0
Pink Flamingo   0       40      2
Baltimore Oriole        53      8       7
Number of birds:5
Press any key to continue . . .*/