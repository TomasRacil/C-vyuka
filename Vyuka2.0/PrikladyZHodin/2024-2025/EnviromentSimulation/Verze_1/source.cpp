#include <iostream>
#include <vector>
#include <list>
#include <random>

class Prostredi; // Forward deklarace

class Organismus
{
public:
    int x, y;
    int energie;
    Prostredi *prostredi;

    Organismus(int x, int y, Prostredi *prostredi) : x(x), y(y), prostredi(prostredi) {}

    virtual void pohyb() = 0;
    virtual void metabolismus() = 0;
    virtual void rozmnozovani() = 0;
    virtual bool jeZivy() { return energie > 0; }
    virtual void konzumuj(Organismus *other) = 0;
    virtual char getTyp() = 0; // Pro identifikaci typu organismu
};

class Zvire : public Organismus
{
public:
    Zvire(int x, int y, Prostredi *prostredi) : Organismus(x, y, prostredi) {}

    void pohyb() override;
    void metabolismus() override
    {
        energie -= 2;
    }
    virtual void rozmnozovani() = 0;
    virtual void konzumuj(Organismus *other) = 0;
};

class Rostlina : public Organismus
{
public:
    Rostlina(int x, int y, Prostredi *prostredi) : Organismus(x, y, prostredi)
    {
        energie = 10;
    }

    void pohyb() override {}

    void metabolismus() override
    {
        energie += 1;
    }

    void rozmnozovani() override;

    void konzumuj(Organismus *other) override {}
    char getTyp() override { return 'R'; }
};

class Bylozravec : public Zvire
{
public:
    Bylozravec(int x, int y, Prostredi *prostredi) : Zvire(x, y, prostredi)
    {
        energie = 100;
    }

    void konzumuj(Organismus *other) override
    {
        if (other->getTyp() == 'R')
        {
            energie += other->energie;
            other->energie = 0;
        }
    }
    void rozmnozovani() override;
    char getTyp() override { return 'B'; }
};

class Masozravec : public Zvire
{
public:
    Masozravec(int x, int y, Prostredi *prostredi) : Zvire(x, y, prostredi)
    {
        energie = 200;
    }

    void konzumuj(Organismus *other) override
    {
        if (other->getTyp() == 'B')
        {
            energie += other->energie;
            other->energie = 0;
        }
    }
    void rozmnozovani() override;
    char getTyp() override { return 'M'; }
};

class Prostredi
{
public:
    int vyska, sirka;
    std::list<Organismus *> organismy;

    Prostredi(int vyska, int sirka) : vyska(vyska), sirka(sirka) {}

    void krok()
    {
        for (auto it = organismy.begin(); it != organismy.end();)
        {
            (*it)->pohyb();
            (*it)->metabolismus();
            (*it)->rozmnozovani();

            for (auto it2 = organismy.begin(); it2 != organismy.end(); ++it2)
            {
                if (it != it2 && (*it)->x == (*it2)->x && (*it)->y == (*it2)->y)
                {
                    (*it)->konzumuj(*it2);
                }
            }

            if (!(*it)->jeZivy())
            {
                it = organismy.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    template <typename T>
    void pridejOrganismus()
    {
        T *organismus = new T(rand() % sirka, rand() % vyska, this);
        organismy.push_back(organismus);
    }
    template <typename T>
    void pridejOrganismus(int x, int y)
    {
        int new_position_x = std::max(0, std::min(sirka - 1, x + rand() % 3 - 1));
        int new_position_y = std::max(0, std::min(vyska - 1, y + rand() % 3 - 1));

        T *organismus = new T(new_position_x, new_position_y, this);
        organismy.push_back(organismus);
    }

    void odeberOrganismus(Organismus *o)
    {
        organismy.remove(o);
    }

    void vypisStav()
    {
        int pocetRostlin = 0, pocetBylozravcu = 0, pocetMasozravcu = 0;
        for (Organismus *o : organismy)
        {
            switch (o->getTyp())
            {
            case 'R':
                pocetRostlin++;
                break;
            case 'B':
                pocetBylozravcu++;
                break;
            case 'M':
                pocetMasozravcu++;
                break;
            }
        }
        std::cout << "Rostliny: " << pocetRostlin
                  << ", Bylozravci: " << pocetBylozravcu
                  << ", Masozravci: " << pocetMasozravcu << std::endl;
    }
};

// Definice metod Zvire mimo tělo třídy
void Zvire::pohyb()
{
    x = std::max(0, std::min(prostredi->sirka - 1, x + rand() % 3 - 1));
    y = std::max(0, std::min(prostredi->vyska - 1, y + rand() % 3 - 1));
}

void Bylozravec::rozmnozovani()
{
    if (energie > 300)
    {
        int pocetPotomku = rand() % 4;

        for (int i = 0; i < pocetPotomku; ++i)
        {
            prostredi->pridejOrganismus<Bylozravec>(x, y);
            energie /= 2;
        }
    }
}

void Masozravec::rozmnozovani()
{
    if (energie > 500)
    {
        int pocetPotomku = rand() % 2;

        for (int i = 0; i < pocetPotomku; ++i)
        {
            prostredi->pridejOrganismus<Masozravec>(x, y);
            energie /= 2;
        }
    }
}

void Rostlina::rozmnozovani()
{
    if (energie > 30)
    {
        int pocetPotomku = rand() % 10;

        for (int i = 0; i < pocetPotomku; ++i)
        {
            prostredi->pridejOrganismus<Rostlina>();
            energie /= 2;
        }
    }
}

int main()
{
    Prostredi prostredi(20, 20);

    prostredi.pridejOrganismus<Rostlina>();
    prostredi.pridejOrganismus<Rostlina>();
    prostredi.pridejOrganismus<Rostlina>();
    prostredi.pridejOrganismus<Rostlina>();
    prostredi.pridejOrganismus<Rostlina>();
    prostredi.pridejOrganismus<Rostlina>();
    prostredi.pridejOrganismus<Rostlina>();
    prostredi.pridejOrganismus<Rostlina>();

    prostredi.pridejOrganismus<Bylozravec>();
    prostredi.pridejOrganismus<Bylozravec>();
    prostredi.pridejOrganismus<Bylozravec>();
    prostredi.pridejOrganismus<Bylozravec>();

    prostredi.pridejOrganismus<Masozravec>();
    prostredi.pridejOrganismus<Masozravec>();

    prostredi.vypisStav();

    for (int i = 0; i < 50; ++i)
    {
        prostredi.krok();
        prostredi.vypisStav();
    }

    return 0;
}