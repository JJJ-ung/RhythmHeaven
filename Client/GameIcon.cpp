#include "stdafx.h"
#include "GameIcon.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "ResourceMgr.h"
#include "SoundMgr.h"
#include "MainPlayer.h"

CGameIcon::CGameIcon()
{
}


CGameIcon::~CGameIcon()
{
	Release();
}

void CGameIcon::Initialize()
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iFrameScene = 0;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/InfoBox.bmp", L"InfoBox");
	box_info.fCX = 335;
	box_info.fCY = 320;
	box_info.fX = 199.5f;
	box_info.fY = 300.f;
	box_frame.iFrameStart = 0;
	box_frame.iFrameEnd = 4;
	box_frame.iFrameScene = 0;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/Medal.bmp", L"Medal_Icon");
	Medal_info.fX = 316.f;
	Medal_info.fY = 175.f;
	Medal_info.fCX = 60.f;
	Medal_info.fCY = 70.f;
	Medal_frame.iFrameStart = 0;
	Medal_frame.iFrameEnd = 3;
	Medal_frame.iFrameScene = 0;
}

int CGameIcon::Update()
{
	if (!lstrcmp(m_pFrameKey, L"BlueBirds_Icon"))
	{
		if (CMainPlayer::Get_Instance()->Get_BirdMedal()->PerfectMedal == true)
		{
			m_tFrame.iFrameStart = 4;
			m_tFrame.iFrameEnd = 4;
			Medal_frame.iFrameStart = 0;
			Medal_frame.iFrameEnd = 0;
		}
		else if (CMainPlayer::Get_Instance()->Get_BirdMedal()->SuperbMedal == true)
		{
			m_tFrame.iFrameStart = 3;
			m_tFrame.iFrameEnd = 3;
			Medal_frame.iFrameStart = 1;
			Medal_frame.iFrameEnd = 1;
		}
		else if (CMainPlayer::Get_Instance()->Get_BirdMedal()->OKMedal == true)
		{
			m_tFrame.iFrameStart = 2;
			m_tFrame.iFrameEnd = 2;
			Medal_frame.iFrameStart = 2;
			Medal_frame.iFrameEnd = 2;
		}
		else if (CMainPlayer::Get_Instance()->Get_BirdMedal()->NullMedal == true)
		{
			m_tFrame.iFrameStart = 1;
			m_tFrame.iFrameEnd = 1;
			Medal_frame.iFrameStart = 3;
			Medal_frame.iFrameEnd = 3;
		}
	}
	else if (!lstrcmp(m_pFrameKey, L"FanClub_Icon"))
	{
		if (CMainPlayer::Get_Instance()->Get_FanClubMedal()->PerfectMedal == true)
		{
			m_tFrame.iFrameStart = 4;
			m_tFrame.iFrameEnd = 4;
			Medal_frame.iFrameStart = 0;
			Medal_frame.iFrameEnd = 0;
		}
		else if (CMainPlayer::Get_Instance()->Get_FanClubMedal()->SuperbMedal == true)
		{
			m_tFrame.iFrameStart = 3;
			m_tFrame.iFrameEnd = 3;
			Medal_frame.iFrameStart = 1;
			Medal_frame.iFrameEnd = 1;
		}
		else if (CMainPlayer::Get_Instance()->Get_FanClubMedal()->OKMedal == true)
		{
			m_tFrame.iFrameStart = 2;
			m_tFrame.iFrameEnd = 2;
			Medal_frame.iFrameStart = 2;
			Medal_frame.iFrameEnd = 2;
		}
		else if (CMainPlayer::Get_Instance()->Get_FanClubMedal()->NullMedal == true)
		{
			m_tFrame.iFrameStart = 1;
			m_tFrame.iFrameEnd = 1;
			Medal_frame.iFrameStart = 3;
			Medal_frame.iFrameEnd = 3;
		}
	}
	else if (!lstrcmp(m_pFrameKey, L"Lizard_Icon"))
	{
		if (CMainPlayer::Get_Instance()->Get_LizardMedal()->PerfectMedal == true)
		{
			m_tFrame.iFrameStart = 4;
			m_tFrame.iFrameEnd = 4;
			Medal_frame.iFrameStart = 0;
			Medal_frame.iFrameEnd = 0;
		}
		else if (CMainPlayer::Get_Instance()->Get_LizardMedal()->SuperbMedal == true)
		{
			m_tFrame.iFrameStart = 3;
			m_tFrame.iFrameEnd = 3;
			Medal_frame.iFrameStart = 1;
			Medal_frame.iFrameEnd = 1;
		}
		else if (CMainPlayer::Get_Instance()->Get_LizardMedal()->OKMedal == true)
		{
			m_tFrame.iFrameStart = 2;
			m_tFrame.iFrameEnd = 2;
			Medal_frame.iFrameStart = 2;
			Medal_frame.iFrameEnd = 2;
		}
		else if (CMainPlayer::Get_Instance()->Get_LizardMedal()->NullMedal == true)
		{
			m_tFrame.iFrameStart = 1;
			m_tFrame.iFrameEnd = 1;
			Medal_frame.iFrameStart = 3;
			Medal_frame.iFrameEnd = 3;
		}
	}
	return OBJ_NOEVENT;
}

