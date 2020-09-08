#include "Vec2D.h"
#include "Utils.h"
#include <cassert>
#include <cmath>

const Vec2D Vec2D::Zero;

std::ostream& operator << (std::ostream& consoleOut, const Vec2D& vec)
{
	std::cout << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
	return consoleOut;
}

Vec2D operator*(float scalar, const Vec2D& vec)
{
	return vec * scalar;
}


bool Vec2D::operator==(const Vec2D& vec2) const
{
	return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
}

bool Vec2D::operator!=(const Vec2D& vec2) const
{
	return !(*this == vec2);
}

/* Negating a vector
v = [0, 3]
-v = [0, -3]
/|\		|
 |		|
 |	   \|/
 v = [2, 0]
 -->
 -v = [-2, 0]
 <--
 */

Vec2D Vec2D::operator-() const
{
	return Vec2D(-mX, -mY);
}

/* Vector multiply by a scalar
	v = [1, 0]
	->
	3 * v = [3, 0]
	--->
*/

Vec2D Vec2D::operator*(float scale) const
{
	return Vec2D(scale * mX, scale * mY);
}

Vec2D Vec2D::operator/(float scale) const
{
	assert(fabsf(scale) > EPSILON);
	return Vec2D(mX / scale, mY / scale);
}

Vec2D& Vec2D::operator*=(float scale)
{
	*this = *this * scale;
	return *this;
}

Vec2D& Vec2D::operator/=(float scale)
{
	assert(fabsf(scale) > EPSILON);
	*this = *this / scale;
	return *this;
}

/* Vector addition and subtraction
	v = [1, 4]
	a = [2, -2]
	v + a = [1, 4] + [2, -2] = [3, 2]
	v - a = [1, 4] - [2, -2] = [-1, 6]
*/

Vec2D Vec2D::operator+(const Vec2D& vec) const
{
	return Vec2D(mX + vec.mX, mY + vec.mY);
}

Vec2D Vec2D::operator-(const Vec2D& vec) const
{
	return Vec2D(mX - vec.mX, mY - vec.mY);
}

Vec2D& Vec2D::operator+=(const Vec2D vec)
{
	*this = *this + vec;
	return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D vec)
{
	*this = *this - vec;
	return *this;
}

/*
	  /|
hyp  / | y
	/  |
	----
	  x
*/

float Vec2D::Mag2() const
{
	return mX * mX + mY * mY;
}

float Vec2D::Mag() const
{
	return sqrt(Mag2());
}

Vec2D Vec2D::GetUnitVec() const
{
	float mag = Mag();

	if (mag > EPSILON)
	{
		return *this / mag;
	}

	return Vec2D::Zero;
}

Vec2D Vec2D::Normalize()
{
	float mag = Mag();

	if (mag > EPSILON)
	{
		*this /= mag;
	}

	return *this;
}

float Vec2D::Distance(const Vec2D& vec) const
{
	return (vec - *this).Mag();
}

float Vec2D::Dot(const Vec2D& vec) const
{
	return mX * vec.mX + mY * vec.mY;
}