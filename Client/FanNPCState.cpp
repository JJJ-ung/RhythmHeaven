#include "stdafx.h"
#include "FanNPCState.h"
#include "FanNPC.h"

FanNPCState::FanNPCState()
{
}


FanNPCState::~FanNPCState()
{
}

/////////////////////////////////////////

NPCFan_IdleState * NPCFan_IdleState::Instance()
{
	static NPCFan_IdleState instance;
	return &instance;
}

void NPCFan_IdleState::Enter(CFanNPC * owner)
{
	owner->Set_FrameKey(L"NPC_Fan_Idle");
	m_tEnterTime = system_clock::now();
	owner->Set_Frame(0, 3, 0, 150, m_tEnterTime);
	//cout << "IDLE" << endl;
}

void NPCFan_IdleState::Execute(CFanNPC * owner)
{
	if (owner->Get_Reaction())	//틀렸다
	{
		//Watch_Time = system_clock::now();
		if (owner->Get_Motion() == owner->CLAP)
			owner->GetFSM()->ChangeState(NPCFan_WatchClapState::Instance());
		else
			owner->GetFSM()->ChangeState(NPCFan_WatchState::Instance());
	}
	else
	{
		if (owner->Get_Motion() == owner->CLAP)
			owner->GetFSM()->ChangeState(NPCFan_ClapState::Instance());
	}
}

void NPCFan_IdleState::Exit(CFanNPC * owner)
{
}

///////////////////////////////////////////////////////////

NPCFan_WatchState * NPCFan_WatchState::Instance()
{
	static NPCFan_WatchState instance;
	return &instance;
}

void NPCFan_WatchState::Enter(CFanNPC * owner)
{
	owner->Set_FrameKey(L"NPC_Fan_Watch");
	m_tEnterTime = system_clock::now();
	owner->Set_Frame(0, 3, 0, 150, m_tEnterTime);
	//cout << "쳐다봄" << endl;

}

void NPCFan_WatchState::Execute(CFanNPC * owner)
{
	//쳐다보고 있는 Idle
	system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
	if (!owner->Get_Reaction())
	{
		if (owner->Get_Motion() == owner->CLAP)
			owner->GetFSM()->ChangeState(NPCFan_ClapState::Instance());
		else if(owner->Get_Motion() == owner->IDLE)
			owner->GetFSM()->ChangeState(NPCFan_IdleState::Instance());
	}
	else
	{
		if (owner->Get_Motion() == owner->CLAP)
			owner->GetFSM()->ChangeState(NPCFan_WatchClapState::Instance());
	}
}

void NPCFan_WatchState::Exit(CFanNPC * owner)
{
}

//////////////////////////////////////////////

NPCFan_ClapState * NPCFan_ClapState::Instance()
{
	static NPCFan_ClapState instance;
	return &instance;
}

void NPCFan_ClapState::Enter(CFanNPC * owner)
{
	owner->Set_FrameKey(L"NPC_Fan_Clap");
	owner->Set_Frame(0, 3, 0, 50, system_clock::now());
	m_tEnterTime = system_clock::now();
	//cout << "박수" << endl;
}

void NPCFan_ClapState::Execute(CFanNPC * owner)
{
	system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
	if (owner->Get_Reaction())	// 틀렸을때
	{
		if (owner->Get_Motion() == owner->CLAP_UP)
			owner->GetFSM()->ChangeState(NPCFan_WatchClapUpState::Instance());
		else if (_time > (milliseconds)500)
			owner->GetFSM()->ChangeState(NPCFan_WatchState::Instance());
	}
	else
	{
		if (owner->Get_Motion() == owner->CLAP_UP)
			owner->GetFSM()->ChangeState(NPCFan_ClapUpState::Instance());
		else if (_time > (milliseconds)500)
			owner->GetFSM()->ChangeState(NPCFan_IdleState::Instance());
	}
}

void NPCFan_ClapState::Exit(CFanNPC * owner)
{
}

////////////////////////////////////////////////////////////

NPCFan_JumpState * NPCFan_JumpState::Instance()
{
	static NPCFan_JumpState instance;
	return &instance;
}

void NPCFan_JumpState::Enter(CFanNPC * owner)
{
	owner->Set_FrameKey(L"NPC_Fan_Jump");
	owner->Set_Frame(0, 3, 0, 100, system_clock::now());
	m_tEnterTime = system_clock::now();
	//cout << "점프" << endl;

}

void NPCFan_JumpState::Execute(CFanNPC * owner)
{
	if (owner->Get_Reaction())	// 틀렸을때
	{
		//Watch_Time = system_clock::now();
		system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
		if (_time > (milliseconds)600)
			owner->GetFSM()->ChangeState(NPCFan_WatchState::Instance());
		else if (owner->Get_Motion() == owner->IDLE)
			owner->GetFSM()->ChangeState(NPCFan_WatchState::Instance());
	}
	else
	{
		system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
		if (_time > (milliseconds)600)
			owner->GetFSM()->ChangeState(NPCFan_IdleState::Instance());
		else if (owner->Get_Motion() == owner->IDLE)
			owner->GetFSM()->ChangeState(NPCFan_IdleState::Instance());
	}
}

void NPCFan_JumpState::Exit(CFanNPC * owner)
{
}

////////////////////////////////////////////////////////////////////

NPCFan_WatchClapState * NPCFan_WatchClapState::Instance()
{
	static NPCFan_WatchClapState instance;
	return &instance;
}

