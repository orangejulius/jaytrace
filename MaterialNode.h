#ifndef MATERIALNODE_H
#define MATERIALNODE_H

#include "CompositeNode.h"
#include "Material.h"

class MaterialNode: public CompositeNode
{
public:
	MaterialNode(NodePointer parent = NodePointer(0));
	virtual ~MaterialNode();

	virtual Material getMaterial();

	void setAmbient(Color a);
	void setDiffuse(Color d);
	void setSpecular(Color s);
	void setEmission(Color e);
	void setShininess(float s);
	void setEta(float e);
protected:
	Material material;
};

typedef QSharedPointer<MaterialNode> MaterialNodePointer;

#endif // MATERIALNODE_H
