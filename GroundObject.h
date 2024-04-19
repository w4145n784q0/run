#pragma once
#include "Engine/GameObject.h"
class GroundObject :
    public GameObject
{
    int hModel_;
    float ObjectSpeed_;
    float inittimer_;
    float ObjectInitTime_;
    float PosX_;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    GroundObject(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //
    void ObjectPositionSet();

    //
    void ObjectTimeCount();

    float GetPosX() { return PosX_; }
};

