#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
    float inittimer_;
    signed int StandardEnemyPosX_;
    signed int SecondEnemyPos_;
    int ThroughCount_;

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
};

