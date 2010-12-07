#include "Camera.h"

#include <Eigen/Array>

using Eigen::Matrix4d;

Camera::Camera()
{
	eye = Vector3d::Zero();
	look = -Vector3d::UnitZ();
	up = Vector3d::UnitY();
}

Camera::Camera(Vector3d eye, Vector3d look, Vector3d up): eye(eye), look(look), up(up)
{

}

void Camera::setEye(Vector3d newEye)
{
	eye = newEye;
}

void Camera::setLook(Vector3d newLook)
{
	look = newLook;
}

void Camera::setUp(Vector3d newUp)
{
	up = newUp;
}

Transform3d Camera::getTransform() const
{
	//first calculate the camera coordinate system
	Vector3d n = eye - look;
	Vector3d u = up.cross(n);

	n.normalize();
	u.normalize();

	Vector3d v = n.cross(u);

	//create a transformation matrix to convert world coordinates into camera coordinates
	Matrix4d m = Matrix4d::Identity();
	m << u.x(), u.y(), u.z(), -eye.dot(u),
	  v.x(), v.y(), v.z(), -eye.dot(v),
	  n.x(), n.y(), n.z(), -eye.dot(n),
	  0, 0, 0, 1;

	return Transform3d(m);
}
