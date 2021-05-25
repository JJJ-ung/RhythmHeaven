#include "stdafx.h"
#include "CaptainBird.h"
#include "ResourceMgr.h"
#include "MouseMgr.h"

CCaptainBird::CCaptainBird()
{
}


CCaptainBird::~CCaptainBird()
{
}

void CCaptainBird::Initialize()
{
	m_tInfo.fX = 85.f;
	m_tInfo.fY = 118.f;
	m_tInfo.fCX = 190.f;
	m_tInfo.fCY = 235.f;
	m_iSpeed = 3;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/BlueBirds_Captain.bmp", L"CaptainBird");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/BlueBirds_Effect.bmp", L"BirdEffect");

	m_tEffectInfo.fCX = 118.f;
	m_tEffectInfo.fCY = 96.f;
	m_tEffectInfo.fX = m_tInfo.fX + 72.f + (0.5f * m_tEffectInfo.fCX);
	m_tEffectInfo.fY = m_tInfo.fY + 118.f - m_tEffectInfo.fCY;

	m_tEffectFrame.iFrameStart = 0;
	m_tEffectFrame.iFrameEnd = 2;
	m_tEffectFrame.iFrameScene = 0;
	m_tEffectFrame.tFrameTime = system_clock::now();
	m_tEffectFrame.tFrameSpeed = 100;

	Set_Note();
	iter_Current = m_vNPCMotion.begin();
	iter_Next = m_vNPCMotion.begin();
	++iter_Next;

	m_pStateMachine = new StateMachine<CCaptainBird>(this);
	m_pStateMachine->SetCurrentState(CaptainBirdState_IdleState::Instance());
	m_pStateMachine->GetCurrentState()->Enter(this);
}

int CCaptainBird::Update()
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
	else
	{
		if (m_tInfo.fX > -95.f)
			m_tInfo.fX -= m_iSpeed;
		UpdateEffectPos();
	}

	m_pStateMachine->Update();

	return OBJ_NOEVENT;
}

void CCaptainBird::LateUpdate()
{
	UpdateEffect();
	CObj::FrameMove();

	if (m_bReaction)
		MoveEffectFrame();
}

void CCaptainBird::Render(HDC _hdc)
{
	CObj::UpdateRect();
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"CaptainBird");
	GdiTransparentBlt(_hdc,
		m_tRect.left, m_tRect.top,
		m_tInfo.fCX, m_tInfo.fCY,
		hMemDC,
		m_tFrame.iFrameStart * m_tInfo.fCX, m_tFrame.iFrameScene * m_tInfo.fCY,// 출력할 그림의 시작 좌표. 
		m_tInfo.fCX, m_tInfo.fCY,//그림의 전체 가로세로 크기 
		RGB(246, 255, 230));

	if (m_bReaction)
	{
		HDC hMemDC2 = CResourceMgr::Get_Instance()->FindImage(L"BirdEffect");
		GdiTransparentBlt(_hdc,
			m_tEffectRect.left, m_tEffectRect.top,
			m_tEffectInfo.fCX, m_tEffectInfo.fCY,
			hMemDC2,
			m_tEffectFrame.iFrameStart * m_tEffectInfo.fCX, m_tEffectFrame.iFrameScene * m_tEffectInfo.fCY,// 출력할 그림의 시작 좌표. 
			m_tEffectInfo.fCX, m_tEffectInfo.fCY,//그림의 전체 가로세로 크기 
			RGB(246, 255, 230));
	}
}

void CCaptainBird::Release()
{
}

void CCaptainBird::Set_Note()
{
	m_vNPCMotion.emplace_back(IDLE, 0);

	//쭉쭉뻗어
	m_vNPCMotion.emplace_back(TALK, 4227);
	m_vNPCMotion.emplace_back(WAIT, 5609);
	m_vNPCMotion.emplace_back(STRETCH, 6088);
	
	m_vNPCMotion.emplace_back(IDLE, 6888);

	m_vNPCMotion.emplace_back(TALK, 9772);
	m_vNPCMotion.emplace_back(IDLE, 10676);

	m_vNPCMotion.emplace_back(TALK, 13461);
	m_vNPCMotion.emplace_back(IDLE, 14370);

	m_vNPCMotion.emplace_back(TALK, 17157);
	m_vNPCMotion.emplace_back(IDLE, 18061);

	m_vNPCMotion.emplace_back(TALK, 20842);
	m_vNPCMotion.emplace_back(IDLE, 21752);

	m_vNPCMotion.emplace_back(END, 21752);
}

void CCaptainBird::UpdateEffect()
{
	m_tEffectRect.left = LONG(m_tEffectInfo.fX - m_tEffectInfo.fCX * 0.5f);
	m_tEffectRect.top = LONG(m_tEffectInfo.fY - (LONG(m_tEffectInfo.fCY) >> 1));
	m_tEffectRect.right = LONG(m_tEffectInfo.fX + m_tEffectInfo.fCX * 0.5f);
	m_tEffectRect.bottom = LONG(m_tEffectInfo.fY + m_tEffectInfo.fCY * 0.5f);
}

void CCaptainBird::UpdateEffectPos()
{
	m_tEffectInfo.fCX = 118.f;
	m_tEffectInfo.fCY = 96.f;
	m_tEffectInfo.fX = m_tInfo.fX + 72.f + (0.5f * m_tEffectInfo.fCX);
	m_tEffectInfo.fY = m_tInfo.fY + 118.f - m_tEffectInfo.fCY;
}

void CCaptainBird::MoveEffectFrame()
{
	if (duration_cast<milliseconds>(system_clock::now() - m_tEffectFrame.tFrameTime).count() > m_tEffectFrame.tFrameSpeed)
	{
		++m_tEffectFrame.iFrameStart;
		m_tEffectFrame.tFrameTime = system_clock::now();
	}
	if (m_tEffectFrame.iFrameStart > m_tEffectFrame.iFrameEnd)
		m_tEffectFrame.iFrameStart = 0;
}
