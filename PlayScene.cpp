#include "PlayScene.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"
#include"EnemyLevel.h"
#include"BeforeStart.h"
#include"Engine/Input.h"
#include"Engine/Image.h"
#include"Engine/Audio.h"
#include"Engine/SceneManager.h"
#include<chrono>
#include<thread>

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),
	pText(nullptr), pText2(nullptr),pText3(nullptr),
	pEL(nullptr), IsGameStart_(false)
	,pBS_(nullptr),//SurvivalTime_(0.0),
	hSoundSE_(-1)
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
	hSoundSE_ = Audio::Load("Sound\\maou_se_sound_whistle01.wav");
	assert(hSoundSE_ >= 0);
}

void PlayScene::Update()
{
	if (IsGameStart_ == false && Input::IsKeyDown(DIK_SPACE))
	{
		Audio::Play(hSoundSE_);
		IsGameStart_ = true;
		pBS_->HiddenImage();
	}

	if (IsGameStart_)
	{
		//Ž©‹@‚ª¶‘¶‚µ‚Ä‚¢‚éŠÔŽžŠÔ‚ð”‚¦‚é
		if (!(FindObject("Player") == nullptr))
		{
			pEL->SurvivalTimePlus();
		}

		//ˆê’èŠÔŠu‚Å“G‚ðo‚·
		if (pEL->IsEnemyTimeUp())
		{
			pEL->PosSetAndLevelUp();
			EnemySpawn();
			pEL->EnemySetAfter();
		}

		//PlayerŽ€–S‚ÅƒV[ƒ“‘JˆÚ
		if (FindObject("Player") == nullptr)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
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
	pText3->Draw(30, 80, pEL->GetSurvivalTime());
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
