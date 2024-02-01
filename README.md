# AvoidPoopGame_with_WinAPI
WinAPI를 이용해서 간단하게 똥피하기 게임을 구현해봤습니다. 
똥과 플레이어는 RECT로 구현해 Rectangle함수를 통해 렌더링됩니다.

# 게임설명
![image](https://github.com/jh11240/AvoidPoopGame_with_WinAPI/assets/73728655/f79be63a-f20f-45d7-b8e6-40a2c285effd)
framework헤더파일에 필요한 클래스들과 전역변수들을 몰아서 선언했습니다.

WindowsProject1클래스에서 wWinMain을 구현했습니다. 

Init(), Update(), Render()를 순수 가상 함수로 GameNode클래스에 구현 후, 
init, render, update함수를 사용하는 모든 클래스에서 상속받게 해서 구현하게 했습니다. 

GameNode를 상속받는 클래스인 mainGame클래스에서 다른 모든 클래스들의 init, update, render함수를 실행시키도록 구현해서, 
windowsProject1클래스에서는 mainGame클래스의 init, update, render함수만 실행시키면 구동이 됩니다.

player클래스는 플레이어 RECT를 담당하는 클래스고, Objects클래스는 떨어지는 똥들을 담당하는 클래스입니다. 

keymanager.h도 싱글턴패턴이고, GetAsyncState함수를 이용해 어떤 키가 눌렸는지 체크하는 용도로 구현했습니다. 

wWinMain에서 처음에 wndproc에서 Settimer을 통해 1ms마다 update/render문을 호출했습니다.
그러던 중 게임에서는 peekmessage를 활용한다고 듣고  while문에서 peekmessage를 이용해 메시지를 처리하고 else문에서 업데이트/렌더문을 처리했습니다.
하지만 위치 갱신이 너무 빨라져서 유니티의 deltatime을 구현할 필요가 있어 timeManager클래스를 구현했습니다.

timemanager.h는 싱글톤 템플릿 클래스를 상속받아 싱글톤패턴으로 구현되었습니다. 
QueryPerformaceCounter, Frequency를 이용해 deltatime을 구현해봤습니다.   

