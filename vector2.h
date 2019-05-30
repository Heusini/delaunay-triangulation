#ifndef H_VECTOR2
#define H_VECTOR2

#include "numeric.h"

#include <iostream>
#include <cmath>

template <typename T>
class Vector2
{
	public:
		//
		// Constructors
		//

		Vector2():x(0), y(0), color(-10){}

		Vector2(T _x, T _y, int _color): x(_x), y(_y), color(_color), curvature(0){}
    Vector2(T _x, T _y): x(_x), y(_y),color(-10), curvature(0){}

		Vector2(const Vector2 &v): x(v.x), y(v.y), color(v.color), curvature(v.curvature){}

		//
		// Operations
		//
		T dist2(const Vector2 &v) const
		{
			T dx = x - v.x;
			T dy = y - v.y;
			return dx * dx + dy * dy;
		}

		T dist(const Vector2 &v) const
		{
			return sqrt(dist2(v));
		}

		T norm2() const
		{
			return x * x + y * y;
		}
    
    

    T norm() const
    {
      return hypot(x,y);
    }
    double crossproduct(const Vector2<double> &v1);
    double scalar(const Vector2<double> &v);

		T x;
		T y;
    int color;
    double curvature;
};


template <>
float Vector2<float>::dist(const Vector2<float> &v) const { return hypotf(x - v.x, y - v.y);}

template <>
double Vector2<double>::dist(const Vector2<double> &v) const { return hypot(x - v.x, y - v.y);}

template <>
double Vector2<double>::scalar(const Vector2<double> &v)
{
  return x * v.x + y * v.y;
}
template <>
double Vector2<double>::crossproduct(const Vector2<double> &v)
{
  return x * v.y - y * v.x;
}

template<typename T>
std::ostream &operator << (std::ostream &str, Vector2<T> const &point)
{
	return str << "Point x: " << point.x << " y: " << point.y << " curvature: " << point.curvature;
}

template<typename T>
bool operator == (const Vector2<T>& v1, const Vector2<T>& v2)
{
	return (v1.x == v2.x) && (v1.y == v2.y);
}

template <typename T>
Vector2<T> operator + (const Vector2<T> &v1, const Vector2<T>&v2)
{
  return Vector2<T>(v1.x+v2.x, v1.y+v2.y);
}

template <typename T>
Vector2<T> operator - (const Vector2<T> &v1, const Vector2<T>&v2)
{
  return Vector2<T>(v1.x - v2.x, v1.y - v2.y);
}

template <typename T, typename X>
Vector2<T> operator * (const Vector2<T> &v1, X factor)
{
  return Vector2<T>(v1.x * factor, v1.y * factor);
}

template <typename T, typename X>
Vector2<T> operator / (const Vector2<T> &v1, X factor)
{
  return Vector2<T>(v1.x / factor, v1.y / factor);
}



template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    almost_equal(const Vector2<T>& v1, const Vector2<T>& v2, int ulp=2)
{
	return almost_equal(v1.x, v2.x, ulp) && almost_equal(v1.y, v2.y, ulp);
}



#endif
