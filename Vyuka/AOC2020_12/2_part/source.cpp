#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class NavigacniBod{
    public:
        int sever;
        int vychod;
        NavigacniBod();
        void rotace(char smer, int hodnota);
        void posun(char smer, int hodnota);
};

class Lod
{
    public:
        int sever;
        int vychod;
        NavigacniBod nav_bod;

        Lod();
        void naviguj(string soubor);
        void pohyb(int hodnota);
        void tisk_souradnic();

};

int main(){
    Lod novaLod;
    novaLod.naviguj("aoc.txt");
    novaLod.tisk_souradnic();

    return 0;
}

Lod::Lod(){
    this->sever = 0;
    this->vychod = 0;
    this->nav_bod = NavigacniBod();
}

void Lod::pohyb(int hodnota)
{
    this->sever += (this->nav_bod.sever*hodnota);
    this->vychod += (this->nav_bod.vychod*hodnota);
}

NavigacniBod::NavigacniBod(){
    this->sever = 2;
    this->vychod = 10;
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
                nav_bod.rotace(ukol, hodnota);
                break;
            case 'N':
            case 'S':
            case 'E':
            case 'W':
                nav_bod.posun(ukol, hodnota);
                break;
            case 'F':
                this->pohyb(hodnota);
                break;
        }
    
    }
  myfile.close();

}

void NavigacniBod::rotace(char smer, int hodnota){

    if (smer == 'L') {
        //stupen = hodnota;
        
        int pomX = vychod;
        int pomY = sever;

        if (hodnota == 90) {
            vychod = - pomY;
            sever = + pomX;
        }

        else if (hodnota == 180) {
            vychod = - pomX;
            sever = - pomY;
        }

        else if (hodnota == 270) {
            vychod = pomY;
            sever = - pomX;
        }   

    }

    else if (smer == 'R') {
        int stupen = 360 - hodnota;
        
        int pomX = vychod;
        int pomY = sever;

        if (stupen == 90) {
            vychod = - pomY;
            sever = + pomX;
        }

        else if (stupen == 180) {
            vychod = - pomX;
            sever = - pomY;
        }

        else if (stupen == 270) {
            vychod = pomY;
            sever = - pomX;
        }   
    }

}

void NavigacniBod::posun(char smer, int hodnota)
{
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
    }
}

void Lod::tisk_souradnic(){
    cout<<abs(sever)+abs(vychod);
}