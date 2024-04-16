#pragma once
#include "Engine/GameObject.h"
class BeforeStart :
    public GameObject
{
   int hImage_;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    BeforeStart(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //画像非表示
    void HiddenImage();
};

