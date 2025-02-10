#include "SFX.h"
#include <Novice.h>

SFX::SFX() {
	//idArrayに数字を割り当て(被らないように) idArray_[eSFX::SFX_] = ;
	idArray_[eSFX::SFX_DAMAGE] = 0;
	idArray_[eSFX::SFX_SHOT] = 1;

	//効果音をロード sfx_[idArray_[eSFX::SFX_]] = Novice::LoadAudio("./Resources/Sounds/SFX.mp3");
	sfx_[idArray_[eSFX::SFX_DAMAGE]] = Novice::LoadAudio("./Resources/Sounds/damage.wav");
	sfx_[idArray_[eSFX::SFX_SHOT]] = Novice::LoadAudio("./Resources/Sounds/shot.wav");
}

void SFX::Play(eSFX sfxId, const float& volume) const {
	Novice::PlayAudio(sfx_[idArray_[sfxId]], false, volume);
}
