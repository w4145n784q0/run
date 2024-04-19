#include "GroundObject.h"
#include"Engine/Model.h"

GroundObject::GroundObject(GameObject* parent)
	:GameObject(parent,"GameObject"),hModel_(-1),
	ObjectSpeed_(0.05),inittimer_(0.0),
	ObjectInitTime_(0.01)
{
}

void GroundObject::Initialize()
{
	hModel_ = Model::Load("models\\tree.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.5,0.5,0.5 };
}

void GroundObject::Update()
{
	transform_.position_.z -= ObjectSpeed_;//playScene‚Å“G‚Ì‘¬‚³‚ðƒZƒbƒg
	if (transform_.position_.z <= -4.5)
	{
		KillMe();
	}
}

void GroundObject::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void GroundObject::Release()
{
}

void GroundObject::ObjectPositionSet()
{
	//int i = rand() % 2;
	if (rand() % 2 == 0)
	{
		PosX_ = 2;
	}
	else
	{
		PosX_ = -2;
	}
}

void GroundObject::ObjectTimeCount()
{
	inittimer_ += ObjectInitTime_;
}
