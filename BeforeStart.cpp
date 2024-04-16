#include "BeforeStart.h"
#include"Engine/Image.h"
BeforeStart::BeforeStart(GameObject* parent)
	:GameObject(parent, "PlayScene"), hImage_(-1)
{
}

void BeforeStart::Initialize()
{
	hImage_ = Image::Load("PressStart.png");
	assert(hImage_ >= 0);
	transform_.position_ = XMFLOAT3(0, 0, 0);

}

void BeforeStart::Update()
{
	
}

void BeforeStart::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void BeforeStart::Release()
{
	
}

void BeforeStart::HiddenImage()
{
	Image::SetAlpha(hImage_, 0);
}

