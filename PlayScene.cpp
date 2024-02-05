#include "PlayScene.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include"Ground.h"
#include"Tank.h"
#include"Enemy.h"
#include"HUD.h"
#include"Engine/SceneManager.h"
//#include"TankHead.h"
namespace {
	const int EnemyNum{ 14 };
}
//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

PlayScene::~PlayScene()
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player=Instantiate<Tank>(this);
	//instantiating enemy
	enemynum = EnemyNum;
	for(int i=0;i<enemynum;i++)
	Instantiate<Enemy>(this);


	Instantiate<HUD>(this);
}

//�X�V
void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

//�`��
void PlayScene::Draw()
{
	
}

//�J��
void PlayScene::Release()
{
}
