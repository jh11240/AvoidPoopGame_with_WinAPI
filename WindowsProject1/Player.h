#pragma once
#include "framework.h"
#include "GameNode.h"
class Player : public GameNode
{
private:
	fPos			m_ptPos;
	fRect			m_frtBox;
	RECT			m_rtBox;
	float			m_fMoveSpeed;
public:
	Player();
	~Player();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	RECT& GetRect() { return m_rtBox; }
};

