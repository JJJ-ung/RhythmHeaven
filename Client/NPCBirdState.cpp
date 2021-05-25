#include "stdafx.h"
#include "NPCBirdState.h"


NPCBirdState::NPCBirdState()
{
}


NPCBirdState::~NPCBirdState()
{
}

//////////////////////////////////////////////////////////

NPCBird_IdleState * NPCBird_IdleState::Instance()
{
	static NPCBird_IdleState instance;
	return &instance;
}

void NPCBird_IdleState::Enter(CNPCBird * owner)
{
	owner->Set_Frame(0, 4, 0, 80, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void NPCBird_IdleState::Execute(CNPCBird * owner)
{
	if (owner->Get_Ready() == owner->TOUCH_READY)
		owner->GetFSM()->ChangeState(NPCBird_PeckReadyState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY)
		owner->GetFSM()->ChangeState(NPCBird_SlideReadyState::Instance());
	else if (owner->Get_Ready() == owner->PECK)
		owner->GetFSM()->ChangeState(NPCBird_PeckState::Instance());
}

void NPCBird_IdleState::Exit(CNPCBird * owner)
{
}

//////////////////////////////////////////////////////////

NPCBird_PeckReadyState * NPCBird_PeckReadyState::Instance()
{
	static NPCBird_PeckReadyState instance;
	return &instance;
}

void NPCBird_PeckReadyState::Enter(CNPCBird * owner)
{
	owner->Set_Frame(0, 4, 1, 100, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void NPCBird_PeckReadyState::Execute(CNPCBird * owner)
{
	if (owner->Get_Ready() == owner->PECK)
		owner->GetFSM()->ChangeState(NPCBird_PeckState::Instance());
	else if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(NPCBird_IdleState::Instance());
}

void NPCBird_PeckReadyState::Exit(CNPCBird * owner)
{
}

//////////////////////////////////////////////////////////

NPCBird_SlideReadyState * NPCBird_SlideReadyState::Instance()
{
	static NPCBird_SlideReadyState instance;
	return &instance;
}

void NPCBird_SlideReadyState::Enter(CNPCBird * owner)
{
	owner->Set_Frame(0, 5, 3, 50, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void NPCBird_SlideReadyState::Execute(CNPCBird * owner)
{
	if (owner->Get_Ready() == owner->SLIDE_READY2)
		owner->GetFSM()->ChangeState(NPCBird_SlideReady2State::Instance());
	else if (owner->Get_Ready() == owner->PECK)
		owner->GetFSM()->ChangeState(NPCBird_PeckState::Instance());
}

void NPCBird_SlideReadyState::Exit(CNPCBird * owner)
{
}

//////////////////////////////////////////////////////////

NPCBird_SlideReady2State * NPCBird_SlideReady2State::Instance()
{
	static NPCBird_SlideReady2State instance;
	return &instance;
}

void NPCBird_SlideReady2State::Enter(CNPCBird * owner)
{
	owner->Set_Frame(0, 6, 4, 30, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void NPCBird_SlideReady2State::Execute(CNPCBird * owner)
{
	if (owner->Get_Ready() == owner->PECK)
		owner->GetFSM()->ChangeState(NPCBird_PeckState::Instance());
	else if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(NPCBird_IdleState::Instance());
}

void NPCBird_SlideReady2State::Exit(CNPCBird * owner)
{
}

//////////////////////////////////////////////////////////

NPCBird_PeckState * NPCBird_PeckState::Instance()
{
	static NPCBird_PeckState instance;
	return &instance;
}

void NPCBird_PeckState::Enter(CNPCBird * owner)
{
	owner->Set_Frame(0, 5, 5, 30, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void NPCBird_PeckState::Execute(CNPCBird * owner)
{
	if (owner->Get_Ready() == owner->PECK_UP)
		owner->GetFSM()->ChangeState(NPCBird_PeckUpState::Instance());
	else if (owner->Get_Ready() == owner->STRETCH)
		owner->GetFSM()->ChangeState(NPCBird_StretchState::Instance());
}

void NPCBird_PeckState::Exit(CNPCBird * owner)
{
}

//////////////////////////////////////////////////////////

NPCBird_PeckUpState * NPCBird_PeckUpState::Instance()
{
	static NPCBird_PeckUpState instance;
	return &instance;
}

void NPCBird_PeckUpState::Enter(CNPCBird * owner)
{
	owner->Set_Frame(0, 3, 2, 30, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void NPCBird_PeckUpState::Execute(CNPCBird * owner)
{
	if (owner->Get_Ready() == owner->SLIDE_READY)
		owner->GetFSM()->ChangeState(NPCBird_SlideReadyState::Instance());
	else if (owner->Get_Ready() == owner->TOUCH_READY)
		owner->GetFSM()->ChangeState(NPCBird_PeckReadyState::Instance());
	else if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(NPCBird_IdleState::Instance());
	else if (owner->Get_Ready() == owner->PECK)
		owner->GetFSM()->ChangeState(NPCBird_PeckState::Instance());
}

void NPCBird_PeckUpState::Exit(CNPCBird * owner)
{
}

//////////////////////////////////////////////////////////

NPCBird_StretchState * NPCBird_StretchState::Instance()
{
	static NPCBird_StretchState instance;
	return &instance;
}

void NPCBird_StretchState::Enter(CNPCBird * owner)
{
	owner->Set_Frame(0, 5, 6, 50, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void NPCBird_StretchState::Execute(CNPCBird * owner)
{
	if (owner->Get_Ready() == owner->SLIDE_READY)
		owner->GetFSM()->ChangeState(NPCBird_SlideReadyState::Instance());
	else if (owner->Get_Ready() == owner->TOUCH_READY)
		owner->GetFSM()->ChangeState(NPCBird_PeckReadyState::Instance());
	else if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(NPCBird_IdleState::Instance());
	else if (owner->Get_Ready() == owner->PECK)
		owner->GetFSM()->ChangeState(NPCBird_PeckState::Instance());
	else if (owner->Get_Ready() == owner->SLIDE_READY2)
		owner->GetFSM()->ChangeState(NPCBird_SlideReady2State::Instance());
}

void NPCBird_StretchState::Exit(CNPCBird * owner)
{
}
