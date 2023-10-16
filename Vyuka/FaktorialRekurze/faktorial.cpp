#include <iostream> 

using namespace std;

int faktorial(int cislo){
    if (cislo == 1) return 1;
    else return faktorial(cislo-1)*cislo;
}

int main(){
    cout<< faktorial(5)<<endl;
    return 0;
}