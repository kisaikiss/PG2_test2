#pragma once
#include "Obj.h"
#include "PlayerBullet.h"
#include <memory>
#include <list>

class Player : public Obj {
public:
	//プレイヤーの弾を管理するリスト
	std::list<std::shared_ptr<PlayerBullet>> bullet_;

	Player();
	~Player();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>オブジェクトを破棄するときはfalse、それ以外の時はtrue</returns>
	bool Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="vpVpMatrix">レンダリングパイプラインを通すための行列</param>
	void Draw(const Matrix3x3& vpVpMatrix) const override;

	void TakeDamage();
private:
	const float kPlayerBaseSpeed;//プレイヤーのスピード
	bool isDamage_;//ダメージを受けたか

	/// <summary>
	/// 移動関数
	/// </summary>
	void Move();
};

