#include "Point.hpp"

// source : https://www.youtube.com/watch?v=qObJQesvZUU

Fixed areaOfTriangle(const Point& A, const Point& B, const Point& C) {
	Fixed Ax = A.getX();
	Fixed Ay = A.getY();
	Fixed Bx = B.getX();
	Fixed By = B.getY();
	Fixed Cx = C.getX();
	Fixed Cy = C.getY();

	Fixed area = Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By);
	if (area < Fixed(0)) {
		area = area * Fixed(-1);
	}
	area = area / Fixed(2);
	return area;
}

bool	bsp(const Point& P, const Point& A, const Point& B, const Point& C)
{
	Fixed areaT = areaOfTriangle(A, B, C);
	Fixed areaTp1 = areaOfTriangle(A, B, P);
	Fixed areaTp2 = areaOfTriangle(A, C, P);
	Fixed areaTp3 = areaOfTriangle(B, C, P);

	if (areaT == (areaTp1 + areaTp2 + areaTp3))
		return true;
	return false;
}
