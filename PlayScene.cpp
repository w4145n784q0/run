#include "PlayScene.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"
#include"EnemyLevel.h"
#include"BeforeStart.h"
#include"GroundObject.h"
#include"StageSide.h"
#include"Engine/Input.h"
#include"Engine/Image.h"
#include"Engine/Audio.h"
#include"Engine/Camera.h"
#include"Engine/SceneManager.h"
#include<chrono>
#include<thread>

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),
	pText(nullptr), pText2(nullptr),pText3(nullptr),
	pEL(nullptr), IsGameStart_(false)
	,pBS_(nullptr),hSoundSE_(-1),inittime_(0.0),
	ObjectInitTime_(0.01)
	
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	StageSide* pSS_ =  Instantiate<StageSide>(this);
	pSS_->SetPosition(-2, 0, 10);
	StageSide* pSS2_ = Instantiate<StageSide>(this);
	pSS2_->SetPosition(2, 0, 10);

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
	//bool IsGoGameOver = false;
	int i = 0;

	if (IsGameStart_ == false && Input::IsKeyDown(DIK_SPACE))
	{
		Audio::Play(hSoundSE_);
		IsGameStart_ = true;
		pBS_->HiddenImage();
	}

	if (IsGameStart_)
	{
		//�؂̃I�u�W�F�N�g�o��
		if (inittime_ > 1.0)
		{
			GroundObject* pGO = Instantiate<GroundObject>(this);
			pGO->SetPosition(2, 1, 20);
			GroundObject* pGO2 = Instantiate<GroundObject>(this);
			pGO2->SetPosition(-2, 1, 20);
			inittime_ = 0;
		}

		//���@���������Ă���Ԏ��Ԃ𐔂���
		if (!(FindObject("Player") == nullptr))
		{
			pEL->SurvivalTimePlus();
		}

		//���Ԋu�œG���o��
		if (pEL->IsEnemyTimeUp())
		{
			pEL->PosSetAndLevelUp();
			EnemySpawn();
			pEL->EnemySetAfter();
		}

		//Player���S�ŃV�[���J��
		if (FindObject("Player") == nullptr)
		{
			float init = 0.0;
			float nextscene = 0.3;
			int j = rand() % 10 + 1;
			
			while (init <= 1)
			{
				//Camera::SetPosition(XMFLOAT3(0, j, -6));
				Camera::SetTarget(XMFLOAT3(0, j, 0));
				init += nextscene;
				if (init >= 1.1)
					break;
			}
			std::this_thread::sleep_for(std::chrono::seconds(1));
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
		}

		pEL->EnemyTimeCount();
		inittime_ += ObjectInitTime_;
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
	pEnemy->SetPosition(pEL->GetStandardEnemyPosX(), 0.5, 20);
	pEnemy->SetSpeed(pEL->GetEnemySpeed());
	Enemy* pEnemy2 = Instantiate<Enemy>(this);
	pEnemy2->SetPosition(pEL->GetSecondEnemyPosX(), 0.5, 20);
	pEnemy2->SetSpeed(pEL->GetEnemySpeed());
}

