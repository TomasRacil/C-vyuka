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
		while (getline(myFile,radek))
		{
            cisla.push_back(stoi(radek));
		}
		myFile.close();
	}
    for (int cislo: cisla){
        cout<<cislo<<", ";
    }
    return 0;
}