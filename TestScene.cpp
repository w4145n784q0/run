#include "TestScene.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
	,EnemyInstantiateTime_(1),TimerOver_(true)
{
}

//������
void TestScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	if (IsTimeOver())
	{ 
		Instantiate<Enemy>(this);
	}
	
}

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}

void TestScene::TimeCount()
{
	EnemyInstantiateTime_ -= 1 / 60;
	if (EnemyInstantiateTime_ < 0)
	{
		EnemyInstantiateTime_ = 0;
		TimerOver_ = true;
	}
}

bool TestScene::IsTimeOver()
{
	if (TimerOver_) {
		return true;
		EnemyInstantiateTime_ = 1;
	}
	return false;
}
