#pragma once
#include "Obj.h"
class DustParticle : public Obj {
public:
	DustParticle();
	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>オブジェクトを破棄するときはfalse、それ以外の時はtrue</returns>
	bool Update() override;
private:
	//でかく成り切ったか
	bool isZoom_;

	//透明度が上がり切ったか
	bool isSee_;

	//大きさの最大値と最小値
	float maxRadius_;
	float minRadius_;

};

