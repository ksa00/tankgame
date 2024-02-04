#include "PlayScene.h"
#include"Engine/Model.h"
#include"Engine/Text.h"
#include"Engine/Camera.h"
#include"Ground.h"
#include"Tank.h"
#include"Enemy.h"
#include"HUD.h"
#include"Engine/SceneManager.h"
//#include"TankHead.h"
namespace {
	const int EnemyNum{ 8 };
}
//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),pText(nullptr)
{
}

PlayScene::~PlayScene()
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player=Instantiate<Tank>(this);
	//instantiating enemy
	enemynum = EnemyNum;
	for(int i=0;i<enemynum;i++)
	Instantiate<Enemy>(this);

	pText = new Text;
	pText->Initialize();
	Instantiate<HUD>(this);
}

//更新
void PlayScene::Update()
{
	//moving camera along with tank
	//Camera::SetTarget(player->GetPosition());
	//XMFLOAT3 camPos = player->GetPosition();
	//camPos.y += 8;
	//camPos.z -= 15;
	//Camera::SetPosition(camPos);
	if (FindObject("Enemy") == nullptr) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

//描画
void PlayScene::Draw()
{
	//pText->Draw(30, 30, "HAROOO!!");
}

//開放
void PlayScene::Release()
{
}
