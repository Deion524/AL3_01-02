#include "GameScene.h"

using namespace KamataEngine;

/*============================================
				コンストラクタ
============================================*/
GameScene::GameScene() {

}

/*============================================
                デストラクタ
============================================*/
GameScene::~GameScene() {
 //   // モデルデータ解放
	//delete model_;
	//for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
	//	delete worldTransformBlock;
	//}
	//worldTransformBlocks_.clear();
}

/*============================================
                    初期化
============================================*/
void GameScene::Initialize() {
 //   // モデルデータ生成
	//model_->Create();
	//// 要素数
	//const uint32_t kNumBlockHrizonal = 20;
	//// ブロック1個分の横幅
	//const float kBlockWidth = 2.0f;
	//// 要素数を変更する
	//worldTransformBlocks_.resize(kNumBlockHrizonal);

	//// キューブの生成
	//for (uint32_t i = 0; i < kNumBlockHrizonal; ++i) {
	//	worldTransformBlocks_[i] = new WorldTransform();
	//	worldTransformBlocks_[i].Initialize();
	//}
}

/*============================================
                    更新
============================================*/
void GameScene::Update() {

}

/*============================================
                    描画
============================================*/
void GameScene::Draw() {

}