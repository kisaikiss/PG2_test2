#include "TitleScene.h"
#include "Pad.h"
#include "eScene.h"
#include <Novice.h>

TitleScene::TitleScene(IOnSceneChangedListener* impl):AbstractScene(impl){
	titleImage_ = Novice::LoadTexture("./Resources/Images/title.png");
}

TitleScene::~TitleScene() {
	Novice::UnloadTexture(titleImage_);
}

void TitleScene::Update() {
	//ボタンを押されたらゲーム画面に移る
	if (Pad::getIns()->Get(ePad::PAD_A) == 1) {
		implSceneChanged_->OnSceneChanged(eSCENE::GAME, true);
		return;
	}
}

void TitleScene::Draw() const {
	Novice::DrawSprite(0, 0, titleImage_, 1.f, 1.f, 0.f, WHITE);
}
