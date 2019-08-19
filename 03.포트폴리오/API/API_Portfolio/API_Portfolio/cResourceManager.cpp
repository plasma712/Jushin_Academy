#include "stdafx.h"
#include "cResourceManager.h"

bool cResourceManager::m_bInstantiated = false;

cResourceManager::cResourceManager()
{
}


cResourceManager::~cResourceManager()
{
}

void cResourceManager::Init(HDC hdc)
{
	assert(!m_bInstantiated);
	m_bInstantiated = true;

	m_hDC = hdc;
	LoadResource();

}

void cResourceManager::Release()
{
}

HDC cResourceManager::Get(wstring ID)
{
	ResourceMap::iterator iter = m_ImageMap.find(ID);
	if (m_ImageMap.end() != iter)
	{
		return m_ImageMap[ID];
	}
	else
	{
		MessageBox(g_hwnd, L"fail to find Resource", L"error", MB_OK);
		exit(1);
	}
}

AniData cResourceManager::GetAniData(wstring ID)
{
	AniDataMap::iterator iter = m_AniDataMap.find(ID);
	if (m_AniDataMap.end() != iter)
	{
		return m_AniDataMap[ID];
	}
	else
	{
		MessageBox(g_hwnd, L"fail to find Ani Resource", L"error", MB_OK);
		exit(1);
	}
}

void cResourceManager::LoadResource()
{
	FILE* fp;
	//_wfopen_s(&fp, L"./resource.csv", L"rt");
	//L"../Resource/Image/01.Player/Left_Player/x_left_01.bmp",
	_wfopen_s(&fp, L"../Resource/Image/resource.csv", L"rt");
	if (nullptr == fp)
	{
		MessageBox(g_hwnd, L"fail to read Resource.csv", L"error", MB_OK);
	}
	wchar_t buffer[128];

	while (!feof(fp))
	{
		fgetws(buffer, sizeof(buffer), fp);

		if (buffer[wcslen(buffer) - 1] == '\n')
		{
			buffer[wcslen(buffer) - 1] = '\0';
		}

		HDC Resource = CreateCompatibleDC(m_hDC);
		TCHAR* pTemp;

		TCHAR* id = _tcstok_s(buffer, L",", &pTemp);
		TCHAR* dir = _tcstok_s(pTemp, L",", &pTemp);
		int iCount = _wtoi(_tcstok_s(pTemp, L",", &pTemp));

		HBITMAP Bitmap = (HBITMAP)LoadImage(NULL, dir, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		SelectObject(Resource, Bitmap);

		BITMAP bmp_info;
		GetObject(Bitmap, sizeof(BITMAP), &bmp_info);

		AniData aniTemp;

		aniTemp.iWidth = bmp_info.bmWidth;
		aniTemp.iHeight = bmp_info.bmHeight;
		aniTemp.iImageCount = iCount;
		aniTemp.iWarpWidth = bmp_info.bmWidth / iCount;

		DeleteObject(Bitmap);
		m_ImageMap[id] = Resource;
		m_AniDataMap[id] = aniTemp;
	}

}
