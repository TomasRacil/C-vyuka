#pragma once
#include <string>
#include <iostream>
class Vector
{
private:
	std::string name;
	double x;
	double y;
	double z;
public:
	Vector(std::string name, double x, double y, double z);
	Vector operator + (Vector const& obj);
	Vector operator - (Vector const& obj);
	Vector operator * (Vector const& obj);
	Vector operator * (double const& obj);
	bool operator < (Vector& obj);
	bool operator > (Vector& obj);
	bool operator == (Vector& obj);
	double vector_size();
	friend std::ostream& operator<<(std::ostream& out, Vector& m);
	friend class VectorGroup;

};

