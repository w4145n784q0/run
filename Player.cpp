#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Audio.h"
#include"Engine/Camera.h"
#include"Engine/SphereCollider.h"
#include<chrono>
#include<thread>

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1),
	hSound_(-1)
{
	
}

void Player::Initialize()
{
//Animated Characters 2\\Model\\characterMedium.fbx
	hModel_ = Model::Load("models\\ambulance_2.fbx");
	//hModel_ = Model::Load("models\\box.fbx");
	assert(hModel_ >= 0);
	hSound_ = Audio::Load("Sound\\maou_se_battle_explosion06.wav");
	assert(hSound_  >= 0);
	transform_.position_ = XMFLOAT3(0.5,1.0,-2);
	transform_.scale_ = XMFLOAT3(0.005,0.005,0.005);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.2f);
	AddCollider(collision);
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		if (transform_.position_.x < -1.0)
		{
			transform_.position_.x = -1.0;
		}
		transform_.position_.x -= 0.1;
	}
	
	if (Input::IsKey(DIK_RIGHT))
	{
		if(transform_.position_.x > 1.0)
		{
			transform_.position_.x = 1.0;
		}
		transform_.position_.x += 0.1;	
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	Audio::Play(hSound_);

	/*Camera::SetPosition(XMFLOAT3(0, 3, -6));
	Camera::SetTarget(XMFLOAT3(0, 2, 0));*/
	KillMe();
}