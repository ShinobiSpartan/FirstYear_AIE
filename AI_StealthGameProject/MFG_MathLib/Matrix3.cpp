#include "Matrix3.h"
#include <math.h>


Matrix3::Matrix3()
{
	m_xAxis = { 1, 0, 0 };
	m_yAxis = { 0, 1, 0 };
	m_zAxis = { 0, 0, 1 };
}

Matrix3::Matrix3(float a_x, float a_y, float a_z, float b_x, float b_y, float b_z, float c_x, float c_y, float c_z)
{
	m[0] = a_x;
	m[1] = a_y;
	m[2] = a_z;
	m[3] = b_x;
	m[4] = b_y;
	m[5] = b_z;
	m[6] = c_x;
	m[7] = c_y;
	m[8] = c_z;
}

Matrix3::Matrix3(const Matrix3 & other)
{
	m[0] = other.m[0];
	m[1] = other.m[1];
	m[2] = other.m[2];
	m[3] = other.m[3];
	m[4] = other.m[4];
	m[5] = other.m[5];
	m[6] = other.m[6];
	m[7] = other.m[7];
	m[8] = other.m[8];
}

Vector3& Matrix3::operator[](int index)
{
	return m_axis[index];
}

Matrix3::operator float*()
{
	return m;
}

Matrix3 Matrix3::operator*(const Matrix3 & a_mat) const
{
	Matrix3 result;

	for (int matR = 0; matR < 3; ++matR)
	{
		for (int matC = 0; matC < 3; ++matC)
		{
			result.m_data[matR][matC] = m_data[0][matC] * a_mat.m_data[matR][0]
									  + m_data[1][matC] * a_mat.m_data[matR][1]
									  + m_data[2][matC] * a_mat.m_data[matR][2];
		}
	}
	return result;
}

Vector3 Matrix3::operator*(const Vector3 & a_vec) const
{
	return { m[0] * a_vec.m_x + m[3] * a_vec.m_y + m[6] * a_vec.m_z,
			 m[1] * a_vec.m_x + m[4] * a_vec.m_y + m[7] * a_vec.m_z,
			 m[2] * a_vec.m_x + m[5] * a_vec.m_y + m[8] * a_vec.m_z };
}

void Matrix3::setRotateX(float radians)
{
	m_xAxis = { 1, 0, 0 };
	m_yAxis = { 0, cosf(radians), sinf(radians) };
	m_zAxis = { 0, -sinf(radians), cosf(radians) };
}

void Matrix3::setRotateY(float radians)
{
	m_xAxis = { cosf(radians), 0 , -sinf(radians) };
	m_yAxis = { 0, 1, 0 };
	m_zAxis = { sinf(radians), 0, cosf(radians) };
}

void Matrix3::setRotateZ(float radians)
{
	m_xAxis = { cosf(radians), sinf(radians), 0 };
	m_yAxis = { -sinf(radians), cosf(radians), 0 };
	m_zAxis = { 0, 0, 1 };
}

void Matrix3::rotateX(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);

	*this = *this * m;
}

void Matrix3::rotateY(float radians)
{
	Matrix3 m;
	m.setRotateY(radians);

	*this = *this * m;
}

void Matrix3::rotateZ(float radians)
{
	Matrix3 m;
	m.setRotateZ(radians);

	*this = *this * m;
}

void Matrix3::setScaled(float x, float y, float z)
{
	// set scale of each axis
	m_xAxis = { x, 0, 0 };
	m_yAxis = { 0, y, 0 };
	m_zAxis = { 0, 0, z };
}

void Matrix3::scale(float x, float y, float z)
{
	Matrix3 m;
	m.setScaled(x, y, z);

	*this = *this * m;
}

void Matrix3::translate(float x, float y, float z)
{
	m_wAxis += Vector3(x, y, z);
}

Matrix3::~Matrix3()
{
}
