#include "stdafx.h"
#include "PlayerBird.h"
#include "ResourceMgr.h"
#include "MouseMgr.h"
#include "StateMachine.h"

CPlayerBird::CPlayerBird()
{
}


CPlayerBird::~CPlayerBird()
{
	Safe_Delete(m_pStateMachine);
	Release();
}

void CPlayerBird::Initialize()
{
	m_tInfo.fX = 333.f;
	m_tInfo.fY = 387.f;
	m_tInfo.fCX = 200.f;
	m_tInfo.fCY = 307.f;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/BlueBirds_Bird.bmp", L"PlayerBird");

	Set_ReadyNote();
	iter_Current = m_vReadyTime.begin();
	iter_Next = m_vReadyTime.begin();
	++iter_Next;

	m_pStateMachine = new StateMachine<CPlayerBird>(this);
	
	//상태패턴 적용
	m_pStateMachine->SetCurrentState(PlayerBird_IdleState::Instance());
	m_pStateMachine->GetCurrentState()->Enter(this);
}

int CPlayerBird::Update()
{
	milliseconds _time = duration_cast<milliseconds>(system_clock::now() - m_tStartTime);
	if (iter_Next != m_vReadyTime.end() && iter_Current != m_vReadyTime.end())
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

void CPlayerBird::LateUpdate()
{
	if (m_pStateMachine->GetCurrentState() == PlayerBird_IdleState::Instance())
		CObj::FrameMove();
	else
		CObj::FrameStop();
}

void CPlayerBird::Render(HDC _hdc)
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

void CPlayerBird::Release()
{
}

void CPlayerBird::Set_ReadyNote()
{
	m_vReadyTime.emplace_back(IDLE, 0);

	m_vReadyTime.emplace_back(SLIDE_READY, 4907);
	m_vReadyTime.emplace_back(SLIDE_READY2, 5247);

	m_vReadyTime.emplace_back(WAIT, 5609);
	m_vReadyTime.emplace_back(IDLE, 6888);

	m_vReadyTime.emplace_back(TOUCH_READY, 9772);

	m_vReadyTime.emplace_back(WAIT, 10272);
	m_vReadyTime.emplace_back(IDLE, 11738);

	m_vReadyTime.emplace_back(TOUCH_READY, 13461);

	m_vReadyTime.emplace_back(WAIT, 13961);
	m_vReadyTime.emplace_back(IDLE, 15427);

	m_vReadyTime.emplace_back(TOUCH_READY, 17157);

	m_vReadyTime.emplace_back(WAIT, 17657);
	m_vReadyTime.emplace_back(IDLE, 19122);

	m_vReadyTime.emplace_back(TOUCH_READY, 20842);

	m_vReadyTime.emplace_back(WAIT, 21342);
	m_vReadyTime.emplace_back(IDLE, 22816);

	m_vReadyTime.emplace_back(TOUCH_READY, 24546);

	m_vReadyTime.emplace_back(WAIT, 25046);
	m_vReadyTime.emplace_back(IDLE, 26107);

	m_vReadyTime.emplace_back(TOUCH_READY, 26376);

	m_vReadyTime.emplace_back(WAIT, 26876);
	m_vReadyTime.emplace_back(IDLE, 28357);

	m_vReadyTime.emplace_back(TOUCH_READY, 28680);

	m_vReadyTime.emplace_back(WAIT, 29180);
	m_vReadyTime.emplace_back(IDLE, 30683);

	m_vReadyTime.emplace_back(TOUCH_READY, 31920);

	m_vReadyTime.emplace_back(WAIT, 32420);
	m_vReadyTime.emplace_back(IDLE, 33666);

	m_vReadyTime.emplace_back(TOUCH_READY, 33766);

	m_vReadyTime.emplace_back(WAIT, 34266);
	m_vReadyTime.emplace_back(IDLE, 35748);

	m_vReadyTime.emplace_back(TOUCH_READY, 36072);

	m_vReadyTime.emplace_back(WAIT, 36572);
	m_vReadyTime.emplace_back(IDLE, 38061);

	m_vReadyTime.emplace_back(TOUCH_READY, 40214);

	m_vReadyTime.emplace_back(WAIT, 40714);
	m_vReadyTime.emplace_back(IDLE, 42113);

	m_vReadyTime.emplace_back(SLIDE_READY, 43681);
	m_vReadyTime.emplace_back(SLIDE_READY2, 44021);

	//m_vReadyTime.emplace_back(IDLE, 45021);

	m_vReadyTime.emplace_back(TOUCH_READY, 44848);

	m_vReadyTime.emplace_back(WAIT, 45348);
	m_vReadyTime.emplace_back(IDLE, 46825);

	m_vReadyTime.emplace_back(TOUCH_READY, 47621);

	m_vReadyTime.emplace_back(WAIT, 48121);
	m_vReadyTime.emplace_back(IDLE, 49587);

	m_vReadyTime.emplace_back(SLIDE_READY, 51082);
	m_vReadyTime.emplace_back(SLIDE_READY2, 51422);

	m_vReadyTime.emplace_back(WAIT2, 51922);

	//m_vReadyTime.emplace_back(SLIDE_READY, 52922);
	m_vReadyTime.emplace_back(SLIDE_READY2, 53262);

	m_vReadyTime.emplace_back(WAIT2, 53762);

	//m_vReadyTime.emplace_back(SLIDE_READY, 54771);
	m_vReadyTime.emplace_back(SLIDE_READY2, 55111);

	//m_vReadyTime.emplace_back(WAIT2, 56685);
	m_vReadyTime.emplace_back(WAIT2, 55611);

	m_vReadyTime.emplace_back(IDLE, 56685);
}
