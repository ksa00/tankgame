#pragma once
#include "Engine/GameObject.h"
class Text;
//�e�X�g�V�[�����Ǘ�����N���X
class TitleScene : public GameObject
{
	Text* pText;
	int hTitle;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};