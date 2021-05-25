#include "stdafx.h"
#include "BackButton.h"
#include "ResourceMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

CBackButton::CBackButton()
{
}


CBackButton::~CBackButton()
{
}

void CBackButton::Initialize()
{
	//697.f, 531.f
	m_tInfo.fX = 697.f;
	m_tInfo.fY = 531.f;
	m_tInfo.fCX = 160.f;
	m_tInfo.fCY = 58.f;

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iFrameScene = 0;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/Cafe/Back.bmp", L"BackButton");
}

int CBackButton::Update()
{
	return 0;
}

void CBackButton::LateUpdate()
{
	CObj::UpdateRect();
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->KeyUp(VK_LBUTTON))
		{
			CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_MENU);
		}
		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void CBackButton::Render(HDC _hdc)
{
	CObj::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"BackButton");
	GdiTransparentBlt(_hdc,
		m_tRect.left, m_tRect.top,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		hMemDC, m_iDrawID * m_tInfo.fCX, 0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		RGB(255, 0, 255));
}

void CBackButton::Release()
{
}
