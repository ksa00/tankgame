#include "Ground.h"
#include"Engine/Model.h"

//コンストラクタ
Ground::Ground(GameObject* parent)
	: GameObject(parent, "Ground"), hmodel(-1)
{
}

//初期化
void Ground::Initialize()
{
	hmodel = Model::Load("Model/ground.fbx");
	assert(hmodel >= 0);
}

//更新
void Ground::Update()
{
}

//描画
void Ground::Draw()
{
	Model::SetTransform(hmodel, transform_);
	Model::Draw(hmodel);
}

//開放
void Ground::Release()
{
}
