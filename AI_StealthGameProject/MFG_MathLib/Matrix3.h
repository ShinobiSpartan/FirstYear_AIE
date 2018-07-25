#pragma once
#include "Vector3.h"
class Matrix3
{
public:
	union {
		struct {
			Vector3 m_xAxis, m_yAxis;
			union {
				Vector3 m_zAxis, m_wAxis;
			};
		};
		Vector3 m_axis[3];
		float m[9], m_data[3][3];
	};

	Matrix3();
	Matrix3( float a_x, float a_y, float a_z,
			 float b_x, float b_y, float b_z,
			 float c_x, float c_y, float c_z );
	Matrix3(const Matrix3 & other);

	Vector3& operator [] (int index);

	explicit operator float* ();

	Matrix3 operator *(const Matrix3& a_mat) const;
	Vector3 operator *(const Vector3& a_vec) const;

	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);

	void setScaled(float x, float y, float z);
	void scale(float x, float y, float z);

	void translate(float x, float y, float z);

	~Matrix3();
};

