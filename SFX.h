#pragma once
#include "Singleton.h"
#include <array>
enum eSFX {
	SFX_DAMAGE,
	SFX_SHOT
};

class SFX final : public Singleton<SFX> {
public:
	SFX();

	/// <summary>
	/// 効果音を再生
	/// </summary>
	/// <param name="sfxId">効果音ID</param>
	/// <param name="volume">音量</param>
	void Play(eSFX sfxId, const float& volume) const;

private:
	const static int SFX_NUM = 2; //SFXの数、とりあえず2
	std::array<int, SFX_NUM> idArray_;  //どのeSFXがどの効果音に割り当たっているかを示す
	std::array<int, SFX_NUM> sfx_;      //SFXを格納する配列
};

