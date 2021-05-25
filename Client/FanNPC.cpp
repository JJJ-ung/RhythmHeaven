#include "stdafx.h"
#include "FanNPC.h"
#include "ObjMgr.h"
#include "ResourceMgr.h"

CFanNPC::CFanNPC()
{
}


CFanNPC::~CFanNPC()
{
	Safe_Delete(m_pStateMachine);
	Release();
}

void CFanNPC::Initialize()
{
	Set_Note();

	m_tInfo.fCX = 197.f;
	m_tInfo.fCY = 226.f;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/NPC_Idle.bmp", L"NPC_Fan_Idle");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Fan_watch.bmp", L"NPC_Fan_Watch");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Player_Clap.bmp", L"NPC_Fan_Clap");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Player_Jump.bmp", L"NPC_Fan_Jump");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/NPC_Watch_Clap.bmp", L"NPC_Fan_Watch_Clap");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/NPC_Watch_Jump.bmp", L"NPC_Fan_Watch_Jump");

	iter_CurNote = m_vNPCNote.begin();
	iter_NextNote = m_vNPCNote.begin();
	++iter_NextNote;

	m_pStateMachine = new StateMachine<CFanNPC>(this);
	m_pStateMachine->SetCurrentState(NPCFan_IdleState::Instance());
	m_pStateMachine->GetCurrentState()->Enter(this);
}

int CFanNPC::Update()
{
	milliseconds _time = duration_cast<milliseconds>(system_clock::now() - m_tStartTime);
	if (iter_NextNote != m_vNPCNote.end() && iter_CurNote != m_vNPCNote.end())
	{
		if ((_time > (milliseconds)((*iter_NextNote).second - 20)) && (_time < (milliseconds)((*iter_NextNote).second + 20)))
		{
			++iter_NextNote;
			++iter_CurNote;
		}
	}

	m_pStateMachine->Update();

	return OBJ_NOEVENT;
}

void CFanNPC::LateUpdate()
{
	if ((*iter_CurNote).first == IDLE)
		CObj::FrameMove();
	else
		CObj::FrameStop();
}

void CFanNPC::Render(HDC _hdc)
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

void CFanNPC::Release()
{
}


