#pragma once

#include "KamataEngine.h"
#include <vector>

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
	//// モデルデータ
	//KamataEngine::Model* model_ = nullptr;
	//// ブロック用ワールドトランスフォーム
	//std::vector<WorldTransform*> worldTransformBlocks_;
};
