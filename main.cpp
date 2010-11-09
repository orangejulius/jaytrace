#include "RaytraceRenderer.h"

#include "MaterialNode.h"
#include "TranslationNode.h"
#include "Sphere.h"
#include <QDate>

int main()
{
	RaytraceRenderer raytraceRenderer;

	LightPointer l1(new Light(Vector3d(-3,2,0),0));
	Color white(1,1,1);
	l1->setAmbient(white);
	l1->setDiffuse(white);
	l1->setSpecular(white);

	NodePointer t1(new TranslationNode(0,0,-10));
	MaterialNodePointer m1(new MaterialNode(t1));
	Color m1Color(.5,.2,.2);
	m1->setAmbient(m1Color);
	m1->setDiffuse(m1Color);
	m1->setSpecular(white);
	m1->setShininess(10);
	RayObjectPointer s1(new Sphere(m1));

	raytraceRenderer.addObject(s1);
	raytraceRenderer.addLight(l1);
	QImage output = raytraceRenderer.render();
	QString filename = QDateTime::currentDateTime().toString(Qt::ISODate) + ".png";
	output.save(filename, "PNG");
	return 0;
}
