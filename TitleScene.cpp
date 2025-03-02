#include "TitleScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"), hImage_(-1)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	hImage_ = Image::Load("title.png");
	assert(hImage_ >= 0);
}

void TitleScene::Update()
{
	if (Input::IsKey(DIK_SPACE))//�X�y�[�X�L�[����������Q�[���X�^�[�g
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void TitleScene::Release()
{
}
