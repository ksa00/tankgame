#pragma once
#include "Engine/GameObject.h"
//�e�X�g�V�[�����Ǘ�����N���X
class Tank : public GameObject
{
public:
	int hmodel;
	XMVECTOR front;
	float speed_;
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Tank(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
