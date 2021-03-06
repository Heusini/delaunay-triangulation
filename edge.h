#ifndef H_EDGE
#define H_EDGE

#include "vector2.h"

template <class T>
class Edge
{
	public:
		using VertexType = Vector2<T>;

		Edge(const VertexType &p1, const VertexType &p2) : p1(p1), p2(p2), isBad(false) {};
		Edge(const Edge &e) : p1(e.p1), p2(e.p2), isBad(false) {};
    Edge(): isBad(true){};

		VertexType p1;
		VertexType p2;

    Vector2<double> getMiddlePoint();

		bool isBad;
    double getLength();
};

template<>
double Edge<double>::getLength()
{
  return p1.dist(p2);
}

template <class T>
Vector2<double> Edge<T>::getMiddlePoint()
{
  return Vector2<double> ((p2.x+p1.x)/2,(p2.y+p1.y)/2);
}

template <class T>
inline std::ostream &operator << (std::ostream &str, Edge<T> const &e)
{
	return str << "Edge " << e.p1 << ", " << e.p2;
}

template <class T>
inline bool operator == (const Edge<T> & e1, const Edge<T> & e2)
{
	return 	(e1.p1 == e2.p1 && e1.p2 == e2.p2) ||
			(e1.p1 == e2.p2 && e1.p2 == e2.p1);
}

template <class T>
inline bool almost_equal (const Edge<T> & e1, const Edge<T> & e2)
{
	return	(almost_equal(e1.p1, e2.p1) && almost_equal(e1.p2, e2.p2)) ||
			(almost_equal(e1.p1, e2.p2) && almost_equal(e1.p2, e2.p1));
}

namespace boost {
namespace serialization {

template<class Archive>
void serialize(Archive & ar, Edge<double> & v, const unsigned int version)
{
    ar & v.p1;
    ar & v.p2;
}

} // namespace serialization
}
#endif

