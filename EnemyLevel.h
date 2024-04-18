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

    //敵の位置を決める
    void EnemyPositionSet();

    //敵の速度上昇
    void EnemySpeedUp();

    //敵の出現間隔上昇
    void EnemyInterval();
    
    //敵の出現間隔カウント
    void EnemyTimeCount();

    //敵を出すか出さないか（敵を出す時間になったか）
    bool IsEnemyTimeUp();

    //敵の位置を決め、レベル10以下なら速度や間隔をあげる
    void PosSetAndLevelUp();

    //敵を出した後の処理（タイマーを0にする、避けた回数を上げる）
    void EnemySetAfter();

    // 一定以上の速度になったら制限かける
    bool LevelLimit(int _Speedphase);

    //常に1/60プラスして、生存時間としてカウント
    void SurvivalTimePlus();
};

