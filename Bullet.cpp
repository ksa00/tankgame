#include "Bullet.h"
#include"Engine//Model.h"
#include"Engine/SphereCollider.h"
#include"PlayScene.h"
#include"Engine/Debug.h"
Bullet::Bullet(GameObject* parent)
	:GameObject(parent,"Bullet"),hmodel(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hmodel = Model::Load("Model/Bullet.fbx");
	assert(hmodel >= 0);
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
	AddCollider(collider);
	playscene_ = (PlayScene*)GetParent();
}

void Bullet::Update()
{
	transform_.position_.x = transform_.position_.x+moveDir_.x*bulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
	moveDir_ = { moveDir_.x,moveDir_.y - 0.01f,moveDir_.z };
	if (transform_.position_.y < -10)
		KillMe();

}

void Bullet::Draw()
{
	Model::SetTransform(hmodel, transform_);
	Model::Draw(hmodel);
}

void Bullet::Release()
{
}

void Bullet::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy") {
		playscene_->DescEnemy();
		pTarget->KillMe();
			
		
	}
	this->KillMe();
}
