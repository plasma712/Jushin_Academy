#pragma once

// �߻� ���丮 ����
// ������Ʈ�� ������ �� ����� ��Ҹ� ��Ƽ� ĸ��ȭ�� ������ ����
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

