#include <iostream>

using namespace std;

void koruna(int vyska){
    for (int i = 0; i < vyska; i++)
    {
        for (int j = 0; j < vyska-1-i; j++)
        {
            cout<<" ";
        }
        for (int k = 0; k < 2*i+1; k++)
        {
            cout<<"*";
        }
        
        cout<<endl;
    }
}

void kmen(int vyska, int sirka, int vyska_stromu){
    for (int i = 0; i < vyska; i++)
    {
        for (int k = 0; k < vyska_stromu-1-sirka/2; k++)
        {
            cout<<" ";
        }
        
        for (int j = 0; j < sirka; j++)
        {
            cout<<"#";
        }
        
        cout<<endl;
    } 
}

int main()
{
    int vyska, vyska_kmen, sirka;

    cout << "Zadejte vysku koruny: ";
    cin >> vyska;
    cout << "Zadejte vysku kmene: ";
    cin >> vyska_kmen;
    cout << "Zadejte sirku kmene: ";
    cin >> sirka;

    koruna(vyska);
    kmen(vyska_kmen, sirka, vyska);
    return 0;
}