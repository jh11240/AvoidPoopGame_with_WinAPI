#include "framework.h"
#include "TimeManager.h"
#include <Windows.h>
void TimeManager::Init()
{
	//현재 카운트
	QueryPerformanceCounter(&m_nPrevCnt);
	QueryPerformanceFrequency(&m_nFrequency);	
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&m_nCurCnt);

	//delta time구하기
	m_nDeltaTime = static_cast<double>(m_nCurCnt.QuadPart - m_nPrevCnt.QuadPart) / static_cast<double>(m_nFrequency.QuadPart);



	m_nPrevCnt = m_nCurCnt;
	++m_nCallCount;
	m_nCumul += m_nDeltaTime;

	//1초 지날때마다
	if (m_nCumul >= 1.)
	{
		//나누기 연산 비용높다고 들어서 그냥 초당 프레임 다 더해서 계산
		m_iFPS = m_nCallCount;

		m_nCumul = 0;
		m_nCallCount = 0;
	}

}

void TimeManager::Render()
{
	char szBuffer[255] = {};
	sprintf_s(szBuffer, "FPS : %d, DeltaTIme: %lf", m_iFPS, m_nDeltaTime);
	string str = string(szBuffer);
	TextOutA(g_hDC, 100, 10, str.c_str(), str.length());
}
