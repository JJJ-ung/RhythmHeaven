#include "stdafx.h"
#include "PlayerLizardBody.h"
#include "ResourceMgr.h"
#include "StateMachine.h"
#include "PlayerLizardBodyState.h"

CPlayerLizardBody::CPlayerLizardBody()
{
	m_pFrameKey = L"";
}


CPlayerLizardBody::~CPlayerLizardBody()
{
	Safe_Delete(m_pStateMachine);
	Release();
}

void CPlayerLizardBody::Initialize()
{
	m_tInfo.fX = 115.f;
	m_tInfo.fY = 424.f;
	m_tInfo.fCX = 278.f;
	m_tInfo.fCY = 300.f;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/Player_Idle.bmp", L"Lizard_Idle");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/Player_movement.bmp", L"Lizard_movement");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/Player_movement_keydown.bmp", L"Lizard_KeyDown");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/LoveLizards/Player_React.bmp", L"Lizard_React");

	Set_ReadyNote();
	iter_Current = m_vReadyTime.begin();
	iter_Next = m_vReadyTime.begin();
	++iter_Next;

	m_pStateMachine = new StateMachine<CPlayerLizardBody>(this);
	//상태패턴 추가
	m_pStateMachine->SetCurrentState(Lizard_IdleState::Instance());
	m_pStateMachine->GetCurrentState()->Enter(this);
}

int CPlayerLizardBody::Update()
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

	//CPlayerLizard::Mouse();
	m_pStateMachine->Update();

	return OBJ_NOEVENT;
}

