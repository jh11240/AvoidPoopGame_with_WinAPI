#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	m_ptPos = { WINSIZEX / 2,WINSIZEY - 30 };
	m_fMoveSpeed = 100;
}

void Player::Update()
{

	if (g_pKeyManager->isStayKeyDown(VK_RIGHT) || g_pKeyManager->isStayKeyDown('D')) {
		m_ptPos.x += (m_rtBox.right <= WINSIZEX) ? m_fMoveSpeed * g_pTimeManager->GetFDT() : 0;
	}
	else if (g_pKeyManager->isStayKeyDown(VK_LEFT) || g_pKeyManager->isStayKeyDown('A')) {
		m_ptPos.x -= (m_rtBox.left >= m_fMoveSpeed * g_pTimeManager->GetFDT()) ? m_fMoveSpeed * g_pTimeManager->GetFDT() : 0;
	}

	//포지션 위치에 따른 렉트 정보 업데이트
	//m_rtBox = RECT_MAKE(static_cast<int>(m_ptPos.x),static_cast<int>( m_ptPos.y), 50);

	m_frtBox = RECT_MAKE((m_ptPos.x),(m_ptPos.y), 50);
	

	//왜안될까
	m_rtBox.left = static_cast<int>(m_frtBox.left);
	m_rtBox.right = static_cast<int>(m_frtBox.right);
	m_rtBox.top= static_cast<int>(m_frtBox.top);
	m_rtBox.bottom = static_cast<int>(m_frtBox.bottom);
}

void Player::Render()
{
	RECT_DRAW(m_rtBox);


}
