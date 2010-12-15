#include "Camera.h"

#include <Eigen/Array>
#include <Eigen/LU>

using Eigen::Matrix4d;
using Eigen::Translation3d;

Camera::Camera()
{
	eye = Vector3d::Zero();
	look = -Vector3d::UnitZ();
	up = Vector3d::UnitY();

	computeCameraCoordinates();
}

Camera::Camera(Vector3d eye, Vector3d look, Vector3d up): eye(eye), look(look), up(up)
{
	computeCameraCoordinates();
}

void Camera::setEye(Vector3d newEye)
{
	eye = newEye;

	computeCameraCoordinates();
}

void Camera::setLook(Vector3d newLook)
{
	look = newLook;

	computeCameraCoordinates();
}

void Camera::setUp(Vector3d newUp)
{
	up = newUp;

	computeCameraCoordinates();
}

void Camera::slide(Vector3d delta)
{
	//get a transform to convert world coordinates to camera coordinates
	Transform3d worldToCamera = getTransform();
	//get the inverse transform which is returned by inverse() as a matrix
	Transform3d cameraToWorld = Transform3d(worldToCamera.inverse());

	Transform3d slide = worldToCamera * Translation3d(delta) * cameraToWorld;

	eye = slide * eye;
	look = slide * eye;
}

Transform3d Camera::getTransform() const
{
	//create a transformation matrix to convert world coordinates into camera coordinates
	Matrix4d m = Matrix4d::Identity();
	m << u.x(), u.y(), u.z(), -eye.dot(u),
	  v.x(), v.y(), v.z(), -eye.dot(v),
	  n.x(), n.y(), n.z(), -eye.dot(n),
	  0, 0, 0, 1;

	return Transform3d(m);
}

void Camera::computeCameraCoordinates()
{
	n = eye - look;
	u = up.cross(n);

	n.normalize();
	u.normalize();

	v = n.cross(u);
}
