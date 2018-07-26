#include "Vector4.h"
#include <math.h>



Vector4::Vector4()
{
}

Vector4::Vector4(float x, float y, float z, float w) : m_x(x), m_y(y), m_z(z), m_w(w)
{
}

Vector4 Vector4::operator+(Vector4 other)
{
	return { m_x + other.m_x, m_y + other.m_y, m_z + other.m_z, m_w + other.m_w };
}

Vector4 Vector4::operator-(Vector4 other)
{
	return { m_x - other.m_x, m_y - other.m_y, m_z - other.m_z, m_w - other.m_w };
}

Vector4 Vector4::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar, m_z * scalar, m_w * scalar };
}

Vector4 Vector4::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar, m_z / scalar, m_w / scalar };
}

Vector4::operator float*()
{
	return &m_x;
}

float Vector4::magnitude()
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
}

void Vector4::normalise()
{
	float m = sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
	m_x /= m;
	m_y /= m;
	m_z /= m;
	m_w /= m;
}

Vector4 Vector4::cross(Vector4 other)
{
	return	{	m_y*other.m_z - m_z * other.m_y,
				m_z*other.m_x - m_x * other.m_z,
				m_x*other.m_y - m_y * other.m_x,
				0									};
}

float Vector4::dot(const Vector4 & other)
{
	return { m_x * other.m_x + m_y * other.m_y + m_z * other.m_z + m_w * other.m_w };
}


Vector4::~Vector4()
{
}

Vector4 operator*(float scalar, const Vector4 & other)
{
	return { scalar * other.m_x, scalar * other.m_y, scalar * other.m_z, scalar * other.m_w };
}
