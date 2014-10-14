#ifndef ANGLE_H
#define ANGLE_H

#define PI 3.141592653589793

/** Class Angle
 * Represents a geometric angle. Internally uses radians but presents static methods for construction from degrees or radians.
 */
class Angle
{
public:
	static Angle radians(double angleRadians) {
		return Angle(angleRadians);
	}

	static Angle degrees(double angleDegrees) {
		return Angle(angleDegrees * PI / 180);
	}

	double getRadians() const {
		return angle;
	}

	double getDegrees() const {
		return angle * 180 / PI;
	}

	bool operator==(const Angle& other) const {
		return angle == other.angle;
	}

	Angle operator +(const Angle& other) const {
		return Angle(angle + other.angle);
	}

protected:
	Angle(double radians) {
		angle = radians;
	}

	double angle;
};

#endif // ANGLE_H
