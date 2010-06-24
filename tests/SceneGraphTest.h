#ifndef SCENEGRAPHTEST_H
#define SCENEGRAPHTEST_H

#include <QtTest/QtTest>

class SceneGraphTest: public QObject
{
	Q_OBJECT
private slots:
	void testCreation();
	void testSingleTransformNode();
	void testSingleTranslationNode();
	void testScalingNodeParent();
	void testScalingNodeParents();
	void testTranslationNodeParent();
	void testTranslationNodeParents();
};
#endif // SCENEGRAPHTEST_H
