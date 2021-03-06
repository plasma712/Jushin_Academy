#pragma once


typedef struct tagInfoMation
{
	float fX;
	float fY;
	float fWidthX;
	float fHeightY;

}INFO;

typedef struct tagLine
{
	POINTFLOAT tLPoint;
	POINTFLOAT tRPoint;
	tagLine() {}
	tagLine(POINTFLOAT _lPoint, POINTFLOAT _rPoint)
		:tLPoint(_lPoint), tRPoint(_rPoint)
	{}
}LINE;

typedef struct tagFrame
{
	int iStartX;		
	int iStartY;		
	int iFrameCount;	

	DWORD dwOldTime;
	DWORD dwCurTime;
	DWORD dwFrameSpeed;	
}FRAME;

typedef struct tagAniData
{
	int iWidth = 0;			// 가로길이
	int iHeight = 0;		// 세로길이
	int iImageCount = 0;	// 이미지 수 
	int iWarpWidth = 0;		// 이미지 간격

}AniData;


