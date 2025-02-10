#pragma once
#include "Matrix3x3.h"
#include "Vector2.h"

class Camera {
public:
	Camera();
	~Camera() = default;
	void Update();

	Matrix3x3 GetVpVpMatrix() const { return vpVpMatrix_; }
private:
	int isAction_;
	float thetaT_;
	float theta_;
	Vector2 pos_;
	Vector2 scale_;
	Matrix3x3 worldMatrix_;
	Matrix3x3 viewMatrix_;			//ビュー行列
	Matrix3x3 orthoMatrix_;		//正規化デバイス行列
	Matrix3x3 viewportMatrix_;		//ビューポート行列
	Matrix3x3 vpVpMatrix_;			//ビュー、正規化デバイス、ビューポート、それぞれの行列を合成した行列
};