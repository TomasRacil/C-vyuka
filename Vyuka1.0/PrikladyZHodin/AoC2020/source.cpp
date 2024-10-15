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
		// cout<<cisla[i]<<", ";
		for (int j = i+1; j < cisla.size(); j++)
		{
			int soucet = cisla[i]+cisla[j];
			if(soucet==2020) cout<<cisla[i]<<"*"<<cisla[j]<< "=" << cisla[i]*cisla[j] <<endl;
			
			for (int k = j+1; k < cisla.size(); k++){
				if (soucet+cisla[k]==2020) cout<<cisla[i]<<"*"<<cisla[j] << "*" << cisla[k] << "=" << cisla[i]*cisla[j]*cisla[k]  <<endl;
			}
		}
		
	}
	
    return 0;
}