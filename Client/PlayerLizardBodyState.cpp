#include "stdafx.h"
#include "PlayerLizardBodyState.h"
#include "SoundMgr.h"
#include "MouseMgr.h"

PlayerLizardBodyState::PlayerLizardBodyState()
{
}


PlayerLizardBodyState::~PlayerLizardBodyState()
{
}

/////////////////////////////////////////////////////////////////

Lizard_IdleState * Lizard_IdleState::Instance()
{
	static Lizard_IdleState instance;
	return &instance;
}

void Lizard_IdleState::Enter(CPlayerLizardBody * owner)
{
	owner->Set_FrameKey(L"Lizard_Idle");
	owner->Set_Frame(0, 6, 0, 100, system_clock::now());
}

void Lizard_IdleState::Execute(CPlayerLizardBody * owner)
{
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(Lizard_KeyDownState::Instance());
	else if (owner->Get_Ready() == owner->MOVEMENT_READY)
		owner->GetFSM()->ChangeState(Lizard_MovementReadyState::Instance());
}

void Lizard_IdleState::Exit(CPlayerLizardBody * owner)
{
}

/////////////////////////////////////////////////////////////////

Lizard_MovementReadyState * Lizard_MovementReadyState::Instance()
{
	static Lizard_MovementReadyState instance;
	return &instance;
}

void Lizard_MovementReadyState::Enter(CPlayerLizardBody * owner)
{
	owner->Set_FrameKey(L"Lizard_movement");
	owner->Set_Frame(0, 1, 1, 70, system_clock::now());
}

void Lizard_MovementReadyState::Execute(CPlayerLizardBody * owner)
{
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(Lizard_KeyDownState::Instance());
	else if (owner->Get_Ready() == owner->MOVEMENT_1)
		owner->GetFSM()->ChangeState(Lizard_Movement1State::Instance());
}

void Lizard_MovementReadyState::Exit(CPlayerLizardBody * owner)
{
}

/////////////////////////////////////////////////////////////////

Lizard_Movement1State * Lizard_Movement1State::Instance()
{
	static Lizard_Movement1State instance;
	return &instance;
}

void Lizard_Movement1State::Enter(CPlayerLizardBody * owner)
{
	owner->Set_FrameKey(L"Lizard_movement");
	owner->Set_Frame(0, 1, 0, 70, system_clock::now());
}

void Lizard_Movement1State::Execute(CPlayerLizardBody * owner)
{
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(Lizard_KeyDownState::Instance());
	else if (owner->Get_Ready() == owner->MOVEMENT_2)
		owner->GetFSM()->ChangeState(Lizard_Movement2State::Instance());
	else if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(Lizard_IdleState::Instance());
}

void Lizard_Movement1State::Exit(CPlayerLizardBody * owner)
{
}

/////////////////////////////////////////////////////////////////

Lizard_Movement2State * Lizard_Movement2State::Instance()
{
	static Lizard_Movement2State instance;
	return &instance;
}

void Lizard_Movement2State::Enter(CPlayerLizardBody * owner)
{
	owner->Set_FrameKey(L"Lizard_movement");
	owner->Set_Frame(0, 1, 1, 70, system_clock::now());
}

void Lizard_Movement2State::Execute(CPlayerLizardBody * owner)
{
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
		owner->GetFSM()->ChangeState(Lizard_KeyDownState::Instance());
	else if (owner->Get_Ready() == owner->MOVEMENT_1)
		owner->GetFSM()->ChangeState(Lizard_Movement1State::Instance());
}

void Lizard_Movement2State::Exit(CPlayerLizardBody * owner)
{
}

/////////////////////////////////////////////////////////////////

Lizard_KeyDownState * Lizard_KeyDownState::Instance()
{
	static Lizard_KeyDownState instance;
	return &instance;
}

void Lizard_KeyDownState::Enter(CPlayerLizardBody * owner)
{
	owner->Set_FrameKey(L"Lizard_KeyDown");
	owner->Set_Frame(0, 0, 0, 70, system_clock::now());
}

void Lizard_KeyDownState::Execute(CPlayerLizardBody * owner)
{
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SCRATCHUP)
		owner->GetFSM()->ChangeState(Lizard_UP_State::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SCRATCHDOWN)
		owner->GetFSM()->ChangeState(Lizard_DOWN_State::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_UP)
	{
		if(owner->Get_Ready() == owner->IDLE)
			owner->GetFSM()->ChangeState(Lizard_IdleState::Instance());
		else if (owner->Get_Ready() == owner->MOVEMENT_READY)
			owner->GetFSM()->ChangeState(Lizard_MovementReadyState::Instance());
		else if (owner->Get_Ready() == owner->MOVEMENT_1)
			owner->GetFSM()->ChangeState(Lizard_Movement1State::Instance());
		else if (owner->Get_Ready() == owner->MOVEMENT_2)
			owner->GetFSM()->ChangeState(Lizard_Movement2State::Instance());
	}
}

void Lizard_KeyDownState::Exit(CPlayerLizardBody * owner)
{
}

/////////////////////////////////////////////////////////////////

Lizard_UP_State * Lizard_UP_State::Instance()
{
	static Lizard_UP_State instance;
	return &instance;
}

void Lizard_UP_State::Enter(CPlayerLizardBody * owner)
{
	owner->Set_FrameKey(L"Lizard_React");
	owner->Set_Frame(0, 2, 0, 70, system_clock::now());
}

void Lizard_UP_State::Execute(CPlayerLizardBody * owner)
{
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SCRATCHDOWN)
		owner->GetFSM()->ChangeState(Lizard_DOWN_State::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_UP)
	{
		if (owner->Get_Ready() == owner->IDLE)
			owner->GetFSM()->ChangeState(Lizard_IdleState::Instance());
		else if (owner->Get_Ready() == owner->MOVEMENT_READY)
			owner->GetFSM()->ChangeState(Lizard_MovementReadyState::Instance());
		else if (owner->Get_Ready() == owner->MOVEMENT_1)
			owner->GetFSM()->ChangeState(Lizard_Movement1State::Instance());
		else if (owner->Get_Ready() == owner->MOVEMENT_2)
			owner->GetFSM()->ChangeState(Lizard_Movement2State::Instance());
	}
}

void Lizard_UP_State::Exit(CPlayerLizardBody * owner)
{
}

/////////////////////////////////////////////////////////////////

Lizard_DOWN_State * Lizard_DOWN_State::Instance()
{
	static Lizard_DOWN_State instance;
	return &instance;
}

void Lizard_DOWN_State::Enter(CPlayerLizardBody * owner)
{
	owner->Set_FrameKey(L"Lizard_React");
	owner->Set_Frame(0, 1, 1, 105, system_clock::now());
}

void Lizard_DOWN_State::Execute(CPlayerLizardBody * owner)
{
	if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SCRATCHUP)
		owner->GetFSM()->ChangeState(Lizard_UP_State::Instance());
	else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_UP)
	{
		if (owner->Get_Ready() == owner->IDLE)
			owner->GetFSM()->ChangeState(Lizard_IdleState::Instance());
		else if (owner->Get_Ready() == owner->MOVEMENT_READY)
			owner->GetFSM()->ChangeState(Lizard_MovementReadyState::Instance());
		else if (owner->Get_Ready() == owner->MOVEMENT_1)
			owner->GetFSM()->ChangeState(Lizard_Movement1State::Instance());
		else if (owner->Get_Ready() == owner->MOVEMENT_2)
			owner->GetFSM()->ChangeState(Lizard_Movement2State::Instance());
	}
}

void Lizard_DOWN_State::Exit(CPlayerLizardBody * owner)
{
}
