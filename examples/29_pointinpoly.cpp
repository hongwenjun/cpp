#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <iostream>

using namespace boost::geometry;
using namespace std;

int main()
{
	typedef model::d2::point_xy<double> pointtype;
	pointtype point1(3, 3);
	pointtype point2(2, 12.1);

	model::polygon<pointtype> poly;
	pointtype points[] = {pointtype(0, 0), pointtype(0, 10), pointtype(5, 15),
						  pointtype(10, 10), pointtype(10, 0), pointtype(0, 0)};
	append(poly, points);

	cout << wkt(point1) << " is "
		 << (within(point1, poly) ? "inside" : "outside of") << " the "
		 << wkt(poly) << endl;
	cout << wkt(point2) << " is "
		 << (within(point2, poly) ? "inside" : "outside of") << " the "
		 << wkt(poly) << endl;
	return 0;
}
