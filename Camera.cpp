#include "Camera.h"
#include "MatrixOperater.h"
#include "Define.h"
#include "Pad.h"
#include "Easing.h"
#include <Novice.h>

Camera::Camera() {
	pos_.x = static_cast<float>(kWindowWidth / 2);
	pos_.y = static_cast<float>(kWindowHeight / 2);
	theta_ = 0.f;
	thetaT_ = 0.f;
	isAction_ = false;
	scale_.x = 1.f;
	scale_.y = 1.f;
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
	viewMatrix_ = Inverse(worldMatrix_);
	orthoMatrix_ = MakeOrthographicMatrix(static_cast<float>(-kWindowWidth / 2), static_cast<float>(kWindowHeight / 2),
		static_cast<float>(kWindowWidth / 2), static_cast<float>(-kWindowHeight / 2));
	viewportMatrix_ = MakeViewportMatrix(0.f, 0.f, static_cast<float>(kWindowWidth), static_cast<float>(kWindowHeight));
	vpVpMatrix_ = Multiply(viewMatrix_, orthoMatrix_);
	vpVpMatrix_ = Multiply(vpVpMatrix_, viewportMatrix_);
}

void Camera::Update() {
	
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
	viewMatrix_ = Inverse(worldMatrix_);
	orthoMatrix_ = MakeOrthographicMatrix(static_cast<float>(-kWindowWidth / 2), static_cast<float>(kWindowHeight / 2),
		static_cast<float>(kWindowWidth / 2), static_cast<float>(-kWindowHeight / 2));
	viewportMatrix_ = MakeViewportMatrix(0.f, 0.f, static_cast<float>(kWindowWidth), static_cast<float>(kWindowHeight));
	vpVpMatrix_ = Multiply(viewMatrix_, orthoMatrix_);
	vpVpMatrix_ = Multiply(vpVpMatrix_, viewportMatrix_);
}