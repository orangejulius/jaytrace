#ifndef ANGLE_H
#define ANGLE_H

/** Class Angle
 * Represents a geometric angle. Internally uses radians but presents static methods for construction from degrees or radians.
 */
class Angle
{
public:
	/// Get an Angle object for a given angle in degrees.
	static Angle degrees(double angleDegrees) {
		return Angle(degreesToRadians(angleDegrees));
	}

	/// Get an Angle object for a given angle in radians.
	static Angle radians(double angleRadians) {
		return Angle(angleRadians);
	}

	/// Default constructor that sets the angle to 0 degrees
	Angle() {
		angle = 0;
	}

	Angle(const Angle& other) {
		angle = other.angle;
	}

	Angle& operator=(const Angle& other) {
		angle = other.angle;
		return *this;
	}

	bool operator==(const Angle& other) const {
		return angle == other.angle;
	}

	double getRadians() const {
		return angle;
	}

	double getDegrees() const {
		return radiansToDegrees(angle);
	}

	Angle operator+(const Angle &a) const {
		return Angle(angle + a.angle);
	}

	Angle operator-(const Angle &a) const {
		return Angle(angle - a.angle);
	}

	Angle operator*(const Angle &a) const {
		return Angle(angle * a.angle);
	}

	Angle operator/(const Angle &a) const {
		return Angle(angle / a.angle);
	}

	Angle operator*(int s) const {
		return Angle(angle * s);
	}

	Angle operator/(int s) const {
		return Angle(angle / s);
	}

	Angle& operator+=(const Angle &a) {
		angle += a.angle;
		return *this;
	}

	Angle& operator-=(const Angle &a) {
		angle -= a.angle;
		return *this;
	}

	static const double pi = 3.141592653589793;
private:
	/**
	 * Private constructor of an Angle object from an angle in radians.
	 * Used by the degrees and radians static methods.
	 */
	Angle(double radians) {
		angle = radians;
	}

	static double degreesToRadians(double degrees) {
		return degrees * pi / 180;
	}

	static double radiansToDegrees(double radians) {
		return radians * 180 / pi;
	}

	/// The angle in radians
	double angle;
};

#endif // ANGLE_H
