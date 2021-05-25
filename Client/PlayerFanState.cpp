#include "stdafx.h"
#include "PlayerFanState.h"
#include "PlayerFan.h"
#include "MouseMgr.h"

CPlayerFanState::CPlayerFanState()
{
}


CPlayerFanState::~CPlayerFanState()
{
}

///////////////////////////////////////////////////////

PlayerFan_IdleState * PlayerFan_IdleState::Instance()
{
	static PlayerFan_IdleState instance;
	return &instance;
}

void PlayerFan_IdleState::Enter(CPlayerFan * owner)
{
	owner->Set_FrameKey(L"Player_Idle");
	owner->Set_Frame(0, 1, 0, 150, system_clock::now());
}

void PlayerFan_IdleState::Execute(CPlayerFan * owner)
{
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerFan_ClapState::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SLIDE)
		owner->GetFSM()->ChangeState(PlayerFan_JumpState::Instance());
}

void PlayerFan_IdleState::Exit(CPlayerFan * owner)
{
}



PlayerFan_ClapState * PlayerFan_ClapState::Instance()
{
	static PlayerFan_ClapState instance;
	return &instance;
}

void PlayerFan_ClapState::Enter(CPlayerFan * owner)
{
	owner->Set_FrameKey(L"Player_Clap");
	owner->Set_Frame(0, 3, 0, 50, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerFan_ClapState::Execute(CPlayerFan * owner)
{
	system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
	if(CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerFan_ClapState::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SLIDE)
		owner->GetFSM()->ChangeState(PlayerFan_JumpState::Instance());
	else if (_time > (milliseconds)600)
		owner->GetFSM()->ChangeState(PlayerFan_IdleState::Instance());
}

void PlayerFan_ClapState::Exit(CPlayerFan * owner)
{
}



PlayerFan_JumpState * PlayerFan_JumpState::Instance()
{
	static PlayerFan_JumpState instance;
	return &instance;
}

void PlayerFan_JumpState::Enter(CPlayerFan * owner)
{
	owner->Set_FrameKey(L"Player_Jump");
	owner->Set_Frame(0, 3, 0, 100, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerFan_JumpState::Execute(CPlayerFan * owner)
{
	system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
	if (_time > (milliseconds)700)
		owner->GetFSM()->ChangeState(PlayerFan_IdleState::Instance());
}

void PlayerFan_JumpState::Exit(CPlayerFan * owner)
{
}
