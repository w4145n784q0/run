#pragma once
#include "Engine/GameObject.h"
#include"Engine/Text.h"
#include "EnemyLevel.h"
#include "BeforeStart.h"
#include"GroundObject.h"

class PlayScene :
    public GameObject
{
    Text* pText;
    Text* pText2;
    Text* pText3;
    EnemyLevel* pEL;
    bool IsGameStart_;
    BeforeStart* pBS_;
   // GroundObject* pGO_;
    int hSoundSE_;
    float inittime_;
    float ObjectInitTime_;
    int ShakeCount_;
    bool IsShakeEnd_;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    PlayScene(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //敵を出す
    void EnemySpawn();
};

