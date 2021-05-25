#pragma once
#include "PlayerLizard.h"
#include "StateMachine.h"
#include "LizardNPCState.h"

class CPlayerLizardBody :
	public CPlayerLizard
{
public:
	CPlayerLizardBody();
	virtual ~CPlayerLizardBody();

	// CPlayerLizard을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

	enum MOTION {IDLE, MOVEMENT_READY, MOVEMENT_1, MOVEMENT_2, WAIT, TAIL_UP, TAIL_DOWN};

public:
	const MOTION Get_Ready()
	{
		if (iter_Current != m_vReadyTime.end())
			return (*iter_Current).first;
		else
		{
			iter_Current = m_vReadyTime.end();
			return (*iter_Current).first;
		}
	}

public:
	void Set_ReadyNote();
	StateMachine<CPlayerLizardBody>*GetFSM() { return this->m_pStateMachine; }
private:
	system_clock::time_point m_tTime;
	StateMachine<CPlayerLizardBody>* m_pStateMachine;
	vector<pair<MOTION, long long>> m_vReadyTime;
	vector<pair<MOTION, long long>>::iterator iter_Current;
	vector<pair<MOTION, long long>>::iterator iter_Next;

};

