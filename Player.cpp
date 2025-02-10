#include "Player.h"
#include "Pad.h"
#include "MatrixOperater.h"
#include "Define.h"
#include "Draw.h"
#include "SFX.h"
#include <Novice.h>

Player::Player():kPlayerBaseSpeed(5.f) {
	pos_.x = 100.f;
	pos_.y = static_cast<float>(kWindowHeight / 2);
	widthHalf_ = 32.f;
	heightHalf_ = 16.f;
	SetBaseVertex();
	blendMode_ = kBlendModeNormal;
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
	isDamage_ = false;
}

Player::~Player() {
	Novice::UnloadTexture(graph_);
}

bool Player::Update() {
	
	if (!isDamage_) {
		Move();
	} else {
		widthHalf_ -= 4.f;
		heightHalf_ -= 2.f;
		SetBaseVertex();
		if (widthHalf_ < 0.f) {
			return false;
		}
	}

	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);
	UpdateColor();
	//弾を更新する
	//もしUpdateの戻り値がfalseならリストから消す。
	for (auto it = bullet_.begin(); it != bullet_.end();) {
		if (!(*it)->Update()) {
			it = bullet_.erase(it);
		} else {
			it++;
		}
	}
	return true;
}

void Player::Draw(const Matrix3x3& vpVpMatrix) const {
	Novice::SetBlendMode(blendMode_);
	//弾の描画
	for (const auto& it : bullet_) {
		it->Draw(vpVpMatrix);
	}
	//プレイヤーの描画
	DrawObj(baseVertex_, worldMatrix_, vpVpMatrix, graphCropPos_, graphWidthHalf_, graphHeightHalf_, graph_, 1, color_);
}

void Player::TakeDamage() {
	//ダメージを受けていなければ
	if (!isDamage_) {
		isDamage_ = true;
		SFX::getIns()->Play(eSFX::SFX_DAMAGE, 0.5f);
	}
}

void Player::Move() {
	speed_.x = 0.f;
	speed_.y = 0.f;

	//キー入力に応じてスピードに代入
	if (Pad::getIns()->Get(ePad::PAD_UP)) {
		speed_.y += kPlayerBaseSpeed;
	}
	if (Pad::getIns()->Get(ePad::PAD_DOWN)) {
		speed_.y += -kPlayerBaseSpeed;
	}
	if (Pad::getIns()->Get(ePad::PAD_RIGHT)) {
		speed_.x += kPlayerBaseSpeed;
	}
	if (Pad::getIns()->Get(ePad::PAD_LEFT)) {
		speed_.x += -kPlayerBaseSpeed;
	}

	//X,Yどちらの方向にもスピードがあったら2の平方根で割る
	if (speed_.x && speed_.y) {
		speed_.x /= kSquareRootOf2;
		speed_.y /= kSquareRootOf2;
	}

	//ボタンを押されたら弾を撃つ
	if (Pad::getIns()->Get(ePad::PAD_A) == 1) {
		bullet_.emplace_back(std::make_shared<PlayerBullet>(pos_));
		SFX::getIns()->Play(eSFX::SFX_SHOT, 0.5f);
	}

	//移動
	pos_.x += speed_.x;
	pos_.y += speed_.y;
}

