#include "IntersectionLibraryTest.h"

#include "IntersectionLibrary.h"
#include "Ray.h"
#include "ScalingNode.h"
#include "Sphere.h"
#include "TranslationNode.h"

void IntersectionLibraryTest::testIntersections()
{
	IntersectionLibrary intersectionLibrary;

	NodePointer t1(new TranslationNode(10, 0, 0));
	NodePointer t2(new TranslationNode(0, 10, 0, t1));
	NodePointer s1(new ScalingNode(5, 5, 5, t2));

	RayObjectPointer sphere1(new Sphere(t1));
	RayObjectPointer sphere2(new Sphere(s1));

	Ray ray1(Vector3d(0, 0, 0), Vector3d(1, 0, 0));
	Ray ray2(Vector3d(0, 0, 0), Vector3d(-1, 0, 0));
	Ray ray3(Vector3d(2, 0, 0), Vector3d(1, 1, 0));

	intersectionLibrary.addObject(sphere1);
	intersectionLibrary.addObject(sphere2);

	IntersectionInfo* info1 = intersectionLibrary.intersect(ray1);
	IntersectionInfo* info2 = intersectionLibrary.intersect(ray2);
	IntersectionInfo* info3 = intersectionLibrary.intersect(ray3);

	QVERIFY(info1);
	QCOMPARE(info1->normal, Vector3d(-1, 0, 0));
	QCOMPARE(info1->time, 9.0);

	QVERIFY(!info2);

	QVERIFY(info3);
}

void IntersectionLibraryTest::testOccultation()
{
	IntersectionLibrary intersectionLibrary;

	NodePointer t1(new TranslationNode(10, 0, 0));
	NodePointer t2(new TranslationNode(10, 0, 0, t1));

	//radius 1 spheres with centers at (10,0,0) and (20,0,0)
	RayObjectPointer sphere1(new Sphere(t1));
	RayObjectPointer sphere2(new Sphere(t2));

	//vector starting at origin heading in the +x direction
	Ray ray1(Vector3d(0, 0, 0), Vector3d(1, 0, 0));
	//vector coming from the oposite direction
	Ray ray2(Vector3d(30, 0, 0), Vector3d(-1, 0, 0));

	intersectionLibrary.addObject(sphere1);
	intersectionLibrary.addObject(sphere2);

	IntersectionInfo* info1 = intersectionLibrary.intersect(ray1);
	IntersectionInfo* info2 = intersectionLibrary.intersect(ray2);

	QVERIFY(info1);
	QCOMPARE(info1->normal, Vector3d(-1, 0, 0));
	//correct intersection is at time 9 when the ray hits the first sphere
	QCOMPARE(info1->time, 9.0);

	QVERIFY(info2);
	QCOMPARE(info2->normal, Vector3d(1, 0, 0));
	//correct intersection is at time 9 when the ray hits the second sphere
	QCOMPARE(info2->time, 9.0);
}
