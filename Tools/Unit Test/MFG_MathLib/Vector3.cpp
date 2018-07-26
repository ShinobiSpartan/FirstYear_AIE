#include "Vector3.h"
#include <math.h>

Vector3::Vector3()
{
}

Vector3::Vector3(float x, float y, float z) : m_x(x), m_y(y), m_z(z)
{
}

Vector3 Vector3::operator+(Vector3 other)
{
	return { m_x + other.m_x, m_y + other.m_y, m_z + other.m_z };
}

Vector3 Vector3::operator-(Vector3 other)
{
	return { m_x - other.m_x, m_y - other.m_y, m_z - other.m_z };
}

Vector3 Vector3::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar, m_z * scalar };
}

Vector3 Vector3::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar, m_z / scalar };
}

Vector3 Vector3::operator+=(const Vector3 & other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
	return *this;
}

Vector3::operator float*()
{
	return &m_x;
}

float Vector3::magnitude()
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

void Vector3::normalise()
{
	float m = sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	m_x /= m;
	m_y /= m;
	m_z /= m;
}

Vector3 Vector3::cross(Vector3 other)
{
return {	m_y*other.m_z - m_z * other.m_y,
			m_z*other.m_x - m_x * other.m_z,
			m_x*other.m_y - m_y * other.m_x		};
}

float Vector3::dot(const Vector3& other)
{
	return { m_x * other.m_x + m_y * other.m_y + m_z * other.m_z };
}


Vector3::~Vector3()
{
}

Vector3 operator*(float scalar, const Vector3 & other)
{
	return { scalar * other.m_x, scalar * other.m_y, scalar * other.m_z };
}
