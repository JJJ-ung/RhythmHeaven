#include "stdafx.h"
#include "Idol.h"
#include "ResourceMgr.h"

CIdol::CIdol()
{
}


CIdol::~CIdol()
{
}

void CIdol::Initialize()
{
	Set_Note();
	iter_NPCNote = m_vNPCNote.begin();
	m_tInfo.fCX = 163.f;
	m_tInfo.fCY = 227.f;
	m_tInfo.fX = 209.f;
	m_tInfo.fY = 280.f;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Idol_Idle_Basic.bmp", L"Idol_Idle_Basic");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Idol_Idle_1.bmp", L"Idol_Idle_1");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Idol_Idle_2.bmp", L"Idol_Idle_2");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Idol_Pose_1.bmp", L"Idol_Pose");

	m_pFrameKey = L"Idol_Idle_Basic";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 2;
	m_tFrame.iFrameScene = 0;
	m_tFrame.tFrameTime = system_clock::now();
	m_tFrame.tFrameSpeed = 150;

	m_tStartTime = system_clock::now();
}

int CIdol::Update()
{
	m_tCurrentTime = duration_cast<milliseconds>(system_clock::now() - m_tStartTime);
	if (iter_NPCNote != m_vNPCNote.end())
	{
		if ((m_tCurrentTime.count() > (*iter_NPCNote).second - 50) && (m_tCurrentTime.count() < (*iter_NPCNote).second + 50))
		{
			if ((*iter_NPCNote).first == IDLE_BASIC)
			{
				m_pFrameKey = L"Idol_Idle_Basic";
			}
			else if ((*iter_NPCNote).first == IDLE_FIRST)
			{
				m_pFrameKey = L"Idol_Idle_1";
			}
			else if ((*iter_NPCNote).first == IDLE_SECOND)
			{
				m_pFrameKey = L"Idol_Idle_2";
			}
			else if ((*iter_NPCNote).first == POSE)
			{
				m_pFrameKey = L"Idol_Pose";
			}
			++iter_NPCNote;
		}
	}

	return OBJ_NOEVENT;
}

void CIdol::LateUpdate()
{
	CObj::FrameMove();
}

void CIdol::Render(HDC _hdc)
{
	CObj::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(m_pFrameKey);
	GdiTransparentBlt(_hdc,
		m_tRect.left, m_tRect.top,
		m_tInfo.fCX, m_tInfo.fCY,
		hMemDC,
		m_tFrame.iFrameStart * m_tInfo.fCX, m_tFrame.iFrameScene * m_tInfo.fCY,// 출력할 그림의 시작 좌표. 
		m_tInfo.fCX, m_tInfo.fCY,//그림의 전체 가로세로 크기 
		RGB(255, 0, 255));
}

void CIdol::Release()
{
}

void CIdol::Set_Note()
{
	m_vNPCNote.emplace_back(POSE, 4238);
	m_vNPCNote.emplace_back(IDLE_BASIC, 5909);
	m_vNPCNote.emplace_back(IDLE_FIRST, 8050);
	m_vNPCNote.emplace_back(IDLE_SECOND,11423);
	m_vNPCNote.emplace_back(IDLE_FIRST, 14816);
	m_vNPCNote.emplace_back(POSE, 17349);
	m_vNPCNote.emplace_back(IDLE_BASIC,19477);
	m_vNPCNote.emplace_back(IDLE_SECOND, 21146);
	m_vNPCNote.emplace_back(POSE, 24500);
	m_vNPCNote.emplace_back(IDLE_BASIC,26863);
	m_vNPCNote.emplace_back(IDLE_FIRST, 27910);
	m_vNPCNote.emplace_back(POSE, 31007);
	m_vNPCNote.emplace_back(IDLE_BASIC,33200);
	m_vNPCNote.emplace_back(IDLE_SECOND, 35095);
	m_vNPCNote.emplace_back(POSE, 38036);
	m_vNPCNote.emplace_back(IDLE_BASIC, 39728);
	m_vNPCNote.emplace_back(POSE, 42066);
	m_vNPCNote.emplace_back(IDLE_BASIC, 43722);
	m_vNPCNote.emplace_back(POSE, 44686);
	m_vNPCNote.emplace_back(IDLE_FIRST, 48161);
	m_vNPCNote.emplace_back(POSE, 50694);
	m_vNPCNote.emplace_back(IDLE_BASIC, 51574);
	m_vNPCNote.emplace_back(POSE, 53258);
	m_vNPCNote.emplace_back(IDLE_BASIC,54725);
}
