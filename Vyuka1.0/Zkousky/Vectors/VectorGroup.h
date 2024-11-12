#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Vector.h"

class VectorGroup
{
private:
	std::vector<Vector> vectors;
public:
	VectorGroup(std::string path);
	void add_vector(Vector vector);
	Vector get_vector(int idx);
	Vector get_vector(std::string name);
	Vector sum_all_vectors();
	friend std::ostream& operator<<(std::ostream& out, VectorGroup& m);
};

