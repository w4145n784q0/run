#include "PlayScene.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"
#include"EnemyLevel.h"
#include"BeforeStart.h"
#include"Engine/Input.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),
	pText(nullptr), pText2(nullptr),pText3(nullptr),
	pEL(nullptr), IsGameStart_(false)
	,pBS_(nullptr),SurvivalTime_(0.0)
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	pText = new Text;
	pText->Initialize();
	pText2 = new Text;
	pText2->Initialize();
	pText3 = new Text;
	pText3->Initialize();
	pEL = Instantiate<EnemyLevel>(this);//(EnemyLevel*)FindObject("EnemyLevel");
	pBS_ = Instantiate<BeforeStart>(this);
}

void PlayScene::Update()
{
	if (IsGameStart_ == false && Input::IsKeyDown(DIK_SPACE))
	{
		IsGameStart_ = true;
		pBS_->HiddenImage();
	}

	if (IsGameStart_)
	{
		if (!(FindObject("Player") == nullptr))
		{
			SurvivalTime_ += static_cast<float>(1) / 60;
		}

		if (pEL->IsEnemyTimeUp())
		{
			pEL->PosSetAndLevelUp();
			EnemySpawn();
			pEL->EnemySetAfter();
		}

		if (FindObject("Player") == nullptr)//PlayerŽ€–S‚ÅƒV[ƒ“‘JˆÚ
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
		}

		pEL->EnemyTimeCount();
	}
}

void PlayScene::Draw()
{
	pText->Draw(160, 30, pEL ->GetSpeedLevel());
	pText2->Draw(30, 30, "Level: ");
	pText3->Draw(30, 80, SurvivalTime_);
}

void PlayScene::Release()
{

}

void PlayScene::EnemySpawn()
{
	Enemy* pEnemy = Instantiate<Enemy>(this);
	pEnemy->SetPosition(pEL->GetStandardEnemyPosX(), 0.5, 10);
	pEnemy->SetSpeed(pEL->GetEnemySpeed());
	Enemy* pEnemy2 = Instantiate<Enemy>(this);
	pEnemy2->SetPosition(pEL->GetSecondEnemyPosX(), 0.5, 10);
	pEnemy2->SetSpeed(pEL->GetEnemySpeed());
}
