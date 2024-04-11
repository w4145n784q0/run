#include "PlayScene.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),inittimer_(0),
	ThroughCount_(0)
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
		StandardEnemyPosX_ = rand() % 3 - 1;
		switch (StandardEnemyPosX_)
		{
		case -1:
			SecondEnemyPos_ = rand() % 2;
			break;
		case 0:
			if (rand() % 2 == 0)
			{
				SecondEnemyPos_ = -1;
			}
			else
			{
				SecondEnemyPos_ = 1;
			}
			break;
		case 1:
			SecondEnemyPos_ = rand() % 2 - 1;
			break;
		default:
			break;
		}

		Enemy* pEnemy = Instantiate<Enemy>(this);
		pEnemy->SetPosition(StandardEnemyPosX_, 0.5, 10);
		Enemy* pEnemy2 = Instantiate<Enemy>(this);
		pEnemy2->SetPosition(SecondEnemyPos_, 0.5, 10);

		ThroughCount_++;
		inittimer_ = 0;
	}
	
	inittimer_ += 0.01;

	if (FindObject("Player") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}

}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
