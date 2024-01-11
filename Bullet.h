#pragma once
#include "Engine/GameObject.h"
#include"Engine//Model.h"
class Bullet :
    public GameObject
{
	int hmodel;
	float bulletSpeed_;
	XMFLOAT3 moveDir_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Bullet(GameObject* parent);
	~Bullet();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	void SetMoveDir(XMFLOAT3 move) { moveDir_ = move; }
	void setSpeed(float speed) { bulletSpeed_ = speed; }
};