void NPCFan_WatchClapState::Enter(CFanNPC * owner)
{
	owner->Set_FrameKey(L"NPC_Fan_Watch_Clap");
	m_tEnterTime = system_clock::now();
	owner->Set_Frame(0, 3, 0, 50, system_clock::now());
	//cout << "쳐다보면서 박수" << endl;

}

void NPCFan_WatchClapState::Execute(CFanNPC * owner)
{
	system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
	if (!owner->Get_Reaction())
	{
		if (owner->Get_Motion() == owner->CLAP_UP)
			owner->GetFSM()->ChangeState(NPCFan_ClapUpState::Instance());
		else if (owner->Get_Motion() == owner->IDLE)
			owner->GetFSM()->ChangeState(NPCFan_IdleState::Instance());
	}
	else
	{
		if (owner->Get_Motion() == owner->CLAP_UP)
			owner->GetFSM()->ChangeState(NPCFan_WatchClapUpState::Instance());
		else if (owner->Get_Motion() == owner->IDLE)
			owner->GetFSM()->ChangeState(NPCFan_WatchState::Instance());
	}
}

void NPCFan_WatchClapState::Exit(CFanNPC * owner)
{
}

/////////////////////////////////////////////////////////////

NPCFan_WatchJumpState * NPCFan_WatchJumpState::Instance()
{
	static NPCFan_WatchJumpState instance;
	return &instance;
}

void NPCFan_WatchJumpState::Enter(CFanNPC * owner)
{
	owner->Set_FrameKey(L"NPC_Fan_Watch_Jump");
	owner->Set_Frame(0, 3, 0, 100, system_clock::now());
	m_tEnterTime = system_clock::now();
	// << "쳐다보면서 점프" << endl;

}

void NPCFan_WatchJumpState::Execute(CFanNPC * owner)
{
	system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
	if (!owner->Get_Reaction())
	{
		if (_time > (milliseconds)600)
			owner->GetFSM()->ChangeState(NPCFan_IdleState::Instance());
	}
	else
	{
		if (_time > (milliseconds)600)
			owner->GetFSM()->ChangeState(NPCFan_WatchState::Instance());
	}
}

void NPCFan_WatchJumpState::Exit(CFanNPC * owner)
{
}


/////////////////////////////////////////////////////////////

NPCFan_ClapUpState * NPCFan_ClapUpState::Instance()
{
	static NPCFan_ClapUpState instance;
	return &instance;
}

void NPCFan_ClapUpState::Enter(CFanNPC * owner)
{
	owner->Set_FrameKey(L"NPC_Fan_Clap");
	owner->Set_Frame(3, 3, 0, 100, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void NPCFan_ClapUpState::Execute(CFanNPC * owner)
{
	system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
	if (!owner->Get_Reaction())	//맞을때
	{
		if (owner->Get_Motion() == owner->JUMP)
			owner->GetFSM()->ChangeState(NPCFan_JumpState::Instance());
		else if (owner->Get_Motion() == owner->CLAP)
			owner->GetFSM()->ChangeState(NPCFan_ClapState::Instance());
		else if (_time > (milliseconds)500)
			owner->GetFSM()->ChangeState(NPCFan_IdleState::Instance());
	}
	else
	{
		if (owner->Get_Motion() == owner->JUMP)
			owner->GetFSM()->ChangeState(NPCFan_WatchJumpState::Instance());
		else if (owner->Get_Motion() == owner->CLAP)
			owner->GetFSM()->ChangeState(NPCFan_WatchClapState::Instance());
		else if (_time > (milliseconds)500)
			owner->GetFSM()->ChangeState(NPCFan_WatchState::Instance());
	}
}

void NPCFan_ClapUpState::Exit(CFanNPC * owner)
{
}

/////////////////////////////////////////////////

NPCFan_WatchClapUpState * NPCFan_WatchClapUpState::Instance()
{
	static NPCFan_WatchClapUpState instance;
	return &instance;
}

void NPCFan_WatchClapUpState::Enter(CFanNPC * owner)
{
	owner->Set_FrameKey(L"NPC_Fan_Watch_Clap");
	owner->Set_Frame(3, 3, 0, 100, system_clock::now());
	m_tEnterTime = system_clock::now();
}

void NPCFan_WatchClapUpState::Execute(CFanNPC * owner)
{
	system_clock::duration _time = duration_cast<milliseconds>(system_clock::now() - m_tEnterTime);
	if (!owner->Get_Reaction())	//맞을때
	{
		if (owner->Get_Motion() == owner->JUMP)
			owner->GetFSM()->ChangeState(NPCFan_JumpState::Instance());
		else if (owner->Get_Motion() == owner->CLAP)
			owner->GetFSM()->ChangeState(NPCFan_ClapState::Instance());
		else if (_time > (milliseconds)500)
			owner->GetFSM()->ChangeState(NPCFan_IdleState::Instance());
	}
	else
	{
		if (owner->Get_Motion() == owner->JUMP)
			owner->GetFSM()->ChangeState(NPCFan_WatchJumpState::Instance());
		else if (owner->Get_Motion() == owner->CLAP)
			owner->GetFSM()->ChangeState(NPCFan_WatchClapState::Instance());
		else if (_time > (milliseconds)500)
			owner->GetFSM()->ChangeState(NPCFan_WatchState::Instance());
	}
}

void NPCFan_WatchClapUpState::Exit(CFanNPC * owner)
{
}
