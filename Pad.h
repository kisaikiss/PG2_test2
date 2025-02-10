#pragma once
#include "Singleton.h"
#include <array>

enum ePad {
	PAD_LEFT,
	PAD_UP,
	PAD_RIGHT,
	PAD_DOWN,
	PAD_A,
	PAD_X,
	PAD_Y,
	PAD_START
};

class Pad final : public Singleton<Pad> {

public:
	Pad();
	~Pad() = default;
	void Update();

	/// <summary>
	/// 渡されたパッドキー番号の入力フレーム数を返す
	/// </summary>
	/// <param name="eID">パッドキー番号</param>
	/// <returns>入力フレーム数</returns>
	int Get(ePad eID) const; 

private:
	/// <summary>
	/// キーボード入力とマージする
	/// </summary>
	void Merge();

	const static int PAD_KEY_NUM = 16;
	std::array<int, PAD_KEY_NUM> _idArray;  //どのボタンがどのボタンに割り当たっているかを示す
	std::array<int, PAD_KEY_NUM> pad_;      //16ボタンのpad入力状態格納

};
