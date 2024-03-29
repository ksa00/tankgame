#pragma once
#include "Engine/GameObject.h"
//テストシーンを管理するクラス
class Tank : public GameObject
{
public:
	int hmodel;
	int camState_;
	XMVECTOR front;
	float speed_;
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Tank(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};
