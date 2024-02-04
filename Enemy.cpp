#include "Enemy.h"
#include"Engine/Model.h"
#include"Engine//SphereCollider.h"
#include"Ground.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hmodel(-1)
{
	
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hmodel = Model::Load("Model/myenemy.fbx");
	assert(hmodel >= 0);
	//animationpart
	Model::SetAnimFrame(hmodel, 0, 60, 1);
	float x = (float)rand() / RAND_MAX;//0-1random numbers
	x = 2.0 * x;//0-2random numbers
	transform_.position_.x = 25.0 * (x - 1.0);//25*(-1.0-1.0)random numbers
	float z = (float)rand() / RAND_MAX;//0-1Randomnumbers
	z = 2.0 * z;//0-2random numbers
	transform_.position_.z = 25.0 * (z - 1.0);//25*(-1.0-1.0)random numbers
	transform_.position_.y = 0;

	Ground* ptrground = (Ground*)FindObject("Ground");
	int hGmodel = ptrground->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true) {
		transform_.position_.y = -data.dist + 0.5;
	}
	SphereCollider* spc = new SphereCollider({ 0,0,0 }, 0.5);
	AddCollider(spc);
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hmodel, transform_);
	Model::Draw(hmodel);
}

void Enemy::Release()
{
}
