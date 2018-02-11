#include "vector.hpp"

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

namespace ATP
{
	namespace Math
	{
		Vector Vector::Null(0,0,0);
		Vector Vector::X(1,0,0);
		Vector Vector::Y(0,1,0);
		Vector Vector::Z(0,0,1);

		Vector::Vector(void)
		{
			x=0.0;
			y=0.0;
			z=0.0;
		}
		
		Vector::Vector(float x1, float y1, float z1)
		{
			x=x1;
			y=y1;
			z=z1;
		}
		
		//-------------------------------------------------------------------//
		
		//--Dot Product--//
		float operator *(const class Vector &v1,const class Vector &v2)
		{
			return(v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
		}
		
		//--Cross Product--//
		Vector operator ^(const Vector &v1,const Vector &v2)
		{
			Vector temp;
		
			temp.x=v1.y*v2.z - v1.z*v2.y;
			temp.y=v1.z*v2.x - v1.x*v2.z;
			temp.z=v1.x*v2.y - v1.y*v2.x;
			return temp;
		}
		
		Vector& Vector::operator =(const Vector &v)
		{
			x=v.x;
			y=v.y;
			z=v.z;
			return *this;
		}
		
		Vector operator *(const Vector &v, float d)
		{
			Vector temp;
		
			temp.x=v.x*d;
			temp.y=v.y*d;
			temp.z=v.z*d;
			return temp;
		}
		
		Vector operator *(float d, const Vector &v)
		{
			Vector temp;
		
			temp.x=v.x*d;
			temp.y=v.y*d;
			temp.z=v.z*d;
			return temp;
		}
		
		Vector operator /(const Vector &v, float d)
		{
			Vector temp;
		
		    temp.x=v.x/d;
		    temp.y=v.y/d;
		    temp.z=v.z/d;
		    return temp;
		}
		
		Vector& Vector::operator /=(float d)
		{
			x/=d;
			y/=d;
			z/=d;
			return *this;
		}
		
		Vector& Vector::operator *=(float d)
		{
			x*=d;
			y*=d;
			z*=d;
			return *this;
		}
		
		Vector operator -(const Vector &v1,const Vector &v2)
		{
			Vector temp;
		
			temp.x=v1.x - v2.x;
			temp.y=v1.y - v2.y;
			temp.z=v1.z - v2.z;
			return temp;
		}
		
		Vector& Vector::operator -=(const Vector &v)
		{
			x-=v.x;
			y-=v.y;
			z-=v.z;
			return *this;
		}
		
		Vector operator +(const Vector &v1,const Vector &v2)
		{
			Vector temp;
		
			temp.x=v1.x + v2.x;
			temp.y=v1.y + v2.y;
			temp.z=v1.z + v2.z;
			return temp;
		}
		
		Vector& Vector::operator +=(const Vector &v)
		{
			x+=v.x;
			y+=v.y;
			z+=v.z;
			return *this;
		}
		
		bool operator ==(const Vector &v1, const Vector &v2)
		{
			return fabs((v1-v2).length()) < 0.0000001;
		}
		
		bool operator !=(const Vector &v1, const Vector &v2)
		{
			return !(v1==v2);
		}
		
		//---------------------------------------------------------------------//
		
		float Random(float min, float max)
		{
			return (float)rand()/(float)RAND_MAX*(max-min)+min;
		}
		
		//--Random unit Vectors--//
		//-------IMPROVE!-------//
		Vector Vector::random(float length)
		{
		 Vector temp;
		 float theta1,theta2;
		
		 //Random direction
		 theta1=Random(0.0f,2.0f*(float)M_PI);
		 theta2=Random(-(float)M_PI/2.0f,(float)M_PI/2.0f);
		
		 //Set the components
		 temp.x=cos(theta1)*cos(theta2);
		 temp.y=sin(theta2);
		 temp.z=sin(theta1)*cos(theta2);
		 return temp*length;
		}
		
		
		Vector Vector::midpoint(const Vector &v1,const Vector &v2)
		{
			return (v1+v2)/2.0;
		}
		
		Vector Vector::project(const Vector &v2)
		{
			return (((*this)*v2)/v2.length2())*v2;
		}
		
		Vector Vector::perpendicular(const Vector &v2)
		{
			return (*this) - project(v2);
		}
		
		Vector Vector::normalize() const
		{
			if(length() > 0.0f)
		    	        return (*this)/length();
		        else
		    	        return (*this);
		}
		
		Vector Vector::rotate(const Vector &axis, float angle) const
		{
			Vector temp=*this;
			if(axis.length2() < 0.00000000001) return temp;

			Vector proj=temp.project(axis);
			Vector right=temp-proj;
			Vector up=(axis^right).normalize();
			up=right.length()*sin(angle)*up;
			right=cos(angle)*right;
			temp=up+right+proj;
			return temp;
		}

		Vector Vector::rotateTo(const Vector goal, float amount) const
		{
			return rotate((*this)^goal,acos((*this)*goal)*amount);
		}

		float Vector::theta()
		{
			return acos(normalize().z);
		}

		float Vector::psi()
		{
			return atan2(normalize().y,normalize().x);
		}
	}
}
