#include "StageSide.h"
#include"Engine/Model.h"
StageSide::StageSide(GameObject* parent)
	:GameObject(parent,"StageSide"),hModel_(-1)
{
}

void StageSide::Initialize()
{
	hModel_ = Model::Load("models\\road_3.fbx");
	assert(hModel_ >= 0);
}

void StageSide::Update()
{
}

void StageSide::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void StageSide::Release()
{
}
