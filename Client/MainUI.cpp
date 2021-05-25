#include "stdafx.h"
#include "MainUI.h"
#include "GameIcon.h"
#include "Inven.h"
#include "MouseMgr.h"
#include "ResourceMgr.h"
#include "SoundMgr.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "MainPlayer.h"

CMainUI::CMainUI()
{
}


CMainUI::~CMainUI()
{
	Release();
}

void CMainUI::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 800.f;
	m_tInfo.fCY = 600.f;
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/Back.bmp", L"Alpha");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/MainUI.bmp", L"Main");

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/Birds.bmp", L"BlueBirds_Icon");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/FanClub.bmp", L"FanClub_Icon");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/Farm.bmp", L"Farm_Icon");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/Lizard.bmp", L"Lizard_Icon");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/MainUI/Robot.bmp", L"Robot_Icon");

	CObj*pObj = CAbstractFactory<CGameIcon>::Create(530.f, 170.f);
	D_CAST(CGameIcon, pObj)->Set_FrameKey(L"BlueBirds_Icon");
	CObjMgr::Get_Instance()->AddObject(ObjID::BUTTON_GAMEICON, pObj);
	
	pObj = CAbstractFactory<CGameIcon>::Create(530.f, 290.f);
	D_CAST(CGameIcon, pObj)->Set_FrameKey(L"FanClub_Icon");
	CObjMgr::Get_Instance()->AddObject(ObjID::BUTTON_GAMEICON, pObj);

	pObj = CAbstractFactory<CGameIcon>::Create(530.f, 410.f);
	D_CAST(CGameIcon, pObj)->Set_FrameKey(L"Lizard_Icon");
	CObjMgr::Get_Instance()->AddObject(ObjID::BUTTON_GAMEICON, pObj);

	pObj = CAbstractFactory<CInven>::Create(706.f, 300.f);
	CObjMgr::Get_Instance()->AddObject(ObjID::BUTTON_GAMEICON, pObj);

	CMouseMgr::Get_Instance()->Initialize(SceneID::GAME_NULL);

	m_iAlpha = 0;
}

void CMainUI::Update()
{
	if (CKeyMgr::Get_Instance()->KeyDown('Q'))
		CMainPlayer::Get_Instance()->Set_Perfect_Medal();
	else if (CKeyMgr::Get_Instance()->KeyDown('W'))
		CMainPlayer::Get_Instance()->Set_Superb_Medal();
	else if (CKeyMgr::Get_Instance()->KeyDown('E'))
		CMainPlayer::Get_Instance()->Set_OK_Medal();
	else if (CKeyMgr::Get_Instance()->KeyDown('R'))
		CMainPlayer::Get_Instance()->Set_Null_Medal();
	else if (CKeyMgr::Get_Instance()->KeyDown('A'))
		CMainPlayer::Get_Instance()->Set_All_Medal();

	CObjMgr::Get_Instance()->Update();
	if (m_iAlpha < 255)
		m_iAlpha += 1;
	CMouseMgr::Get_Instance()->Update();
}

void CMainUI::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	CMouseMgr::Get_Instance()->LateUpdate();
}

void CMainUI::Render(HDC hDC)
{
	CScene::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"Main");
	HDC hMemDC2 = CResourceMgr::Get_Instance()->FindImage(L"Alpha");

	if (m_iAlpha < 255)
	{
		_bf.BlendOp = 0;
		_bf.BlendFlags = 0;
		_bf.SourceConstantAlpha = 0 + m_iAlpha;
		_bf.AlphaFormat = AC_SRC_OVER;
		GdiAlphaBlend(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC, 0, 0, m_tInfo.fCX, m_tInfo.fCY, _bf);
	}
	else
	{
		GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(0, 0, 0));
		CObjMgr::Get_Instance()->Render(hDC);

		HFONT hFont, oldFont;
		hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("µ¸¿ò"));
		oldFont = (HFONT)SelectObject(hDC, hFont);
		SetTextColor(hDC, RGB(245, 245, 245));
		SetBkColor(hDC, RGB(30, 30, 30));
		SetTextAlign(hDC, TA_LEFT);
		TCHAR m_Ryhthm[100] = L"";
		swprintf_s(m_Ryhthm, L"%d", CMainPlayer::Get_Instance()->Get_Rhythm());
		TextOut(hDC, 135, 495, m_Ryhthm, lstrlen(m_Ryhthm));
		SetBkMode(hDC, TRANSPARENT);
		SelectObject(hDC, oldFont);
		DeleteObject(hFont);


		CMouseMgr::Get_Instance()->Render(hDC);
	}
}

void CMainUI::Release()
{
	CObjMgr::Get_Instance()->DeleteID(ObjID::BUTTON_GAMEICON);
	CObjMgr::Get_Instance()->DeleteID(ObjID::MOUSE);
	CMouseMgr::Get_Instance()->Destroy_Instance();
}

void CMainUI::Set_Note()
{
}
