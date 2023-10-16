#include <iostream>

using namespace std;

void udelej_korunu(int vyska){
    for (int i = 0; i < vyska; i++)
    {
        /*generovani mezer*/
        for (int j = 0; j < vyska-1-i; j++)
        {
            cout<<" ";
        }
        /*generace listu*/
        for (int k = 0; k < 2*i+1; k++)
        {
            cout<<"*";
        }
        
        cout<<endl;
    }


}

void udelej_kmen(int vyska, int sirka, int vyska_stromu){
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
    udelej_korunu(5);
    udelej_kmen(3,3,5);
    return 0;
}