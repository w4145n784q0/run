#include "GameOverScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"
#include"EnemyLevel.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOverScene"), hImage_(-1),
	pText(nullptr),pText2(nullptr), pEL(nullptr)
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Initialize()
{
	hImage_ = Image::Load("gameover.png");
	assert(hImage_ >= 0);
	pText = new Text;
	pText->Initialize();
	pText2 = new Text;
	pText2->Initialize();
	pEL = Instantiate<EnemyLevel>(this);
}

void GameOverScene::Update()
{
	if (Input::IsKey(DIK_A))//a押すとリトライ
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}

	if (Input::IsKey(DIK_ESCAPE))//esc押すとタイトル
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void GameOverScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
	/*pText->Draw(400, 600, "Survival Time: ");
	pText2->Draw(800, 600, pEL->GetSurvivalTime() );*/
}

void GameOverScene::Release()
{
}