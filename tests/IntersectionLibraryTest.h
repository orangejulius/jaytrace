#ifndef INTERSECTIONLIBRARYTEST_H
#define INTERSECTIONLIBRARYTEST_H

#include <QtTest/QtTest>

class IntersectionLibraryTest: public QObject
{
	Q_OBJECT
private slots:
	///Test basic intersection math
	void testIntersections();
};
#endif // INTERSECTIONLIBRARYTEST_H
