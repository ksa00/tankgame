#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{	private:
	int hmodel ;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TankHead(GameObject* parent);
	~TankHead();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	int GetModelHandle() { return hmodel; }
};