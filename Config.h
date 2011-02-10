#ifndef CONFIG_H
#define CONFIG_H

#include <QSharedPointer>

#include "Angle.h"

/**
 * This class stores config options that can be read and modified by multiple sources
 */
class Config
{
public:
	Angle projectionAngle;
};

typedef QSharedPointer<Config> ConfigPointer;

#endif // CONFIG_H
