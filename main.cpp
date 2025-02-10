#include <Novice.h>
#include <Keyboard.h>
#include <Pad.h>
#include <Define.h>
#include "Looper.h"
#include "Score.h"


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	//ループ
	Looper* looper = new Looper;

	//BGM
	int musicSoundHandle = Novice::LoadAudio("./Resources/Sounds/BGM.mp3");
	int musicPlayHandle = -1;

	//乱数を使えるようにする
	unsigned int currentTime = static_cast<unsigned int>(time(nullptr));
	srand(currentTime);
	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		Keyboard::getIns()->update();   //キーボードの更新
		Pad::getIns()->Update();        //ジョイパッドの更新


		//BGMを鳴らす
		if (!Novice::IsPlayingAudio(musicPlayHandle) || musicPlayHandle == -1) {
			musicPlayHandle = Novice::PlayAudio(musicSoundHandle, 1, 0.3f);
		}

		if (!looper->Loop()) {
			break;
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Keyboard::getIns()->getPressingCount(DIK_ESCAPE) > 0 && Keyboard::getIns()->getReleasingCount(DIK_ESCAPE) == 0) {
			break;
		}
	}
	//ループの破棄
	delete looper;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

/*Player* player = new Player();
	Camera* camera = new Camera();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		Keyboard::getIns()->update();   //キーボードの更新
		Pad::getIns()->update();        //ジョイパッドの更新


#pragma region 更新処理
		//リセット
		if (Keyboard::getIns()->getPressingCount(DIK_R) == 1) {
			delete player;
			delete camera;
			player = new Player;
			camera = new Camera;
		}

		player->Update();
		camera->Update();
#pragma endregion

#pragma region 描画処理
		Novice::DrawBox(0, 0, 1280, 720, 0.f, BLACK, kFillModeSolid);
		camera->Draw();
		player->Draw(camera->GetVpVpMatrix());
#pragma endregion

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Keyboard::getIns()->getPressingCount(DIK_ESCAPE) > 0 && Keyboard::getIns()->getReleasingCount(DIK_ESCAPE) == 0) {
			break;
		}
	}
	delete player;
	delete camera;*/