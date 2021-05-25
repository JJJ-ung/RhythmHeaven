#include "stdafx.h"
#include "BlueBirds.h"
#include "MouseMgr.h"
#include "SoundMgr.h"
#include "ResourceMgr.h"
#include "ObjMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

#include "PlayerBird.h"
#include "NPCBird.h"
#include "CaptainBird.h"
#include "BirdEffect.h"

CBlueBirds::CBlueBirds()
{
}


CBlueBirds::~CBlueBirds()
{
	Release();
}

void CBlueBirds::Initialize()
{
	Set_Note();
	iter_Note = m_vNote.begin();

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/BlueBirds_BG.bmp", L"BlueBirdsBG");
	m_tInfo.fCX = WINCX;
	m_tInfo.fCY = WINCY;
	m_tInfo.fX = 400;
	m_tInfo.fY = 300;

	CMouseMgr::Get_Instance()->Initialize(SceneID::GAME_BIRDS);
	
	m_tStartTime = system_clock::now();

	CSoundMgr::Get_Instance()->PlaySound("Blue Birds.wav", CSoundMgr::BGM);

	//¿©±â¿¡ ¿ÀºêÁ§Æ® Ãß°¡
	CObj* pObj = CAbstractFactory<CBirdEffect>::Create(m_tStartTime);	//È¸»ó
	CObjMgr::Get_Instance()->AddObject(ObjID::NPC_NONREACT, pObj);

	pObj = CAbstractFactory<CPlayerBird>::Create(m_tStartTime);
	CObjMgr::Get_Instance()->AddObject(ObjID::PLAYER, pObj);

	pObj = CAbstractFactory<CNPCBird>::Create(81.f, 387.f, m_tStartTime, 0);	//¿ÞÂÊ ¾Ö
	CObjMgr::Get_Instance()->AddObject(ObjID::NPC_NONREACT, pObj);

	pObj = CAbstractFactory<CNPCBird>::Create(208.f, 387.f, m_tStartTime, 1);	//°¡¿îµ¥ ¾Ö
	CObjMgr::Get_Instance()->AddObject(ObjID::NPC_NONREACT, pObj);

	pObj = CAbstractFactory<CCaptainBird>::Create(m_tStartTime);	//´ëÀå´Ô
	CObjMgr::Get_Instance()->AddObject(ObjID::NPC_REACT, pObj);

	m_eJudge = JudgeID::NOTHING;
	m_bReaction = false;
}

void CBlueBirds::Update()
{
	m_lDuration = (duration_cast<milliseconds>(system_clock::now() - m_tStartTime)).count();
	CObjMgr::Get_Instance()->Update();
	CMouseMgr::Get_Instance()->Update();
	
	//ÆÇÁ¤ Ãß°¡
	Set_Judge();
	CObjMgr::Get_Instance()->Set_Reaction(m_bReaction);


	if (m_lDuration > 60000)
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::OUTRO_BIRDS, m_iCount);
}

void CBlueBirds::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	CMouseMgr::Get_Instance()->LateUpdate();

	if (CKeyMgr::Get_Instance()->KeyDown('P'))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::OUTRO_BIRDS, m_iCount);
}

void CBlueBirds::Render(HDC hDC)
{
	CScene::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"BlueBirdsBG");
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(0, 0, 0));

	CObjMgr::Get_Instance()->Render(hDC);
	CMouseMgr::Get_Instance()->Render(hDC);
}

void CBlueBirds::Release()
{
	CMouseMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->DeleteID(ObjID::PLAYER);
	CObjMgr::Get_Instance()->DeleteID(ObjID::NPC_REACT);
	CObjMgr::Get_Instance()->DeleteID(ObjID::NPC_NONREACT);
}

void CBlueBirds::Set_Note()
{
	//ÂßÂß»¸¾î
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 5609);
	m_vNote.emplace_back(MotionID::MOTION_SLIDE, 6088);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 10676);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 10906);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 11138);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 14370);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 14602);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 14827);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 18061);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 18293);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 18522);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 21752);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 21982);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 22216);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 25449);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 25676);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 25907);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 27296);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 27520);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 27757);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 29606);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 29835);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 30083);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 32832);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 33063);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 33295);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 34680);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 34912);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 35148);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 36987);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 37224);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 37461);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 41141);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 41354);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 41513);

	//ÂßÂß»¸¾î
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 44377);
	m_vNote.emplace_back(MotionID::MOTION_SLIDE, 44870);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 45773);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 46013);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 46225);

	//²Ù²Ù²Ð
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 48532);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 48780);
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 48987);
	
	//ÂßÂß»¸¾î
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 51765);
	m_vNote.emplace_back(MotionID::MOTION_SLIDE, 52191);

	//ÂßÂß»¸¾î
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 53609);
	m_vNote.emplace_back(MotionID::MOTION_SLIDE, 54059);

	//ÂßÂß»¸¾î
	m_vNote.emplace_back(MotionID::MOTION_TOUCH, 55453);
	m_vNote.emplace_back(MotionID::MOTION_SLIDE, 55885);
}

