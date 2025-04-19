#include "GameScene.h"
#include "Matrix4x4Functions.h"

using namespace KamataEngine;
// using namespace std;

/*============================================
                コンストラクタ
============================================*/
GameScene::GameScene() {}

/*============================================
                デストラクタ
============================================*/
GameScene::~GameScene() {
	// モデルデータ解放
	delete model_;

	delete matrix4x4Func;

	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			delete worldTransformBlock;
		}
	}
	worldTransformBlocks_.clear();
	delete debugCamera_;
}

/*============================================
                    初期化
============================================*/
void GameScene::Initialize() {
	// テクスチャ読み込み
	textureHandle_ = TextureManager::Load("./Resources/cube/cube.jpg");
	// モデルデータ生成
	model_ = Model::Create();

	matrix4x4Func = new Matrix4x4Functions();

	// 要素数
	const uint32_t kNumBlockVertical = 10;
	const uint32_t kNumBlockHrizonal = 20;
	// ブロック1個分の横幅
	const float kBlockWidth = 2.0f;
	const float kBlockHeight = 2.0f;
	// 要素数を変更する
	worldTransformBlocks_.resize(kNumBlockVertical);
	// 列数を設定
	for (uint32_t i = 0; i < kNumBlockVertical; ++i) {
		worldTransformBlocks_[i].resize(kNumBlockHrizonal);
	}
	// キューブの生成
	for (uint32_t i = 0; i < kNumBlockVertical; ++i) {
		for (uint32_t j = 0; j < kNumBlockHrizonal; ++j) {
				worldTransformBlocks_[i][j] = new WorldTransform();
				worldTransformBlocks_[i][j]->Initialize();
				if ((i + j) % 2 != 0) {
				    continue;
			    }
				worldTransformBlocks_[i][j]->translation_.x = kBlockWidth * j;
				worldTransformBlocks_[i][j]->translation_.y = kBlockHeight * i;
		}
	}

	// カメラ
	camera_.Initialize();
	// デバッグカメラ
	debugCamera_ = new DebugCamera(1280, 720);
}

/*============================================
                    更新
============================================*/
void GameScene::Update() {
	// ブロックの更新
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			if (!worldTransformBlock) {
				continue;
			}
			// アフィン変換行列作成
			worldTransformBlock->matWorld_ = matrix4x4Func->MakeAffineMatrix({1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 0.0f}, worldTransformBlock->translation_);
			// 定数バッファに転送
			worldTransformBlock->TransferMatrix();
		}
	}

	#ifdef _DEBUG
	if (Input::GetInstance()->TriggerKey(DIK_RETURN)) {
		if (isDebugCameraActive_) {
			isDebugCameraActive_ = false;
		} else {
			isDebugCameraActive_ = true;
		}
	}
#endif // _DEBUG

	if (isDebugCameraActive_) {
		// デバッグカメラ
		debugCamera_->Update();
		camera_.matView = debugCamera_->GetCamera().matView;
		camera_.matProjection = debugCamera_->GetCamera().matProjection;
		// ビュープロジェクション行列の転送
		camera_.TransferMatrix();
	} else {
		// ビュープロジェクション行列の更新と転送
		camera_.UpdateMatrix();
	}
}

/*============================================
                    描画
============================================*/
void GameScene::Draw() {

	// ブロックの描画
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {

			DirectXCommon* dxCommon = DirectXCommon::GetInstance();

			// 3Dモデル描画前処理
			Model::PreDraw(dxCommon->GetCommandList());

			// 3Dモデル描画
			model_->Draw(*worldTransformBlock, camera_, textureHandle_);

			// 3Dモデル描画後処理
			Model::PostDraw();
		}
	}
}