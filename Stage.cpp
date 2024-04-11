#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hModel_(-1)
{
}

void Stage::Initialize()
{
	hModel_ = Model::Load("models\\road5.fbx");
	assert(hModel_ >= 0); 
	transform_.position_ = XMFLOAT3(0, 0, 0);
	Camera::SetPosition(XMFLOAT3(0, 5, -8));
	Camera::SetTarget(XMFLOAT3(0, 2, 0));
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Stage::Release()
{
}
