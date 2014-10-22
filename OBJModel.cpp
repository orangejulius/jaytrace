#include "OBJModel.h"

#include "Triangle.h"

#include "tiny_obj_loader.h"

using std::vector;
using tinyobj::shape_t;
using tinyobj::material_t;

OBJModel OBJModel::import(std::string filename, NodePointer parent)
{
	vector<shape_t> shapes;
	vector<material_t> materials;

	tinyobj::LoadObj(shapes, materials, filename.c_str());

	vector<RayObjectPointer> objects;
	for (size_t shape_idx = 0; shape_idx < shapes.size(); shape_idx++) {
		shape_t shape = shapes[shape_idx];
		assert((shape.mesh.indices.size() % 3) == 0);
		for (size_t face_idx = 0; face_idx < shape.mesh.indices.size() / 3; face_idx++) {
			// size 3 float array. each element is an id of a vertex
			unsigned int *face_vertex_ids = &shape.mesh.indices[3*face_idx];
			Vector3d verticies[3];
			for (int face_vertex_index = 0; face_vertex_index < 3; face_vertex_index++) {
				int vertex_id = face_vertex_ids[face_vertex_index];
				float* vertex = &shape.mesh.positions[3*vertex_id];
				for (int dim = 0; dim < 3; dim++) {
					verticies[face_vertex_index][dim] = vertex[dim];
				}
			}
			RayObjectPointer newObject(new Triangle(verticies[0], verticies[1], verticies[2], parent));

			objects.push_back(newObject);
		}
	}

	return OBJModel(objects, parent);
}

OBJModel::OBJModel(vector<RayObjectPointer> objects, NodePointer parent): Node(parent), objects(objects)
{
}
