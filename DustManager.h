#pragma once
#include "Matrix3x3.h"
#include "DustParticle.h"
#include <memory>
#include <list>

//パーティクルの埃を管理するクラス
class DustManager {
public:
	DustManager();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>オブジェクトを破棄するときはfalse、それ以外の時はtrue</returns>
	bool Update();
	void Draw(const Matrix3x3& vpVpMatrix) const;
private:
	//埃のリスト
	std::list<std::shared_ptr<DustParticle>> dust_;
	//埃の最大数
	const int kMaxDust_;
};

