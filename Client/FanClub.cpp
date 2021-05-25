#include "stdafx.h"
#include "FanClub.h"
#include "MouseMgr.h"
#include "ResourceMgr.h"
#include "ObjMgr.h"
#include "PlayerFan.h"
#include "FanNPC.h"
#include "SoundMgr.h"
#include "Idol.h"
#include "SceneMgr.h"
#include "FanClubOutro.h"
#include "KeyMgr.h"

CFanClub::CFanClub()
{
}


CFanClub::~CFanClub()
{
	Release();
}

void CFanClub::Initialize()
{
	Set_Note();
	iter_Note = m_vNote.begin();

	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 800.f;
	m_tInfo.fCY = 600.f;
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/FanClup_Background.bmp", L"FanClubBG");

	CMouseMgr::Get_Instance()->Initialize(SceneID::GAME_FANCLUB);

	m_tStartTime = system_clock::now();

	CSoundMgr::Get_Instance()->PlaySound("Fan_Club.mp3", CSoundMgr::BGM);

	CObj* pObj = CAbstractFactory<CPlayerFan>::Create();
	CObjMgr::Get_Instance()->AddObject(ObjID::PLAYER, pObj);

	pObj = CAbstractFactory<CIdol>::Create(m_tStartTime);
	CObjMgr::Get_Instance()->AddObject(ObjID::NPC_NONREACT, pObj);

	pObj = CAbstractFactory<CFanNPC>::Create(74.f, 451.f, m_tStartTime);
	CObjMgr::Get_Instance()->AddObject(ObjID::NPC_REACT, pObj);

	pObj = CAbstractFactory<CFanNPC>::Create(209.f, 451.f, m_tStartTime);
	CObjMgr::Get_Instance()->AddObject(ObjID::NPC_REACT, pObj);
	
	m_eJudge = JudgeID::NOTHING;
	m_bReaction = false;
}

void CFanClub::Update()
{
	m_lDuration = (duration_cast<milliseconds>(system_clock::now() - m_tStartTime)).count();
	CObjMgr::Get_Instance()->Update();
	CMouseMgr::Get_Instance()->Update();
	Set_Judge();
	CObjMgr::Get_Instance()->Set_Reaction(m_bReaction);

	if (m_lDuration > 61212)
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::OUTRO_FANCLUB, m_iCount);
}

void CFanClub::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	CMouseMgr::Get_Instance()->LateUpdate();

	if(CKeyMgr::Get_Instance()->KeyDown('P'))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::OUTRO_FANCLUB, m_iCount);
}

void CFanClub::Render(HDC hDC)
{
	CScene::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"FanClubBG");
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(0, 0, 0));
	
	CObjMgr::Get_Instance()->Render(hDC);
	CMouseMgr::Get_Instance()->Render(hDC);
}

void CFanClub::Release()
{
	CMouseMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->DeleteID(ObjID::PLAYER);
	CObjMgr::Get_Instance()->DeleteID(ObjID::NPC_REACT);
	CObjMgr::Get_Instance()->DeleteID(ObjID::NPC_NONREACT);
}


void CFanClub::Set_Note()
{
	// 호이호이호이
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 5909);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 6333);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 6769);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 7201);

	//어떡해
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 19477);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 20086);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 20286);
	m_vNote.emplace_back(MotionID::MOTION_SLIDE, 20696);

	//얍수리수리수리
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 26240);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 26643);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 27056);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 27481);

	//어떡해
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 33013);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 33623);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 33818);
	m_vNote.emplace_back(MotionID::MOTION_SLIDE, 34231);

	//두근두근두근
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 39728);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 40133);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 40588);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 41005);

	//나어떡해
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 43155);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 43760);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 43960);
	m_vNote.emplace_back(MotionID::MOTION_SLIDE, 44347);

	//좋아좋아좋아
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 46503);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 46907);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 47344);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 47773);

	//어떡해
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 51574);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 52216);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 52408);
	m_vNote.emplace_back(MotionID::MOTION_SLIDE, 52807);

	//호이호이호이
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 54946);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 55359);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 55780);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 56212);
}
