#include "PlayScene.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"
#include"Engine/Input.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),inittimer_(0)
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
}

void PlayScene::Update()
{
	
	if (inittimer_ > 1.0)
	{
		Enemy *pEnemy = Instantiate<Enemy>(this);

		inittimer_ = 0;

	}
	inittimer_ += 0.01;
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
