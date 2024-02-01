#pragma once
#include "SingletonBase.h"
#include <bitset>
using namespace std;

//bitset을 이용한 KeyManager

#define g_pKeyManager  KeyManager::GetInstance()

#define KEYMAX 256

class KeyManager : public SingletonBase<KeyManager>
{
	private:
		bitset<KEYMAX> m_bitKeyUp;
		bitset<KEYMAX> m_bitKeyDown;
public:
	void Setup();						//키 매니저 초기화

	bool isOnceKeyDown(int key);		//키가 한번 눌림
	bool isOnceKeyUp(int key);			//키를 눌렀다 땜
	bool isStayKeyDown(int key);		//키를 누르고있음
	bool isToggleKey(int key);			//토글 키 (키를 키고 끔)
};

