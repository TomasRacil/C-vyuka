#include <iostream>

using namespace std;

void Secti(int a, int b, int* vysledek);

int main() {

	//Základní ukázka

	int n = 1004;
	char c = 'n';
	int* p = &n; 
	char* f = &c; 


	/*printf("hodnota n=%d hodnota c=%c\n", n, c);
	printf("pointer na cislo=%p pointer na znak=%p\n", p, f);*/
	printf("hodnota n=%d hodnota c=%c\n",*p, *f);
	printf("pointer na cislo=%p pointer na znak=%p\n", &n, &c);


	int* u;

	//inicializace
	u = new int; 
	//nebo
	//u = (int*)malloc(sizeof(int));
	//nebo
	//u = &n;
	
	*u = 2022; //dereferencing

	printf("\npointer u=%p, cislo a=%d\n", u,*u);

	//uvolnìní pamìti ukazatele
	delete u; //alokován dynamicky (heap)
	////nebo
	//free(u);
	// 
	//free(p); //nebyl dynamicky alokován delete/free nebude fungovat (stack)


	//ukazatele na ukazatele

	int* a;
	int** b;

	b = &a;

	*b = &n;

	printf("\nhodnota cisla n=%d",n);
	printf("\nadresa cisla n=%p", &n);
	printf("\nhodnota ukazatele a=%p", a);
	printf("\nadresa ukazatele a=%p", &a);
	printf("\nhodnota ukaztele b=%p\n", b);


	**b = 50; //zmìna hodnoty èísla n pøes dvojitý dereferencing
	printf("hodnota cisla n po zmene=%d\n", n);

	//predavani parametru do funkci

	int x = 5;
	int y = 6;
	int vysledek;

	Secti(x, y, &vysledek);

	printf("Vysledek je : % d", vysledek);


	//https://www.geeksforgeeks.org/smart-pointers-cpp/ Smart pointers

	return 0;
}

void Secti(int a, int b, int* vysledek) {

	*vysledek = a + b;
}