#include "PlayScene.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"
#include"EnemyLevel.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),/*inittimer_(0),
	StandardEnemyPosX_(0),SecondEnemyPos_(0),
	ThroughCount_(0),EnemySpeedSet_(0.1),
	EnemyInitTime_(0.01),SpeedLevel_(1),*/
	pText(nullptr), pText2(nullptr),pEL(nullptr)
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<EnemyLevel>(this);
	pText = new Text;
	pText->Initialize();
	pText2 = new Text;
	pText2->Initialize();
	pEL = (EnemyLevel*)FindObject("EnemyLevel");
}

void PlayScene::Update()
{
	if (pEL->IsEnemyTimeUp())//
	{
		/*pEL->EnemyPositionSet();
		if (!(LevelLimit(SpeedLevel_)))
		{
			EnemySpeedUp();
			EnemyInterval();
		}*/
		pEL->PosSetAndLevelUp();
		
		Enemy* pEnemy = Instantiate<Enemy>(this);
		pEnemy->SetPosition(pEL->GetStandardEnemyPosX(), 0.5, 10);
		pEnemy->SetSpeed(pEL->GetEnemySpeed());
		Enemy* pEnemy2 = Instantiate<Enemy>(this);
		pEnemy2->SetPosition(pEL->GetSecondEnemyPosX(), 0.5, 10);
		pEnemy2->SetSpeed(pEL->GetEnemySpeed());

		pEL->EnemySetAfter();
		//ThroughCount_++;
		//inittimer_ = 0;//発生までのタイマーをリセット
	}
	
	if (FindObject("Player") == nullptr)//Player死亡でシーン遷移
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}

	pEL->EnemyTimeCount();
//inittimer_ += EnemyInitTime_;
}

void PlayScene::Draw()
{
	pText->Draw(160, 30, pEL ->GetSpeedLevel());
	pText2->Draw(30, 30, "Level: ");
}

void PlayScene::Release()
{

}

void PlayScene::EnemyPositionSet()
{
	//StandardEnemyPosX_ = rand() % 3 - 1;

	////StandardEnemyPosX_を基準位置として、
	////SecondEnemyPos_にもう一体の敵を出す
	//switch (StandardEnemyPosX_)
	//{

	//	//発生位置が-1なら1か2にもう一体を出現
	//case -1:
	//	SecondEnemyPos_ = rand() % 2;
	//	break;

	//	//発生位置が0なら-1か1にもう一体を出現
	//case 0:
	//	if (rand() % 2 == 0)
	//	{
	//		SecondEnemyPos_ = -1;
	//	}
	//	else
	//	{
	//		SecondEnemyPos_ = 1;
	//	}
	//	break;

	//	//発生位置が1なら-1か0にもう一体を出現
	//case 1:
	//	SecondEnemyPos_ = rand() % 2 - 1;
	//	break;
	//default:
	//	break;
	//}
}

void PlayScene::EnemySpeedUp()
{
	//if (ThroughCount_ > 0 && ThroughCount_ % 5 == 0)//5の倍数になったらスピードあげる
	//{
	//	EnemySpeedSet_ += 0.025;
	//	SpeedLevel_ += 1;
	//}
}

void PlayScene::EnemyInterval()
{
	//if (ThroughCount_ > 0 && ThroughCount_ % 10 == 0)//10の倍数になったら敵の発生間隔あげる
	//{
	//	EnemyInitTime_ += 0.005;
	//}
}

//bool PlayScene::LevelLimit(int _Speedphase)
//{
//	if (_Speedphase >= 10)
//		return true;
//	else
//		return false;
//}
