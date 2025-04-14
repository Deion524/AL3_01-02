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
    // モデルデータ解放
	delete model_;
    // 自キャラの解放
	delete player_;
}

/*============================================
                    初期化
============================================*/
void GameScene::Initialize() {
    // テクスチャ読み込み
	textureHandle_ = TextureManager::Load("./Resources/uvChecker.png");
    // 3Dモデルデータ生成
	model_->Create();
    // カメラ初期化
	camera_.Initialize();
    // 自キャラの生成
	player_ = new Player();
    // 自キャラの初期化
	player_->Initialize(model_, textureHandle_,&camera_);
}

/*============================================
                    更新
============================================*/
void GameScene::Update() {
    // 自キャラの更新
	player_->Update();
}

/*============================================
                    描画
============================================*/
void GameScene::Draw() {
	// 自キャラの描画
	player_->Draw();
}