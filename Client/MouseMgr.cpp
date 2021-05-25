#include "stdafx.h"
#include "MouseMgr.h"
#include "ResourceMgr.h"
#include "KeyMgr.h"
#include "SoundMgr.h"

IMPLEMENT_SINGLETON(CMouseMgr)

CMouseMgr::CMouseMgr()
{
}


CMouseMgr::~CMouseMgr()
{
}

void CMouseMgr::Initialize(SceneID::ID _scene)
{
	m_tInfo.fX = 0.f;
	m_tInfo.fY = 0.f;
	m_tInfo.fCX = 51.f;
	m_tInfo.fCY = 51.f;
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/Mouse.bmp", L"Mouse");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;
	m_tFrame.iFrameScene = 0;
	m_tFrame.tFrameSpeed = 0;
	m_tFrame.tFrameTime = system_clock::now();

	m_eScene = SceneID::GAME_NULL;

	m_dSpeed = 0;
	m_eMotion = MotionID::MOTION_NULL;

	m_dCurrent = 0;

	m_eScene = _scene;

	m_eCurState = NO_EVENT;
	m_eNextState = NO_EVENT;
}

void CMouseMgr::Update()
{
	POINT pt = {};
	Update_Rect();
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);
	m_tInfo.fX = float(pt.x);
	m_tInfo.fY = float(pt.y);
	ShowCursor(FALSE);

}

void CMouseMgr::LateUpdate()
{
	if (m_eScene == SceneID::GAME_NULL)
		m_tFrame.iFrameScene = 0;
	if (m_eScene == SceneID::GAME_LIZARDS)
		m_tFrame.iFrameScene = 1;
	if (m_eScene == SceneID::GAME_FARM)
		m_tFrame.iFrameScene = 2;
	if (m_eScene == SceneID::GAME_BIRDS)
		m_tFrame.iFrameScene = 3;
	if (m_eScene == SceneID::GAME_ROBOT)
		m_tFrame.iFrameScene = 3;
	if (m_eScene == SceneID::GAME_FANCLUB)
		m_tFrame.iFrameScene = 4;


	if (CKeyMgr::Get_Instance()->KeyDown(VK_LBUTTON))
	{
		Sound_KeyDown();
		m_tFrame.iFrameStart = 1;
		GetCursorPos(&m_pStart);
		ScreenToClient(g_hWND, &m_pStart);
		m_tPressStart = system_clock::now();
		m_eMotion = MotionID::MOTION_TOUCH;
		if (m_eScene == SceneID::GAME_LIZARDS)
		{
			if (m_pStart.y > 300)
				m_bLizardCheck = true;
			else
				m_bLizardCheck = false;
		}
	}
	else if (CKeyMgr::Get_Instance()->KeyPressing(VK_LBUTTON))
	{
		m_tFrame.iFrameStart = 1;
		GetCursorPos(&m_pCurrent);
		ScreenToClient(g_hWND, &m_pCurrent);
		double a1 = (m_pCurrent.x - m_pStart.x)*(m_pCurrent.x - m_pStart.x);
		double b1 = (m_pCurrent.y - m_pStart.y)*(m_pCurrent.y - m_pStart.y);
		double Distance = sqrt(a1 + b1);
		if (Distance > 5)
			++m_dCurrent;
		m_tPressTime = duration_cast<milliseconds>(system_clock::now() - m_tPressStart);
		m_eMotion = MotionID::MOTION_PRESS;

		if (m_eScene == SceneID::GAME_LIZARDS)
			Set_Lizard();
	}
	else if (CKeyMgr::Get_Instance()->KeyUp(VK_LBUTTON))
	{
		m_tFrame.iFrameStart = 0;
		GetCursorPos(&m_pEnd);
		double a1 = (m_pEnd.x - m_pStart.x)*(m_pEnd.x - m_pStart.x);
		double b1 = (m_pEnd.y - m_pStart.y)*(m_pEnd.y - m_pStart.y);
		double Distance = sqrt(a1 + b1);
		if (m_dCurrent == 0)
			m_dCurrent = Distance;
		m_dSpeed = Distance / m_dCurrent;
		if (m_dSpeed > 20)
			m_eMotion = MotionID::MOTION_SLIDE;
		else if (isinf(m_dSpeed))
			m_eMotion = MotionID::MOTION_UP;
		else
			m_eMotion = MotionID::MOTION_UP;
		int a = 0;
		m_dCurrent = 0;
		Sound_Slide();

		if (m_eScene == SceneID::GAME_LIZARDS)
			m_eNextState = NO_EVENT;
	}
	else
	{
		m_tFrame.iFrameStart = 0;
		m_eMotion = MotionID::MOTION_NULL;
	}

}

void CMouseMgr::Render(HDC _hdc)
{
	Update_Rect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"Mouse");
	GdiTransparentBlt(_hdc, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC, m_tFrame.iFrameStart*m_tInfo.fCX, m_tFrame.iFrameScene*m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY, RGB(255, 0, 255));
}

void CMouseMgr::Release()
{
}

