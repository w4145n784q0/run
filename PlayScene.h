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
    Text* pText4;
    EnemyLevel* pEL;
    bool IsGameStart_;
    BeforeStart* pBS_;
    int hSoundSE_;
    float inittime_;//オブジェクト発生までのインターバル　1になったら敵が発生
    float ObjectInitTime_;//オブジェクトの生成までの時間　inittimerから引く数　
    int ShakeCount_;//振動したカウント
    bool IsShakeEnd_;//振動終わったか
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

