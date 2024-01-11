#pragma once
#include "Engine/GameObject.h"
#include"Engine//Model.h"
class Bullet :
    public GameObject
{
	int hmodel;
	float bulletSpeed_;
	XMFLOAT3 moveDir_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Bullet(GameObject* parent);
	~Bullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	void SetMoveDir(XMFLOAT3 move) { moveDir_ = move; }
	void setSpeed(float speed) { bulletSpeed_ = speed; }
};

