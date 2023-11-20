#include <iostream>

using namespace std;

class Shape
{
public:
    Shape();

};

Shape::Shape()
{
    std::cout << "Vykresluji obrazec" << endl;
}

class Square:public Shape
{

private:
    int a;

public:
    Square();
    Square(int a);
    double content();
    double perimeter();
    int getA()
    {
        return a;
    }
    void print();

};

class Rectangle:public Square
{

private:
    int b;

public:
    Rectangle();
    Rectangle(int a, int b);
    double perimeter();
    double content();
    void print();

};

class Cube:public Square
{
public:
    double volume();
    Cube();
    Cube(int a);
    void print();

};


int main()
{

    Rectangle rec;
    Rectangle rec1(5, 6);

    Cube cb(5);
    cout << cb.volume() << endl;
    cb.print();

    return 0;
}


Square::Square():Shape()
{
    cout << "Vytvarime ctverec" << endl;
}

Square::Square(int a)
{
    this -> a = a;
    cout << "Vytvarime ctverec" << endl;
}

double Square::perimeter()
{
    return a * 4;
}

double Square::content()
{
    return a * a;
}

Rectangle::Rectangle()
{
    cout << "Vytvarime obdelnik" << endl;
}

Rectangle::Rectangle(int a, int b):Square(a)
{
    this -> b = b;
    cout << "Vytvarime obdelnik" << endl;

}

double Rectangle::perimeter()
{
    return 2 * b + 2 * getA();
}

double Rectangle::content()
{
    return b * getA();
}

void Rectangle::print()
{
    cout << "Obdelnik se stranou o delce " << getA() << " a druhou stranou o delce " << b << endl;
}

Cube::Cube()
{
    cout << "Vytvarime kostku" << endl;
}

void Cube::print()
{
    cout << "Kostka se stranami o delce " << getA() << endl;
}

Cube::Cube(int a):Square(a)
{
    cout << "Vytvarime kostku" << endl;
}

double Cube::volume()
{
    return content() * getA();
}