void CFanNPC::Set_Note()
{
	m_vNPCNote.emplace_back(IDLE, 0);

	//
	m_vNPCNote.emplace_back(CLAP, 5909);
	m_vNPCNote.emplace_back(CLAP_UP, 6109);

	m_vNPCNote.emplace_back(CLAP, 6333);
	m_vNPCNote.emplace_back(CLAP_UP, 6533);

	m_vNPCNote.emplace_back(CLAP, 6769);
	m_vNPCNote.emplace_back(CLAP_UP, 6969);

	m_vNPCNote.emplace_back(CLAP, 7201);
	//m_vNPCNote.emplace_back(CLAP_UP, 7401);
	//
	//
	m_vNPCNote.emplace_back(IDLE, 7624);
	//
	//
	m_vNPCNote.emplace_back(CLAP, 19477);
	m_vNPCNote.emplace_back(CLAP_UP, 19677);

	m_vNPCNote.emplace_back(CLAP, 20086);
	m_vNPCNote.emplace_back(CLAP_UP, 20286);

	m_vNPCNote.emplace_back(CLAP, 20286);
	m_vNPCNote.emplace_back(CLAP_UP, 20486);

	m_vNPCNote.emplace_back(JUMP, 20696);
	//
	//
	m_vNPCNote.emplace_back(IDLE, 21137);
	//
	//
	m_vNPCNote.emplace_back(CLAP, 26240);
	m_vNPCNote.emplace_back(CLAP_UP, 26440);

	m_vNPCNote.emplace_back(CLAP, 26643);
	m_vNPCNote.emplace_back(CLAP_UP, 26843);

	m_vNPCNote.emplace_back(CLAP, 27056);
	m_vNPCNote.emplace_back(CLAP_UP, 27256);

	m_vNPCNote.emplace_back(CLAP, 27481);
	//m_vNPCNote.emplace_back(CLAP_UP, 27681);
	//
	//
	m_vNPCNote.emplace_back(IDLE, 27901);
	//
	//
	m_vNPCNote.emplace_back(CLAP, 33013);
	m_vNPCNote.emplace_back(CLAP_UP, 33213);

	m_vNPCNote.emplace_back(CLAP, 33623);
	m_vNPCNote.emplace_back(CLAP_UP, 33823);

	m_vNPCNote.emplace_back(CLAP, 33818);
	m_vNPCNote.emplace_back(CLAP_UP, 34018);

	m_vNPCNote.emplace_back(JUMP, 34231);
	//
	//
	m_vNPCNote.emplace_back(IDLE, 34791);
	//
	//
	m_vNPCNote.emplace_back(CLAP, 39728);
	m_vNPCNote.emplace_back(CLAP_UP, 39928);

	m_vNPCNote.emplace_back(CLAP, 40133);
	m_vNPCNote.emplace_back(CLAP_UP, 40333);

	m_vNPCNote.emplace_back(CLAP, 40588);
	m_vNPCNote.emplace_back(CLAP_UP, 40788);

	m_vNPCNote.emplace_back(CLAP, 41005);
	//m_vNPCNote.emplace_back(CLAP_UP, 41205);
	//
	//
	m_vNPCNote.emplace_back(IDLE, 41419);
	//
	m_vNPCNote.emplace_back(CLAP, 43155);
	m_vNPCNote.emplace_back(CLAP_UP, 43255);

	m_vNPCNote.emplace_back(CLAP, 43760);
	m_vNPCNote.emplace_back(CLAP_UP, 43960);

	m_vNPCNote.emplace_back(CLAP, 43960);
	m_vNPCNote.emplace_back(CLAP_UP, 44160);

	m_vNPCNote.emplace_back(JUMP, 44347);
	//
	//
	m_vNPCNote.emplace_back(IDLE, 44801);
	//
	//
	m_vNPCNote.emplace_back(CLAP, 46503);
	m_vNPCNote.emplace_back(CLAP_UP, 46703);

	m_vNPCNote.emplace_back(CLAP, 46907);
	m_vNPCNote.emplace_back(CLAP_UP, 47107);

	m_vNPCNote.emplace_back(CLAP, 47344);
	m_vNPCNote.emplace_back(CLAP_UP, 47544);

	m_vNPCNote.emplace_back(CLAP, 47773);
	//m_vNPCNote.emplace_back(CLAP_UP, 47973);
	//
	//
	m_vNPCNote.emplace_back(IDLE, 48172);
	//
	//
	m_vNPCNote.emplace_back(CLAP, 51574);
	m_vNPCNote.emplace_back(CLAP_UP, 51774);

	m_vNPCNote.emplace_back(CLAP, 52216);
	m_vNPCNote.emplace_back(CLAP_UP, 52416);

	m_vNPCNote.emplace_back(CLAP, 52408);
	m_vNPCNote.emplace_back(CLAP_UP, 52608);

	m_vNPCNote.emplace_back(JUMP, 52807);
	//
	//
	m_vNPCNote.emplace_back(IDLE, 53258);
	//
	//
	m_vNPCNote.emplace_back(CLAP, 54946);
	m_vNPCNote.emplace_back(CLAP_UP, 55146);

	m_vNPCNote.emplace_back(CLAP, 55359);
	m_vNPCNote.emplace_back(CLAP_UP, 55559);

	m_vNPCNote.emplace_back(CLAP, 55780);
	m_vNPCNote.emplace_back(CLAP_UP, 55980);

	m_vNPCNote.emplace_back(CLAP, 56212);
	//m_vNPCNote.emplace_back(CLAP_UP, 56412);
	//
	//
	m_vNPCNote.emplace_back(IDLE, 56645);

}
