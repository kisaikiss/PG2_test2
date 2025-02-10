#pragma once
//矩形同士の当たり判定
template <typename T, typename U>
inline bool BoxCollision(T objA, U objB) {
	if (objB->GetPos().x - objB->GetWidthHalf() < objA->GetPos().x + objA->GetWidthHalf() && objA->GetPos().x - objA->GetWidthHalf() < objB->GetPos().x + objB->GetWidthHalf()) {
		if (objB->GetPos().y - objB->GetHeightHalf() < objA->GetPos().y + objA->GetHeightHalf() && objA->GetPos().y - objA->GetHeightHalf() < objB->GetPos().y + objB->GetHeightHalf()) {
			return true;
		}
		return false;
	}
	return false;
}