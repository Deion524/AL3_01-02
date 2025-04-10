#pragma once

#include "KamataEngine.h"

class GameScene {
public:
	GameScene();
	~GameScene();

public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// サウンドハンドル
	uint32_t soundDataHandle_ = 0;
	// 音声再生ハンドル
	uint32_t voiceHandle_ = 0;
	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	// モデル
	KamataEngine::Model* model_ = nullptr;
	// ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;
	// カメラ
	KamataEngine::Camera camera_;
	// デバッグカメラ
	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	// imguiインプットfloat
	float inputFloat3[3] = {0.0f, 0.0f, 0.0f};
};
