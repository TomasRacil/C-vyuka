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
    std::vector<Otazka> otazky;
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
            otazky.push_back(otazka);
		}
		myFile.close();
	}
    int score = 0;
    for (Otazka otazka: otazky){
        char odpoved;
        std::cout<< otazka.otazka<<std::endl;
        std::cout<< "a) " << otazka.a<<std::endl;
        std::cout<< "b) " <<otazka.b<<std::endl;
        std::cout<< "c) " <<otazka.c<<std::endl;
        std::cin >> odpoved;
        if (odpoved == otazka.spravnaOdpoved) score+=1;
    }
    std::cout << "Tve score je: " << score<<std::endl;
    // for (std::string radek: radky){
    //     std::cout<<radek<<"\n";
    // }

    return 0;
}