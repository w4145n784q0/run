#include "EnemyLevel.h"

EnemyLevel::EnemyLevel(GameObject* parent)
	:GameObject(parent, "EnemyLevel"), 
	 inittimer_(0),
	StandardEnemyPosX_(0), SecondEnemyPos_(0),
	ThroughCount_(0), EnemySpeedSet_(0.1),
	EnemyInitTime_(0.01), SpeedLevel_(1)
{
}

void EnemyLevel::Initialize()
{
}

void EnemyLevel::Update()
{
}

void EnemyLevel::Draw()
{
}

void EnemyLevel::Release()
{
}

void EnemyLevel::EnemyPositionSet()
{
	StandardEnemyPosX_ = rand() % 3 - 1;

	//StandardEnemyPosX_を基準位置として、
	//SecondEnemyPos_にもう一体の敵を出す
	switch (StandardEnemyPosX_)
	{

		//発生位置が-1なら1か2にもう一体を出現
	case -1:
		SecondEnemyPos_ = rand() % 2;
		break;

		//発生位置が0なら-1か1にもう一体を出現
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

		//発生位置が1なら-1か0にもう一体を出現
	case 1:
		SecondEnemyPos_ = rand() % 2 - 1;
		break;
	default:
		break;
	}
}

void EnemyLevel::EnemySpeedUp()
{
	if (ThroughCount_ > 0 && ThroughCount_ % 5 == 0)//5の倍数になったらスピードあげる
	{
		EnemySpeedSet_ += 0.025;
		SpeedLevel_ += 1;
	}
}

void EnemyLevel::EnemyInterval()
{
	if (ThroughCount_ > 0 && ThroughCount_ % 10 == 0)//10の倍数になったら敵の発生間隔あげる
	{
		EnemyInitTime_ += 0.005;
	}
}

void EnemyLevel::EnemyTimeCount()
{
	inittimer_ += EnemyInitTime_;
}

bool EnemyLevel::IsEnemyTimeUp()
{
	if (inittimer_ > 1.0)
		return true;
	else
		return false;
}

void EnemyLevel::PosSetAndLevelUp()
{
	EnemyPositionSet();
	if (!LevelLimit(SpeedLevel_))
	{
		EnemySpeedUp();
		EnemyInterval();
	}
}

void EnemyLevel::EnemySetAfter()
{
	ThroughCount_++;
	inittimer_ = 0;//発生までのタイマーをリセット
}

bool EnemyLevel::LevelLimit(int _Speedphase)
{
	if (_Speedphase >= 10)
		return true;
	else
		return false;
}

void EnemyLevel::SurvivalTimePlus()
{
	SurvivalTime_ += static_cast<float>(1) / 60;
}
