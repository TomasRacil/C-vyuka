// 1_Ship.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <string>

class Ship {
public:
    Ship();
    void move(char direction, int value);
    void turn(char direction, int value);
    void info();
    void navigate(string navigationData); 

private:
    //auto orientation;
    int positionE;
    int poitionS;
};

int main()
{
}

