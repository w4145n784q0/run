#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
    float inittimer_;
    signed int StandardEnemyPosX_;
    signed int SecondEnemyPos_;
    int ThroughCount_;

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
};

