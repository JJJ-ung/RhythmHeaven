#include "stdafx.h"
#include "PlayerFan.h"
#include "ResourceMgr.h"
#include "KeyMgr.h"
#include "MouseMgr.h"
#include "StateMachine.h"

CPlayerFan::CPlayerFan()
{
}

CPlayerFan::~CPlayerFan()
{
	Safe_Delete(m_pStateMachine);
	Release();
}

void CPlayerFan::Initialize()
{
	m_tInfo.fX = 344.f;
	m_tInfo.fY = 451.f;
	m_tInfo.fCX = 197.f;
	m_tInfo.fCY = 226.f;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Player_Idle.bmp", L"Player_Idle");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Player_Clap.bmp", L"Player_Clap");
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/FanClub/Player_Jump.bmp", L"Player_Jump");

	m_pStateMachine = new StateMachine<CPlayerFan>(this);
	m_pStateMachine->SetCurrentState(PlayerFan_IdleState::Instance());
	m_pStateMachine->GetCurrentState()->Enter(this);
}

int CPlayerFan::Update()
{
	m_pStateMachine->Update();
	return OBJ_NOEVENT;
}

void CPlayerFan::LateUpdate()
{
	if (m_pFrameKey == L"Player_Clap")
		CObj::FrameStop();
	else if (m_pFrameKey == L"Player_Jump")
		CObj::FrameStop();
	else if (m_pFrameKey == L"Player_Idle")
		CObj::FrameMove();
}

void CPlayerFan::Render(HDC _hdc)
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

void CPlayerFan::Release()
{
}
