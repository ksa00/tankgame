#include "GameOver.h"
#include "Engine/Image.h"
#include "Engine/INPUT.h"
#include "Engine/SceneManager.h"
GameOver::GameOver(GameObject* parent)
	:GameObject(parent,"GameOver"),hGameOver(-1)
{
}

void GameOver::Initialize()
{
	hGameOver = Image::Load("Image/GameOver.png");
	assert(hGameOver >= 0);
}

void GameOver::Update()
{
	if (Input::IsKeyDown(DIK_RETURN)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void GameOver::Draw()
{
	Image::SetTransform(hGameOver, transform_);
	Image::Draw(hGameOver);
}

void GameOver::Release()
{
}
