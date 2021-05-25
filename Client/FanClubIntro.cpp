#include "stdafx.h"
#include "FanClubIntro.h"
#include "SceneMgr.h"

CFanClubIntro::CFanClubIntro()
{
}


CFanClubIntro::~CFanClubIntro()
{
	Release();
}

void CFanClubIntro::Initialize()
{
	m_hVideo = MCIWndCreate(g_hWND, nullptr, WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR, L"../Image/FanClub_Intro.wmv");
	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, false);
	MCIWndPlay(m_hVideo);
}

void CFanClubIntro::Update()
{
	if (MCIWndGetLength(m_hVideo) <= MCIWndGetPosition(m_hVideo))
	{
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_FANCLUB);
	}
}

void CFanClubIntro::LateUpdate()
{
}

void CFanClubIntro::Render(HDC hDC)
{
}

void CFanClubIntro::Release()
{
	MCIWndClose(m_hVideo);
}

void CFanClubIntro::Set_Note()
{
}
