#include "stdafx.h"
#include "LizardNPCState.h"
#include "SoundMgr.h"

LizardNPCState::LizardNPCState()
{
}


LizardNPCState::~LizardNPCState()
{
}

//L"NPC_Idle"
//L"NPC_Movement"
//L"NPC_Movement_1"
//L"NPC_React"

/////////////////////////////////////////////////////////

NPCLizard_IdleState * NPCLizard_IdleState::Instance()
{
	static NPCLizard_IdleState instance;
	return &instance;
}

void NPCLizard_IdleState::Enter(CLizardNPC * owner)
{
	owner->Set_FrameKey(L"NPCLizard_Idle");
	owner->Set_Frame(0, 6, 0, 100, system_clock::now());
}

void NPCLizard_IdleState::Execute(CLizardNPC * owner)
{
	if (owner->Get_Ready() == owner->MOVEMENT_READY)
		owner->GetFSM()->ChangeState(NPCLizard_ReadyState::Instance());
}

void NPCLizard_IdleState::Exit(CLizardNPC * owner)
{
}

/////////////////////////////////////////////////////////

NPCLizard_ReadyState * NPCLizard_ReadyState::Instance()
{
	static NPCLizard_ReadyState instance;
	return &instance;
}

void NPCLizard_ReadyState::Enter(CLizardNPC * owner)
{
	owner->Set_FrameKey(L"NPCLizard_Movement");
	owner->Set_Frame(0, 1, 1, 70, system_clock::now());
}

void NPCLizard_ReadyState::Execute(CLizardNPC * owner)
{
	if (owner->Get_Ready() == owner->MOVEMENT_1)
		owner->GetFSM()->ChangeState(NPCLizard_Movement1State::Instance());
}

void NPCLizard_ReadyState::Exit(CLizardNPC * owner)
{
}

/////////////////////////////////////////////////////////

NPCLizard_Movement1State * NPCLizard_Movement1State::Instance()
{
	static NPCLizard_Movement1State instance;
	return &instance;
}

void NPCLizard_Movement1State::Enter(CLizardNPC * owner)
{
	owner->Set_FrameKey(L"NPCLizard_Movement");
	owner->Set_Frame(0, 1, 0, 70, system_clock::now());
}

void NPCLizard_Movement1State::Execute(CLizardNPC * owner)
{
	if (owner->Get_Ready() == owner->MOVEMENT_2)
		owner->GetFSM()->ChangeState(NPCLizard_Movement2State::Instance());
	else if (owner->Get_Ready() == owner->TAIL_1)
		owner->GetFSM()->ChangeState(NPCLizard_Tail1State::Instance());
}

void NPCLizard_Movement1State::Exit(CLizardNPC * owner)
{
}

/////////////////////////////////////////////////////////

NPCLizard_Movement2State * NPCLizard_Movement2State::Instance()
{
	static NPCLizard_Movement2State instance;
	return &instance;
}

void NPCLizard_Movement2State::Enter(CLizardNPC * owner)
{
	owner->Set_FrameKey(L"NPCLizard_Movement");
	owner->Set_Frame(0, 1, 1, 70, system_clock::now());
}

void NPCLizard_Movement2State::Execute(CLizardNPC * owner)
{
	if (owner->Get_Ready() == owner->MOVEMENT_1)
		owner->GetFSM()->ChangeState(NPCLizard_Movement1State::Instance());
}

void NPCLizard_Movement2State::Exit(CLizardNPC * owner)
{
}

/////////////////////////////////////////////////////////

NPCLizard_Tail1State * NPCLizard_Tail1State::Instance()
{
	static NPCLizard_Tail1State instance;
	return &instance;
}

void NPCLizard_Tail1State::Enter(CLizardNPC * owner)
{
	owner->Set_FrameKey(L"NPCLizard_Movement_1");
	owner->Set_Frame(0, 3, 0, 40, system_clock::now());
}

void NPCLizard_Tail1State::Execute(CLizardNPC * owner)
{
	if (owner->Get_Ready() == owner->TAIL_2)
		owner->GetFSM()->ChangeState(NPCLizard_Tail2State::Instance());
	else if (owner->Get_Ready() == owner->REACTION)
	{
		if (owner->Get_Reaction())	//틀림
			owner->GetFSM()->ChangeState(NPCLizard_ReactBadState::Instance());
		else
			owner->GetFSM()->ChangeState(NPCLizard_ReactGoodState::Instance());
	}
}

void NPCLizard_Tail1State::Exit(CLizardNPC * owner)
{
}

/////////////////////////////////////////////////////////

NPCLizard_Tail2State * NPCLizard_Tail2State::Instance()
{
	static NPCLizard_Tail2State instance;
	return &instance;
}

void NPCLizard_Tail2State::Enter(CLizardNPC * owner)
{
	owner->Set_FrameKey(L"NPCLizard_Movement_1");
	owner->Set_Frame(0, 3, 1, 40, system_clock::now());
}

void NPCLizard_Tail2State::Execute(CLizardNPC * owner)
{
	if (owner->Get_Ready() == owner->TAIL_1)
		owner->GetFSM()->ChangeState(NPCLizard_Tail1State::Instance());
	else if (owner->Get_Ready() == owner->REACTION)
	{
		if (owner->Get_Reaction())	//틀림
			owner->GetFSM()->ChangeState(NPCLizard_ReactBadState::Instance());
		else
			owner->GetFSM()->ChangeState(NPCLizard_ReactGoodState::Instance());
	}
}

void NPCLizard_Tail2State::Exit(CLizardNPC * owner)
{
}

/////////////////////////////////////////////////////////

NPCLizard_ReactGoodState * NPCLizard_ReactGoodState::Instance()
{
	static NPCLizard_ReactGoodState instance;
	return &instance;
}

void NPCLizard_ReactGoodState::Enter(CLizardNPC * owner)
{
	CSoundMgr::Get_Instance()->PlaySoundW("LoveLizards_Reaction.wav", CSoundMgr::EFFECT);
	owner->Set_FrameKey(L"NPCLizard_React");
	owner->Set_Frame(0, 4, 1, 100, system_clock::now());
}

void NPCLizard_ReactGoodState::Execute(CLizardNPC * owner)
{
	if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(NPCLizard_IdleState::Instance());
	else if (owner->Get_Ready() == owner->MOVEMENT_READY)
		owner->GetFSM()->ChangeState(NPCLizard_ReadyState::Instance());
}

void NPCLizard_ReactGoodState::Exit(CLizardNPC * owner)
{
}

/////////////////////////////////////////////////////////

NPCLizard_ReactBadState * NPCLizard_ReactBadState::Instance()
{
	static NPCLizard_ReactBadState instance;
	return &instance;
}

void NPCLizard_ReactBadState::Enter(CLizardNPC * owner)
{
	CSoundMgr::Get_Instance()->PlaySoundW("LoveLizards_Reaction.wav", CSoundMgr::EFFECT);
	owner->Set_FrameKey(L"NPCLizard_React");
	owner->Set_Frame(0, 0, 0, 100, system_clock::now());
}

void NPCLizard_ReactBadState::Execute(CLizardNPC * owner)
{
	if (owner->Get_Ready() == owner->IDLE)
		owner->GetFSM()->ChangeState(NPCLizard_IdleState::Instance());
	else if (owner->Get_Ready() == owner->MOVEMENT_READY)
		owner->GetFSM()->ChangeState(NPCLizard_ReadyState::Instance());
}

void NPCLizard_ReactBadState::Exit(CLizardNPC * owner)
{
}
