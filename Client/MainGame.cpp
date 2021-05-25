#include "stdafx.h"
#include "MainGame.h"
#include "SceneMgr.h"
#include "ResourceMgr.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "SoundMgr.h"
#include "MouseMgr.h"
#include "MainPlayer.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	tStart = system_clock::now();
	m_hdc = GetDC(g_hWND);
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/Back.bmp", L"Back");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/Back.bmp", L"BackBuffer");
	CSoundMgr::Get_Instance()->Initialize();
	CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_OPENING);
	CMainPlayer::Get_Instance()->Initialize();
}

void CMainGame::Update()
{
	tCurrent = system_clock::now();
	tDuration = duration_cast<milliseconds>(tCurrent - tStart);
	CSceneMgr::Get_Instance()->Update();
}

void CMainGame::LateUpdate()
{
	CSceneMgr::Get_Instance()->LateUpdate();

	CKeyMgr::Get_Instance()->KeyUpdate();
	CSoundMgr::Get_Instance()->Update();
}

void CMainGame::Render()
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == CSceneMgr::INTRO_BIRDS)
		return;
	else if (CSceneMgr::Get_Instance()->Get_SceneID() == CSceneMgr::INTRO_FANCLUB)
		return;

	HDC hBack = CResourceMgr::Get_Instance()->FindImage(L"BackBuffer");
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"Back");
	BitBlt(hBack, 0, 0, 800, 600, hMemDC, 0, 0, SRCCOPY);
	
	
	CSceneMgr::Get_Instance()->Render(hBack);
	//CheckTime(hBack);

	BitBlt(m_hdc, 0, 0, 800, 600, hBack, 0, 0, SRCCOPY);
}

void CMainGame::Release()
{
	CSceneMgr::Get_Instance()->Destroy_Instance();
	CSoundMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->Destroy_Instance();
	CMainPlayer::Get_Instance()->Destroy_Instance();
}
