#pragma once
class CEffectManager
{
public:
	CEffectManager();
	~CEffectManager();

public:
	static void CreateEffect(INFO _targetInfo);
	static void CreateEffect(float x,float y,wstring name);
	static void CreatePlayerAttackEffect(float x, float y, wstring name);
	static void CreatePlayerAttackEffect2(float x, float y, wstring name);

	///////////////////////////////////////////////////////////////////////////


};

