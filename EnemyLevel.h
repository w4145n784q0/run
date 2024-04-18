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

    //�G�̈ʒu�����߂�
    void EnemyPositionSet();

    //�G�̑��x�㏸
    void EnemySpeedUp();

    //�G�̏o���Ԋu�㏸
    void EnemyInterval();
    
    //�G�̏o���Ԋu�J�E���g
    void EnemyTimeCount();

    //�G���o�����o���Ȃ����i�G���o�����ԂɂȂ������j
    bool IsEnemyTimeUp();

    //�G�̈ʒu�����߁A���x��10�ȉ��Ȃ瑬�x��Ԋu��������
    void PosSetAndLevelUp();

    //�G���o������̏����i�^�C�}�[��0�ɂ���A�������񐔂��グ��j
    void EnemySetAfter();

    // ���ȏ�̑��x�ɂȂ����琧��������
    bool LevelLimit(int _Speedphase);

    //���1/60�v���X���āA�������ԂƂ��ăJ�E���g
    void SurvivalTimePlus();
};

