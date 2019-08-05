#include "stdafx.h"
#include "GuideBullet.h"


CGuideBullet::CGuideBullet()
	: m_pTarget(nullptr)
{
}


CGuideBullet::~CGuideBullet()
{
	Release();
}

void CGuideBullet::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	m_fSpeed = 5.f;
}

int CGuideBullet::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	IsMoving();

	return NO_EVENT;
}

void CGuideBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CGuideBullet::Release()
{
}

void CGuideBullet::IsMoving()
{
	m_pTarget = CObjectMgr::GetInstance()->GetNearTarget(this, OBJECT_MONSTER);

	if (nullptr == m_pTarget)
	{
		m_bIsDead = true;
		return;
	}

	// ���� ���� ����!!!
	// ������ - ����� = ��������� �������� ���ϴ� ����.
	float w = m_pTarget->GetInfo().fX - m_tInfo.fX;
	float h = m_pTarget->GetInfo().fY - m_tInfo.fY;
	float d = sqrtf(w * w + h * h);

	// cos�� = ��/��
	// acosf�� ��ȯ�ϴ� ���� ������ 0 ~ 180���̴�.
	m_fAngle = acosf(w / d); // cos�� ���ڷ� ��� ���ΰ��� ���� ������ ��ȯ�Ѵ�.

	// Ư�� �������� ������ ���������־�� �Ѵ�.
	if (m_tInfo.fY < m_pTarget->GetInfo().fY)
		m_fAngle *= -1.f;

	// ���� ���� �������� �����δ�.
	m_tInfo.fX += cosf(m_fAngle) * m_fSpeed;
	m_tInfo.fY -= sinf(m_fAngle) * m_fSpeed;
}
