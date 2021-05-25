#include "stdafx.h"
#include "CropStomp.h"
#include "MouseMgr.h"
#include "ResourceMgr.h"
#include "SoundMgr.h"

CCropStomp::CCropStomp()
{
}


CCropStomp::~CCropStomp()
{
}

void CCropStomp::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 800.f;
	m_tInfo.fCY = 600.f;
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/CropStomp/Background.bmp", L"FarmBG");


	CMouseMgr::Get_Instance()->Initialize(SceneID::GAME_FARM);

	CSoundMgr::Get_Instance()->PlayBGM("Stomp Farmer - Rhythm Heaven.wav");
}

void CCropStomp::Update()
{
	CMouseMgr::Get_Instance()->Update();
}

void CCropStomp::LateUpdate()
{
	CMouseMgr::Get_Instance()->LateUpdate();
}

void CCropStomp::Render(HDC hDC)
{
	CScene::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"FarmBG");
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(0, 0, 0));

	CMouseMgr::Get_Instance()->Render(hDC);
}

void CCropStomp::Release()
{
	CMouseMgr::Get_Instance()->Destroy_Instance();
}

void CCropStomp::Set_Note()
{
}


