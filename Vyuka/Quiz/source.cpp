#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

struct Otazka {
    std::string otazka;
    std::string a;
    std::string b;
    std::string c;
    char spravnaOdpoved;
};

int main(){

    std::fstream myFile;
    std::vector<std::string> radky;
	myFile.open("questions.txt", std::ios::in);
	if (myFile.is_open()) {
		std::string radek;
		while (getline(myFile,radek))
		{
            // radky.push_back(radek);
            Otazka otazka;
            std::stringstream ss(radek);
            getline(ss, otazka.otazka, ';');
            getline(ss, otazka.a, ';');
            getline(ss, otazka.b, ';');
            getline(ss, otazka.c, ';');
            ss>>otazka.spravnaOdpoved;

		}
		myFile.close();
	}
    // for (std::string radek: radky){
    //     std::cout<<radek<<"\n";
    // }
    return 0;
}