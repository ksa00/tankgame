#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"



HUD::HUD(GameObject* parent)
	:GameObject(parent, "HUD"), hHUD_(-1), hNumbers_(-1)
{
}

void HUD::Initialize()
{
	hHUD_ = Image::Load("Image/remainingEnemy.png");
	assert(hHUD_ >= 0);
	hNumbers_ = Image::Load("Image/numbers.png");
	assert(hNumbers_ >= 0);
	for (int i = 0; i <2 ; i++)
	{
		Transform t;
		t.scale_= { 0.5, 0.5, 1.0 };
		t.position_ = { -0.80f + 0.05f*(float)i, 0.90f, 0.0f };
		tNumbers_.push_back(t);
	}
	
}


string HUD::ConstructEnemyNumberString()
{
	int enemies = ((PlayScene*)GetParent())->GetEnemyNum();
	string enemyNumStr = std::to_string(enemies);
	return enemyNumStr;
}


void HUD::Update()
{
	tHud_.scale_ = { 0.5, 0.5, 1.0 };
	tHud_.position_ = { -0.8, 0.90, 0 };
	
}




void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);
	Transform trans;

	
string estr = ConstructEnemyNumberString();
	if (estr.size() < 2)
		estr = std::string(2 - estr.size(), '0') + estr;
	for(int i = 0; i < 2; i++) {
		int n = estr[i] - '0';
		Image::SetRect(hNumbers_, 51.2 *(float)n, 0, 51.2, 78);
		Image::SetTransform(hNumbers_, tNumbers_[i]);
		Image::Draw(hNumbers_);
	}

}


void HUD::Release()
{
}