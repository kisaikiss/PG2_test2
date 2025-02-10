#include "PauseScene.h"
#include "Pad.h"
#include <Novice.h>

PauseScene::PauseScene(IOnSceneChangedListener* impl) : AbstractScene(impl) {
	pauseImage_ = Novice::LoadTexture("./Resources/Images/pause.png");
}

PauseScene::~PauseScene() {
	Novice::UnloadTexture(pauseImage_);
}

void PauseScene::Update() {
	//ボタンを押されたらポーズシーンをポップしてスタックしていた元のシーンに戻る
	if (Pad::getIns()->Get(ePad::PAD_START) == 1) {
		implSceneChanged_->ScenePop();
		return;
	}
}

void PauseScene::Draw() const {
	Novice::DrawSprite(0, 0, pauseImage_, 1.f, 1.f, 0.f, WHITE);
}
