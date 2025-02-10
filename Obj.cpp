#include "Obj.h"
#include "MatrixOperater.h"
#include "Draw.h"
#include "Pad.h"
#include "Define.h"
#include <Novice.h>

Obj::Obj() {
	graph_ = Novice::LoadTexture("./NoviceResources/white1x1.png");
	pos_.x = 0.f;
	pos_.y = 0.f;
	speed_.x = 0.f;
	speed_.y = 0.f;
	theta_ = 0.f;
	scale_.x = 1.f;
	scale_.y = 1.f;
	widthHalf_ = 50.f;
	heightHalf_ = 50.f;
	graphWidthHalf_ = 64.f;
	graphHeightHalf_ = 64.f;
	baseVertex_.leftTop.x = -widthHalf_;
	baseVertex_.leftTop.y = heightHalf_;
	baseVertex_.leftBottom.x = -widthHalf_;
	baseVertex_.leftBottom.y = -heightHalf_;
	baseVertex_.rightTop.x = widthHalf_;
	baseVertex_.rightTop.y = heightHalf_;
	baseVertex_.rightBottom.x = widthHalf_;
	baseVertex_.rightBottom.y = -heightHalf_;
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
	vertex_ = VertexTransform(baseVertex_, worldMatrix_);
	graphCropPos_.x = 0;
	graphCropPos_.y = 0;
	colorData_.red = 255;
	colorData_.green = 255;
	colorData_.blue = 255;
	colorData_.alpha = 255;
	color_ = (colorData_.red << 24) | (colorData_.green << 16) | (colorData_.blue << 8) | colorData_.alpha;
	blendMode_ = kBlendModeNormal;
}

Obj::~Obj() {
	//Novice::UnloadTexture(graph_);
}

bool Obj::Update() {
	return true;
}

void Obj::Draw(const Matrix3x3& vpVpMatrix) const {
	Novice::SetBlendMode(blendMode_);
	DrawObj(baseVertex_, worldMatrix_, vpVpMatrix, graphCropPos_, graphWidthHalf_, graphHeightHalf_, graph_, 1,color_);
}

void Obj::UpdateColor() {
	color_ = (colorData_.red << 24) | (colorData_.green << 16) | (colorData_.blue << 8) | colorData_.alpha;
}

void Obj::SetColor(const int& red, const int& green, const int& blue, const int& alpha) {
	colorData_.red = red;
	colorData_.green = green;
	colorData_.blue = blue;
	colorData_.alpha = alpha;
}

void Obj::SetBaseVertex() {
	baseVertex_.leftTop.x = -widthHalf_;
	baseVertex_.leftTop.y = heightHalf_;
	baseVertex_.leftBottom.x = -widthHalf_;
	baseVertex_.leftBottom.y = -heightHalf_;
	baseVertex_.rightTop.x = widthHalf_;
	baseVertex_.rightTop.y = heightHalf_;
	baseVertex_.rightBottom.x = widthHalf_;
	baseVertex_.rightBottom.y = -heightHalf_;
}

bool Obj::IsInside() const {
	if (pos_.x + widthHalf_ < 0.f || pos_.x - widthHalf_ > static_cast<float>(kWindowWidth) ||
		pos_.y + heightHalf_ < 0.f || pos_.y - heightHalf_ > static_cast<float>(kWindowHeight)) {
		return false;
	}
	return true;
}

