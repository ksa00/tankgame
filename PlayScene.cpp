#include "PlayScene.h"
#include"Engine/Model.h"
#include"Ground.h"
#include"Tank.h"
//#include"TankHead.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<Tank>(this);
//	
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
