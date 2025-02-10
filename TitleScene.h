#pragma once
#include "AbstractScene.h"

//タイトル画面のクラス
class TitleScene : public AbstractScene {
public:
    TitleScene(IOnSceneChangedListener* impl);
    ~TitleScene() override;
    void Update() override;
    void Draw() const override;
private:
    int titleImage_; //タイトル画面の画像
};

