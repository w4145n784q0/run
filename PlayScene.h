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
    EnemyLevel* pEL;
    bool IsGameStart_;
    BeforeStart* pBS_;
   // GroundObject* pGO_;
    int hSoundSE_;
    float inittime_;
    float ObjectInitTime_;
    int ShakeCount_;
    bool IsShakeEnd_;
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

