#pragma once
#include "Engine/GameObject.h"
#include"Engine/Text.h"

class PlayScene :
    public GameObject
{
    float inittimer_;
    signed int StandardEnemyPosX_;
    signed int SecondEnemyPos_;
    int ThroughCount_;
    float EnemySpeedSet_;
    float EnemyInitTime_;
    int Speedphase_;
    Text* pText;
    Text* pText2;
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

    float GetEnemySpeed() { return EnemySpeedSet_; }

    void EnemyPositionSet();

    void EnemySpeedUp();

    void EnemyInterval();

    /// <summary>
    /// 一定以上の速度になったら制限かける
    /// <param name="_Espeed">敵のスピード
    /// <param name="_EInitTime">敵の出現インターバル
    /// <param name="_Speedphase">敵のレベルint型で表示してる
    /// </summary>
    bool LevelLimit(int _Speedphase);
};

