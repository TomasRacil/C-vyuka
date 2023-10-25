#include <iostream>

void prohodPromene(int* a, int* b);

int main(){
    int a = 1, b = 2;

    std::cout<<"a: "<<a<<" b: "<<b<<std::endl;

    prohodPromene(&a,&b);

    std::cout<<"a: "<<a<<" b: "<<b<<std::endl;

    return 0;
}

void prohodPromene(int* a, int* b){
    // int temp = *a;
    // *a=*b;
    // *b=temp;

    *a += *b;
	*b = *a-*b;
	*a -= *b;
}