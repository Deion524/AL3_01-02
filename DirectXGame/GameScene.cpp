#include "GameScene.h"

#ifdef _DEBUG
#include "imgui.h"
#endif // _DEBUG

using namespace KamataEngine;

/*============================================
                コンストラクタ
============================================*/
GameScene::GameScene() { textureHandle_ = TextureManager::Load("./Resources/sample.png"); }

/*============================================
                デストラクタ
============================================*/
GameScene::~GameScene() {
	delete sprite_;
	delete model_;
	delete debugCamera_;
}

/*============================================
                    初期化
============================================*/
void GameScene::Initialize() {
	// サウンドデータ読み込み
	soundDataHandle_ = Audio::GetInstance()->LoadWave("./Resources/fanfare.wav");
	// 音声再生
	// Audio::GetInstance()->PlayWave(soundDataHandle_);
	voiceHandle_ = Audio::GetInstance()->PlayWave(soundDataHandle_, true);
	// スプライトの初期化
	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	// モデルの初期化
	model_ = Model::Create();
	// ワールドトランスフォーム
	worldTransform_.Initialize();
	// カメラ
	camera_.Initialize();
	// デバッグカメラ
	debugCamera_ = new DebugCamera(1280, 720);
	// ライン描画が参照するカメラを指定する
	PrimitiveDrawer::GetInstance()->SetCamera(&camera_);
	// 軸方向の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	AxisIndicator::GetInstance()->SetTargetCamera(&debugCamera_->GetCamera());
}

/*============================================
                    更新
============================================*/
void GameScene::Update() {
	// スプライトの現在の座標を取得
	Vector2 position = sprite_->GetPosition();
	// 座標を移動させる
	position.x += 2.0f;
	position.y += 1.0f;
	// 移動した座標をスプライトに反映
	sprite_->SetPosition(position);

	// スペースキーが押されたらSEを鳴らす
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		// 音声停止
		Audio::GetInstance()->StopWave(voiceHandle_);
	}

	// デバッグカメラ
	debugCamera_->Update();

	// ImGui更新
#ifdef _DEBUG
	ImGui::ShowDemoWindow();
	ImGui::Begin("Debug");
	ImGui::Text("Kamata Tarou %d.%d.%d", 2025, 12, 31);
	ImGui::InputFloat3("InputFloat", inputFloat3);
	ImGui::SliderFloat3("SliderFloat", inputFloat3, 0.0f, 1.0f);
	ImGui::End();
#endif // _DEBUG
}

/*============================================
                    描画
============================================*/
void GameScene::Draw() {
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//// スプライトの描画処理
	// Sprite::PreDraw(dxCommon->GetCommandList());

	// sprite_->Draw();

	//// スプライトの描画後処理
	// Sprite::PostDraw();

	// 3Dモデルの描画処理
	Model::PreDraw(dxCommon->GetCommandList());

	// 通常時
	//model_->Draw(worldTransform_, camera_, textureHandle_);

	// デバッグ時
	model_->Draw(worldTransform_, debugCamera_->GetCamera(), textureHandle_);

	// ラインを描画する
	PrimitiveDrawer::GetInstance()->DrawLine3d({0, 0, 0}, {0, 10, 0}, {1.0f, 0.0f, 0.0f, 1.0f});

	// 3Dモデルの描画後処理
	Model::PostDraw();


}