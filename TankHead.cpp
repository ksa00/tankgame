#include "TankHead.h"
#include"Tank.h"
#include"Bullet.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"),hmodel(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hmodel = Model::Load("Model/tankhead.fbx");
	assert(hmodel >= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		this->transform_.rotate_.y -= 1.5;
	}

	if (Input::IsKey(DIK_RIGHT))
	{
		this->transform_.rotate_.y += 1.5;
	}
	if (Input::IsKeyDown(DIK_SPACE)) {
		XMFLOAT3 CanonToppos =Model::GetBonePosition(hmodel,"CanonHole");
		XMFLOAT3 CanonRootpos = Model::GetBonePosition(hmodel, "CanonRoot");
		XMVECTOR moveDir;
		XMVECTOR vtop = XMLoadFloat3(&CanonToppos);
		XMVECTOR vroot = XMLoadFloat3(&CanonRootpos);
		 moveDir = vtop - vroot;
		moveDir = XMVector3Normalize(moveDir);
		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);

		Bullet* pBullet=Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(CanonToppos);
		pBullet->SetMoveDir(vmove);
		pBullet->setSpeed(0.15);
	}
}

void TankHead::Draw()
{
	Model::SetTransform(hmodel,transform_);
	Model::Draw(hmodel);
}

void TankHead::Release()
{
}
