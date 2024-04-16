#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include"EnemyLevel.h"

class GameOverScene :
    public GameObject
{
    int hImage_;
    Text* pText;
    Text* pText2;
    EnemyLevel* pEL;
public:
    // �R���X�g���N�^
        //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    GameOverScene(GameObject* parent);

    //�f�X�g���N�^
    ~GameOverScene();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

};

