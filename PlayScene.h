#pragma once
#include "Engine/GameObject.h"
#include"Engine/Text.h"
#include "EnemyLevel.h"

class PlayScene :
    public GameObject
{
    //float inittimer_;//敵発生までのインターバル　1になったら敵が発生
    //signed int StandardEnemyPosX_;//敵の基準位置
    //signed int SecondEnemyPos_;//敵のもう一つの発生位置
    //int ThroughCount_;//避けた回数　敵の発生した回数
    //float EnemySpeedSet_;//敵のスピードを入れる変数
    //float EnemyInitTime_;//inittimerから引く数　避けるたび増える
    //int SpeedLevel_;//現在のレベル　一定回数避けると上がる
    Text* pText;
    Text* pText2;
    EnemyLevel* pEL;

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

   // float GetEnemySpeed() { return EnemySpeedSet_; }

    void EnemyPositionSet();

    void EnemySpeedUp();

    void EnemyInterval();

    /// <summary>
    /// 一定以上の速度になったら制限かける
    /// <param name="_Espeed">敵のスピード
    /// <param name="_EInitTime">敵の出現インターバル
    /// <param name="_Speedphase">敵のレベルint型で表示してる
    /// </summary>
    //bool LevelLimit(int _Speedphase);
};

