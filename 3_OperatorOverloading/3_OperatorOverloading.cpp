#include <iostream>
#include "Matrix.h"


int main()
{
	int rows, cols;

	std::cout << "Zadej pocet radku a sloupcu matice A: " << std::endl;
	std::cin >> rows >> cols;
	Matrix A(rows, cols);

	std::cout << "Zadej pocet radku a sloupcu matice B: " << std::endl;
	std::cin >> rows >> cols;
	Matrix B(rows, cols);

	bool run = true;

	while (run)
	{
		std::cout << "Zadej operaci k provedeni 0-Zobraz matice; 1-Secti matice; 2-Vynasob skalrem; 3-vynasob mezi sebou; 4 - odecti matice; 5- ukonci program: " << std::endl;
		int option;
		std::cin >> option;
		std::cout << std::endl;
		switch (option) {
		case 0:
		{
			std::cout<<A<<B;
			break;
		}
		case 1:
		{
			try {
				std::cout << (A + B);
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}
			break;
		}
		case 2:
		{
			int sclr;
			std::cout << "Zadej skalar: ";
			std::cin >> sclr;
			try {
				std::cout << (A * sclr);
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}
			break;
		}
		case 3:
		{
			try {
				std::cout << (A * B);
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}
			break;
		}
		case 4:
		{
			try {
				std::cout << (A - B);
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}
			break;
		}
		case 5:
		{
			run = false;
			break;
		}

		}
	}
	std::cin >> A;
	std::cout << A;

}
