#pragma once
class Score {
public:
	Score();

	void Update();
	void Draw() const;

	/// <summary>
	/// スコアを加算する
	/// </summary>
	/// <param name="score">加算したい数</param>
	void ScorePlus(const int& score);

private:
	int score_;
	int numGraph_[10];	//数字の画像
	int scoreGraph_; //スコアの画像
	int scoreArray_[5];		//スコアを描画するための変数
};

