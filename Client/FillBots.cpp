#include "stdafx.h"
#include "FillBots.h"
#include "MouseMgr.h"
#include "ResourceMgr.h"
#include "SoundMgr.h"

CFillBots::CFillBots()
{
}


CFillBots::~CFillBots()
{
}

void CFillBots::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 800.f;
	m_tInfo.fCY = 600.f;

	CMouseMgr::Get_Instance()->Initialize(SceneID::GAME_ROBOT);


	CSoundMgr::Get_Instance()->PlayBGM("Fillbots  - Rhythm Heaven.wav");
}

void CFillBots::Update()
{
	CMouseMgr::Get_Instance()->Update();
}

void CFillBots::LateUpdate()
{
	CMouseMgr::Get_Instance()->LateUpdate();
	m_eMotion = CMouseMgr::Get_Instance()->Get_Motion();
}

void CFillBots::Render(HDC hDC)
{
	CMouseMgr::Get_Instance()->Render(hDC);
	if (m_eMotion == MotionID::MOTION_SLIDE)
	{
		TCHAR m_szMotion[100] = L"";
		swprintf_s(m_szMotion, L"슬라이드 인식됨");
		TextOut(hDC, 400, 300, m_szMotion, lstrlen(m_szMotion));
	}
}

void CFillBots::Release()
{
	CMouseMgr::Get_Instance()->Destroy_Instance();
}

void CFillBots::Set_Note()
{
}
