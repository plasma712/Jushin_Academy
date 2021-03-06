// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
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
#include <map>
using std::wstring;
using std::hash;
using std::list;
using std::unordered_map;


////////////////////////////////
#include "Struct.h"
#include "Extern.h"
#include "Define.h"
#include "TemPlate.h"
#include "Enum.h"
#include "cAbstractFactory.h"
#include "cObjectMgr.h"

////////////////////////////////
#include "cMousePoint.h"
#include "cMouse.h"
#include "cLineEditer.h"
#include "cAniMation.h"
#include "cKeyMgr.h"
#include "cSceneMgr.h"
#include "cScrollMgr.h"
#include "cCollsionMgr.h"
#include "Resource.h"
//

#include <vld.h>

#include <crtdbg.h>