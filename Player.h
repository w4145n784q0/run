#pragma once
#include "Engine/GameObject.h"
class Player :
    public GameObject
{
    int hModel_;
    int hSound_;
    struct Shake 
    {
        float Shaketime_;
        float ShakeStrength_;
        float ShakeTime_;
    };
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    Player(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;

    //void shakeCamera();
};

