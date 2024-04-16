#pragma once
#include "Engine/GameObject.h"
class EnemyLevel :
    public GameObject
{
    float inittimer_;//�G�����܂ł̃C���^�[�o���@1�ɂȂ�����G������
    signed int StandardEnemyPosX_;//�G�̊�ʒu
    signed int SecondEnemyPos_;//�G�̂�����̔����ʒu
    int ThroughCount_;//�������񐔁@�G�̔���������
    float EnemySpeedSet_;//�G�̃X�s�[�h������ϐ�
    float EnemyInitTime_;//inittimer����������@�����邽�ё�����
    int SpeedLevel_;//���݂̃��x���@���񐔔�����Əオ��
    float SurvivalTime_;//�������Ԃ𐔂���
public:
    //�R���X�g���N�^
   //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    EnemyLevel(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
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

    bool LevelLimit(int _Speedphase);// ���ȏ�̑��x�ɂȂ����琧��������

    void SurvivalTimePlus();
};

