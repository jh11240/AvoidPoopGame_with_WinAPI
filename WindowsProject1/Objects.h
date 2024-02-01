#pragma once
#include "framework.h"
#include "GameNode.h"


class Objects : public GameNode
{
private:
	vector<tagBox>  m_vecBox;
	float			m_nDelay;
	
	int				m_nLevel;
	int				m_nObjSpeed;
	int				m_nSpawnSpeed;
public:
	Objects();
	~Objects();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetLevel(int n) { m_nLevel = n; }
	vector<tagBox>& GetBox() { return m_vecBox; }
};

