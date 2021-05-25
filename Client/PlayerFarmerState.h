#pragma once
#include "State.h"
#include "PlayerFarmer.h"

class CPlayerFarmer;
class CPlayerFarmerState
{
public:
	CPlayerFarmerState();
	~CPlayerFarmerState();
};

class Farmer_WalkState :public State<CPlayerFarmer>
{
	Farmer_WalkState() {}
	Farmer_WalkState(const Farmer_WalkState&);
	system_clock::time_point m_tEnterTime;
public:
	static Farmer_WalkState*Instance();
	void Enter(CPlayerFarmer*owner);
	void Execute(CPlayerFarmer*owner);
	void Exit(CPlayerFarmer*owner);
};

class Farmer_StompState :public State<CPlayerFarmer>
{
	Farmer_StompState() {}
	Farmer_StompState(const Farmer_StompState&);
	system_clock::time_point m_tEnterTime;
public:
	static Farmer_StompState*Instance();
	void Enter(CPlayerFarmer*owner);
	void Execute(CPlayerFarmer*owner);
	void Exit(CPlayerFarmer*owner);
};

class Farmer_SlideState :public State<CPlayerFarmer>
{
	Farmer_SlideState() {}
	Farmer_SlideState(const Farmer_SlideState&);
	system_clock::time_point m_tEnterTime;
public:
	static Farmer_SlideState*Instance();
	void Enter(CPlayerFarmer*owner);
	void Execute(CPlayerFarmer*owner);
	void Exit(CPlayerFarmer*owner);
};
