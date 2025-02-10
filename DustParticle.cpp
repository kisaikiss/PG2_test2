#include "DustParticle.h"
#include "Define.h"
#include "MatrixOperater.h"

DustParticle::DustParticle() {
	//ランダムな位置に出現する
	pos_.x = static_cast<float>(rand() % kWindowWidth);
	pos_.y = static_cast<float>(rand() % kWindowHeight);

	//ランダムなスピードを決める
	if (rand() % 2) {
		speed_.x = static_cast<float>(rand() % 100) / 150.f - 3.f;
	} else {
		speed_.x = -static_cast<float>(rand() % 100) / 150.f - 3.f;
	}
	
	if (rand() % 2) {
		speed_.y = static_cast<float>(rand() % 100) / 150.f;
	} else {
		speed_.y = -static_cast<float>(rand() % 100) / 150.f;
	}


	isZoom_ = false;
	isSee_ = false;

	//大きさの最大値と最小値を決める
	maxRadius_ = static_cast<float>(rand() % 5) + 10.f;
	minRadius_ = maxRadius_ - 5.f;

	blendMode_ = kBlendModeAdd;

	//大きさを最小値にする
	widthHalf_ = minRadius_;
	heightHalf_ = minRadius_;
	SetBaseVertex();
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
	colorData_.alpha = 0;
	UpdateColor();
}

bool DustParticle::Update() {
	//移動
	pos_.x += speed_.x;
	pos_.y += speed_.y;

	//画面外なら消す
	if (!IsInside()) {
		return false;
	}

	//大きさを変える
	if (isZoom_) {
		widthHalf_ -= 0.1f;
		if (widthHalf_ < minRadius_) {
			isZoom_ = false;
		}
	} else {
		widthHalf_ += 0.1f;
		if (widthHalf_ > maxRadius_) {
			isZoom_ = true;
		}
	}
	heightHalf_ = widthHalf_;
	SetBaseVertex();

	//透明度を変える
	if (isSee_) {
		colorData_.alpha -= 1;
		if (colorData_.alpha < 30) {
			isSee_ = false;
		}
	} else {
		colorData_.alpha += 1;
		if (colorData_.alpha > 70) {
			isSee_ = true;
		}
	}
	UpdateColor();
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
	return true;
}
