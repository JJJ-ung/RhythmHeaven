#include "stdafx.h"
#include "Cafe.h"
#include "BackButton.h"
#include "Medal.h"
#include "MouseMgr.h"
#include "ResourceMgr.h"
#include "ObjMgr.h"
#include "MainPlayer.h"

CCafe::CCafe()
{
}


CCafe::~CCafe()
{
	Release();
}

void CCafe::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 800.f;
	m_tInfo.fCY = 600.f;
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/Cafe/Cafe_BackGround_BOX.bmp", L"Cafe_Back");

	CObj*pObj = CAbstractFactory<CBackButton>::Create();
	CObjMgr::Get_Instance()->AddObject(ObjID::BUTTON_INVENTORY, pObj);

	//블루버드 메달
	if (CMainPlayer::Get_Instance()->Get_BirdMedal()->PerfectMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(80.f, 175.f);
		pObj->Set_Frame(0, 0, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}
	if (CMainPlayer::Get_Instance()->Get_BirdMedal()->SuperbMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(155.f, 175.f);
		pObj->Set_Frame(1, 1, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}
	if (CMainPlayer::Get_Instance()->Get_BirdMedal()->OKMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(230.f, 175.f);
		pObj->Set_Frame(2, 2, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}
	if (CMainPlayer::Get_Instance()->Get_BirdMedal()->NullMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(300.f, 175.f);
		pObj->Set_Frame(3, 3, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}

	//도마뱀 메달
	if (CMainPlayer::Get_Instance()->Get_LizardMedal()->PerfectMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(80.f, 284.f);
		pObj->Set_Frame(0, 0, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}
	if (CMainPlayer::Get_Instance()->Get_LizardMedal()->SuperbMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(155.f, 284.f);
		pObj->Set_Frame(1, 1, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}
	if (CMainPlayer::Get_Instance()->Get_LizardMedal()->OKMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(230.f, 284.f);
		pObj->Set_Frame(2, 2, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}
	if (CMainPlayer::Get_Instance()->Get_LizardMedal()->NullMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(300.f, 284.f);
		pObj->Set_Frame(3, 3, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}

	//팬클럽 메달
	if (CMainPlayer::Get_Instance()->Get_FanClubMedal()->PerfectMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(80.f, 392.f);
		pObj->Set_Frame(0, 0, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}
	if (CMainPlayer::Get_Instance()->Get_FanClubMedal()->SuperbMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(155.f, 392.f);
		pObj->Set_Frame(1, 1, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}
	if (CMainPlayer::Get_Instance()->Get_FanClubMedal()->OKMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(230.f, 392.f);
		pObj->Set_Frame(2, 2, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}
	if (CMainPlayer::Get_Instance()->Get_FanClubMedal()->NullMedal)
	{
		CObj*pObj = CAbstractFactory<CMedal>::Create(300.f, 392.f);
		pObj->Set_Frame(3, 3, 0);
		CObjMgr::Get_Instance()->AddObject(ObjID::MEDAL, pObj);
	}

	CMouseMgr::Get_Instance()->Initialize(SceneID::GAME_NULL);
}

void CCafe::Update()
{
	CObjMgr::Get_Instance()->Update();
	CMouseMgr::Get_Instance()->Update();
}

void CCafe::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	CMouseMgr::Get_Instance()->LateUpdate();
}

void CCafe::Render(HDC hDC)
{
	CScene::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"Cafe_Back");
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(0, 0, 0));
	CObjMgr::Get_Instance()->Render(hDC);
	Render_Text(hDC);
	CMouseMgr::Get_Instance()->Render(hDC);
}

void CCafe::Release()
{
	CObjMgr::Get_Instance()->DeleteID(ObjID::BUTTON_INVENTORY);
	CObjMgr::Get_Instance()->DeleteID(ObjID::MEDAL);
	CObjMgr::Get_Instance()->DeleteID(ObjID::MOUSE);
	CMouseMgr::Get_Instance()->Destroy_Instance();
}

void CCafe::Set_Note()
{
}

void CCafe::Render_Text(HDC hDC)
{
	HFONT hFont, oldFont;
	hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("돋움"));
	oldFont = (HFONT)SelectObject(hDC, hFont);
	SetTextColor(hDC, RGB(40, 40, 40));
	SetBkColor(hDC, RGB(30, 30, 30));
	SetTextAlign(hDC, TA_RIGHT);

	//블루버드 플레이 횟수
	TCHAR m_BlueBird[100] = L"";
	swprintf_s(m_BlueBird, L"%d", CMainPlayer::Get_Instance()->Get_Bird_Count());
	TextOut(hDC, 715, 108, m_BlueBird, lstrlen(m_BlueBird));

	//팬클럽 플레이 횟수
	TCHAR m_FanClub[100] = L"";
	swprintf_s(m_FanClub, L"%d", CMainPlayer::Get_Instance()->Get_Fan_Count());
	TextOut(hDC, 715, 137, m_FanClub, lstrlen(m_FanClub));

	//도마뱀 플레이 횟수
	TCHAR m_Lizard[100] = L"";
	swprintf_s(m_Lizard, L"%d", CMainPlayer::Get_Instance()->Get_Lizard_Count());
	TextOut(hDC, 715, 165, m_Lizard, lstrlen(m_Lizard));

	//퍼펙트 통계
	TCHAR m_Perfect[100] = L"";
	swprintf_s(m_Perfect, L"%d", CMainPlayer::Get_Instance()->Get_Perfect_Count());
	TextOut(hDC, 715, 267, m_Perfect, lstrlen(m_Perfect));

	//굳 통계
	TCHAR m_Good[100] = L"";
	swprintf_s(m_Good, L"%d", CMainPlayer::Get_Instance()->Get_Good_Count());
	TextOut(hDC, 715, 294, m_Good, lstrlen(m_Good));

	//배드 통계
	TCHAR m_Bad[100] = L"";
	swprintf_s(m_Bad, L"%d", CMainPlayer::Get_Instance()->Get_Bad_Count());
	TextOut(hDC, 715, 323, m_Bad, lstrlen(m_Bad));

	SetBkMode(hDC, TRANSPARENT);
	SelectObject(hDC, oldFont);
	DeleteObject(hFont);
}
