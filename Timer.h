#pragma once
#include "Engine/GameObject.h"
class Timer :
    public GameObject
{
    bool TimeOver_;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Timer(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�^�C�}�[
    void TimerCount(float _start,float _end);

    //
    bool IsTimeOver();
};

