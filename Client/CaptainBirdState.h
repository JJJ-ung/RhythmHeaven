#pragma once
#include "State.h"
#include "CaptainBird.h"

class CCaptainBird;
class CaptainBirdState
{
public:
	CaptainBirdState();
	~CaptainBirdState();
};

class CaptainBirdState_IdleState :public State<CCaptainBird>
{
	CaptainBirdState_IdleState() {}
	CaptainBirdState_IdleState(const CaptainBirdState_IdleState&);
	system_clock::time_point m_tEnterTime;
public:
	static CaptainBirdState_IdleState*Instance();
	void Enter(CCaptainBird*owner);
	void Execute(CCaptainBird*owner);
	void Exit(CCaptainBird*owner);
};

class CaptainBirdState_WaitState :public State<CCaptainBird>
{
	CaptainBirdState_WaitState() {}
	CaptainBirdState_WaitState(const CaptainBirdState_WaitState&);
	system_clock::time_point m_tEnterTime;
public:
	static CaptainBirdState_WaitState*Instance();
	void Enter(CCaptainBird*owner);
	void Execute(CCaptainBird*owner);
	void Exit(CCaptainBird*owner);
};

class CaptainBirdState_TalkState :public State<CCaptainBird>
{
	CaptainBirdState_TalkState() {}
	CaptainBirdState_TalkState(const CaptainBirdState_TalkState&);
	system_clock::time_point m_tEnterTime;
public:
	static CaptainBirdState_TalkState*Instance();
	void Enter(CCaptainBird*owner);
	void Execute(CCaptainBird*owner);
	void Exit(CCaptainBird*owner);
};

class CaptainBirdState_StretchState :public State<CCaptainBird>
{
	CaptainBirdState_StretchState() {}
	CaptainBirdState_StretchState(const CaptainBirdState_StretchState&);
	system_clock::time_point m_tEnterTime;
public:
	static CaptainBirdState_StretchState*Instance();
	void Enter(CCaptainBird*owner);
	void Execute(CCaptainBird*owner);
	void Exit(CCaptainBird*owner);
};

class CaptainBirdState_AngryState :public State<CCaptainBird>
{
	CaptainBirdState_AngryState() {}
	CaptainBirdState_AngryState(const CaptainBirdState_AngryState&);
	system_clock::time_point m_tEnterTime;
public:
	static CaptainBirdState_AngryState*Instance();
	void Enter(CCaptainBird*owner);
	void Execute(CCaptainBird*owner);
	void Exit(CCaptainBird*owner);
};
