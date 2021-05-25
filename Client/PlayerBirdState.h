#pragma once
#include "State.h"
#include "PlayerBird.h"

class CPlayerBird;
class CPlayerBirdState
{
public:
	CPlayerBirdState();
	~CPlayerBirdState();
};

class PlayerBird_IdleState :public State<CPlayerBird>
{
	PlayerBird_IdleState() {}
	PlayerBird_IdleState(const PlayerBird_IdleState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerBird_IdleState*Instance();
	void Enter(CPlayerBird*owner);
	void Execute(CPlayerBird*owner);
	void Exit(CPlayerBird*owner);
};

class PlayerBird_PeckState :public State<CPlayerBird>
{
	PlayerBird_PeckState() {}
	PlayerBird_PeckState(const PlayerBird_PeckState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerBird_PeckState*Instance();
	void Enter(CPlayerBird*owner);
	void Execute(CPlayerBird*owner);
	void Exit(CPlayerBird*owner);
};

class PlayerBird_PeckReadyState :public State<CPlayerBird>
{
	PlayerBird_PeckReadyState() {}
	PlayerBird_PeckReadyState(const PlayerBird_PeckReadyState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerBird_PeckReadyState*Instance();
	void Enter(CPlayerBird*owner);
	void Execute(CPlayerBird*owner);
	void Exit(CPlayerBird*owner);
};

class PlayerBird_StretchState :public State<CPlayerBird>
{
	PlayerBird_StretchState() {}
	PlayerBird_StretchState(const PlayerBird_StretchState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerBird_StretchState*Instance();
	void Enter(CPlayerBird*owner);
	void Execute(CPlayerBird*owner);
	void Exit(CPlayerBird*owner);
};

class PlayerBird_StretchReadyState :public State<CPlayerBird>
{
	PlayerBird_StretchReadyState() {}
	PlayerBird_StretchReadyState(const PlayerBird_StretchReadyState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerBird_StretchReadyState*Instance();
	void Enter(CPlayerBird*owner);
	void Execute(CPlayerBird*owner);
	void Exit(CPlayerBird*owner);
};

class PlayerBird_UpState :public State<CPlayerBird>
{
	PlayerBird_UpState() {}
	PlayerBird_UpState(const PlayerBird_UpState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerBird_UpState*Instance();
	void Enter(CPlayerBird*owner);
	void Execute(CPlayerBird*owner);
	void Exit(CPlayerBird*owner);
};

class PlayerBird_StretchReady2State :public State<CPlayerBird>
{
	PlayerBird_StretchReady2State() {}
	PlayerBird_StretchReady2State(const PlayerBird_StretchReady2State&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerBird_StretchReady2State*Instance();
	void Enter(CPlayerBird*owner);
	void Execute(CPlayerBird*owner);
	void Exit(CPlayerBird*owner);
};

class PlayerBird_WaitState :public State<CPlayerBird>
{
	PlayerBird_WaitState() {}
	PlayerBird_WaitState(const PlayerBird_WaitState&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerBird_WaitState*Instance();
	void Enter(CPlayerBird*owner);
	void Execute(CPlayerBird*owner);
	void Exit(CPlayerBird*owner);
};

class PlayerBird_Wait2State :public State<CPlayerBird>
{
	PlayerBird_Wait2State() {}
	PlayerBird_Wait2State(const PlayerBird_Wait2State&);
	system_clock::time_point m_tEnterTime;
public:
	static PlayerBird_Wait2State*Instance();
	void Enter(CPlayerBird*owner);
	void Execute(CPlayerBird*owner);
	void Exit(CPlayerBird*owner);
};