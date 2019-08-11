#pragma once

#ifndef __DEFINE_H__

#define PI 3.141592f
#define GRAVITY 9.8f

#define WINCX 800
#define WINCY 600

// 타일 가로, 세로 개수
#define TILEX 30
#define TILEY 20

// 타일 가로, 세로 크기
#define TILECX 64
#define TILECY 64

#define NO_EVENT 0
#define DEAD_OBJ 1
#define CHANGE_SCENE 2

#define NULL_CHECK(ptr)	\
if(nullptr == (ptr)) return;

#define NULL_CHECK_RETURN(ptr, val)	\
if(nullptr == (ptr)) return val;

#define DECLARE_SINGLETON(ClassName)	\
public:									\
static ClassName* GetInstance();		\
void DestroyInstance();					\
private:								\
	static ClassName* m_pInstance;

#define IMPLEMENT_SINGLETON(ClassName)			\
ClassName* ClassName::m_pInstance = nullptr;	\
ClassName* ClassName::GetInstance()		\
{											\
	if (nullptr == m_pInstance)				\
		m_pInstance = new ClassName;		\
	return m_pInstance;						\
}											\
void ClassName::DestroyInstance()			\
{											\
	if (m_pInstance)						\
	{										\
		delete m_pInstance;					\
		m_pInstance = nullptr;				\
	}										\
}

#define __DEFINE_H__
#endif
