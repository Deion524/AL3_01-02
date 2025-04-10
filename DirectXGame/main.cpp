#include <Windows.h>

#include "GameScene.h"
#include "KamataEngine.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	KamataEngine::Initialize();

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// ImGuiManagerのインスタンス取得
	ImGuiManager* imguiManager = ImGuiManager::GetInstance();

	// ゲームシーンのインスタンス生成
	GameScene* gameScene = new GameScene();
	// ゲームシーンの初期化
	gameScene->Initialize();

	// メインループ
	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		// ImGui受付開始
		imguiManager->Begin();

		// ゲームシーンの更新処理
		gameScene->Update();

		// ImGui受付終了
		imguiManager->End();

		// 描画開始
		dxCommon->PreDraw();

		// ゲームシーンの描画処理
		gameScene->Draw();

		// 軸表示の描画
		AxisIndicator::GetInstance()->Draw();

		// ImGui描画
		imguiManager->Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	// インスタンス削除
	delete gameScene;
	gameScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}
