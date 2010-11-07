#include "Light.h"

#include <QtDebug>

Light::Light(Vector3d position, bool isDirectional): position(position), isDirectional(isDirectional)
{
	if (isDirectional) {
		position.normalize();
	}
}

Light::~Light()
{
	qDebug() << "Deleting Light " << this;
}

Vector3d Light::getLightVector(Vector3d point) const
{
	if (isDirectional) {
		return position;
	} else {
		Vector3d lightVector = position - point;
		lightVector.normalize();
		return lightVector;
	}
}

void Light::setAmbient(Color a)
{
	ambient = a;
}

void Light::setDiffuse(Color d)
{
	diffuse = d;
}

void Light::setSpecular(Color s)
{
	specular = s;
}

const Color& Light::getAmbient() const
{
	return ambient;
}

const Color& Light::getDiffuse() const
{
	return diffuse;
}

const Color& Light::getSpecular() const
{
	return specular;
}
