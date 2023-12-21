#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Ground.h"

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
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
			XMVECTOR rotVec = XMVector3TransformCoord(front, rotY);
		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_S))
	{
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		XMVECTOR rotVec = XMVector3TransformCoord(front, rotY);
		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos -move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
		
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 1;


	}
	Ground* pground = (Ground*)FindObject("Ground");
	int hGmodel = pground->GetModelHandle();
	RayCastData data;

	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);
	if (data.hit == true) 
	{
		transform_.position_.y = -data.dist;
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
