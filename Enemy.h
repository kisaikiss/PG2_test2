#pragma once
#include "Obj.h"
class Enemy : public Obj {
public:
	Enemy();
	~Enemy() = default;
	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>オブジェクトを破棄するときはfalse、それ以外の時はtrue</returns>
	bool Update() override;

	/// <summary>
	/// ダメージを受ける
	/// </summary>
	void TakeDamage();
private:
	//ダメージを受けたか
	bool isDamage_;

	/// <summary>
	/// 移動関数
	/// </summary>
	void Move();
};

