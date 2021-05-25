#include "stdafx.h"
#include "BirdIntro.h"
#include "SceneMgr.h"

CBirdIntro::CBirdIntro()
{
}


CBirdIntro::~CBirdIntro()
{
	Release();
}

void CBirdIntro::Initialize()
{
	m_hVideo = MCIWndCreate(g_hWND, nullptr, WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR, L"../Image/BlueBirds_Intro.wmv");
	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, false);
	MCIWndPlay(m_hVideo);
}

void CBirdIntro::Update()
{
	if (MCIWndGetLength(m_hVideo) <= MCIWndGetPosition(m_hVideo))
	{
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_BIRDS);
	}
}

void CBirdIntro::LateUpdate()
{
}

void CBirdIntro::Render(HDC hDC)
{
}

void CBirdIntro::Release()
{
	MCIWndClose(m_hVideo);
}

void CBirdIntro::Set_Note()
{
}
