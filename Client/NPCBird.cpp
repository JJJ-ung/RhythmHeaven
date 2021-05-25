#include "stdafx.h"
#include "NPCBird.h"
#include "ResourceMgr.h"
#include "MouseMgr.h"

CNPCBird::CNPCBird()
{
}


CNPCBird::~CNPCBird()
{
	Safe_Delete(m_pStateMachine);
	Release();
}

void CNPCBird::Initialize()
{
	m_tInfo.fCX = 200.f;
	m_tInfo.fCY = 307.f;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/BlueBirds_Bird.bmp", L"NPCBird");

	Set_Note();
	iter_Current = m_vNPCMotion.begin();
	iter_Next = m_vNPCMotion.begin();
	++iter_Next;

	m_pStateMachine = new StateMachine<CNPCBird>(this);
	m_pStateMachine->SetCurrentState(NPCBird_IdleState::Instance());
	m_pStateMachine->GetCurrentState()->Enter(this);
}

int CNPCBird::Update()
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

void CNPCBird::LateUpdate()
{
	if (m_pStateMachine->GetCurrentState() == NPCBird_IdleState::Instance())
		CObj::FrameMove();
	else
		CObj::FrameStop();
}

void CNPCBird::Render(HDC _hdc)
{
	CObj::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"PlayerBird");
	GdiTransparentBlt(_hdc,
		m_tRect.left, m_tRect.top,
		m_tInfo.fCX, m_tInfo.fCY,
		hMemDC,
		m_tFrame.iFrameStart * m_tInfo.fCX, m_tFrame.iFrameScene * m_tInfo.fCY,// 출력할 그림의 시작 좌표. 
		m_tInfo.fCX, m_tInfo.fCY,//그림의 전체 가로세로 크기 
		RGB(246, 255, 230));
}

void CNPCBird::Release()
{
}

