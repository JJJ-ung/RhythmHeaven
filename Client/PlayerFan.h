#pragma once
#include "Player.h"
#include "PlayerFanState.h"

class CPlayerFan :
	public CPlayer
{
public:
	CPlayerFan();
	virtual ~CPlayerFan();

	// CPlayer을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

public:
	StateMachine<CPlayerFan>*GetFSM() { return this->m_pStateMachine; }
private:
	system_clock::time_point m_tTime;
	StateMachine<CPlayerFan>* m_pStateMachine;
};

