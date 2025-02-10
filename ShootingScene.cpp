#include "ShootingScene.h"
#include "Define.h"
#include "Pad.h"
#include <Novice.h>

using namespace std;

ShootingScene::ShootingScene(IOnSceneChangedListener* impl):AbstractScene(impl) {
	player_ = make_shared<Player>();
	camera_ = make_shared<Camera>();
	dustManager_ = make_shared<DustManager>();
	enemyManager_ = make_shared<EnemyManager>();
}

void ShootingScene::Update() {
	//スタートボタンを押すとポーズ画面へ移動
	if (Pad::getIns()->Get(ePad::PAD_START) == 1) {
		implSceneChanged_->OnSceneChanged(eSCENE::PAUSE, false);
		return;
	}

	//プレイヤーが消えたらタイトルシーンへ移動
	if (!player_->Update()) {
		implSceneChanged_->OnSceneChanged(eSCENE::TITLE, true);
		return;
	}
	enemyManager_->Update(*player_);
	camera_->Update();
	dustManager_->Update();
}

void ShootingScene::Draw() const {
	//背景の描画
	Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.f, BLACK, kFillModeSolid);

	//カメラの行列をもとに描画
	player_->Draw(camera_->GetVpVpMatrix());
	enemyManager_->Draw(camera_->GetVpVpMatrix());
	dustManager_->Draw(camera_->GetVpVpMatrix());
}
