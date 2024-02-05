#pragma once
#include "Engine/GameObject.h"

class Tank;

//�e�X�g�V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
	Tank* player;
	int enemynum;
public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);
	~PlayScene();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//inline defining
	void DescEnemy() { enemynum--; }
	bool isEnemyleft() { return enemynum > 0; }
	int GetEnemyNum() { return enemynum; }
};