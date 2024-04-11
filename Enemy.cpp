#include "Enemy.h"
#include"Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("models\\Player.fbx");
	assert(hModel_ >= 0);
	
	//FirstEnemyPosition(transform_.position_.x);
	transform_.rotate_.y = 180.0f;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
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

void Enemy::FirstEnemyPosition(int _xpos)
{
	
	firstpos_ = _xpos;
}
