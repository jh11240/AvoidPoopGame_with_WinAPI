#include "Objects.h"

Objects::Objects()
{
}

Objects::~Objects()
{
}

void Objects::Init()
{
	m_nDelay = 1000;
	m_nObjSpeed = 100;
	m_nSpawnSpeed = 1;
}

void Objects::Update()
{
	if (m_nDelay >= 1/m_nSpawnSpeed) {
		tagBox box;
		box.rt.left = rand() % (WINSIZEX - 15);
		box.rt.right = box.rt.left + 30;
		box.rt.top = 0;
		box.rt.bottom = 30;

		box.speed = rand() % 11 + 5;

		m_vecBox.push_back(box);
		m_nDelay = 0;
	}
	else
		m_nDelay += g_pTimeManager->GetDT();



	float moveAmount = g_pTimeManager->GetDT()*m_nObjSpeed;
	for (vector<tagBox>::iterator iter = m_vecBox.begin(); iter != m_vecBox.end(); ++iter) {
		iter->rt.top += moveAmount;
		iter->rt.bottom += moveAmount;
	}
}

void Objects::Render()
{
	for (int i = 0; i < m_vecBox.size(); i++) {
		RECT_DRAW(m_vecBox[i].rt);
	}
}
