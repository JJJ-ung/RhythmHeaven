#include "stdafx.h"
#include "LizardNPC.h"
#include "ResourceMgr.h"

CLizardNPC::CLizardNPC()
{
	m_pFrameKey = L"";
}


CLizardNPC::~CLizardNPC()
{
	Safe_Delete(m_pStateMachine);
	Release();
}

void CLizardNPC::Initialize()
{
	m_tInfo.fX = 333.f;
	m_tInfo.fY = 151.f;
	m_tInfo.fCX = 182.f;
	m_tInfo.fCY = 176.f;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/NPC_idle.bmp",		L"NPCLizard_Idle");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/NPC_Movement.bmp",	L"NPCLizard_Movement");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/NPC_Movement_1.bmp", L"NPCLizard_Movement_1");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/NPC_React.bmp",		L"NPCLizard_React");

	Set_Note();
	iter_Current = m_vNPCMotion.begin();
	iter_Next = m_vNPCMotion.begin();
	++iter_Next;

	m_pStateMachine = new StateMachine<CLizardNPC>(this);
	//상태패턴 추가
	m_pStateMachine->SetCurrentState(NPCLizard_IdleState::Instance());
	m_pStateMachine->GetCurrentState()->Enter(this);

	m_bReaction = true;
}

int CLizardNPC::Update()
{
	milliseconds _time = duration_cast<milliseconds>(system_clock::now() - m_tStartTime);
	if (iter_Next != m_vNPCMotion.end() && iter_Current != m_vNPCMotion.end())
	{
		if ((_time > (milliseconds)((*iter_Next).second - 20)) && (_time < (milliseconds)((*iter_Next).second + 20)))
		{
			++iter_Next;
			++iter_Current;
		}
	}

	m_pStateMachine->Update();

	return OBJ_NOEVENT;
}

void CLizardNPC::LateUpdate()
{
	if (m_pStateMachine->GetCurrentState() == NPCLizard_IdleState::Instance())
	{
		if (duration_cast<milliseconds>(system_clock::now() - m_tFrame.tFrameTime).count() > m_tFrame.tFrameSpeed)
		{
			++m_tFrame.iFrameStart;
			m_tFrame.tFrameTime = system_clock::now();
		}
		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		{
			if (m_tFrame.iFrameScene == 0)
				m_tFrame.iFrameScene = 1;
			else if (m_tFrame.iFrameScene == 1)
				m_tFrame.iFrameScene = 0;
			m_tFrame.iFrameStart = 0;
		}
	}
	else
		CObj::FrameStop();
}

void CLizardNPC::Render(HDC _hdc)
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

void CLizardNPC::Release()
{
}