void CNPCBird::Set_Note()
{
	m_vNPCMotion.emplace_back(IDLE, 0);

	m_vNPCMotion.emplace_back(SLIDE_READY, 4227 + (m_iNPCNum*340));
	m_vNPCMotion.emplace_back(SLIDE_READY2, 5247);

	m_vNPCMotion.emplace_back(PECK, 5609);
	m_vNPCMotion.emplace_back(STRETCH, 6088);

	m_vNPCMotion.emplace_back(IDLE, 6888);

	m_vNPCMotion.emplace_back(TOUCH_READY, 9772);

	m_vNPCMotion.emplace_back(PECK, 10676);
	m_vNPCMotion.emplace_back(PECK_UP, 10767);
	m_vNPCMotion.emplace_back(PECK, 10906);
	m_vNPCMotion.emplace_back(PECK_UP, 11006);
	m_vNPCMotion.emplace_back(PECK, 11138);
	m_vNPCMotion.emplace_back(PECK_UP, 11238);

	m_vNPCMotion.emplace_back(IDLE, 11738);

	m_vNPCMotion.emplace_back(TOUCH_READY, 13461);

	m_vNPCMotion.emplace_back(PECK, 14370);
	m_vNPCMotion.emplace_back(PECK_UP, 14470);
	m_vNPCMotion.emplace_back(PECK, 14602);
	m_vNPCMotion.emplace_back(PECK_UP, 14702);
	m_vNPCMotion.emplace_back(PECK, 14827);
	m_vNPCMotion.emplace_back(PECK_UP, 14927);

	m_vNPCMotion.emplace_back(IDLE, 15427);

	m_vNPCMotion.emplace_back(TOUCH_READY, 17157);

	m_vNPCMotion.emplace_back(PECK, 18061);
	m_vNPCMotion.emplace_back(PECK_UP, 18161);
	m_vNPCMotion.emplace_back(PECK, 18293);
	m_vNPCMotion.emplace_back(PECK_UP, 18393);
	m_vNPCMotion.emplace_back(PECK, 18522);
	m_vNPCMotion.emplace_back(PECK_UP, 18622);

	m_vNPCMotion.emplace_back(IDLE, 19122);

	m_vNPCMotion.emplace_back(TOUCH_READY, 20842);

	m_vNPCMotion.emplace_back(PECK, 21752);
	m_vNPCMotion.emplace_back(PECK_UP, 21852);
	m_vNPCMotion.emplace_back(PECK, 21982);
	m_vNPCMotion.emplace_back(PECK_UP, 22082);
	m_vNPCMotion.emplace_back(PECK, 22216);
	m_vNPCMotion.emplace_back(PECK_UP, 22316);

	m_vNPCMotion.emplace_back(IDLE, 22816);

	m_vNPCMotion.emplace_back(TOUCH_READY, 24546);

	m_vNPCMotion.emplace_back(PECK, 25449);
	m_vNPCMotion.emplace_back(PECK_UP, 25549);
	m_vNPCMotion.emplace_back(PECK, 25676);
	m_vNPCMotion.emplace_back(PECK_UP, 25776);
	m_vNPCMotion.emplace_back(PECK, 25907);
	m_vNPCMotion.emplace_back(PECK_UP, 26007);

	m_vNPCMotion.emplace_back(IDLE, 26107);

	m_vNPCMotion.emplace_back(TOUCH_READY, 26376);

	m_vNPCMotion.emplace_back(PECK, 27296);
	m_vNPCMotion.emplace_back(PECK_UP, 27396);
	m_vNPCMotion.emplace_back(PECK, 27520);
	m_vNPCMotion.emplace_back(PECK_UP, 27620);
	m_vNPCMotion.emplace_back(PECK, 27757);
	m_vNPCMotion.emplace_back(PECK_UP, 27857);

	m_vNPCMotion.emplace_back(IDLE, 28357);

	m_vNPCMotion.emplace_back(TOUCH_READY, 28680);

	m_vNPCMotion.emplace_back(PECK, 29606);
	m_vNPCMotion.emplace_back(PECK_UP, 29706);
	m_vNPCMotion.emplace_back(PECK, 29835);
	m_vNPCMotion.emplace_back(PECK_UP, 29935);
	m_vNPCMotion.emplace_back(PECK, 30083);
	m_vNPCMotion.emplace_back(PECK_UP, 30183);

	m_vNPCMotion.emplace_back(IDLE, 30683);

	m_vNPCMotion.emplace_back(TOUCH_READY, 31920);

	m_vNPCMotion.emplace_back(PECK, 32832);
	m_vNPCMotion.emplace_back(PECK_UP, 32932);
	m_vNPCMotion.emplace_back(PECK, 33063);
	m_vNPCMotion.emplace_back(PECK_UP, 33163);
	m_vNPCMotion.emplace_back(PECK, 33295);
	m_vNPCMotion.emplace_back(PECK_UP, 33395);

	m_vNPCMotion.emplace_back(IDLE, 33666);

	m_vNPCMotion.emplace_back(TOUCH_READY, 33766);

	m_vNPCMotion.emplace_back(PECK, 34680);
	m_vNPCMotion.emplace_back(PECK_UP, 34780);
	m_vNPCMotion.emplace_back(PECK, 34912);
	m_vNPCMotion.emplace_back(PECK_UP, 35012);
	m_vNPCMotion.emplace_back(PECK, 35148);
	m_vNPCMotion.emplace_back(PECK_UP, 35248);

	m_vNPCMotion.emplace_back(IDLE, 35748);

	m_vNPCMotion.emplace_back(TOUCH_READY, 36072);

	m_vNPCMotion.emplace_back(PECK, 36987);
	m_vNPCMotion.emplace_back(PECK_UP, 37087);
	m_vNPCMotion.emplace_back(PECK, 37224);
	m_vNPCMotion.emplace_back(PECK_UP, 37324);
	m_vNPCMotion.emplace_back(PECK, 37461);
	m_vNPCMotion.emplace_back(PECK_UP, 37561);

	m_vNPCMotion.emplace_back(IDLE, 38061);

	m_vNPCMotion.emplace_back(TOUCH_READY, 40214);

	m_vNPCMotion.emplace_back(PECK, 41141);
	m_vNPCMotion.emplace_back(PECK_UP, 41241);
	m_vNPCMotion.emplace_back(PECK, 41354);
	m_vNPCMotion.emplace_back(PECK_UP, 41454);
	m_vNPCMotion.emplace_back(PECK, 41513);
	m_vNPCMotion.emplace_back(PECK_UP, 41613);

	m_vNPCMotion.emplace_back(IDLE, 42113);

	m_vNPCMotion.emplace_back(SLIDE_READY, 43001 + (m_iNPCNum * 340));
	m_vNPCMotion.emplace_back(SLIDE_READY2, 44021);

	m_vNPCMotion.emplace_back(PECK, 44377);
	m_vNPCMotion.emplace_back(STRETCH, 44870);

	//m_vNPCMotion.emplace_back(IDLE, 45021);

	//m_vNPCMotion.emplace_back(TOUCH_READY, 44848);

	m_vNPCMotion.emplace_back(PECK, 45773);
	m_vNPCMotion.emplace_back(PECK_UP, 45873);
	m_vNPCMotion.emplace_back(PECK, 46013);
	m_vNPCMotion.emplace_back(PECK_UP, 46113);
	m_vNPCMotion.emplace_back(PECK, 46225);
	m_vNPCMotion.emplace_back(PECK_UP, 46325);

	m_vNPCMotion.emplace_back(IDLE, 46825);

	m_vNPCMotion.emplace_back(TOUCH_READY, 47621);

	m_vNPCMotion.emplace_back(PECK, 48532);
	m_vNPCMotion.emplace_back(PECK_UP, 48632);
	m_vNPCMotion.emplace_back(PECK, 48780);
	m_vNPCMotion.emplace_back(PECK_UP, 48880);
	m_vNPCMotion.emplace_back(PECK, 48987);
	m_vNPCMotion.emplace_back(PECK_UP, 49087);

	m_vNPCMotion.emplace_back(IDLE, 49587);

	m_vNPCMotion.emplace_back(SLIDE_READY, 50402 + (m_iNPCNum * 340));
	m_vNPCMotion.emplace_back(SLIDE_READY2, 51422);

	m_vNPCMotion.emplace_back(PECK, 51765);
	m_vNPCMotion.emplace_back(STRETCH, 52191);

	//m_vNPCMotion.emplace_back(SLIDE_READY, 52242 + (m_iNPCNum * 340));
	m_vNPCMotion.emplace_back(SLIDE_READY2, 53262);

	m_vNPCMotion.emplace_back(PECK, 53609);
	m_vNPCMotion.emplace_back(STRETCH, 54059);

	//m_vNPCMotion.emplace_back(SLIDE_READY, 54091 + (m_iNPCNum * 340));
	m_vNPCMotion.emplace_back(SLIDE_READY2, 55111);

	m_vNPCMotion.emplace_back(PECK, 55453);
	m_vNPCMotion.emplace_back(STRETCH, 55885);

	m_vNPCMotion.emplace_back(IDLE, 56685);
}
