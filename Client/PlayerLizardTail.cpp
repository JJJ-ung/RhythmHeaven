#include "stdafx.h"
#include "PlayerLizardTail.h"
#include "PlayerLizardBody.h"
#include "ResourceMgr.h"
#include "StateMachine.h"
#include "PlayerLizardBodyState.h"
#include "MouseMgr.h"

CPlayerLizardTail::CPlayerLizardTail()
{
}


CPlayerLizardTail::~CPlayerLizardTail()
{
}

void CPlayerLizardTail::Initialize()
{
	m_tInfo.fCX = 300.f;
	m_tInfo.fCY = 335.f;
	m_tInfo.fX = 48.f;
	m_tInfo.fY = 394.f;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/tail_1.bmp", L"TailUP");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/tail_3.bmp", L"TailDown");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iFrameScene = 0;
	m_tFrame.tFrameTime = system_clock::now();
	m_tFrame.tFrameSpeed = 100;

	m_pFrameKey = L"TailUP";
}

int CPlayerLizardTail::Update()
{
	GetCursorPos(&m_pPoint);
	if (m_pPoint.y > 575 && m_pPoint.y < 600)
	{
		m_tFrame.iFrameStart = 0;
		m_tFrame.iFrameEnd = 0;
		m_tFrame.iFrameScene = 0;
	}
	else if (m_pPoint.y > 550 && m_pPoint.y < 575)
	{
		m_tFrame.iFrameStart = 1;
		m_tFrame.iFrameEnd = 1;
		m_tFrame.iFrameScene = 0;
	}
	else if (m_pPoint.y > 525 && m_pPoint.y < 550)
	{
		m_tFrame.iFrameStart = 2;
		m_tFrame.iFrameEnd = 2;
		m_tFrame.iFrameScene = 0;
	}
	else if (m_pPoint.y > 500 && m_pPoint.y < 525)
	{
		m_tFrame.iFrameStart = 3;
		m_tFrame.iFrameEnd = 3;
		m_tFrame.iFrameScene = 0;
	}
	else if (m_pPoint.y > 475 && m_pPoint.y < 500)
	{
		m_tFrame.iFrameStart = 4;
		m_tFrame.iFrameEnd = 4;
		m_tFrame.iFrameScene = 0;
	}
	else if (m_pPoint.y > 450 && m_pPoint.y < 475)
	{
		m_tFrame.iFrameStart = 5;
		m_tFrame.iFrameEnd = 5;
		m_tFrame.iFrameScene = 0;
	}
	else if (m_pPoint.y > 425 && m_pPoint.y < 450)
	{
		m_tFrame.iFrameStart = 0;
		m_tFrame.iFrameEnd = 0;
		m_tFrame.iFrameScene = 1;
	}
	else if (m_pPoint.y > 400 && m_pPoint.y < 425)
	{
		m_tFrame.iFrameStart = 1;
		m_tFrame.iFrameEnd = 1;
		m_tFrame.iFrameScene = 1;
	}
	else if (m_pPoint.y > 375 && m_pPoint.y < 400)
	{
		m_tFrame.iFrameStart = 2;
		m_tFrame.iFrameEnd = 2;
		m_tFrame.iFrameScene = 1;
	}
	else if (m_pPoint.y > 350 && m_pPoint.y < 375)
	{
		m_tFrame.iFrameStart = 3;
		m_tFrame.iFrameEnd = 3;
		m_tFrame.iFrameScene = 1;
	}
	else if (m_pPoint.y > 325 && m_pPoint.y < 350)
	{
		m_tFrame.iFrameStart = 4;
		m_tFrame.iFrameEnd = 4;
		m_tFrame.iFrameScene = 1;
	}
	else if (m_pPoint.y > 300 && m_pPoint.y < 325)
	{
		m_tFrame.iFrameStart = 5;
		m_tFrame.iFrameEnd = 5;
		m_tFrame.iFrameScene = 1;
	}
	else if (m_pPoint.y > 275 && m_pPoint.y < 300)
	{
		m_tFrame.iFrameStart = 0;
		m_tFrame.iFrameEnd = 0;
		m_tFrame.iFrameScene = 2;
	}
	else if (m_pPoint.y > 250 && m_pPoint.y < 275)
	{
		m_tFrame.iFrameStart = 1;
		m_tFrame.iFrameEnd = 1;
		m_tFrame.iFrameScene = 2;
	}
	else if (m_pPoint.y > 225 && m_pPoint.y < 250)
	{
		m_tFrame.iFrameStart = 2;
		m_tFrame.iFrameEnd = 2;
		m_tFrame.iFrameScene = 2;
	}
	else if (m_pPoint.y > 200 && m_pPoint.y < 225)
	{
		m_tFrame.iFrameStart = 3;
		m_tFrame.iFrameEnd = 3;
		m_tFrame.iFrameScene = 2;
	}
	else if (m_pPoint.y > 175 && m_pPoint.y < 200)
	{
		m_tFrame.iFrameStart = 4;
		m_tFrame.iFrameEnd = 4;
		m_tFrame.iFrameScene = 2;
	}
	else if (m_pPoint.y > 150 && m_pPoint.y < 175)
	{
		m_tFrame.iFrameStart = 5;
		m_tFrame.iFrameEnd = 5;
		m_tFrame.iFrameScene = 2;
	}
	else if (m_pPoint.y > 125 && m_pPoint.y < 150)
	{
		m_tFrame.iFrameStart = 0;
		m_tFrame.iFrameEnd = 0;
		m_tFrame.iFrameScene = 3;
	}
	else if (m_pPoint.y > 100 && m_pPoint.y < 125)
	{
		m_tFrame.iFrameStart = 1;
		m_tFrame.iFrameEnd = 1;
		m_tFrame.iFrameScene = 3;
	}
	else if (m_pPoint.y > 75 && m_pPoint.y < 100)
	{
		m_tFrame.iFrameStart = 2;
		m_tFrame.iFrameEnd = 2;
		m_tFrame.iFrameScene = 3;
	}
	else if (m_pPoint.y > 50 && m_pPoint.y < 75)
	{
		m_tFrame.iFrameStart = 3;
		m_tFrame.iFrameEnd = 3;
		m_tFrame.iFrameScene = 3;
	}
	else if (m_pPoint.y > 25 && m_pPoint.y < 50)
	{
		m_tFrame.iFrameStart = 4;
		m_tFrame.iFrameEnd = 4;
		m_tFrame.iFrameScene = 3;
	}
	else if (m_pPoint.y > 0 && m_pPoint.y < 25)
	{
		m_tFrame.iFrameStart = 5;
		m_tFrame.iFrameEnd = 5;
		m_tFrame.iFrameScene = 3;
	}

	return 0;
}

void CPlayerLizardTail::LateUpdate()
{
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		m_pFrameKey = L"TailDown";
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_UP)
		m_pFrameKey = L"TailUP";
}

void CPlayerLizardTail::Render(HDC _hdc)
{
	CObj::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(m_pFrameKey);
	GdiTransparentBlt(_hdc,
		m_tRect.left, m_tRect.top,
		m_tInfo.fCX, m_tInfo.fCY,
		hMemDC,
		m_tFrame.iFrameStart * m_tInfo.fCX, m_tFrame.iFrameScene * m_tInfo.fCY,// 출력할 그림의 시작 좌표. 
		m_tInfo.fCX, m_tInfo.fCY,//그림의 전체 가로세로 크기 
		RGB(255, 0, 255));
}

void CPlayerLizardTail::Release()
{
}
