#pragma once
#include "Engine/GameObject.h"

class Tank;

//テストシーンを管理するクラス
class PlayScene : public GameObject
{
	Tank* player;
	int enemynum;
public:

	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);
	~PlayScene();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//inline defining
	void DescEnemy() { enemynum--; }
	bool isEnemyleft() { return enemynum > 0; }
	int GetEnemyNum() { return enemynum; }
};