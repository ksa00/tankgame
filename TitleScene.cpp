#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"


//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
TitleScene::TitleScene(GameObject * parent)
	: GameObject(parent, "TitleScene"),hTitle(-1)
{
}

//‰Šú‰»
void TitleScene::Initialize()
{
	hTitle = Image::Load("Image/Title.png");//MEMO::先生が作った画像を使っ手申し訳ないです..
	assert(hTitle >= 0);
}

//XV
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//•`‰æ
void TitleScene::Draw()
{
	Image::SetTransform(hTitle, transform_);
	Image::Draw(hTitle);
}

//ŠJ•ú
void TitleScene::Release()
{
}
