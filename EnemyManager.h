#pragma once
#include <memory>
#include <list>
#include "Enemy.h"
#include "Player.h"
#include "Score.h"

//敵を管理するクラス
class EnemyManager {
public:
	EnemyManager();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="player">プレイヤー</param>
	/// <returns>オブジェクトを破棄するときはfalse、それ以外の時はtrue</returns>
	bool Update(Player& player);

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="vpVpMatrix">レンダリングパイプラインを通すための行列</param>
	void Draw(const Matrix3x3& vpVpMatrix) const;
private:
	//敵のリスト
	std::list<std::shared_ptr<Enemy>> enemyList_;

	//スコア
	std::shared_ptr<Score> score_;
};

