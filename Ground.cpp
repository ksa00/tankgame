#include "Ground.h"
#include"Engine/Model.h"

//�R���X�g���N�^
Ground::Ground(GameObject* parent)
	: GameObject(parent, "Ground"), hmodel(-1)
{
}

//������
void Ground::Initialize()
{
	hmodel = Model::Load("Model/ground.fbx");
	assert(hmodel >= 0);
}

//�X�V
void Ground::Update()
{
}

//�`��
void Ground::Draw()
{
	Model::SetTransform(hmodel, transform_);
	Model::Draw(hmodel);
}

//�J��
void Ground::Release()
{
}
