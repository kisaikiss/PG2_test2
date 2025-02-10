#include "Enemy.h"
#include "Define.h"
#include "MatrixOperater.h"


Enemy::Enemy() {
	isDamage_ = false;
	pos_.x = static_cast<float>(kWindowWidth) + widthHalf_;
	speed_.x = -static_cast<float>(rand() % 10) - 10.f;
	pos_.y = static_cast<float>(rand() % kWindowHeight);
	widthHalf_ = 32.f;
	heightHalf_ = 32.f;
	SetBaseVertex();
	blendMode_ = kBlendModeNormal;
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
}

bool Enemy::Update() {

	//ダメージを受けていなければ普通に動く
	//そうでなければ少しずつ大きさを小さくして0未満になったら消す
	if (!isDamage_) {
		Move();
	} else {
		widthHalf_ -= 2.f;
		heightHalf_ -= 2.f;
		SetBaseVertex();
		if (widthHalf_ < 0.f) {
			return false;
		}
	}
	
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);

	//左端にたどり着いたらけす
	if (pos_.x + widthHalf_ < 0.f) {
		return false;
	}
	return true;
}

void Enemy::TakeDamage() {
	isDamage_ = true;
}

void Enemy::Move() {
	pos_.x += speed_.x;
}

