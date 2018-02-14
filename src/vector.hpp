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
				static Vector random(double length);
				static Vector midpoint(const Vector &v1, const Vector &v2);

				Vector();
				Vector(double x1, double y1, double z1);
				
		        void Set(double x1, double y1, double z1){x=x1;y=y1;z=z1;}
		
				Vector& operator =(const Vector &v);
				Vector& operator +=(const Vector &v);
				Vector& operator -=(const Vector &v);
		
				//Scalar multiplication/division
				Vector& operator *=(double d);
				Vector& operator /=(double d);
		        friend Vector operator * (const Vector &v, double d);
				friend Vector operator * (double d, const Vector &v);
				friend Vector operator / (const Vector &v, double d);
		
		        //Length-related
				double length() const{return sqrt(length2());};
		        double length2() const{return x*x + y*y + z*z;};
		        Vector normalize() const;

				//Rotation
		        Vector rotate(const Vector &axis, double angle) const;
				Vector rotateTo(const Vector goal, double amount) const;

				//Spherical coordinates
				double psi();
				double theta();

				//Vector addition/subtraction
		        friend Vector operator - (const Vector &v1, const Vector &v2);
				friend Vector operator + (const Vector &v1, const Vector &v2);
		
				//Vector dot(*)/cross(^) product
		        friend double operator *(const Vector &v1,const Vector &v2);
				friend Vector operator ^(const Vector &v1,const Vector &v2);
		
				//Comparison
		        friend bool operator ==(const Vector &v1, const Vector &v2);
				friend bool operator !=(const Vector &v1, const Vector &v2);
		
				//Other
				Vector project(const Vector &v2);
				Vector perpendicular(const Vector &v2);

				double x;
				double y;
				double z;
		};
	}
}

#endif
