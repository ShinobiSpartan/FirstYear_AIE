#include "Matrix4.h"
#include <math.h>



Matrix4::Matrix4()
{
	m_xAxis = { 1, 0, 0, 0 };
	m_yAxis = { 0, 1, 0, 0 };
	m_zAxis = { 0, 0, 1, 0 };
	m_wAxis = { 0, 0, 0, 1 };
}

Matrix4::Matrix4(float a_x, float a_y, float a_z, float a_w, float b_x, float b_y, float b_z, float b_w, float c_x, float c_y, float c_z, float c_w, float d_x, float d_y, float d_z, float d_w)
{
	m[0] = a_x;
	m[1] = a_y;
	m[2] = a_z;
	m[3] = a_w;
	m[4] = b_x;
	m[5] = b_y;
	m[6] = b_z;
	m[7] = b_w;
	m[8] = c_x;
	m[9] = c_y;
	m[10] = c_z;
	m[11] = c_w;
	m[12] = d_x;
	m[13] = d_y;
	m[14] = d_z;
	m[15] = d_w;
}

Matrix4::Matrix4(const Matrix4 & other)
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
	m[9] = other.m[9];
	m[10] = other.m[10];
	m[11] = other.m[11];
	m[12] = other.m[12];
	m[13] = other.m[13];
	m[14] = other.m[14];
	m[15] = other.m[15];
}

Vector4& Matrix4::operator[](int index)
{
	return m_axis[index];
}

Matrix4::operator float*()
{
	return m;
}

Matrix4 Matrix4::operator*(const Matrix4 & a_mat) const
{
	Matrix4 result;

	for (int matR = 0; matR < 3; ++matR)
	{
		for (int matC = 0; matC < 3; ++matC)
		{
			result.m_data[matR][matC] = m_data[0][matC] * a_mat.m_data[matR][0]
									  + m_data[1][matC] * a_mat.m_data[matR][1]
									  + m_data[2][matC] * a_mat.m_data[matR][2]
									  + m_data[3][matC] * a_mat.m_data[matR][3];
		}
	}
	return result;
}

Vector4 Matrix4::operator*(const Vector4 & a_vec) const
{
	return { m[0] * a_vec.m_x + m[4] * a_vec.m_y + m[8] * a_vec.m_z + m[12] * a_vec.m_w,
			 m[1] * a_vec.m_x + m[5] * a_vec.m_y + m[9] * a_vec.m_z + m[13] * a_vec.m_w,
			 m[2] * a_vec.m_x + m[6] * a_vec.m_y + m[10] * a_vec.m_z + m[14] * a_vec.m_w,
			 m[3] * a_vec.m_x + m[7] * a_vec.m_y + m[11] * a_vec.m_z + m[15] * a_vec.m_w };
}

void Matrix4::setRotateX(float radians)
{
	m_xAxis = { 1, 0, 0, 0 };
	m_yAxis = { 0, cosf(radians), sinf(radians), 0 };
	m_zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	m_wAxis = { m[3], m[7], m[11], m[15] };
}

void Matrix4::setRotateY(float radians)
{
	m_xAxis = { cosf(radians), 0 , -sinf(radians), 0 };
	m_yAxis = { 0, 1, 0, 0 };
	m_zAxis = { sinf(radians), 0, cosf(radians), 0 };
	m_wAxis = { m[3], m[7], m[11], m[15] };
}

void Matrix4::setRotateZ(float radians)
{
	m_xAxis = { cosf(radians), sinf(radians), 0, 0 };
	m_yAxis = { -sinf(radians), cosf(radians), 0, 0 };
	m_zAxis = { 0, 0, 1, 0 };
	m_wAxis = { m[3], m[7], m[11], m[15] };
}

Matrix4::~Matrix4()
{
}
