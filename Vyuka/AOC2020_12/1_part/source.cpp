#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Lod
{
    public:
        int sever;
        int vychod;
        int stupne;

        Lod(int stupne, int sever, int vychod);
        void naviguj(string soubor);
        void rotace(char smer, int hodnota);
        void pohyb(char smer, int hodnota);
        void tisk_souradnic();

};

int main(){
    Lod novaLod(90,0,0);
    novaLod.naviguj("aoc.txt");
    novaLod.tisk_souradnic();

    return 0;
}

Lod::Lod(int stupne, int sever, int vychod){
    this->stupne = stupne;
    this->sever = sever;
    this->vychod = vychod;
}

void Lod::naviguj(string soubor){

    fstream myfile;
    string radek;
    myfile.open(soubor,ios::in);
    while(getline(myfile,radek)){
        char ukol;
        int hodnota;
        ukol=radek.at(0);
        hodnota=stoi(radek.substr(1,radek.length()));
        switch(ukol){
            case 'L':
            case 'R':
                this->rotace(ukol, hodnota);
                break;
            case 'N':
            case 'S':
            case 'E':
            case 'W':
            case 'F':
                this->pohyb(ukol, hodnota);
                break;
        }
    
    }
  myfile.close();

}

void Lod::pohyb(char smer, int hodnota){
    switch (smer)
    {
    case 'N':
        sever += hodnota;
        break;
    case 'S':
        sever -= hodnota;
        break;
    case 'E':
        vychod += hodnota;
        break;
    case 'W':
        vychod -= hodnota;
        break;
    case 'L':
        rotace(smer, hodnota);
        break;
    case 'R':
        rotace(smer, hodnota);
        break;
    case 'F':
        switch (this->stupne)
        {
        case 0:
            sever += hodnota;
            break;
        case 90:
            vychod += hodnota;
            break;
        case 180:
            sever -= hodnota;
            break;
        case 270:
            vychod -= hodnota;
            break;
        
        default:
            break;
        }
    
    default:
        break;
    }
}

void Lod::rotace(char smer, int hodnota){
    if (smer == 'L') {
        stupne -= hodnota;
    }
    else if (smer == 'R') {
        stupne += hodnota;
    }
    if (stupne < 0) {
        stupne += 360;
    }
    else if (stupne >= 360) {
        stupne -= 360;
    }
}

void Lod::tisk_souradnic(){
    
}