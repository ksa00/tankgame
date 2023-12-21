#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"

//コンストラクタ
Tank::Tank(GameObject* parent)
	: GameObject(parent, "PlayScene"), hmodel(-1),speed_(0.05),front({0,0,1,0})
{
}

//初期化
void Tank::Initialize()
{
	hmodel = Model::Load("Model/tankbody.fbx");
	assert(hmodel >= 0);
}

//更新
void Tank::Update()
{
	if (Input::IsKey(DIK_W))
	{
		XMVECTOR move;
		move = speed_ * front;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_A))
	{

	}
	if (Input::IsKey(DIK_S))
	{

		XMVECTOR move;
		move = speed_ * front;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos -
			move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
		
	if (Input::IsKey(DIK_D))
	{
		

	}
}

//描画
void Tank::Draw()
{
	Model::SetTransform(hmodel, transform_);
	Model::Draw(hmodel);
}

//開放
void Tank::Release()
{
}
