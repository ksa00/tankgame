#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Camera.h"
#include"Ground.h"
#include"TankHead.h"

enum CAM_TYPE
{
	FIXED_TYPE,
	TPS_NOROT_TYPE,
	TPS_TYPE,
	FPS_TYPE,
	MAX_TYPE
};
//コンストラクタ
Tank::Tank(GameObject* parent)
	: GameObject(parent, "PlayScene"), hmodel(-1),speed_(0.05),
	front({0,0,1,0}), camState_(CAM_TYPE::FIXED_TYPE)
{
}

//初期化
void Tank::Initialize()
{
	
	hmodel = Model::Load("Model/tankbody.fbx");
	assert(hmodel >= 0);
	Instantiate<TankHead>(this);
}

//更新
void Tank::Update()
{
	XMMATRIX rotY = XMMatrixIdentity();
	XMVECTOR move{ 0,0,0,0 };
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;
	if (Input::IsKey(DIK_W))
	{
		dir = 1.0;
	}
	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_S))
	{
		 dir = -1.0;
	}
		
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 1;


	}
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	rotVec = XMVector3TransformCoord(front, rotY);
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + dir * move;
	XMStoreFloat3(&(transform_.position_), pos);

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

	//camera mode
	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		if (camState_ == CAM_TYPE::MAX_TYPE)
			camState_ = CAM_TYPE::FIXED_TYPE;
	}

	switch (camState_)
	{
	case CAM_TYPE::FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3(0, 20, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 15.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case CAM_TYPE::TPS_TYPE:
	{
		Camera::SetTarget(transform_.position_);
		XMVECTOR vEye{ 0, 5, -10, 0 };
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, pos + vEye);
		Camera::SetPosition(camPos);
		break;
	}
	case CAM_TYPE::FPS_TYPE:
	{
		Camera::SetPosition(transform_.position_);
		XMFLOAT3 camTarget;
		XMStoreFloat3(&camTarget, pos + move);
		Camera::SetTarget(camTarget);
		break;
	}
	default:
		break;
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
