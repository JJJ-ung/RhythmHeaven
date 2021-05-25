#pragma once
#include "State.h"

//static system_clock::time_point Watch_Time;

class CFanNPC;
class FanNPCState
{
public:
	FanNPCState();
	~FanNPCState();
};

class NPCFan_IdleState :public State<CFanNPC>
{
	NPCFan_IdleState() {}
	NPCFan_IdleState(const NPCFan_IdleState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCFan_IdleState*Instance();
	void Enter(CFanNPC*owner);
	void Execute(CFanNPC*owner);
	void Exit(CFanNPC*owner);
};


class NPCFan_ClapState :public State<CFanNPC>
{
	NPCFan_ClapState() {}
	NPCFan_ClapState(const NPCFan_ClapState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCFan_ClapState*Instance();
	void Enter(CFanNPC*owner);
	void Execute(CFanNPC*owner);
	void Exit(CFanNPC*owner);
};

class NPCFan_JumpState :public State<CFanNPC>
{
	NPCFan_JumpState() {}
	NPCFan_JumpState(const NPCFan_JumpState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCFan_JumpState*Instance();
	void Enter(CFanNPC*owner);
	void Execute(CFanNPC*owner);
	void Exit(CFanNPC*owner);
};

class NPCFan_WatchState :public State<CFanNPC>
{
	NPCFan_WatchState() {}
	NPCFan_WatchState(const NPCFan_WatchState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCFan_WatchState*Instance();
	void Enter(CFanNPC*owner);
	void Execute(CFanNPC*owner);
	void Exit(CFanNPC*owner);
};

class NPCFan_WatchClapState :public State<CFanNPC>
{
	NPCFan_WatchClapState() {}
	NPCFan_WatchClapState(const NPCFan_WatchClapState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCFan_WatchClapState*Instance();
	void Enter(CFanNPC*owner);
	void Execute(CFanNPC*owner);
	void Exit(CFanNPC*owner);
};

class NPCFan_WatchJumpState :public State<CFanNPC>
{
	NPCFan_WatchJumpState() {}
	NPCFan_WatchJumpState(const NPCFan_WatchJumpState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCFan_WatchJumpState*Instance();
	void Enter(CFanNPC*owner);
	void Execute(CFanNPC*owner);
	void Exit(CFanNPC*owner);
};

class NPCFan_ClapUpState :public State<CFanNPC>
{
	NPCFan_ClapUpState() {}
	NPCFan_ClapUpState(const NPCFan_ClapUpState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCFan_ClapUpState*Instance();
	void Enter(CFanNPC*owner);
	void Execute(CFanNPC*owner);
	void Exit(CFanNPC*owner);
};

class NPCFan_WatchClapUpState :public State<CFanNPC>
{
	NPCFan_WatchClapUpState() {}
	NPCFan_WatchClapUpState(const NPCFan_WatchClapUpState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCFan_WatchClapUpState*Instance();
	void Enter(CFanNPC*owner);
	void Execute(CFanNPC*owner);
	void Exit(CFanNPC*owner);
};