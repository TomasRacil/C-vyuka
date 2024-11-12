#include "Vector.h"

Vector::Vector(std::string name, double x, double y, double z)
{
	this->name = name;
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector Vector::operator+(Vector const& obj)
{
	return Vector(name + "+" + obj.name, x + obj.x, y + obj.y, z + obj.z);
}

Vector Vector::operator-(Vector const& obj)
{
	return Vector(name + "-" + obj.name, x - obj.x, y - obj.y, z - obj.z);
}

Vector Vector::operator*(Vector const& obj)
{
	std::string new_name = name + " x " + obj.name;
	double new_x = y * obj.z - z * obj.y;
	double new_y = z * obj.x - x * obj.z;
	double new_z = x * obj.y - y * obj.x;
	return Vector(new_name, new_x, new_y, new_z);
}

Vector Vector::operator*(double const& obj)
{
	return Vector(name + "*" + std::to_string(obj), x * obj, y * obj, z * obj);
}

bool Vector::operator<(Vector& obj)
{
	if (this->vector_size() < obj.vector_size()) return true;
	return false;
}

bool Vector::operator>(Vector& obj)
{
	if (this->vector_size() > obj.vector_size()) return true;
	return false;
}

bool Vector::operator==(Vector& obj)
{
	if (this->vector_size() == obj.vector_size()) return true;
	return false;
}

double Vector::vector_size()
{
	return std::sqrt(x * x + y * y + z * z);
}

std::ostream& operator<<(std::ostream& out, Vector& m)
{
	out << "Vektor " + m.name + "(" + std::to_string(m.x) + ", " + std::to_string(m.y) + ", " << std::to_string(m.z) + ") |" + m.name + "| = " + std::to_string(m.vector_size()) + "\n";
	return out;
}
