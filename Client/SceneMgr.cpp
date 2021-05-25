#include "stdafx.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "OpeningUI.h"
#include "MainUI.h"
#include "BlueBirds.h"
#include "LoveLizards.h"
#include "FanClub.h"
#include "SoundMgr.h"
#include "MouseMgr.h"

#include "Cafe.h"
#include "BirdIntro.h"
#include "FanClubIntro.h"
#include "LoveLizardsIntro.h"

#include "BirdOutro.h"
#include "FanClubOutro.h"
#include "LoveLizardsOutro.h"

IMPLEMENT_SINGLETON(CSceneMgr)

CSceneMgr::CSceneMgr()
	:m_pScene(nullptr)
	,m_eCurScene(SCENE_END)
	,m_eNextScene(SCENE_END)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Update()
{
	m_pScene->Update();
}

void CSceneMgr::LateUpdate()
{
	m_pScene->LateUpdate();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
}

void CSceneMgr::SceneChange(SCENEID eScene)
{
	m_eNextScene = eScene;
	if (m_eNextScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);
		switch (m_eNextScene)
		{
		case CSceneMgr::SCENE_OPENING:
			m_pScene = new COpeningUI;
			CSoundMgr::Get_Instance()->PlayBGM("Title Theme - Rhythm Heaven.wav");
			break;
		case CSceneMgr::SCENE_MENU:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CMainUI;
			CSoundMgr::Get_Instance()->PlayBGM("Game Select - Rhythm Heaven.wav");
			break;
		case CSceneMgr::SCENE_CAFE:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CCafe;
			CSoundMgr::Get_Instance()->PlayBGM("Endless Games - Rhythm Heaven.wav");
			break;
		case CSceneMgr::INTRO_BIRDS:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CBirdIntro;
			break;
		case CSceneMgr::SCENE_BIRDS:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CBlueBirds;
			break;
		case CSceneMgr::INTRO_FANCLUB:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CFanClubIntro;
			break;
		case CSceneMgr::SCENE_FANCLUB:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CFanClub;
			break;
		case CSceneMgr::INTRO_LIZARDS:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CLoveLizardsIntro;
			break;
		case CSceneMgr::SCENE_LIZARDS:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CLoveLizards;
			break;

		}
		m_pScene->Initialize();
		m_eCurScene = m_eNextScene;
	}
}

void CSceneMgr::SceneChange(SCENEID eScene, int _i)
{
	m_eNextScene = eScene;
	if (m_eNextScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);
		switch (m_eNextScene)
		{
		case CSceneMgr::OUTRO_BIRDS:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CBirdOutro;
			break;
		case CSceneMgr::OUTRO_FANCLUB:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CFanClubOutro;
			break;
		case CSceneMgr::OUTRO_LIZARDS:
			CSoundMgr::Get_Instance()->StopAll();
			m_pScene = new CLoveLizardsOutro;
			break;
		}
		m_pScene->Set_Count(_i);
		m_pScene->Initialize();
		m_eCurScene = m_eNextScene;
	}
}
