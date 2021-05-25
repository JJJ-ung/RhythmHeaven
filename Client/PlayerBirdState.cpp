#include "stdafx.h"
#include "PlayerBirdState.h"
#include "MouseMgr.h"

CPlayerBirdState::CPlayerBirdState()
{
}


CPlayerBirdState::~CPlayerBirdState()
{
}

//////////////////////////////////////////////////////////

PlayerBird_IdleState * PlayerBird_IdleState::Instance()
{
	static PlayerBird_IdleState instance;
	return &instance;
}

void PlayerBird_IdleState::Enter(CPlayerBird * owner)
{
	owner->Set_Frame(0, 4, 0, 80, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerBird_IdleState::Execute(CPlayerBird * owner)
{
	if (owner->Get_Ready() == owner->TOUCH_READY)
		owner->GetFSM()->ChangeState(PlayerBird_PeckReadyState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY)
		owner->GetFSM()->ChangeState(PlayerBird_StretchReadyState::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerBird_PeckState::Instance());
}

void PlayerBird_IdleState::Exit(CPlayerBird * owner)
{
}

//////////////////////////////////////////////////////////

PlayerBird_PeckState * PlayerBird_PeckState::Instance()
{
	static PlayerBird_PeckState instance;
	return &instance;
}

void PlayerBird_PeckState::Enter(CPlayerBird * owner)
{
	owner->Set_Frame(0, 5, 5, 30, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerBird_PeckState::Execute(CPlayerBird * owner)
{
	system_clock::duration _time = system_clock::now() - m_tEnterTime;
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_UP)
		owner->GetFSM()->ChangeState(PlayerBird_UpState::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SLIDE)
		owner->GetFSM()->ChangeState(PlayerBird_StretchState::Instance());
}

void PlayerBird_PeckState::Exit(CPlayerBird * owner)
{
}

//////////////////////////////////////////////////////////

PlayerBird_PeckReadyState * PlayerBird_PeckReadyState::Instance()
{
	static PlayerBird_PeckReadyState instance;
	return &instance;
}

void PlayerBird_PeckReadyState::Enter(CPlayerBird * owner)
{
	owner->Set_Frame(0, 4, 1, 100, system_clock::now());
	m_tEnterTime = system_clock::now();
	cout << " 준비 자세 확인용도 " << endl;
}

void PlayerBird_PeckReadyState::Execute(CPlayerBird * owner)
{
	system_clock::duration _time = system_clock::now() - m_tEnterTime;
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerBird_PeckState::Instance());
	else if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(PlayerBird_IdleState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY)
		owner->GetFSM()->ChangeState(PlayerBird_StretchReadyState::Instance());
}

void PlayerBird_PeckReadyState::Exit(CPlayerBird * owner)
{
}
//////////////////////////////////////////////////////////

PlayerBird_StretchState * PlayerBird_StretchState::Instance()
{
	static PlayerBird_StretchState instance;
	return &instance;
}

void PlayerBird_StretchState::Enter(CPlayerBird * owner)
{
	owner->Set_Frame(0, 5, 6, 50, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerBird_StretchState::Execute(CPlayerBird * owner)
{
	system_clock::duration _time = system_clock::now() - m_tEnterTime;
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerBird_PeckState::Instance());
	else if (_time > (milliseconds)800)
		owner->GetFSM()->ChangeState(PlayerBird_Wait2State::Instance());
}

void PlayerBird_StretchState::Exit(CPlayerBird * owner)
{
}
//////////////////////////////////////////////////////////

PlayerBird_StretchReadyState * PlayerBird_StretchReadyState::Instance()
{
	static PlayerBird_StretchReadyState instance;
	return &instance;
}

void PlayerBird_StretchReadyState::Enter(CPlayerBird * owner)
{
	owner->Set_Frame(0, 5, 3, 50, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerBird_StretchReadyState::Execute(CPlayerBird * owner)
{
	system_clock::duration _time = system_clock::now() - m_tEnterTime;
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerBird_PeckState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY2)
		owner->GetFSM()->ChangeState(PlayerBird_StretchReady2State::Instance());
}

void PlayerBird_StretchReadyState::Exit(CPlayerBird * owner)
{
}

/////////////////////////////////////////////////////////////////////////

PlayerBird_StretchReady2State * PlayerBird_StretchReady2State::Instance()
{
	static PlayerBird_StretchReady2State instance;
	return &instance;
}

void PlayerBird_StretchReady2State::Enter(CPlayerBird * owner)
{
	owner->Set_Frame(0, 6, 4, 30, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerBird_StretchReady2State::Execute(CPlayerBird * owner)
{
	system_clock::duration _time = system_clock::now() - m_tEnterTime;
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerBird_PeckState::Instance());
	else if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(PlayerBird_IdleState::Instance());
	else if (owner->Get_Ready() == owner->TOUCH_READY)
		owner->GetFSM()->ChangeState(PlayerBird_PeckReadyState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY)
		owner->GetFSM()->ChangeState(PlayerBird_StretchReadyState::Instance());
}

void PlayerBird_StretchReady2State::Exit(CPlayerBird * owner)
{
}

/////////////////////////////////////////////////////////////////////////

PlayerBird_UpState * PlayerBird_UpState::Instance()
{
	static PlayerBird_UpState instance;
	return &instance;
}

void PlayerBird_UpState::Enter(CPlayerBird * owner)
{
	owner->Set_Frame(0, 3, 2, 30, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerBird_UpState::Execute(CPlayerBird * owner)
{
	system_clock::duration _time = system_clock::now() - m_tEnterTime;
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerBird_PeckState::Instance());
	else if (_time > (milliseconds)200)
		owner->GetFSM()->ChangeState(PlayerBird_WaitState::Instance());
}

void PlayerBird_UpState::Exit(CPlayerBird * owner)
{
}

/////////////////////////////////////////////////////////////////////////

PlayerBird_WaitState * PlayerBird_WaitState::Instance()
{
	static PlayerBird_WaitState instance;
	return &instance;
}

void PlayerBird_WaitState::Enter(CPlayerBird * owner)
{
	owner->Set_Frame(3, 3, 2, 30, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerBird_WaitState::Execute(CPlayerBird * owner)
{
	if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(PlayerBird_IdleState::Instance());
	else if (owner->Get_Ready() == owner->TOUCH_READY)
		owner->GetFSM()->ChangeState(PlayerBird_PeckReadyState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY)
		owner->GetFSM()->ChangeState(PlayerBird_StretchReadyState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY2)
		owner->GetFSM()->ChangeState(PlayerBird_StretchReady2State::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerBird_PeckState::Instance());
}

void PlayerBird_WaitState::Exit(CPlayerBird * owner)
{
}

/////////////////////////////////////////////////////////////////////////

PlayerBird_Wait2State * PlayerBird_Wait2State::Instance()
{
	static PlayerBird_Wait2State instance;
	return &instance;
}

void PlayerBird_Wait2State::Enter(CPlayerBird * owner)
{
	owner->Set_Frame(5, 5, 6, 30, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void PlayerBird_Wait2State::Execute(CPlayerBird * owner)
{
	if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(PlayerBird_IdleState::Instance());
	else if (owner->Get_Ready() == owner->TOUCH_READY)
		owner->GetFSM()->ChangeState(PlayerBird_PeckReadyState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY)
		owner->GetFSM()->ChangeState(PlayerBird_StretchReadyState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY2)
		owner->GetFSM()->ChangeState(PlayerBird_StretchReady2State::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(PlayerBird_PeckState::Instance());
}

void PlayerBird_Wait2State::Exit(CPlayerBird * owner)
{
}
