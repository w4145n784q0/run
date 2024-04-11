#pragma once
#include "Engine/GameObject.h"
#include"PlayScene.h"

class Enemy :
    public GameObject
{
    int hModel_;
    int firstpos_;
    PlayScene* ps_;
    float EnemySpeed_;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    Enemy(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //基準の敵のx座標をとる
    void FirstEnemyPosition(int _xpos);

    int GetFirstpos_() { return firstpos_; }
    void SetSpeed(float _speed);
};

