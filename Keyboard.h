#pragma once

#include "Singleton.h"
#include <array>

class Keyboard final : public Singleton<Keyboard> {

	Keyboard() = default;
	friend Singleton< Keyboard >;

public:
	bool update();	//更新

	/// <summary>
	///  keyCodeのキーが押されているフレーム数を返す
	/// </summary>
	/// <param name="keyCode">キーコード</param>
	/// <returns>キーが押されているフレーム数</returns>
	int getPressingCount(int keyCode);

	/// <summary>
	/// keyCodeのキーが離されているフレーム数を取得
	/// </summary>
	/// <param name="keyCode">キーコード</param>
	/// <returns>キーが離されているフレーム数</returns>
	int getReleasingCount(int keyCode);

private:
	static const int KEY_NUM = 256;	//キー総数
	std::array<int, KEY_NUM> _pressingCount;//押されカウンタ
	std::array<int, KEY_NUM> _releasingCount;//離されカウンタ

	/// <summary>
	/// keyCodeが有効なキー番号か問う
	/// </summary>
	/// <param name="keyCode">キーコード</param>
	/// <returns>有効なキー番号か</returns>
	int isAvailableCode(int keyCode);
};