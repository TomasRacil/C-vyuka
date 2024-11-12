#include <iostream>

using namespace std;

void Secti(int a, int b, int *vysledek);

int main()
{

	// Z�kladn� uk�zka

	int n = 1004;
	char c = 'n';
	cout << &n << endl;
	int *p = &n;
	char *f = &c;

	/*printf("hodnota n=%d hodnota c=%c\n", n, c);
	printf("pointer na cislo=%p pointer na znak=%p\n", p, f);*/
	printf("hodnota n=%d hodnota c=%c\n", *p, *f);
	printf("pointer na cislo=%p pointer na znak=%p\n", &n, &c);

	int *u;

	// inicializace
	u = new int;
	// nebo
	// u = (int*)malloc(sizeof(int));
	// nebo
	// u = &n;

	*u = 2022; // dereferencing

	printf("\npointer u=%p, cislo *u=%d\n", u, *u);

	// uvoln�n� pam�ti ukazatele
	delete u; // alokov�n dynamicky (heap)
	////nebo
	// free(u);
	//
	// free(p); //nebyl dynamicky alokov�n delete/free nebude fungovat (stack)

	// ukazatele na ukazatele

	int *a;
	int **b;

	b = &a;

	*b = &n;

	printf("\nhodnota cisla n=%d", n);
	printf("\nadresa cisla n=%p", &n);
	printf("\nhodnota ukazatele a=%p", a);
	printf("\nadresa ukazatele a=%p", &a);
	printf("\nhodnota ukaztele b=%p\n", b);

	**b = 50; // zm�na hodnoty ��sla n p�es dvojit� dereferencing
	printf("hodnota cisla n po zmene=%d\n", n);

	// predavani parametru do funkci

	int x = 5;
	int y = 6;
	int vysledek;

	Secti(x, y, &vysledek);

	printf("Vysledek je : % d", vysledek);

	// https://www.geeksforgeeks.org/smart-pointers-cpp/ Smart pointers

	return 0;
}

void Secti(int a, int b, int *vysledek)
{

	*vysledek = a + b;
}