#include "framework.h"
#include "MainGame.h"

//OOP(Object Oriented Programming)
//High Cohesion, Low Coupling

MainGame::MainGame() {
	//seed
	srand((unsigned int)time(NULL));

	m_pPlayer = new Player;
	m_pObjects = new Objects;

}
MainGame::~MainGame() {
	g_pKeyManager->ReleaseInstance();
}

void MainGame::Init()
{
	m_nScore = 0;
	m_nLevel = 1;

	m_pPlayer->Init();
	m_pObjects->Init();
	g_pTimeManager->Init();
	g_pKeyManager->Setup();
}

void MainGame::Update()
{
	//지워줄 필요없이 화면 갱신만하면됨 이미 백버퍼를 하얀색으로 지우고  그리기때문
	InvalidateRect(g_hwind, NULL, false);   //세번째 인자는 초기화하고 다시그릴지 계속그릴지

	m_nLevel = m_nScore / 100 + 1;

	//레벨 정보 obeject의 level로 넘겨줘야함
	m_pObjects->SetLevel(m_nLevel);

	g_pTimeManager->Update();
	m_pPlayer->Update();
	m_pObjects->Update();

	//충돌처리
	for (vector<tagBox>::iterator iter = m_pObjects->GetBox().begin(); iter != m_pObjects->GetBox().end(); ++iter) {

		RECT rt;
		RECT rtIter;
		rtIter.left= iter->rt.left;
		rtIter.right= iter->rt.right;
		rtIter.top= iter->rt.top;
		rtIter.bottom= iter->rt.bottom;

		if (iter->rt.top > WINSIZEY) {
			m_nScore++;
			m_pObjects->GetBox().erase(iter);
			break;

		}
		//RECT끼리 충돌 처리
		else if (IntersectRect(&rt, &m_pPlayer->GetRect(), &rtIter)) {
			m_nScore -= 10;
			m_pObjects->GetBox().erase(iter);
			break;
		}
		//마우스와 RECT충돌 감지
		else if (PtInRect(&rtIter, g_ptMouse)) {
			m_nScore += 5;
			m_pObjects->GetBox().erase(iter);
			break;
		}

	}
}

void MainGame::Render()
{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(g_hwind, &ps);

		//백버퍼에 흰색으로 칠함
		PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

		m_pPlayer->Render();
		m_pObjects->Render();
		g_pTimeManager->Render();

		char szBuff[32];
		_itoa_s(m_nScore, szBuff, 10);                    //정수값을 문자열 값으로 변환 해주는 함수
		string str = string(szBuff);
		TextOutA(g_hDC, 10, 30, str.c_str(), str.length());

		_itoa_s(m_nLevel, szBuff, 10);                    //정수값을 문자열 값으로 변환 해주는 함수
		str = string(szBuff);
		TextOutA(g_hDC, 10, 10, str.c_str(), str.length());

		//hdc에 옮겨그림
		BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, g_hDC, 0, 0, SRCCOPY);

		EndPaint(g_hwind, &ps);
}
