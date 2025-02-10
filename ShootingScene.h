#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Camera.h"
#include "DustManager.h"
#include "EnemyManager.h"
#include <memory>

//ゲーム画面のクラス
class ShootingScene : public AbstractScene {
public:
    ShootingScene(IOnSceneChangedListener* impl);
    virtual ~ShootingScene() = default;
    void Update() override;
    void Draw() const override;
private:
    //プレイヤー
    std::shared_ptr<Player> player_;
    //カメラ
    std::shared_ptr<Camera> camera_;
    //埃のパーティクル
    std::shared_ptr<DustManager> dustManager_;
    //敵
    std::shared_ptr<EnemyManager> enemyManager_;
};

