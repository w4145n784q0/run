#pragma once
#include "Engine/GameObject.h"
class BeforeStart :
    public GameObject
{
   int hImage_;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    BeforeStart(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�摜��\��
    void HiddenImage();
};

