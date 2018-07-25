#include "Matrix2.h"
#include <math.h>


Matrix2::Matrix2()
{
	m_xAxis = { 1, 0 };
	m_yAxis = { 0, 1 };
}

Matrix2::Matrix2(float a_x, float a_y, float b_x, float b_y)
{
	m[0] = a_x;
	m[1] = a_y;
	m[2] = b_x;
	m[3] = b_y;
}

Matrix2::Matrix2(const Matrix2 & other)
{
	m[0] = other.m[0];
	m[1] = other.m[1];
	m[2] = other.m[2];
	m[3] = other.m[3];
}

Vector2& Matrix2::operator[](const int index)
{
	return m_axis[index];
}

Matrix2::operator float*()
{
	return m;
}

// [0][2] * [0][2]
// [1][3]   [1][3]
Matrix2 Matrix2::operator*(const Matrix2 & a_mat) const
{
	return { m[0] * a_mat.m[0] + m[1] * a_mat.m[2],		// 0 = (0 * 0) + (1 * 2)
			 m[0] * a_mat.m[1] + m[1] * a_mat.m[3],		// 1 = (0 * 1) + (1 * 3)
			 m[2] * a_mat.m[0] + m[3] * a_mat.m[2],		// 2 = (2 * 0) + (3 * 2)
			 m[2] * a_mat.m[1] + m[3] * a_mat.m[3] };	// 3 = (2 * 1) + (3 * 3)
}

Vector2 Matrix2::operator*(const Vector2 & a_vec) const
{
	return { m[0] * a_vec.m_x + m[2] * a_vec.m_y,
			 m[1] * a_vec.m_x + m[3] * a_vec.m_y };
}


void Matrix2::setRotate(const float scalar)
{
	m_xAxis = { cosf(scalar), sinf(scalar) };
	m_yAxis = { -sinf(scalar), cosf(scalar) };
}

Matrix2::~Matrix2()
{
}
