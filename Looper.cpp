#include "Looper.h"
#include "TitleScene.h"
#include "ShootingScene.h"
#include "PauseScene.h"

using namespace std;

Looper::Looper() {
	sceneStack_.push(make_shared<TitleScene>(this)); //タイトル画面シーンを作ってpush
}

Looper::~Looper() {
	
}

bool Looper::Loop() const{
	//現在のシーンの更新処理と描画処理
	sceneStack_.top()->Update();
	sceneStack_.top()->Draw();
	return true;
}

void Looper::OnSceneChanged(const eSCENE scene, const bool stackClear) {
	//スタックを消すなら全て消す
	if (stackClear) {
		while (!sceneStack_.empty()) {
			sceneStack_.pop();
		}
	}

	//引数のシーンをプッシュする
	switch (scene) {
	case TITLE:
		sceneStack_.push(make_shared<TitleScene>(this));
		break;
	case GAME:
		sceneStack_.push(make_shared<ShootingScene>(this));
		break;
	case PAUSE:
		sceneStack_.push(make_shared<PauseScene>(this));
		break;
	default:
		break;
	}
}

void Looper::ScenePop() {
	sceneStack_.pop();
}