void CMouseMgr::Update_Rect()
{
	m_tRect.left = LONG(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = LONG(m_tInfo.fY - (LONG(m_tInfo.fCY) >> 1));
	m_tRect.right = LONG(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = LONG(m_tInfo.fY + m_tInfo.fCY * 0.5f);
}

void CMouseMgr::Sound_KeyDown()
{
	if (m_eScene == SceneID::GAME_NULL)
		CSoundMgr::Get_Instance()->PlaySound("MouseKeyDown.wav", CSoundMgr::UI);
	else if (m_eScene == SceneID::GAME_FANCLUB)
		CSoundMgr::Get_Instance()->PlaySound("FanClub_KeyDown.wav", CSoundMgr::UI);
	else if (m_eScene == SceneID::GAME_BIRDS)
		CSoundMgr::Get_Instance()->PlaySound("BlueBirds_ShortKeyDown.wav", CSoundMgr::UI);
	else if (m_eScene == SceneID::GAME_FARM)
		CSoundMgr::Get_Instance()->PlaySound("CropStomp_KeyDown.wav", CSoundMgr::UI);
}

void CMouseMgr::Sound_KeyUp()
{
}

void CMouseMgr::Sound_Slide()
{
	if (m_eScene == SceneID::GAME_NULL)
		CSoundMgr::Get_Instance()->PlaySound("MouseKeyUp.wav", CSoundMgr::UI);
	else if (m_eScene == SceneID::GAME_FANCLUB)
	{
		if (m_dSpeed > 30)
			CSoundMgr::Get_Instance()->PlaySound("FanClub_Slide.wav", CSoundMgr::UI);
	}
	else if (m_eScene == SceneID::GAME_BIRDS)
	{
		if (m_dSpeed > 30)
		{
			CSoundMgr::Get_Instance()->PlaySound("BlueBirds_Slide_1.wav", CSoundMgr::UI);
			CSoundMgr::Get_Instance()->PlaySound("BlueBirds_Slide_2.wav", CSoundMgr::UI);
		}
	}
}

void CMouseMgr::Set_Lizard()
{
	//위에서 찍음
	if (m_bLizardCheck)
	{
		if (m_eNextState == NO_EVENT)
		{
			if (m_pCurrent.y < 300)
				Change_State(DOWN_1);
		}
		else if (m_eNextState == DOWN_1)
		{
			if (m_pCurrent.y > 300)
				Change_State(UP_1);
		}
		else if (m_eNextState == UP_1)
		{
			if (m_pCurrent.y < 300)
				Change_State(DOWN_2);
		}
		else if (m_eNextState == DOWN_2)
		{
			if (m_pCurrent.y > 300)
				Change_State(UP_2);
		}
		else if (m_eNextState == UP_2)
		{
			if (m_pCurrent.y < 300)
				Change_State(DOWN_1);
		}
	}
	//아래에서 찍음
	else
	{
		if (m_eNextState == NO_EVENT)
		{
			if (m_pCurrent.y > 300)
				Change_State(UP_1);
		}
		else if (m_eNextState == UP_1)
		{
			if (m_pCurrent.y < 300)
				Change_State(DOWN_1);
		}
		else if (m_eNextState == DOWN_1)
		{
			if (m_pCurrent.y > 300)
				Change_State(UP_2);
		}
		else if (m_eNextState == UP_2)
		{
			if (m_pCurrent.y < 300)
				Change_State(DOWN_2);
		}
		else if (m_eNextState == DOWN_2)
		{
			if (m_pCurrent.y > 300)
				Change_State(UP_1);
		}
	}
}

void CMouseMgr::Change_State(Scratch _event)
{
	m_eNextState = _event;
	if (m_eNextState != m_eCurState)
	{
		switch (m_eNextState)
		{
		case CMouseMgr::NO_EVENT:
			m_eMotion = MotionID::MOTION_NULL;
			m_iRandonSound = rand() % 5;
			break;
		case CMouseMgr::UP_1:
			m_eMotion = MotionID::MOTION_SCRATCHUP;
			CSoundMgr::Get_Instance()->PlaySoundW("Love Lizards_A_Down_1.wav", CSoundMgr::PLAYER);
			break;
		case CMouseMgr::UP_2:
			m_eMotion = MotionID::MOTION_SCRATCHUP;
			CSoundMgr::Get_Instance()->PlaySoundW("Love Lizards_A_Down_2.wav", CSoundMgr::PLAYER);
			break;
		case CMouseMgr::DOWN_1:
			m_eMotion = MotionID::MOTION_SCRATCHDOWN;
			CSoundMgr::Get_Instance()->PlaySoundW("Love Lizards_A_UP_1.wav", CSoundMgr::PLAYER);
			break;
		case CMouseMgr::DOWN_2:
			m_eMotion = MotionID::MOTION_SCRATCHDOWN;
			CSoundMgr::Get_Instance()->PlaySoundW("Love Lizards_A_UP_2.wav", CSoundMgr::PLAYER);
			break;
		default:
			break;
		}
	}
}

