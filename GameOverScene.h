#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include"EnemyLevel.h"

class GameOverScene :
    public GameObject
{
    int hImage_;
    Text* pText;
    Text* pText2;
    EnemyLevel* pEL;
public:
    // コンストラクタ
        //引数：parent  親オブジェクト（SceneManager）
    GameOverScene(GameObject* parent);

    //デストラクタ
    ~GameOverScene();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

};

