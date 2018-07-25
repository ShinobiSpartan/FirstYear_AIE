#pragma once
#include "Vector2.h"
class Matrix2
{
public:
	union {
		struct {
			Vector2 m_xAxis, m_yAxis;
		};
		Vector2 m_axis[2];
		float m[4], m_data[2][2];
	};

	Matrix2();
	Matrix2( float a_x, float a_y,
			 float b_x, float b_y );
	Matrix2(const Matrix2 & other);

	Vector2& operator [] (const int index);

	explicit operator float* ();

	Matrix2 operator *(const Matrix2& a_mat) const;
	Vector2 operator *(const Vector2& a_vec) const;
	
	void setRotate(const float scalar);
	
	~Matrix2();
};

