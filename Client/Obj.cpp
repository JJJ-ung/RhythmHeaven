#include "stdafx.h"
#include "Obj.h"

CObj::CObj()
	:m_pFrameKey(L"")
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tFrame, sizeof(FRAME));
}


CObj::~CObj()
{
}

void CObj::UpdateRect()
{
	m_tRect.left = LONG(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = LONG(m_tInfo.fY - (LONG(m_tInfo.fCY) >> 1));
	m_tRect.right = LONG(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = LONG(m_tInfo.fY + m_tInfo.fCY * 0.5f);
}

void CObj::FrameMove()
{
	if (duration_cast<milliseconds>(system_clock::now() - m_tFrame.tFrameTime).count() > m_tFrame.tFrameSpeed)
	{
		++m_tFrame.iFrameStart;
		m_tFrame.tFrameTime = system_clock::now();
	}
	if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		m_tFrame.iFrameStart = 0;
}

void CObj::FrameStop()
{
	if (duration_cast<milliseconds>(system_clock::now() - m_tFrame.tFrameTime).count() > m_tFrame.tFrameSpeed)
	{
		++m_tFrame.iFrameStart;
		m_tFrame.tFrameTime = system_clock::now();
	}
	if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		m_tFrame.iFrameStart = m_tFrame.iFrameEnd;
}