void CGameIcon::LateUpdate()
{
	CObj::UpdateRect();
	Update_BoxRect();
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		m_tFrame.iFrameStart = 0;
		m_tFrame.iFrameEnd = 0;
		m_tFrame.iFrameScene = 1;
		GetCursorPos(&pt);
		if (!lstrcmp(m_pFrameKey, L"BlueBirds_Icon"))
		{
			box_info.fCX = 335;
			box_info.fCY = 320;
			box_frame.iFrameStart = 2;
			Medal_info.fCX = 60.f;
			Medal_info.fCY = 70.f;
		}
		else if (!lstrcmp(m_pFrameKey, L"FanClub_Icon"))
		{ 
			box_info.fCX = 335;
			box_info.fCY = 320;
			box_frame.iFrameStart = 3;
			Medal_info.fCX = 60.f;
			Medal_info.fCY = 70.f;
		}
		else if (!lstrcmp(m_pFrameKey, L"Farm_Icon"))
		{
			box_info.fCX = 335;
			box_info.fCY = 320;
			box_frame.iFrameStart = 0;
			Medal_info.fCX = 60.f;
			Medal_info.fCY = 70.f;
		}
		else if (!lstrcmp(m_pFrameKey, L"Lizard_Icon"))
		{
			box_info.fCX = 335;
			box_info.fCY = 320;
			box_frame.iFrameStart = 1;
			Medal_info.fCX = 60.f;
			Medal_info.fCY = 70.f;
		}
		else if (!lstrcmp(m_pFrameKey, L"Robot_Icon"))
		{
			box_info.fCX = 335;
			box_info.fCY = 320;
			box_frame.iFrameStart = 4;
			Medal_info.fCX = 60.f;
			Medal_info.fCY = 70.f;
		}
		if (CKeyMgr::Get_Instance()->KeyUp(VK_LBUTTON))
		{
			CSoundMgr::Get_Instance()->PlaySound("Button.wav", CSoundMgr::UI);
			m_tFrame.iFrameStart = 1;
			if (!lstrcmp(m_pFrameKey, L"BlueBirds_Icon"))
			{
				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::INTRO_BIRDS);
			}
			else if (!lstrcmp(m_pFrameKey, L"FanClub_Icon"))
			{
				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::INTRO_FANCLUB);
			}
			else if (!lstrcmp(m_pFrameKey, L"Farm_Icon"))
			{
				//CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_FARM);
			}
			else if (!lstrcmp(m_pFrameKey, L"Lizard_Icon"))
			{
				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::INTRO_LIZARDS);
			}
			else if (!lstrcmp(m_pFrameKey, L"Robot_Icon"))
			{
				//CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_FILLBOTS);
			}
			return;
		}
	}
	else
	{
		m_tFrame.iFrameScene = 0;
		box_info.fCX = 0;
		box_info.fCY = 0;
		Medal_info.fCX = 0;
		Medal_info.fCY = 0;
	}
}

void CGameIcon::Render(HDC _hdc)
{
	CObj::UpdateRect();
	Update_BoxRect();
	Update_MedalRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(m_pFrameKey);
	HDC hMemDC2 = CResourceMgr::Get_Instance()->FindImage(L"InfoBox");
	HDC hMemDC3 = CResourceMgr::Get_Instance()->FindImage(L"Medal_Icon");
	GdiTransparentBlt(_hdc,
		m_tRect.left, m_tRect.top,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		hMemDC, m_tFrame.iFrameStart * m_tInfo.fCX, m_tFrame.iFrameScene * m_tInfo.fCY,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		RGB(255, 0, 255));
	GdiTransparentBlt(_hdc,
		box_rect.left, box_rect.top,
		(int)box_info.fCX, (int)box_info.fCY,
		hMemDC2, box_frame.iFrameStart * box_info.fCX, box_frame.iFrameScene * box_info.fCY,
		(int)box_info.fCX, (int)box_info.fCY,
		RGB(255, 0, 255));
	GdiTransparentBlt(_hdc,
		Medal_rect.left, Medal_rect.top,
		(int)Medal_info.fCX, (int)Medal_info.fCY,
		hMemDC3, Medal_frame.iFrameStart * Medal_info.fCX, Medal_frame.iFrameScene * Medal_info.fCY,
		(int)Medal_info.fCX, (int)Medal_info.fCY,
		RGB(255, 0, 255));
}

void CGameIcon::Release()
{
}

void CGameIcon::Update_BoxRect()
{
	box_rect.left = LONG(box_info.fX - box_info.fCX * 0.5f);
	box_rect.top = LONG(box_info.fY - (LONG(box_info.fCY) >> 1));
	box_rect.right = LONG(box_info.fX + box_info.fCX * 0.5f);
	box_rect.bottom = LONG(box_info.fY + box_info.fCY * 0.5f);
}

void CGameIcon::Update_MedalRect()
{
	Medal_rect.left = LONG(Medal_info.fX - Medal_info.fCX * 0.5f);
	Medal_rect.top = LONG(Medal_info.fY - (LONG(Medal_info.fCY) >> 1));
	Medal_rect.right = LONG(Medal_info.fX + Medal_info.fCX * 0.5f);
	Medal_rect.bottom = LONG(Medal_info.fY + Medal_info.fCY * 0.5f);
}
