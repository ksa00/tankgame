#include "Enemy.h"
#include"Engine/Model.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hmodel(-1)
{
	
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hmodel = Model::Load("Model/Enemy.fbx");
	assert(hmodel >= 0);
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
