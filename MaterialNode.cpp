#include "MaterialNode.h"

#include <QDebug>

MaterialNode::MaterialNode(NodePointer parent): Node(parent)
{

}

MaterialNode::~MaterialNode()
{
	qDebug() << "Deleting MaterialNode " << this;
}

Material MaterialNode::getMaterial()
{
	return material;
}

void MaterialNode::setAmbient(Color a)
{
	material.setAmbient(a);
}

void MaterialNode::setDiffuse(Color d)
{
	material.setDiffuse(d);
}

void MaterialNode::setSpecular(Color s)
{
	material.setSpecular(s);
}

void MaterialNode::setEmission(Color e)
{
	material.setEmission(e);
}

void MaterialNode::setShininess(float s)
{
	material.setShininess(s);
}

void MaterialNode::setEta(float e)
{
	material.setEta(e);
}
