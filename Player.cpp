#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
	
}

void Player::Initialize()
{
	hModel_ = Model::Load("models\\box.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = XMFLOAT3(0,1.0,-2);
}

void Player::Update()
{
	XMVECTOR move{ 0,0,0,0 };//移動ベクトル　移動先

	/*if (Input::IsKey(DIK_UP))
	{
		move = XMVECTOR{ 0,0,1,0 };
	}*/
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.position_.x -= 0.1;
		// move = XMVECTOR{ -1,0,0,0 };
	}
	/*if (Input::IsKey(DIK_DOWN))
	{
		move = XMVECTOR{ 0,0,-1,0 };
	}*/
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.position_.x += 0.1;
		//move = XMVECTOR{ 1,0,0,0 };
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
