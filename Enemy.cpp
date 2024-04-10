#include "Enemy.h"
#include"Engine/Model.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("models\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = XMFLOAT3(0, 0.5, 3.3);
	transform_.scale_ = XMFLOAT3(2.0f, 2.0f, 2.0f);
	transform_.rotate_.y = 180.0f;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
