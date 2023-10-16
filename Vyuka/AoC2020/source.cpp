#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    fstream myFile;
    vector<int> cisla;
	myFile.open("aoc.txt", ios::in);
	if (myFile.is_open()) {
		string radek;
		// getline(myFile, radek);
		// cout<<radek<<endl;
		// getline(myFile, radek);
		// cout<<radek<<endl;
		// getline(myFile, radek);
		// cout<<radek<<endl;
		while (getline(myFile,radek))
		{
            cisla.push_back(stoi(radek));
		}
		myFile.close();
	}
    // for (int cislo: cisla){
    //     cout<<cislo<<", ";
    // }

	for (int i = 0; i < cisla.size(); i++)
	{
		cout<<cisla[i]<<", ";
		for (int j = 0; j < cisla.size(); j++)
		{
			/* code */
		}
		
	}
	
    return 0;
}