#pragma once
#include "Engine/GameObject.h"
#include"Engine/Text.h"
#include "EnemyLevel.h"

class PlayScene :
    public GameObject
{
    //float inittimer_;//�G�����܂ł̃C���^�[�o���@1�ɂȂ�����G������
    //signed int StandardEnemyPosX_;//�G�̊�ʒu
    //signed int SecondEnemyPos_;//�G�̂�����̔����ʒu
    //int ThroughCount_;//�������񐔁@�G�̔���������
    //float EnemySpeedSet_;//�G�̃X�s�[�h������ϐ�
    //float EnemyInitTime_;//inittimer����������@�����邽�ё�����
    //int SpeedLevel_;//���݂̃��x���@���񐔔�����Əオ��
    Text* pText;
    Text* pText2;
    EnemyLevel* pEL;

public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    PlayScene(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

   // float GetEnemySpeed() { return EnemySpeedSet_; }

    void EnemyPositionSet();

    void EnemySpeedUp();

    void EnemyInterval();

    /// <summary>
    /// ���ȏ�̑��x�ɂȂ����琧��������
    /// <param name="_Espeed">�G�̃X�s�[�h
    /// <param name="_EInitTime">�G�̏o���C���^�[�o��
    /// <param name="_Speedphase">�G�̃��x��int�^�ŕ\�����Ă�
    /// </summary>
    //bool LevelLimit(int _Speedphase);
};

