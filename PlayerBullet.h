#pragma once
#include "Obj.h"
class PlayerBullet : public Obj {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">弾の初期位置</param>
	PlayerBullet(Vector2 pos);

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>オブジェクトを破棄するときはfalse、それ以外の時はtrue</returns>
	bool Update() override;
private:
	const float kBaseSpeed;
};

