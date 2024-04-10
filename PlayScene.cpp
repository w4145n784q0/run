#include "PlayScene.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),inittimer_(0)
{
}

void PlayScene::Initialize()
{
	inittimer_ += 0.5;
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	if (inittimer_ > 1.0)
	{
		Instantiate<Enemy>(this);
		inittimer_ = 0;
	}
		
	
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
