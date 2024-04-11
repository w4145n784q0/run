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
    void SetSpeed(float _speed);
};

