#pragma once
#include "SingletonBase.h"

#define g_pTimeManager TimeManager::GetInstance()

class TimeManager: public SingletonBase<TimeManager>
{
private:
	LARGE_INTEGER m_nCurCnt;
	LARGE_INTEGER m_nPrevCnt;
	LARGE_INTEGER m_nFrequency;

	double			m_nDeltaTime = 0.;				// 델타타임
	double			m_nFPS = 0.;					// 1 / 델타타임
	double			m_nCumul = 0.;					// 누적시간
	UINT			m_nCallCount =0;
	UINT			m_iFPS=0;
public:
	void Init();
	void Update();
	void Render();

	double GetDT() { return m_nDeltaTime; }
	float GetFDT() { return (float)m_nDeltaTime; }
};

