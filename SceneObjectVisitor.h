#ifndef SCENEOBJECTVISITOR_H
#define SCENEOBJECTVISITOR_H

class Sphere;

class SceneObjectVisitor
{

public:
	virtual void visit(const Sphere* sphere) = 0;
};

#endif // SCENEOBJECTVISITOR_H
