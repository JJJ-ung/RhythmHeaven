#pragma once
#include "State.h"
class CPlayerFan;
class CPlayerFanState
{
public:
	CPlayerFanState();
	~CPlayerFanState();
};

class PlayerFan_IdleState :public State<CPlayerFan>
{
	PlayerFan_IdleState() {}
	PlayerFan_IdleState(const PlayerFan_IdleState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerFan_IdleState*Instance();
	void Enter(CPlayerFan*owner);
	void Execute(CPlayerFan*owner);
	void Exit(CPlayerFan*owner);
};

class PlayerFan_ClapState :public State<CPlayerFan>
{
	PlayerFan_ClapState() {}
	PlayerFan_ClapState(const PlayerFan_ClapState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerFan_ClapState*Instance();
	void Enter(CPlayerFan*owner);
	void Execute(CPlayerFan*owner);
	void Exit(CPlayerFan*owner);
};

class PlayerFan_JumpState :public State<CPlayerFan>
{
	PlayerFan_JumpState() {}
	PlayerFan_JumpState(const PlayerFan_JumpState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerFan_JumpState*Instance();
	void Enter(CPlayerFan*owner);
	void Execute(CPlayerFan*owner);
	void Exit(CPlayerFan*owner);
};
