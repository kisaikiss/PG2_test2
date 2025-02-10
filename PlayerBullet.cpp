#include "PlayerBullet.h"
#include "MatrixOperater.h"
#include "Define.h"

PlayerBullet::PlayerBullet(Vector2 pos):kBaseSpeed(16.f) {
	pos_ = pos;
	speed_.x = kBaseSpeed;
	widthHalf_ = 8.f;
	heightHalf_ = 8.f;
	SetBaseVertex();
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
}

bool PlayerBullet::Update() {
	pos_.x += speed_.x;

	//画面外にでたら消す
	if (!IsInside()) {
		return false;
	}
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
	return true;
}
