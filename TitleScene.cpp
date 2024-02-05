#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include"Engine/Text.h"

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
TitleScene::TitleScene(GameObject * parent)
	: GameObject(parent, "TitleScene"),hTitle(-1),pText(nullptr)
{
}

//‰Šú‰»
void TitleScene::Initialize()
{
	hTitle = Image::Load("Image/Title.png");//MEMO::先生が作った画像を使っ手申し訳ないです..
	assert(hTitle >= 0);
	pText = new Text;
	pText->Initialize();
}

//XV
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//•`‰æ(
void TitleScene::Draw()
{
	pText->Draw(475, 150, "PRESS ENTER TO PLAY!!!");
	Image::SetTransform(hTitle, transform_);
	Image::Draw(hTitle);
}

//ŠJ•ú
void TitleScene::Release()
{
}
