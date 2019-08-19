#pragma once
class CResourceManager;
class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	virtual void		Initialize()=0;
	virtual	void		Update() = 0;
	virtual	void		Render() = 0;
	OBJLIST*			GetOBJLST();
private:
	virtual	void		Release() = 0;
	virtual void		LoadMonster() = 0;
protected:
	HDC					m_hDC;
	CResourceManager*	m_pResourceMgr;
	OBJLIST				m_ObjLst[OBJECT_END];
};

