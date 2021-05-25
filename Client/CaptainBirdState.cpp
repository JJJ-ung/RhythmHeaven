#include "stdafx.h"
#include "CaptainBirdState.h"


CaptainBirdState::CaptainBirdState()
{
}


CaptainBirdState::~CaptainBirdState()
{
}

///////////////////////////////////////////////////

CaptainBirdState_IdleState * CaptainBirdState_IdleState::Instance()
{
	static CaptainBirdState_IdleState instance;
	return &instance;
}

void CaptainBirdState_IdleState::Enter(CCaptainBird * owner)
{
	owner->Set_Frame(0, 2, 0, 160, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void CaptainBirdState_IdleState::Execute(CCaptainBird * owner)
{
	if (owner->Get_Reaction())
		owner->GetFSM()->ChangeState(CaptainBirdState_AngryState::Instance());
	else if (owner->Get_Ready() == owner->TALK)
		owner->GetFSM()->ChangeState(CaptainBirdState_TalkState::Instance());
}

void CaptainBirdState_IdleState::Exit(CCaptainBird * owner)
{
}

///////////////////////////////////////////////////

CaptainBirdState_WaitState * CaptainBirdState_WaitState::Instance()
{
	static CaptainBirdState_WaitState instance;
	return &instance;
}

void CaptainBirdState_WaitState::Enter(CCaptainBird * owner)
{
	owner->Set_Frame(2, 2, 0, 1000, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void CaptainBirdState_WaitState::Execute(CCaptainBird * owner)
{
	if (owner->Get_Reaction())
		owner->GetFSM()->ChangeState(CaptainBirdState_AngryState::Instance());
	else if (owner->Get_Ready() == owner->STRETCH)
		owner->GetFSM()->ChangeState(CaptainBirdState_StretchState::Instance());
}

void CaptainBirdState_WaitState::Exit(CCaptainBird * owner)
{
}

///////////////////////////////////////////////////

CaptainBirdState_TalkState * CaptainBirdState_TalkState::Instance()
{
	static CaptainBirdState_TalkState instance;
	return &instance;
}

void CaptainBirdState_TalkState::Enter(CCaptainBird * owner)
{
	owner->Set_Frame(0, 1, 3, 150, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void CaptainBirdState_TalkState::Execute(CCaptainBird * owner)
{
	if (owner->Get_Reaction())
		owner->GetFSM()->ChangeState(CaptainBirdState_AngryState::Instance());
	else if (owner->Get_Ready() == owner->WAIT)
		owner->GetFSM()->ChangeState(CaptainBirdState_WaitState::Instance());
	else if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(CaptainBirdState_IdleState::Instance());
	else if (owner->Get_Ready() == owner->END)
		owner->GetFSM()->ChangeState(CaptainBirdState_IdleState::Instance());
}

void CaptainBirdState_TalkState::Exit(CCaptainBird * owner)
{
}

///////////////////////////////////////////////////

CaptainBirdState_StretchState * CaptainBirdState_StretchState::Instance()
{
	static CaptainBirdState_StretchState instance;
	return &instance;
}

void CaptainBirdState_StretchState::Enter(CCaptainBird * owner)
{
	owner->Set_Frame(0, 2, 1, 150, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void CaptainBirdState_StretchState::Execute(CCaptainBird * owner)
{
	if (owner->Get_Reaction())
		owner->GetFSM()->ChangeState(CaptainBirdState_AngryState::Instance());
	else if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(CaptainBirdState_IdleState::Instance());
	else if (owner->Get_Ready() == owner->END)
		owner->GetFSM()->ChangeState(CaptainBirdState_IdleState::Instance());
}

void CaptainBirdState_StretchState::Exit(CCaptainBird * owner)
{
}

///////////////////////////////////////////////////

CaptainBirdState_AngryState * CaptainBirdState_AngryState::Instance()
{
	static CaptainBirdState_AngryState instance;
	return &instance;
}

void CaptainBirdState_AngryState::Enter(CCaptainBird * owner)
{
	owner->Set_Frame(0, 3, 2, 130, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void CaptainBirdState_AngryState::Execute(CCaptainBird * owner)
{
	if (!(owner->Get_Reaction()))
	{
		if (owner->Get_Ready() == owner->IDLE)
			owner->GetFSM()->ChangeState(CaptainBirdState_IdleState::Instance());
		else if (owner->Get_Ready() == owner->TALK)
			owner->GetFSM()->ChangeState(CaptainBirdState_TalkState::Instance());
		else if (owner->Get_Ready() == owner->WAIT)
			owner->GetFSM()->ChangeState(CaptainBirdState_WaitState::Instance());
		else if (owner->Get_Ready() == owner->STRETCH)
			owner->GetFSM()->ChangeState(CaptainBirdState_StretchState::Instance());
		else if (owner->Get_Ready() == owner->END)
			owner->GetFSM()->ChangeState(CaptainBirdState_IdleState::Instance());
	}
}

void CaptainBirdState_AngryState::Exit(CCaptainBird * owner)
{
}
