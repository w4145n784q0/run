#pragma once
#include "Engine/GameObject.h"
class GroundObject :
    public GameObject
{
    int hModel_;
    float ObjectSpeed_;
    float inittimer_;
    float ObjectInitTime_;
    float PosX_;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    GroundObject(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //
    void ObjectPositionSet();

    //
    void ObjectTimeCount();

    float GetPosX() { return PosX_; }
};

