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

void EnemyLevel::EnemySpeedUp()
{
	if (ThroughCount_ > 0 && ThroughCount_ % 5 == 0)//5�̔{���ɂȂ�����X�s�[�h������
	{
		EnemySpeedSet_ += 0.025;
		SpeedLevel_ += 1;
	}
}

void EnemyLevel::EnemyInterval()
{
	if (ThroughCount_ > 0 && ThroughCount_ % 10 == 0)//10�̔{���ɂȂ�����G�̔����Ԋu������
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
	inittimer_ = 0;//�����܂ł̃^�C�}�[�����Z�b�g
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
