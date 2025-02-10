#include "Score.h"
#include <Novice.h>
#include <math.h>

Score::Score() {
	score_ = 0;
	//画像読み込み
	numGraph_[0] = Novice::LoadTexture("./Resources/Images/0.png");
	numGraph_[1] = Novice::LoadTexture("./Resources/Images/1.png");
	numGraph_[2] = Novice::LoadTexture("./Resources/Images/2.png");
	numGraph_[3] = Novice::LoadTexture("./Resources/Images/3.png");
	numGraph_[4] = Novice::LoadTexture("./Resources/Images/4.png");
	numGraph_[5] = Novice::LoadTexture("./Resources/Images/5.png");
	numGraph_[6] = Novice::LoadTexture("./Resources/Images/6.png");
	numGraph_[7] = Novice::LoadTexture("./Resources/Images/7.png");
	numGraph_[8] = Novice::LoadTexture("./Resources/Images/8.png");
	numGraph_[9] = Novice::LoadTexture("./Resources/Images/9.png");
	scoreGraph_ = Novice::LoadTexture("./Resources/Images/score.png");

	//実際に描画する値
	for (int i = 0; i < 5; i++) {
		scoreArray_[i] = 0;
	}
}

void Score::Update() {
	//描画するためにスコアの計算
	int scoreCounter = 4;
	int scoreTmp = score_;
	for (int i = 0; i < 5; i++) {
		scoreArray_[i] = scoreTmp / static_cast<int>(powf(10.0f, static_cast<float>(scoreCounter)));
		scoreTmp %= static_cast<int>(powf(10.0f, static_cast<float>(scoreCounter)));
		scoreCounter--;
	}
}

void Score::Draw() const {
	Novice::DrawSprite(0, 12, scoreGraph_, 1.0f, 1.0f, 0.0f, WHITE);
	//Arrayをもとに描画
	for (int i = 0; i < 5; i++) {
		Novice::DrawSprite(230 + i * 40, 32, numGraph_[scoreArray_[i]], 1.0f, 1.0f, 0.0f, WHITE);
	}
}

void Score::ScorePlus(const int& score) {
	score_ += score;
} 
