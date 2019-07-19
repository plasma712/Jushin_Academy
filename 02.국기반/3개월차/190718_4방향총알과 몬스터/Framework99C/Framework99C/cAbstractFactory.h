#pragma once

// 추상 팩토리 패턴
// 오브젝트를 생성할 때 공통된 요소를 모아서 캡슐화한 디자인 패턴
template <typename T>
class cAbstractFactory
{
public:
	static CGameObject* CreateObject()
	{
		CGameObject* pInstance = new T;
		pInstance->Initialize();

		return pInstance;
	}

	static CGameObject* CreateObject(float _x, float _y)
	{
		CGameObject* pInstance = new T;
		pInstance->Initialize();
		pInstance->SetPos(_x, _y);

		return pInstance;
	}

};

