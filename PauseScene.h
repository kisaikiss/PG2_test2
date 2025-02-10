#pragma once
#include "AbstractScene.h"

//ポーズ画面のクラス
class PauseScene : public AbstractScene {
public:
	PauseScene(IOnSceneChangedListener* impl);
	~PauseScene();
	void Update() override;
	void Draw() const override;
private:
	int pauseImage_;//ポーズ画面の画像
};

