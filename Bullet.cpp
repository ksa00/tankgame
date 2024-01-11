#include "Bullet.h"
#include"Engine//Model.h"
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
}

void Bullet::Update()
{
	transform_.position_.x = transform_.position_.x+moveDir_.x*bulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
}

void Bullet::Draw()
{
	Model::SetTransform(hmodel, transform_);
	Model::Draw(hmodel);
}

void Bullet::Release()
{
}
