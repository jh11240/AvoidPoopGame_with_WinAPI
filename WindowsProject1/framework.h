// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include<string>
#include<time.h>
#include<vector>

//전역 디파인
#define WINSIZEX 640
#define WINSIZEY 720

//구조체 선언
typedef struct _fPos fPos;
typedef struct    _fRect fRect;
typedef struct _tagBox tagBox;

//전역 맼크로
//렉트 생성 매크로(x,y,z)
#define RECT_MAKE(x,y,s) {(x)-(s)/2,(y)-(s)/2,(x)+(s)/2,(y)+(s)/2}
//렉트 렌더 매크로
#define RECT_DRAW(rt) Rectangle(g_hDC, rt.left, rt.top, rt.right, rt.bottom)

//전역 변수

extern HWND g_hwind;                                //윈도우 핸들
extern POINT g_ptMouse;								//마우스 좌표
extern HDC g_hDC;

#define PROGRAM_TITLE L"똥피하기 게임"

//전역 구조체
struct _fPos {
	float x;
	float y;
};

struct    _fRect
{
	float left;
	float top;
	float right;
	float bottom;
};

struct _tagBox
{
	fRect rt;
	float   speed;
};
using namespace std;

//매니저
#include "KeyManager.h"
#include "TimeManager.h"