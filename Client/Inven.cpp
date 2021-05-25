#include "stdafx.h"
#include "Inven.h"
#include "ResourceMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

CInven::CInven()
{
}


CInven::~CInven()
{
	Release();
}

void CInven::Initialize()
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 106.f;

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iFrameScene = 0;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/OtherButtons.bmp", L"CafeButton");
}

int CInven::Update()
{
	return 0;
}

void CInven::LateUpdate()
{
	CObj::UpdateRect();
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->KeyUp(VK_LBUTTON))
		{
			CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_CAFE);
		}
		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void CInven::Render(HDC _hdc)
{
	CObj::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"CafeButton");
	GdiTransparentBlt(_hdc,
		m_tRect.left, m_tRect.top,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		hMemDC, m_iDrawID * m_tInfo.fCX, 0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		RGB(255, 0, 255));
}

void CInven::Release()
{
}
