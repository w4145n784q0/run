#pragma once
#include "Engine/GameObject.h"
class EnemyLevel :
    public GameObject
{
    float inittimer_;//敵発生までのインターバル　1になったら敵が発生
    signed int StandardEnemyPosX_;//敵の基準位置
    signed int SecondEnemyPos_;//敵のもう一つの発生位置
    int ThroughCount_;//避けた回数　敵の発生した回数
    float EnemySpeedSet_;//敵のスピードを入れる変数
    float EnemyInitTime_;//inittimerから引く数　避けるたび増える
    int SpeedLevel_;//現在のレベル　一定回数避けると上がる
    float SurvivalTime_;//生存時間を数える
public:
    //コンストラクタ
   //引数：parent  親オブジェクト（SceneManager）
    EnemyLevel(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    float GetStandardEnemyPosX() { return StandardEnemyPosX_; }
    float GetSecondEnemyPosX() { return SecondEnemyPos_; }
    float GetEnemySpeed() { return EnemySpeedSet_; }
    float GetSpeedLevel() { return SpeedLevel_; }
    float GetSurvivalTime() { return SurvivalTime_; }

    void EnemyPositionSet();

    void EnemySpeedUp();

    void EnemyInterval();

    void EnemyTimeCount();

    bool IsEnemyTimeUp();

    void PosSetAndLevelUp();

    void EnemySetAfter();

    bool LevelLimit(int _Speedphase);// 一定以上の速度になったら制限かける

    void SurvivalTimePlus();
};

