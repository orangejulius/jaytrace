#include "Material.h"

void Material::setAmbient(Color a)
{
	ambient = a;
}

void Material::setDiffuse(Color d)
{
	diffuse = d;
}

void Material::setSpecular(Color s)
{
	specular = s;
}

void Material::setEmission(Color e)
{
	emission = e;
}

void Material::setShininess(float s)
{
	shininess = s;
}

void Material::setEta(float e)
{
	eta = e;
}

const Color& Material::getAmbient() const
{
	return ambient;
}

const Color& Material::getDiffuse() const
{
	return diffuse;
}

const Color& Material::getSpecular() const
{
	return specular;
}

const Color& Material::getEmission() const
{
	return emission;
}

float Material::getShininess() const
{
	return shininess;
}

float Material::getEta() const
{
	return eta;
}
