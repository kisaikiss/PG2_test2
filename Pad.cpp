#include "Pad.h"
#include "Keyboard.h"
#include <Novice.h>
#include <string>
#include <algorithm>

using namespace std;

Pad::Pad() {
	_idArray[ePad::PAD_DOWN] = 0;
	_idArray[ePad::PAD_LEFT] = 1;
	_idArray[ePad::PAD_RIGHT] = 2;
	_idArray[ePad::PAD_UP] = 3;
	_idArray[ePad::PAD_A] = 4;
	_idArray[ePad::PAD_X] = 5;
	_idArray[ePad::PAD_Y] = 6;
	_idArray[ePad::PAD_START] = 7;
}

void Pad::Update() {

	//down
	if (Novice::IsPressButton(0, kPadButton1)) {
		pad_[0]++;
	} else {
		pad_[0] = 0;
	}
	//left
	if (Novice::IsPressButton(0, kPadButton2)) {
		pad_[1]++;
	} else {
		pad_[1] = 0;
	}
	//right
	if (Novice::IsPressButton(0, kPadButton3)) {
		pad_[2]++;
	} else {
		pad_[2] = 0;
	}
	//up
	if (Novice::IsPressButton(0, kPadButton0)) {
		pad_[3]++;
	} else {
		pad_[3] = 0;
	}
	//a
	if (Novice::IsPressButton(0, kPadButton10)) {
		pad_[4]++;
	} else {
		pad_[4] = 0;
	}
	//x
	if (Novice::IsPressButton(0, kPadButton12)) {
		pad_[5]++;
	} else {
		pad_[5] = 0;
	}
	//y
	if (Novice::IsPressButton(0, kPadButton13)) {
		pad_[6]++;
	} else {
		pad_[6] = 0;
	}
	//start
	if (Novice::IsPressButton(0, kPadButton4)) {
		pad_[7]++;
	} else {
		pad_[7] = 0;
	}
	Merge();
}

void Pad::Merge() {
	pad_[_idArray[ePad::PAD_LEFT]] = max(pad_[_idArray[ePad::PAD_LEFT]], Keyboard::getIns()->getPressingCount(DIK_LEFT));
	pad_[_idArray[ePad::PAD_UP]] = max(pad_[_idArray[ePad::PAD_UP]], Keyboard::getIns()->getPressingCount(DIK_UP));
	pad_[_idArray[ePad::PAD_RIGHT]] = max(pad_[_idArray[ePad::PAD_RIGHT]], Keyboard::getIns()->getPressingCount(DIK_RIGHT));
	pad_[_idArray[ePad::PAD_DOWN]] = max(pad_[_idArray[ePad::PAD_DOWN]], Keyboard::getIns()->getPressingCount(DIK_DOWN));
	pad_[_idArray[ePad::PAD_LEFT]] = max(pad_[_idArray[ePad::PAD_LEFT]], Keyboard::getIns()->getPressingCount(DIK_A));
	pad_[_idArray[ePad::PAD_UP]] = max(pad_[_idArray[ePad::PAD_UP]], Keyboard::getIns()->getPressingCount(DIK_W));
	pad_[_idArray[ePad::PAD_RIGHT]] = max(pad_[_idArray[ePad::PAD_RIGHT]], Keyboard::getIns()->getPressingCount(DIK_D));
	pad_[_idArray[ePad::PAD_DOWN]] = max(pad_[_idArray[ePad::PAD_DOWN]], Keyboard::getIns()->getPressingCount(DIK_S));
	pad_[_idArray[ePad::PAD_A]] = max(pad_[_idArray[ePad::PAD_A]], Keyboard::getIns()->getPressingCount(DIK_SPACE));
	pad_[_idArray[ePad::PAD_A]] = max(pad_[_idArray[ePad::PAD_A]], Keyboard::getIns()->getPressingCount(DIK_Z));
	pad_[_idArray[ePad::PAD_X]] = max(pad_[_idArray[ePad::PAD_X]], Keyboard::getIns()->getPressingCount(DIK_Q));
	pad_[_idArray[ePad::PAD_Y]] = max(pad_[_idArray[ePad::PAD_Y]], Keyboard::getIns()->getPressingCount(DIK_E));
	pad_[_idArray[ePad::PAD_START]] = max(pad_[_idArray[ePad::PAD_START]], Keyboard::getIns()->getPressingCount(DIK_P));
}

int Pad::Get(ePad eID) const {
	return pad_[_idArray[eID]];
}