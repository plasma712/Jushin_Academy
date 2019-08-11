#pragma once

class cGameObject;

template <typename T>
class cAbstractFactory
{
public:
	static cGameObject* CreateObject()
	{
		cGameObject* pInstance = new T;
		pInstance->Init();
		return pInstance;
	}

	static cGameObject* CreateObject(float _fX, float _fY)
	{
		cGameObject* pInstance = new T;
		pInstance->Init();
		pInstance->SetPos(_fX,_fY);

		return pInstance;
	}


};