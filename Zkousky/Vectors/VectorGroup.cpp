#include "VectorGroup.h"

VectorGroup::VectorGroup(std::string path)
{
	std::ifstream file;
	file.open(path);
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string item;
		std::vector<std::string> elems;
		while (std::getline(ss, item, ';')) {
			elems.push_back(item);
		}
		vectors.push_back(Vector(elems[0], std::stof(elems[1]), std::stof(elems[2]), std::stof(elems[3])));
	}
	sort(vectors.begin(), vectors.end());
}

void VectorGroup::add_vector(Vector vector)
{
	vectors.push_back(vector);
	sort(vectors.begin(), vectors.end());
}

Vector VectorGroup::get_vector(int idx)
{
	return vectors[idx];
}

Vector VectorGroup::get_vector(std::string name)
{
	for (Vector v : vectors) {
		if (v.name == name) return v;
	}
}

Vector VectorGroup::sum_all_vectors()
{
	Vector sum = Vector("0", 0, 0, 0);
	for (Vector v : vectors) {
		sum = sum + v;
	}
	return sum;
}

std::ostream& operator<<(std::ostream& out, VectorGroup& m)
{
	for (Vector v : m.vectors) {
		out << v;
	}
	return out;
}
