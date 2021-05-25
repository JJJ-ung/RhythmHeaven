#include "stdafx.h"
#include "LoveLizards.h"
#include "MouseMgr.h"
#include "ResourceMgr.h"
#include "SoundMgr.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

#include "LizardNPC.h"
#include "PlayerLizardBody.h"
#include "PlayerLizardTail.h"

CLoveLizards::CLoveLizards()
{
}


CLoveLizards::~CLoveLizards()
{
	Release();
}

void CLoveLizards::Initialize()
{
	Set_Note();
	iter_Note = m_vNote.begin();

	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 800.f;
	m_tInfo.fCY = 600.f;
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/Lizard_Background.bmp", L"LizardsBG");

	CMouseMgr::Get_Instance()->Initialize(SceneID::GAME_LIZARDS);

	m_tStartTime = system_clock::now();

	CSoundMgr::Get_Instance()->PlaySoundW("Love Lizards.wav", CSoundMgr::BGM);

	CObj* pObj = CAbstractFactory<CPlayerLizardBody>::Create(m_tStartTime);
	CObjMgr::Get_Instance()->AddObject(ObjID::PLAYER, pObj);

	pObj = CAbstractFactory<CPlayerLizardTail>::Create(m_tStartTime);
	CObjMgr::Get_Instance()->AddObject(ObjID::PLAYER, pObj);

	pObj = CAbstractFactory<CLizardNPC>::Create(m_tStartTime);
	CObjMgr::Get_Instance()->AddObject(ObjID::NPC_REACT, pObj);
}

void CLoveLizards::Update()
{
	m_lDuration = (duration_cast<milliseconds>(system_clock::now() - m_tStartTime)).count();
	CObjMgr::Get_Instance()->Update();

	CMouseMgr::Get_Instance()->Update();
	Set_Lizard_Judge();
	CObjMgr::Get_Instance()->Set_Reaction(m_bReaction);

	if (m_lDuration > 62000)
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::OUTRO_LIZARDS, m_iCount);
}

void CLoveLizards::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();

	CMouseMgr::Get_Instance()->LateUpdate();

	if (CKeyMgr::Get_Instance()->KeyDown('P'))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::OUTRO_LIZARDS, m_iCount);
}

void CLoveLizards::Render(HDC hDC)
{
	CScene::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"LizardsBG");
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, hMemDC, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(0, 0, 0));
	
	CObjMgr::Get_Instance()->Render(hDC);
	CMouseMgr::Get_Instance()->Render(hDC);
}

void CLoveLizards::Release()
{
	CMouseMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->DeleteID(ObjID::PLAYER);
	CObjMgr::Get_Instance()->DeleteID(ObjID::NPC_REACT);
	CObjMgr::Get_Instance()->DeleteID(ObjID::NPC_NONREACT);
}

void CLoveLizards::Set_Note()
{
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 4756);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 4906);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 5060);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 5194);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 9459);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 9610);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 9761);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 9891);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 18874);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 19024);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 19175);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 19306);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 23570);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 23722);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 23870);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 24002);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 25922);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 26074);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 26226);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 26356);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 28271);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 28424);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 28574);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 28704);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 30628);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 30779);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 30929);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 31060);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 32977);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 33129);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 33282);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 33410);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 35329);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 35480);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 35632);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 35762);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 37689);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 37840);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 37993);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 38123);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 40040);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 40189);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 40344);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 40473);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 44155);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 44305);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 44457);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 44587);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 47094);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 47245);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 47397);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 47529);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 49449);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 49600);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 49750);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 49882);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 51809);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 51960);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 52110);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 52241);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 54155);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 54306);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 54457);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 54587);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 56508);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 56659);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 56809);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 56941);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 58861);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 59013);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 59165);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 59295);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 4756);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 4906);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 5060);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 5194);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 9459);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 9610);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 9761);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 9891);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 18874);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 19024);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 19175);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 19306);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 23570);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 23722);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 23870);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 24002);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 25922);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 26074);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 26226);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 26356);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 28271);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 28424);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 28574);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 28704);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 30628);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 30779);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 30929);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 31060);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 32977);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 33129);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 33282);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 33410);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 35329);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 35480);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 35632);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 35762);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 37689);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 37840);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 37993);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 38123);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 40040);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 40189);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 40344);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 40473);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 44155);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 44305);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 44457);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 44587);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 47094);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 47245);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 47397);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 47529);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 49449);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 49600);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 49750);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 49882);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 51809);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 51960);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 52110);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 52241);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 54155);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 54306);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 54457);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 54587);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 56508);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 56659);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 56809);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 56941);

	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 58861);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 59013);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHUP, 59165);
	m_vNote.emplace_back(MotionID::MOTION_SCRATCHDOWN, 59295);
}

