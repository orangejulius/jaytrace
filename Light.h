#ifndef LIGHT_H
#define LIGHT_H

#include <Eigen/Core>
#include <QSharedPointer>

#include "Color.h"

using Eigen::Vector3d;

class Light
{
public:
	Light(Vector3d position, bool isDirectional = false);
	virtual ~Light();

	///get the direction this light is shining from at a given point
	Vector3d getLightVector(Vector3d point) const;

	void setAmbient(Color a);
	void setDiffuse(Color d);
	void setSpecular(Color s);

	const Color& getAmbient() const;
	const Color& getDiffuse() const;
	const Color& getSpecular() const;
protected:
	Color ambient;
	Color diffuse;
	Color specular;

	Vector3d position;
	bool isDirectional;
};

typedef QSharedPointer<Light> LightPointer;

#endif // LIGHT_H
