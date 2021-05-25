#include "stdafx.h"
#include "BirdOutro.h"
#include "ResourceMgr.h"
#include "SoundMgr.h"
#include "MouseMgr.h"
#include "SceneMgr.h"
#include "MainPlayer.h"

CBirdOutro::CBirdOutro()
{
	m_pFrameKey = L"";
}


CBirdOutro::~CBirdOutro()
{
}

void CBirdOutro::Initialize()
{
	if (m_iCount == 0)
	{
		CMainPlayer::Get_Instance()->Set_Bird_Perfect();
		m_eFrame = FrameID::PERFECT;
	}
	else if (m_iCount < 3)
	{
		CMainPlayer::Get_Instance()->Set_Bird_Superb();
		m_eFrame = FrameID::GOLD;
	}
	else if (m_iCount < 6)
	{
		CMainPlayer::Get_Instance()->Set_Bird_OK();
		m_eFrame = FrameID::SILVER;
	}
	else
	{
		CMainPlayer::Get_Instance()->Set_Bird_Null();
		m_eFrame = FrameID::NORMAL;
	}

	m_tInfo.fCX = 800.f;
	m_tInfo.fCY = 600.f;
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;

	m_tStartTime = system_clock::now();

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/Birds_Outro_Superb.bmp", L"Birds_Superb");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/Birds_Outro_Good.bmp", L"Birds_Good");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/Birds_Outro_Bad.bmp", L"Birds_Bad");

	CMouseMgr::Get_Instance()->Initialize(SceneID::GAME_NULL);

	if (m_eFrame == FrameID::GOLD || m_eFrame == FrameID::PERFECT)
	{
		CSoundMgr::Get_Instance()->PlayBGM("Superb  - Rhythm Heaven.wav");
		m_pFrameKey = L"Birds_Superb";
	}
	else if (m_eFrame == FrameID::SILVER)
	{
		CSoundMgr::Get_Instance()->PlayBGM("OK - Rhythm Heaven.wav");
		m_pFrameKey = L"Birds_Good";
	}
	else
	{
		CSoundMgr::Get_Instance()->PlayBGM("Try Again  - Rhythm Heaven.wav");
		m_pFrameKey = L"Birds_Bad";
	}


	CMainPlayer::Get_Instance()->Add_Bird_Count();
}

void CBirdOutro::Update()
{

	CMouseMgr::Get_Instance()->Update();

	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_UP || CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SLIDE)
	{
		system_clock::duration _time = system_clock::now() - m_tStartTime;
		if (_time > (milliseconds)600)
			CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_MENU);
	}
}

void CBirdOutro::LateUpdate()
{
	CMouseMgr::Get_Instance()->LateUpdate();
}

void CBirdOutro::Render(HDC hDC)
{
	CScene::UpdateRect();

	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(m_pFrameKey);

	system_clock::duration _time = system_clock::now() - m_tStartTime;

	if (_time > (milliseconds)1000)
	{
		GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC,
			0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(255, 0, 255));
	}
	CMouseMgr::Get_Instance()->Render(hDC);
}

void CBirdOutro::Release()
{
}

void CBirdOutro::Set_Note()
{
}
