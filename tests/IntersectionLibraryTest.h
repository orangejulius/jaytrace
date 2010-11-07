#ifndef INTERSECTIONLIBRARYTEST_H
#define INTERSECTIONLIBRARYTEST_H

#include <QtTest/QtTest>

class IntersectionLibraryTest: public QObject
{
	Q_OBJECT
private slots:
	///Test basic intersection math
	void testIntersections();

	///Test that depth is handled properly
	void testOccultation();
};
#endif // INTERSECTIONLIBRARYTEST_H
