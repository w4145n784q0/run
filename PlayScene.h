#pragma once
#include "Engine/GameObject.h"
#include"Engine/Text.h"
#include "EnemyLevel.h"
#include "BeforeStart.h"
#include"GroundObject.h"

class PlayScene :
    public GameObject
{
    Text* pText;
    Text* pText2;
    Text* pText3;
    Text* pText4;
    EnemyLevel* pEL;
    bool IsGameStart_;
    BeforeStart* pBS_;
    int hSoundSE_;
    float inittime_;//�I�u�W�F�N�g�����܂ł̃C���^�[�o���@1�ɂȂ�����G������
    float ObjectInitTime_;//�I�u�W�F�N�g�̐����܂ł̎��ԁ@inittimer����������@
    int ShakeCount_;//�U�������J�E���g
    bool IsShakeEnd_;//�U���I�������
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

    //�G���o��
    void EnemySpawn();
};

