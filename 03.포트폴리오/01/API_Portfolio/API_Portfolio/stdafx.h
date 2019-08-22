// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//
#pragma once

#pragma comment(lib, "msimg32.lib")  

#pragma comment(lib,"winmm.lib")


#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <unordered_map>
#include <assert.h> 
#include <list>
#include <string>
#include <iostream>
#include <mmsystem.h>
#include <algorithm>
using std::wstring;
using std::hash;
using std::list;
using std::unordered_map;

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include "extern.h"
#include "enum.h"
#include "define.h"
#include "global.h"
#include "struct.h"
#include "typedef.h"
#include "AbstractFactory.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "MainGame.h"
#include "KeyManager.h"
#include "cScrollMgr.h"
#include "cLineEditer.h"
#include "Player.h"