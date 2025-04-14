#pragma once
#include "KamataEngine.h"

/// <summary>
/// 自キャラ
/// </summary>
class Player {
public:
	Player();
	~Player();

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, uint32_t textureHandle,Camera*camera);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// カメラ
	KamataEngine::Camera* camera_=nullptr;
};
