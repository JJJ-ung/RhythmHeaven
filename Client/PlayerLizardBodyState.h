#pragma once
#include "State.h"
#include "PlayerLizardBody.h"

class CPlayerLizard;
class PlayerLizardBodyState
{
public:
	PlayerLizardBodyState();
	~PlayerLizardBodyState();
};

class Lizard_IdleState :public State<CPlayerLizardBody>
{
	Lizard_IdleState() {}
	Lizard_IdleState(const Lizard_IdleState&);
	system_clock::time_point m_tEnterTime;
public:
	static Lizard_IdleState*Instance();
	void Enter(CPlayerLizardBody*owner);
	void Execute(CPlayerLizardBody*owner);
	void Exit(CPlayerLizardBody*owner);
};

class Lizard_MovementReadyState :public State<CPlayerLizardBody>
{
	Lizard_MovementReadyState() {}
	Lizard_MovementReadyState(const Lizard_MovementReadyState&);
	system_clock::time_point m_tEnterTime;
public:
	static Lizard_MovementReadyState*Instance();
	void Enter(CPlayerLizardBody*owner);
	void Execute(CPlayerLizardBody*owner);
	void Exit(CPlayerLizardBody*owner);
};

class Lizard_Movement1State :public State<CPlayerLizardBody>
{
	Lizard_Movement1State() {}
	Lizard_Movement1State(const Lizard_Movement1State&);
	system_clock::time_point m_tEnterTime;
public:
	static Lizard_Movement1State*Instance();
	void Enter(CPlayerLizardBody*owner);
	void Execute(CPlayerLizardBody*owner);
	void Exit(CPlayerLizardBody*owner);
};

class Lizard_Movement2State :public State<CPlayerLizardBody>
{
	Lizard_Movement2State() {}
	Lizard_Movement2State(const Lizard_Movement2State&);
	system_clock::time_point m_tEnterTime;
public:
	static Lizard_Movement2State*Instance();
	void Enter(CPlayerLizardBody*owner);
	void Execute(CPlayerLizardBody*owner);
	void Exit(CPlayerLizardBody*owner);
};

/////////////////////////////////////////////////////////////////

class Lizard_KeyDownState :public State<CPlayerLizardBody>
{
	Lizard_KeyDownState() {}
	Lizard_KeyDownState(const Lizard_KeyDownState&);
	system_clock::time_point m_tEnterTime;
public:
	static Lizard_KeyDownState*Instance();
	void Enter(CPlayerLizardBody*owner);
	void Execute(CPlayerLizardBody*owner);
	void Exit(CPlayerLizardBody*owner);
};

/////////////////////////////////////////////////////////////////

class Lizard_UP_State :public State<CPlayerLizardBody>
{
	Lizard_UP_State() {}
	Lizard_UP_State(const Lizard_UP_State&);
	system_clock::time_point m_tEnterTime;
public:
	static Lizard_UP_State*Instance();
	void Enter(CPlayerLizardBody*owner);
	void Execute(CPlayerLizardBody*owner);
	void Exit(CPlayerLizardBody*owner);
};

class Lizard_DOWN_State :public State<CPlayerLizardBody>
{
	Lizard_DOWN_State() {}
	Lizard_DOWN_State(const Lizard_DOWN_State&);
	system_clock::time_point m_tEnterTime;
public:
	static Lizard_DOWN_State*Instance();
	void Enter(CPlayerLizardBody*owner);
	void Execute(CPlayerLizardBody*owner);
	void Exit(CPlayerLizardBody*owner);
};
