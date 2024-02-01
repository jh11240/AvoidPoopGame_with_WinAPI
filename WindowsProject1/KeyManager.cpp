#include"framework.h"
#include "KeyManager.h"

//GetAsyncKeyState반환값
//0x0000 이전에 누른적없고 호출 시점에도 안눌림
//0x0001 이전에 누른적 있고 호출 시점에 안눌림
//0x8000 이전에 누른적이 없고 호출 시점에는 눌려있음
//0x8001 이전에 누른적이 있고 호출 시점에도 눌려있는 상태
void KeyManager::Setup()
{
    m_bitKeyUp.reset();
    m_bitKeyDown.reset();
}

bool KeyManager::isOnceKeyDown(int key)
{
    if (GetAsyncKeyState(key) & 0x8000) {
        //키가 이전에 눌려있지 않은 상태
        if (!m_bitKeyDown[key]) {
            //눌린 상태로 변환
            m_bitKeyDown.set(key, true);
            return true;
        }
    }
    else
    {
        m_bitKeyDown.set(key, false);
    }
    return false;
}

bool KeyManager::isOnceKeyUp(int key)
{
    if (GetAsyncKeyState(key) & 0x8000) {
        m_bitKeyUp.set(key, true);
    }
    else {
        //키가 눌렸다가 떼었을 때
        if (m_bitKeyUp[key]) {
            //눌린 상태로 변환
            m_bitKeyUp.set(key, false);
            return true;
        }
    }
    return false;
}

bool KeyManager::isStayKeyDown(int key)
{
    if (GetAsyncKeyState(key) & 0x8000) return true;
    return false;
}

bool KeyManager::isToggleKey(int key)
{
    if (GetAsyncKeyState(key) & 0x0001) return true;
    return false;
}
