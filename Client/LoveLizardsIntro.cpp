#include "stdafx.h"
#include "LoveLizardsIntro.h"
#include "ResourceMgr.h"
#include "SoundMgr.h"
#include "SceneMgr.h"

CLoveLizardsIntro::CLoveLizardsIntro()
{
}


CLoveLizardsIntro::~CLoveLizardsIntro()
{
}

void CLoveLizardsIntro::Initialize()
{
	m_tInfo.fCX = 800.f;
	m_tInfo.fCY = 600.f;
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 2;
	m_tFrame.iFrameScene = 0;
	m_tFrame.tFrameSpeed = 100;
	m_tFrame.tFrameTime = system_clock::now();

	m_tStartTime = system_clock::now();

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/Lizard_Intro.bmp", L"LizardsIntro");
	CSoundMgr::Get_Instance()->PlaySoundW("LoveLizards_Intro.wav", CSoundMgr::BGM);
}

void CLoveLizardsIntro::Update()
{
	system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tStartTime);

	if (_time > (milliseconds)4000)
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_LIZARDS);

	if (duration_cast<milliseconds>(system_clock::now() - m_tFrame.tFrameTime).count() > m_tFrame.tFrameSpeed)
	{
		++m_tFrame.iFrameStart;
		m_tFrame.tFrameTime = system_clock::now();
	}
	if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
	{
		if (m_tFrame.iFrameScene == 0)
			m_tFrame.iFrameScene = 1;
		else if (m_tFrame.iFrameScene == 1)
			m_tFrame.iFrameScene = 0;
		m_tFrame.iFrameStart = 0;
	}
}

void CLoveLizardsIntro::LateUpdate()
{
}

void CLoveLizardsIntro::Render(HDC hDC)
{
	CScene::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"LizardsIntro");
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC,
		m_tFrame.iFrameStart*m_tInfo.fCX, m_tFrame.iFrameScene*m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY, RGB(0, 0, 0));
}

void CLoveLizardsIntro::Release()
{
}

void CLoveLizardsIntro::Set_Note()
{
}
