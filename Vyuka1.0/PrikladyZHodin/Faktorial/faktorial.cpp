#include <iostream>

using namespace std;


int main(){
    int cislo = 5;
    int faktorial = 1;
    for (int i = 2; i <= cislo; i++)
    {
        faktorial*=i;
    }
    cout<<faktorial<<endl;
    
    return 0;
}