void CLizardNPC::Set_Note()
{
	m_vNPCMotion.emplace_back(IDLE, 0);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 3812);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 4012);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 4163);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 4460);

	m_vNPCMotion.emplace_back(TAIL_1, 4756);
	m_vNPCMotion.emplace_back(TAIL_2, 4906);
	m_vNPCMotion.emplace_back(TAIL_1, 5060);
	m_vNPCMotion.emplace_back(TAIL_2, 5194);

	m_vNPCMotion.emplace_back(REACTION, 5632);
	//
	m_vNPCMotion.emplace_back(IDLE, 6432);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 8528);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 8728);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 8878);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 9175);

	m_vNPCMotion.emplace_back(TAIL_1, 9459);
	m_vNPCMotion.emplace_back(TAIL_2, 9610);
	m_vNPCMotion.emplace_back(TAIL_1, 9761);
	m_vNPCMotion.emplace_back(TAIL_2, 9891);

	m_vNPCMotion.emplace_back(REACTION, 10339);
	//
	m_vNPCMotion.emplace_back(IDLE, 10939);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 17941);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 18141);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 18292);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 18589);

	m_vNPCMotion.emplace_back(TAIL_1, 18874);
	m_vNPCMotion.emplace_back(TAIL_2, 19024);
	m_vNPCMotion.emplace_back(TAIL_1, 19175);
	m_vNPCMotion.emplace_back(TAIL_2, 19306);

	m_vNPCMotion.emplace_back(REACTION, 19754);
	//
	m_vNPCMotion.emplace_back(IDLE, 20554);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 22641);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 22841);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 22992);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 23289);

	m_vNPCMotion.emplace_back(TAIL_1, 23570);
	m_vNPCMotion.emplace_back(TAIL_2, 23722);
	m_vNPCMotion.emplace_back(TAIL_1, 23870);
	m_vNPCMotion.emplace_back(TAIL_2, 24002);

	m_vNPCMotion.emplace_back(REACTION, 24457);
	//
	//m_vNPCMotion.emplace_back(IDLE, 24957);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 24987);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 25187);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 25338);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 25635);

	m_vNPCMotion.emplace_back(TAIL_1, 25922);
	m_vNPCMotion.emplace_back(TAIL_2, 26074);
	m_vNPCMotion.emplace_back(TAIL_1, 26226);
	m_vNPCMotion.emplace_back(TAIL_2, 26356);

	m_vNPCMotion.emplace_back(REACTION, 26809);
	//
	//m_vNPCMotion.emplace_back(IDLE, 27309);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 27339);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 27539);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 27690);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 27987);

	m_vNPCMotion.emplace_back(TAIL_1, 28271);
	m_vNPCMotion.emplace_back(TAIL_2, 28424);
	m_vNPCMotion.emplace_back(TAIL_1, 28574);
	m_vNPCMotion.emplace_back(TAIL_2, 28704);

	m_vNPCMotion.emplace_back(REACTION, 29163);
	//
	//m_vNPCMotion.emplace_back(IDLE, 29663);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 29693);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 29893);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 30044);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 30342);

	m_vNPCMotion.emplace_back(TAIL_1, 30628);
	m_vNPCMotion.emplace_back(TAIL_2, 30779);
	m_vNPCMotion.emplace_back(TAIL_1, 30929);
	m_vNPCMotion.emplace_back(TAIL_2, 31060);

	m_vNPCMotion.emplace_back(REACTION, 31517);
	//
	//m_vNPCMotion.emplace_back(IDLE, 32017);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 32048);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 32248);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 32399);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 32697);

	m_vNPCMotion.emplace_back(TAIL_1, 32977);
	m_vNPCMotion.emplace_back(TAIL_2, 33129);
	m_vNPCMotion.emplace_back(TAIL_1, 33282);
	m_vNPCMotion.emplace_back(TAIL_2, 33410);

	m_vNPCMotion.emplace_back(REACTION, 33869);
	//
	//m_vNPCMotion.emplace_back(IDLE, 34369);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 34398);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 34598);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 34749);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 35046);

	m_vNPCMotion.emplace_back(TAIL_1, 35329);
	m_vNPCMotion.emplace_back(TAIL_2, 35480);
	m_vNPCMotion.emplace_back(TAIL_1, 35632);
	m_vNPCMotion.emplace_back(TAIL_2, 35762);

	m_vNPCMotion.emplace_back(REACTION, 36225);
	//
	//m_vNPCMotion.emplace_back(IDLE, 36725);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 36758);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 36958);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 37110);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 37407);

	m_vNPCMotion.emplace_back(TAIL_1, 37689);
	m_vNPCMotion.emplace_back(TAIL_2, 37840);
	m_vNPCMotion.emplace_back(TAIL_1, 37993);
	m_vNPCMotion.emplace_back(TAIL_2, 38123);

	m_vNPCMotion.emplace_back(REACTION, 38575);
	//
	//m_vNPCMotion.emplace_back(IDLE, 39075);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 39105);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 39305);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 39456);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 39753);

	m_vNPCMotion.emplace_back(TAIL_1, 40040);
	m_vNPCMotion.emplace_back(TAIL_2, 40189);
	m_vNPCMotion.emplace_back(TAIL_1, 40344);
	m_vNPCMotion.emplace_back(TAIL_2, 40473);

	m_vNPCMotion.emplace_back(REACTION, 40933);
	//
	m_vNPCMotion.emplace_back(IDLE, 41733);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 43223);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 43423);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 43574);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 43871);

	m_vNPCMotion.emplace_back(TAIL_1, 44155);
	m_vNPCMotion.emplace_back(TAIL_2, 44305);
	m_vNPCMotion.emplace_back(TAIL_1, 44457);
	m_vNPCMotion.emplace_back(TAIL_2, 44587);

	m_vNPCMotion.emplace_back(REACTION, 45050);
	//
	m_vNPCMotion.emplace_back(IDLE, 45850);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 46161);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 46361);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 46513);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 46810);

	m_vNPCMotion.emplace_back(TAIL_1, 47094);
	m_vNPCMotion.emplace_back(TAIL_2, 47245);
	m_vNPCMotion.emplace_back(TAIL_1, 47397);
	m_vNPCMotion.emplace_back(TAIL_2, 47529);

	m_vNPCMotion.emplace_back(REACTION, 47988);
	//
	//m_vNPCMotion.emplace_back(IDLE, 48488);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 48518);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 48718);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 48869);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 49166);

	m_vNPCMotion.emplace_back(TAIL_1, 49449);
	m_vNPCMotion.emplace_back(TAIL_2, 49600);
	m_vNPCMotion.emplace_back(TAIL_1, 49750);
	m_vNPCMotion.emplace_back(TAIL_2, 49882);

	m_vNPCMotion.emplace_back(REACTION, 50347);
	//
	//m_vNPCMotion.emplace_back(IDLE, 50847);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 50878);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 51078);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 51229);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 51526);

	m_vNPCMotion.emplace_back(TAIL_1, 51809);
	m_vNPCMotion.emplace_back(TAIL_2, 51960);
	m_vNPCMotion.emplace_back(TAIL_1, 52110);
	m_vNPCMotion.emplace_back(TAIL_2, 52241);

	m_vNPCMotion.emplace_back(REACTION, 52692);
	//
	//m_vNPCMotion.emplace_back(IDLE, 53192);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 53221);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 53421);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 53573);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 53869);

	m_vNPCMotion.emplace_back(TAIL_1, 54155);
	m_vNPCMotion.emplace_back(TAIL_2, 54306);
	m_vNPCMotion.emplace_back(TAIL_1, 54457);
	m_vNPCMotion.emplace_back(TAIL_2, 54587);

	m_vNPCMotion.emplace_back(REACTION, 55044);
	//
	//m_vNPCMotion.emplace_back(IDLE, 55544);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 55577);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 55777);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 55928);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 56225);

	m_vNPCMotion.emplace_back(TAIL_1, 56508);
	m_vNPCMotion.emplace_back(TAIL_2, 56659);
	m_vNPCMotion.emplace_back(TAIL_1, 56809);
	m_vNPCMotion.emplace_back(TAIL_2, 56941);

	m_vNPCMotion.emplace_back(REACTION, 57400);
	//
	//m_vNPCMotion.emplace_back(IDLE, 57885);
	//
	m_vNPCMotion.emplace_back(MOVEMENT_READY, 57930);

	m_vNPCMotion.emplace_back(MOVEMENT_1, 58130);
	m_vNPCMotion.emplace_back(MOVEMENT_2, 58282);
	m_vNPCMotion.emplace_back(MOVEMENT_1, 58579);

	m_vNPCMotion.emplace_back(TAIL_1, 58861);
	m_vNPCMotion.emplace_back(TAIL_2, 59013);
	m_vNPCMotion.emplace_back(TAIL_1, 59165);
	m_vNPCMotion.emplace_back(TAIL_2, 59295);

	m_vNPCMotion.emplace_back(REACTION, 59752);
	//
	m_vNPCMotion.emplace_back(IDLE, 61252);
}
