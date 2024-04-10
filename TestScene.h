#pragma once
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class TestScene : public GameObject
{
	float EnemyInstantiateTime_;
	bool TimerOver_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TestScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//
	void TimeCount();

	bool IsTimeOver();

	bool GetTimeOver(bool _timerOver) { TimerOver_ = _timerOver; }

};