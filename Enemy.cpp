#include "Enemy.h"
#include"Engine/Model.h"
#include "Engine/SphereCollider.h"



Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1),EnemySpeed_(0)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("models\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.rotate_.y = 180.0f;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= EnemySpeed_;
	if (transform_.position_.z <= -4.5)
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
