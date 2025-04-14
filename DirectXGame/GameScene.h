#pragma once

#include "KamataEngine.h"
#include "Player.h"

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
	// モデルデータ
	KamataEngine::Model* model_ = nullptr;
	// カメラ
	KamataEngine::Camera camera_;
	// 自キャラ
	Player* player_ = nullptr;
};
