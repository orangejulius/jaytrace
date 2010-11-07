#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "Color.h"

class Material
{
public:
	void setAmbient(Color a);
	void setDiffuse(Color d);
	void setSpecular(Color s);
	void setEmission(Color e);
	void setShininess(float s);
	void setEta(float e);

	const Color& getAmbient() const;
	const Color& getDiffuse() const;
	const Color& getSpecular() const;
	const Color& getEmission() const;
	float getShininess() const;
	float getEta() const;

protected:
	Color diffuse;
	Color specular;
	Color ambient;
	Color emission;
	float shininess;
	float eta;
};

#endif // MATERIAL_H_INCLUDED
