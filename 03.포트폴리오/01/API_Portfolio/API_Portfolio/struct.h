#pragma once

#ifndef __STRUCT_H__

typedef struct tagLine
{
	POINTFLOAT tLPoint;
	POINTFLOAT tRPoint;
	tagLine() {}
	tagLine(POINTFLOAT _lPoint, POINTFLOAT _rPoint)
		:tLPoint(_lPoint), tRPoint(_rPoint)
	{}
}LINE;



typedef struct tagInfo
{
	float fX = 0.f;
	float fY = 0.f;
	float fCX = 0.f;
	float fCY = 0.f;
	float fWidthX;
	float fHeightY;

}INFO;

typedef struct tagAniData
{
	int iWidth = 0;			// ���α���
	int iHeight = 0;		// ���α���
	int iImageCount = 0;	// �̹��� �� 
	int iWarpWidth = 0;		// �̹��� ����

	DWORD dwOldTime;
	DWORD dwCurTime;
	DWORD dwFrameSpeed;
}AniData;




#define __STRUCT_H__
#endif
#pragma once
