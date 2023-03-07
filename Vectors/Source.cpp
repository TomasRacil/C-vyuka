#include <iostream>
#include <list>
#include <string.h>
#include "Vector.h"
#include "VectorGroup.h"

using namespace std;




int main()
{
	VectorGroup g = VectorGroup("vectors.txt");
	g.add_vector(Vector("n", 7.3, 6.9, -3.5));
	std::cout << g;
	Vector sum = g.sum_all_vectors();
	std::cout << sum;
	Vector neg = g.get_vector(0) - g.get_vector(1);
	std::cout << neg;
	Vector u = g.get_vector("u");
	Vector v = g.get_vector("v");
	Vector uv = (u * v);
	std::cout << uv;
	Vector u2 = (u * 2);
	std::cout << u2;
	std::cout << (u == v);
}


