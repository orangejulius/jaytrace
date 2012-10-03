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

	double getRadians() const {
		return angle;
	}

protected:
	Angle(double radians) {
		angle = radians;
	}

	double angle;
};

#endif // ANGLE_H