void CPlayerLizardBody::LateUpdate()
{
	if (m_pStateMachine->GetCurrentState() == Lizard_IdleState::Instance())
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

void CPlayerLizardBody::Render(HDC _hdc)
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

void CPlayerLizardBody::Release()
{
}

void CPlayerLizardBody::Set_ReadyNote()
{
	m_vReadyTime.emplace_back(IDLE, 0);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 3812);

	m_vReadyTime.emplace_back(MOVEMENT_1, 4012);
	m_vReadyTime.emplace_back(MOVEMENT_2, 4163);
	m_vReadyTime.emplace_back(MOVEMENT_1, 4460);

	//m_vReadyTime.emplace_back(WAIT, 4756);

	m_vReadyTime.emplace_back(IDLE, 6432);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 8528);

	m_vReadyTime.emplace_back(MOVEMENT_1, 8728);
	m_vReadyTime.emplace_back(MOVEMENT_2, 8878);
	m_vReadyTime.emplace_back(MOVEMENT_1, 9175);

	//m_vReadyTime.emplace_back(WAIT, 9459);

	m_vReadyTime.emplace_back(IDLE, 10939);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 17941);

	m_vReadyTime.emplace_back(MOVEMENT_1, 18141);
	m_vReadyTime.emplace_back(MOVEMENT_2, 18292);
	m_vReadyTime.emplace_back(MOVEMENT_1, 18589);

	//m_vReadyTime.emplace_back(WAIT, 18874);

	m_vReadyTime.emplace_back(IDLE, 20554);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 22641);

	m_vReadyTime.emplace_back(MOVEMENT_1, 22841);
	m_vReadyTime.emplace_back(MOVEMENT_2, 22992);
	m_vReadyTime.emplace_back(MOVEMENT_1, 23289);

	//m_vReadyTime.emplace_back(WAIT, 23570);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 24987);

	m_vReadyTime.emplace_back(MOVEMENT_1, 25187);
	m_vReadyTime.emplace_back(MOVEMENT_2, 25338);
	m_vReadyTime.emplace_back(MOVEMENT_1, 25635);

	//m_vReadyTime.emplace_back(WAIT, 25922);
	
	m_vReadyTime.emplace_back(MOVEMENT_READY, 27339);

	m_vReadyTime.emplace_back(MOVEMENT_1, 27539);
	m_vReadyTime.emplace_back(MOVEMENT_2, 27690);
	m_vReadyTime.emplace_back(MOVEMENT_1, 27987);

	//m_vReadyTime.emplace_back(WAIT, 28271);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 29693);

	m_vReadyTime.emplace_back(MOVEMENT_1, 29893);
	m_vReadyTime.emplace_back(MOVEMENT_2, 30044);
	m_vReadyTime.emplace_back(MOVEMENT_1, 30342);

	//m_vReadyTime.emplace_back(WAIT, 30628);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 32048);

	m_vReadyTime.emplace_back(MOVEMENT_1, 32248);
	m_vReadyTime.emplace_back(MOVEMENT_2, 32399);
	m_vReadyTime.emplace_back(MOVEMENT_1, 32697);

	//m_vReadyTime.emplace_back(WAIT, 32977);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 34398);

	m_vReadyTime.emplace_back(MOVEMENT_1, 34598);
	m_vReadyTime.emplace_back(MOVEMENT_2, 34749);
	m_vReadyTime.emplace_back(MOVEMENT_1, 35046);

	//m_vReadyTime.emplace_back(WAIT, 35329);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 36758);

	m_vReadyTime.emplace_back(MOVEMENT_1, 36958);
	m_vReadyTime.emplace_back(MOVEMENT_2, 37110);
	m_vReadyTime.emplace_back(MOVEMENT_1, 37407);

	//m_vReadyTime.emplace_back(WAIT, 37689);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 39105);

	m_vReadyTime.emplace_back(MOVEMENT_1, 39305);
	m_vReadyTime.emplace_back(MOVEMENT_2, 39456);
	m_vReadyTime.emplace_back(MOVEMENT_1, 39753);

	//m_vReadyTime.emplace_back(WAIT, 40040);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 43223);

	m_vReadyTime.emplace_back(MOVEMENT_1, 43423);
	m_vReadyTime.emplace_back(MOVEMENT_2, 43574);
	m_vReadyTime.emplace_back(MOVEMENT_1, 43871);

	//m_vReadyTime.emplace_back(WAIT, 44155);

	m_vReadyTime.emplace_back(IDLE, 45850);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 46161);

	m_vReadyTime.emplace_back(MOVEMENT_1, 46361);
	m_vReadyTime.emplace_back(MOVEMENT_2, 46513);
	m_vReadyTime.emplace_back(MOVEMENT_1, 46810);

	//m_vReadyTime.emplace_back(WAIT, 47094);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 48518);

	m_vReadyTime.emplace_back(MOVEMENT_1, 48718);
	m_vReadyTime.emplace_back(MOVEMENT_2, 48869);
	m_vReadyTime.emplace_back(MOVEMENT_1, 49166);

	//m_vReadyTime.emplace_back(WAIT, 49449);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 50878);

	m_vReadyTime.emplace_back(MOVEMENT_1, 51078);
	m_vReadyTime.emplace_back(MOVEMENT_2, 51229);
	m_vReadyTime.emplace_back(MOVEMENT_1, 51526);

	//m_vReadyTime.emplace_back(WAIT, 51809);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 53221);

	m_vReadyTime.emplace_back(MOVEMENT_1, 53421);
	m_vReadyTime.emplace_back(MOVEMENT_2, 53573);
	m_vReadyTime.emplace_back(MOVEMENT_1, 53869);

	//m_vReadyTime.emplace_back(WAIT, 54155);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 55577);

	m_vReadyTime.emplace_back(MOVEMENT_1, 55777);
	m_vReadyTime.emplace_back(MOVEMENT_2, 55928);
	m_vReadyTime.emplace_back(MOVEMENT_1, 56225);

	//m_vReadyTime.emplace_back(WAIT, 56508);

	m_vReadyTime.emplace_back(MOVEMENT_READY, 57930);

	m_vReadyTime.emplace_back(MOVEMENT_1, 58130);
	m_vReadyTime.emplace_back(MOVEMENT_2, 58282);
	m_vReadyTime.emplace_back(MOVEMENT_1, 58579);

	//m_vReadyTime.emplace_back(WAIT, 58861);

	m_vReadyTime.emplace_back(IDLE, 61252);
}
