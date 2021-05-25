#include "stdafx.h"
#include "OpeningUI.h"
#include "MouseMgr.h"
#include "ResourceMgr.h"
#include "SoundMgr.h"
#include "ObjMgr.h"
#include "OpeningButton.h"

COpeningUI::COpeningUI()
{
}


COpeningUI::~COpeningUI()
{
	Release();
}

void COpeningUI::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 800.f;
	m_tInfo.fCY = 600.f;
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/OpeningUI/OpeningLogo.bmp", L"Opening");
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 7;
	m_tFrame.iFrameScene = 0;
	m_tFrame.tFrameTime = system_clock::now();
	m_tFrame.tFrameSpeed = 50;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/OpeningUI/Start_Button.bmp", L"Start");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/OpeningUI/Exit_Button.bmp", L"Exit");

	CObj* pObj = CAbstractFactory<COpeningButton>::Create(600.f, 214.f);
	D_CAST(COpeningButton, pObj)->Set_FrameKey(L"Start");
	CObjMgr::Get_Instance()->AddObject(ObjID::BUTTON_OPENING, pObj);

	pObj = CAbstractFactory<COpeningButton>::Create(600.f, 395.f);
	D_CAST(COpeningButton, pObj)->Set_FrameKey(L"Exit");
	CObjMgr::Get_Instance()->AddObject(ObjID::BUTTON_OPENING, pObj);

	CMouseMgr::Get_Instance()->Initialize(SceneID::GAME_NULL);
}

void COpeningUI::Update()
{
	CScene::FrameMove();
	CObjMgr::Get_Instance()->Update();
	CMouseMgr::Get_Instance()->Update();
}

void COpeningUI::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	CMouseMgr::Get_Instance()->LateUpdate();
}

void COpeningUI::Render(HDC hDC)
{
	CScene::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"Opening");
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC,
		m_tFrame.iFrameStart*m_tInfo.fCX, m_tFrame.iFrameScene*m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY, RGB(0, 0, 0));

	CObjMgr::Get_Instance()->Render(hDC);
	CMouseMgr::Get_Instance()->Render(hDC);
}

void COpeningUI::Release()
{
	CObjMgr::Get_Instance()->DeleteID(ObjID::BUTTON_OPENING);
	CObjMgr::Get_Instance()->DeleteID(ObjID::MOUSE);
	CMouseMgr::Get_Instance()->Destroy_Instance();
}

void COpeningUI::Set_Note()
{
}
