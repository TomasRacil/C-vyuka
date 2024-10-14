#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream myFile;
	myFile.open("test.txt", ios::out);
	if (myFile.is_open())
	{
		myFile << "Prvni radek" << endl;
		myFile << "Druhy radek" << endl;
		myFile.close();
	}
	myFile.open("test.txt", ios::in);
	if (myFile.is_open())
	{
		string radek;
		while (getline(myFile, radek))
		{
			cout << radek << endl;
		}
		myFile.close();
	}
	myFile.open("test.txt", ios::out);
	if (myFile.is_open())
	{
		myFile << "Soubor se prepsal" << endl;
		myFile.close();
	}
	myFile.open("test.txt", ios::app);
	if (myFile.is_open())
	{
		myFile << "Doplneno na konec souboru";
		myFile.close();
	}
	myFile.open("test.txt", ios::in);
	if (myFile.is_open())
	{
		string radky[10];
		string radek;
		int i = 0;
		while (getline(myFile, radek))
		{
			radky[i] = radek;
			i++;
		}
		for (i = 0; i < 10; i++)
		{
			cout << i << ": " << radky[i] << endl;
		}
		myFile.close();
	}
	myFile.open("C:/Users/tomas/Desktop/ukazka.txt", ios::in);
	if (myFile.is_open())
	{
		string radek;
		while (getline(myFile, radek))
		{
			cout << radek << endl;
		}
		myFile.close();
	}
	ifstream is("test.txt", ifstream::binary);
	if (is)
	{
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		cout << length << endl;

		// allocate memory:
		char *buffer = new char[length];

		// read data as a block:
		is.read(buffer, length);

		is.close();

		// print content:
		cout.write(buffer, length);

		delete[] buffer;
	}
	return 0;
}