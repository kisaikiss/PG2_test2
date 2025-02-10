#include "DustManager.h"

DustManager::DustManager():kMaxDust_(20){
	//最大値まで埃をだす
	while (dust_.size() < kMaxDust_) {
		dust_.emplace_back(std::make_shared<DustParticle>());
	}
}

bool DustManager::Update() {
	//埃の更新処理
	for (auto it = dust_.begin(); it != dust_.end();) {
		if (!(*it)->Update()) {
			it = dust_.erase(it);
		} else {
			it++;
		}
	}

	//最大数より少なければ最大数まで埃をだす
	while (dust_.size() < kMaxDust_) {
		dust_.emplace_back(std::make_shared<DustParticle>());
	}
	return true;
}

void DustManager::Draw(const Matrix3x3& vpVpMatrix) const {
	//描画
	for (const auto& it : dust_) {
		it->Draw(vpVpMatrix);
	}
}
