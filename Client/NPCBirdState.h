#pragma once
#include "State.h"
#include "NPCBird.h"

class CNPCBird;
class NPCBirdState
{
public:
	NPCBirdState();
	~NPCBirdState();
};

class NPCBird_IdleState :public State<CNPCBird>
{
	NPCBird_IdleState() {}
	NPCBird_IdleState(const NPCBird_IdleState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCBird_IdleState*Instance();
	void Enter(CNPCBird*owner);
	void Execute(CNPCBird*owner);
	void Exit(CNPCBird*owner);
};

class NPCBird_PeckReadyState :public State<CNPCBird>
{
	NPCBird_PeckReadyState() {}
	NPCBird_PeckReadyState(const NPCBird_PeckReadyState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCBird_PeckReadyState*Instance();
	void Enter(CNPCBird*owner);
	void Execute(CNPCBird*owner);
	void Exit(CNPCBird*owner);
};

class NPCBird_SlideReadyState :public State<CNPCBird>
{
	NPCBird_SlideReadyState() {}
	NPCBird_SlideReadyState(const NPCBird_SlideReadyState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCBird_SlideReadyState*Instance();
	void Enter(CNPCBird*owner);
	void Execute(CNPCBird*owner);
	void Exit(CNPCBird*owner);
};

class NPCBird_SlideReady2State :public State<CNPCBird>
{
	NPCBird_SlideReady2State() {}
	NPCBird_SlideReady2State(const NPCBird_SlideReady2State&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCBird_SlideReady2State*Instance();
	void Enter(CNPCBird*owner);
	void Execute(CNPCBird*owner);
	void Exit(CNPCBird*owner);
};

class NPCBird_PeckState :public State<CNPCBird>
{
	NPCBird_PeckState() {}
	NPCBird_PeckState(const NPCBird_PeckState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCBird_PeckState*Instance();
	void Enter(CNPCBird*owner);
	void Execute(CNPCBird*owner);
	void Exit(CNPCBird*owner);
};

class NPCBird_PeckUpState :public State<CNPCBird>
{
	NPCBird_PeckUpState() {}
	NPCBird_PeckUpState(const NPCBird_PeckUpState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCBird_PeckUpState*Instance();
	void Enter(CNPCBird*owner);
	void Execute(CNPCBird*owner);
	void Exit(CNPCBird*owner);
};

class NPCBird_StretchState :public State<CNPCBird>
{
	NPCBird_StretchState() {}
	NPCBird_StretchState(const NPCBird_StretchState&);
	system_clock::time_point m_tEnterTime;
public:
	static NPCBird_StretchState*Instance();
	void Enter(CNPCBird*owner);
	void Execute(CNPCBird*owner);
	void Exit(CNPCBird*owner);
};