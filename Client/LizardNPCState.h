#pragma once
#include "State.h"
#include "LizardNPC.h"

class CLizardNPC;
class LizardNPCState
{
public:
	LizardNPCState();
	~LizardNPCState();
};

class NPCLizard_IdleState :public State<CLizardNPC>
{
	NPCLizard_IdleState() {}
	NPCLizard_IdleState(const NPCLizard_IdleState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCLizard_IdleState*Instance();
	void Enter(CLizardNPC*owner);
	void Execute(CLizardNPC*owner);
	void Exit(CLizardNPC*owner);
};

class NPCLizard_ReadyState :public State<CLizardNPC>
{
	NPCLizard_ReadyState() {}
	NPCLizard_ReadyState(const NPCLizard_ReadyState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCLizard_ReadyState*Instance();
	void Enter(CLizardNPC*owner);
	void Execute(CLizardNPC*owner);
	void Exit(CLizardNPC*owner);
};

class NPCLizard_Movement1State :public State<CLizardNPC>
{
	NPCLizard_Movement1State() {}
	NPCLizard_Movement1State(const NPCLizard_Movement1State&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCLizard_Movement1State*Instance();
	void Enter(CLizardNPC*owner);
	void Execute(CLizardNPC*owner);
	void Exit(CLizardNPC*owner);
};

class NPCLizard_Movement2State :public State<CLizardNPC>
{
	NPCLizard_Movement2State() {}
	NPCLizard_Movement2State(const NPCLizard_Movement2State&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCLizard_Movement2State*Instance();
	void Enter(CLizardNPC*owner);
	void Execute(CLizardNPC*owner);
	void Exit(CLizardNPC*owner);
};

class NPCLizard_Tail1State :public State<CLizardNPC>
{
	NPCLizard_Tail1State() {}
	NPCLizard_Tail1State(const NPCLizard_Tail1State&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCLizard_Tail1State*Instance();
	void Enter(CLizardNPC*owner);
	void Execute(CLizardNPC*owner);
	void Exit(CLizardNPC*owner);
};

class NPCLizard_Tail2State :public State<CLizardNPC>
{
	NPCLizard_Tail2State() {}
	NPCLizard_Tail2State(const NPCLizard_Tail2State&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCLizard_Tail2State*Instance();
	void Enter(CLizardNPC*owner);
	void Execute(CLizardNPC*owner);
	void Exit(CLizardNPC*owner);
};

class NPCLizard_ReactGoodState :public State<CLizardNPC>
{
	NPCLizard_ReactGoodState() {}
	NPCLizard_ReactGoodState(const NPCLizard_ReactGoodState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCLizard_ReactGoodState*Instance();
	void Enter(CLizardNPC*owner);
	void Execute(CLizardNPC*owner);
	void Exit(CLizardNPC*owner);
};

class NPCLizard_ReactBadState :public State<CLizardNPC>
{
	NPCLizard_ReactBadState() {}
	NPCLizard_ReactBadState(const NPCLizard_ReactBadState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCLizard_ReactBadState*Instance();
	void Enter(CLizardNPC*owner);
	void Execute(CLizardNPC*owner);
	void Exit(CLizardNPC*owner);
};