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

    float GetEnemySpeed() { return EnemySpeedSet_; }

    void EnemyPositionSet();

    void EnemySpeedUp();

    void EnemyInterval();

    /// <summary>
    /// ���ȏ�̑��x�ɂȂ����琧��������
    /// <param name="_Espeed">�G�̃X�s�[�h
    /// <param name="_EInitTime">�G�̏o���C���^�[�o��
    /// <param name="_Speedphase">�G�̃��x��int�^�ŕ\�����Ă�
    /// </summary>
    bool LevelLimit(int _Speedphase);
};

