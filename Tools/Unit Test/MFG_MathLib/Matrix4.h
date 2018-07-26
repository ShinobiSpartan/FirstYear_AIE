#pragma once
#include "Vector4.h"
class Matrix4
{
public:
	union {
		struct {
			Vector4 m_xAxis, m_yAxis, m_zAxis, m_wAxis;
		};
		Vector4 m_axis[3];
		float m[16], m_data[4][4];
	};

	Matrix4();
	Matrix4( float a_x, float a_y, float a_z, float a_w,
			 float b_x, float b_y, float b_z, float b_w,
			 float c_x, float c_y, float c_z, float c_w,
			 float d_x, float d_y, float d_z, float d_w );
	Matrix4(const Matrix4 & other);

	Vector4& operator [] (int index);

	explicit operator float* ();

	Matrix4 operator *(const Matrix4& a_mat) const;
	Vector4 operator *(const Vector4& a_vec) const;
	
	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);
	
	~Matrix4();
};

