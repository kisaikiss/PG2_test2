#include "EnemyManager.h"
#include "Define.h"
#include "Collision.h"
#include "SFX.h"

using namespace std;

EnemyManager::EnemyManager() {
	//敵をリストに追加
	enemyList_.emplace_back(make_shared<Enemy>());

	//スコアのスマートポインタ
	score_ = make_shared<Score>();
}

bool EnemyManager::Update(Player& player) {
	//敵がいなければ追加
	if (enemyList_.empty()) {
		enemyList_.emplace_back(make_shared<Enemy>());
	}

	//敵の更新処理
	//Updateがfalseなら消す
	for (auto it = enemyList_.begin(); it != enemyList_.end();) {
		if (!(*it)->Update()) {
			it = enemyList_.erase(it);
		} else {

			it++;
		}
	}

	//敵とプレイヤー、プレイヤーの弾との当たり判定
	for (auto it = enemyList_.begin(); it != enemyList_.end(); it++) {
		for (auto bullet = player.bullet_.begin(); bullet != player.bullet_.end();) {
			if (BoxCollision((*bullet), (*it))) {
				(*it)->TakeDamage();
				bullet = player.bullet_.erase(bullet);

				//スコアを加算
				score_->ScorePlus(100);
				SFX::getIns()->Play(eSFX::SFX_DAMAGE, 0.5f);
				break;
			} else {
				bullet++;
			}
		}
		if (BoxCollision((*it), &player)) {
			player.TakeDamage();
		}
	}
	score_->Update();

	return true;
}

void EnemyManager::Draw(const Matrix3x3& vpVpMatrix) const {
	for (const auto& enemy : enemyList_) {
		enemy->Draw(vpVpMatrix);
	}
	score_->Draw();
}
