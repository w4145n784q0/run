#include "Enemy.h"
#include"Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1),time_(2)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("models\\Player.fbx");
	assert(hModel_ >= 0);

	int EnemyposX = rand() % 3;
	transform_.position_ = XMFLOAT3(EnemyposX-1, 0.5, 10);
	//transform_.scale_ = XMFLOAT3(2.0f, 2.0f, 2.0f);
	transform_.rotate_.y = 180.0f;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0f);
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= 0.1;
	if (transform_.position_.z <= -4.0)
	{
		KillMe();
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

//void Enemy::Timer()
//{
//	time
//	if()
//}
