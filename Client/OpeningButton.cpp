#include "stdafx.h"
#include "OpeningButton.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "ResourceMgr.h"
#include "SoundMgr.h"
COpeningButton::COpeningButton()
{
}


COpeningButton::~COpeningButton()
{
	Release();
}

void COpeningButton::Initialize()
{
	m_tInfo.fCX = 400.f;
	m_tInfo.fCY = 134.f;
}

int COpeningButton::Update()
{
	return OBJ_NOEVENT;
}

void COpeningButton::LateUpdate()
{
	CObj::UpdateRect();
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);
	
	if (PtInRect(&m_tRect, pt))
	{
		GetCursorPos(&pt);
		if (CKeyMgr::Get_Instance()->KeyUp(VK_LBUTTON))
		{
			if (!lstrcmp(m_pFrameKey, L"Start"))
				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_MENU);
			else if (!lstrcmp(m_pFrameKey, L"Exit"))
				DestroyWindow(g_hWND);
			return;
		}
		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void COpeningButton::Render(HDC _hdc)
{
	CObj::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(m_pFrameKey);
	GdiTransparentBlt(_hdc,
		m_tRect.left, m_tRect.top,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		hMemDC, m_iDrawID * m_tInfo.fCX, 0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		RGB(255, 0, 255));
}

void COpeningButton::Release()
{
}
