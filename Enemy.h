#pragma once
#include "Engine/GameObject.h"
class Enemy :
    public GameObject
{
    int hModel_;
    int firstpos_;
   // float EnemySpeed_;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Enemy(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //��̓G��x���W���Ƃ�
    void FirstEnemyPosition(int _xpos);

    int GetFirstpos_() { return firstpos_; }
   // int ThroughCountUp() { ThroughCount_++; }
};

