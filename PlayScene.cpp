#include "PlayScene.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),inittimer_(0),
	StandardEnemyPosX_(0),SecondEnemyPos_(0),
	ThroughCount_(0),EnemySpeedSet_(0.1),
	EnemyInitTime_(0.01),Speedphase_(1),
	pText(nullptr), pText2(nullptr)
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
}

void PlayScene::Update()
{
	if (inittimer_ > 1.0)
	{
		EnemyPositionSet();
		if (!(LevelLimit(Speedphase_)))
		{
			EnemySpeedUp();
			EnemyInterval();
		}
		
		Enemy* pEnemy = Instantiate<Enemy>(this);
		pEnemy->SetPosition(StandardEnemyPosX_, 0.5, 10);
		pEnemy->SetSpeed(EnemySpeedSet_);
		Enemy* pEnemy2 = Instantiate<Enemy>(this);
		pEnemy2->SetPosition(SecondEnemyPos_, 0.5, 10);
		pEnemy2->SetSpeed(EnemySpeedSet_);

		ThroughCount_++;
		inittimer_ = 0;//�����܂ł̃^�C�}�[�����Z�b�g
	}
	
	if (FindObject("Player") == nullptr)//Player���S�ŃV�[���J��
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}

	inittimer_ += EnemyInitTime_;
}

void PlayScene::Draw()
{
	pText->Draw(160, 30, Speedphase_);
	pText2->Draw(30, 30, "Level: ");
}

void PlayScene::Release()
{

}

void PlayScene::EnemyPositionSet()
{
	StandardEnemyPosX_ = rand() % 3 - 1;

	//StandardEnemyPosX_����ʒu�Ƃ��āA
	//SecondEnemyPos_�ɂ�����̂̓G���o��
	switch (StandardEnemyPosX_)
	{

		//�����ʒu��-1�Ȃ�1��2�ɂ�����̂��o��
	case -1:
		SecondEnemyPos_ = rand() % 2;
		break;

		//�����ʒu��0�Ȃ�-1��1�ɂ�����̂��o��
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

		//�����ʒu��1�Ȃ�-1��0�ɂ�����̂��o��
	case 1:
		SecondEnemyPos_ = rand() % 2 - 1;
		break;
	default:
		break;
	}
}

void PlayScene::EnemySpeedUp()
{
	if (ThroughCount_ > 0 && ThroughCount_ % 5 == 0)//5�̔{���ɂȂ�����X�s�[�h������
	{
		EnemySpeedSet_ += 0.05;
		Speedphase_ += 1;
	}
}

void PlayScene::EnemyInterval()
{
	if (ThroughCount_ > 0 && ThroughCount_ % 10 == 0)//10�̔{���ɂȂ�����G�̔����Ԋu������
	{
		EnemyInitTime_ += 0.005;
	}
}

bool PlayScene::LevelLimit(int _Speedphase)
{
	if (_Speedphase >= 10)
		return true;
	else
		return false;
}
