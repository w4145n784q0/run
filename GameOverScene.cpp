#include "GameOverScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOverScene"), hImage_(-1)
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Initialize()
{
	hImage_ = Image::Load("PacMasoYouDead.png");
	assert(hImage_ >= 0);
}

void GameOverScene::Update()
{
	if (Input::IsKey(DIK_A))//a�����ƃ��g���C
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}

	if (Input::IsKey(DIK_ESCAPE))//esc�����ƃ^�C�g��
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void GameOverScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void GameOverScene::Release()
{
}
