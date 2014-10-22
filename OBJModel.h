#ifndef OBJMODEL_H
#define OBJMODEL_H

#include <vector>

#include "Node.h"
#include "RayObject.h"

using std::string;
using std::vector;

class OBJModel: public Node
{
public:
	static OBJModel import(string filename, NodePointer parent = NodePointer(0));

	vector<RayObjectPointer> getObjects() const {
		return objects;
	};

private:
	OBJModel(vector<RayObjectPointer> objects, NodePointer parent);
	vector<RayObjectPointer> objects;
};

#endif // OBJMODEL_H
