#ifndef MATH_VECTOR
#define MATH_VECTOR

#ifndef ATP_LIB
#pragma comment(lib, "atp-vector.lib")
#endif

#include <vector>

#include <math.h>
#include <iostream>
#include <fstream>
#include <string>

namespace ATP
{
	namespace Math
	{
		class Vector
		{
			public:
				//Related type definitions
				typedef std::vector<Vector> List;

				//Standard vectors
				static Vector Null;
				static Vector X;
				static Vector Y;
				static Vector Z;

				//Static functions
				static Vector random(float length);
				static Vector midpoint(const Vector &v1, const Vector &v2);

				Vector();
				Vector(float x1, float y1, float z1);
				
		        void Set(float x1, float y1, float z1){x=x1;y=y1;z=z1;}
		
				Vector& operator =(const Vector &v);
				Vector& operator +=(const Vector &v);
				Vector& operator -=(const Vector &v);
		
				//Scalar multiplication/division
				Vector& operator *=(float d);
				Vector& operator /=(float d);
		        friend Vector operator * (const Vector &v, float d);
				friend Vector operator * (float d, const Vector &v);
				friend Vector operator / (const Vector &v, float d);
		
		        //Length-related
				float length() const{return sqrt(length2());};
		        float length2() const{return x*x + y*y + z*z;};
		        Vector normalize() const;

				//Rotation
		        Vector rotate(const Vector &axis, float angle) const;
				Vector rotateTo(const Vector goal, float amount) const;

				//Spherical coordinates
				float psi();
				float theta();

				//Vector addition/subtraction
		        friend Vector operator - (const Vector &v1, const Vector &v2);
				friend Vector operator + (const Vector &v1, const Vector &v2);
		
				//Vector dot(*)/cross(^) product
		        friend float operator *(const Vector &v1,const Vector &v2);
				friend Vector operator ^(const Vector &v1,const Vector &v2);
		
				//Comparison
		        friend bool operator ==(const Vector &v1, const Vector &v2);
				friend bool operator !=(const Vector &v1, const Vector &v2);
		
				//Other
				Vector project(const Vector &v2);
				Vector perpendicular(const Vector &v2);

				float x;
				float y;
				float z;
		};
	}
}

#endif
