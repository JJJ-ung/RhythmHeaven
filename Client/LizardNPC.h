#pragma once
#include "NPC.h"
#include "StateMachine.h"
#include "LizardNPCState.h"

class CLizardNPC :
	public CNPC
{
public:
	CLizardNPC();
	virtual ~CLizardNPC();

	// CNPC을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
	virtual void Set_Note() override;
	StateMachine<CLizardNPC>*GetFSM() { return this->m_pStateMachine; }

	enum LizardMotion { IDLE, MOVEMENT_READY, MOVEMENT_1, MOVEMENT_2, TAIL_1, TAIL_2, REACTION };
	
	const LizardMotion Get_Ready()
	{
		if (iter_Current != m_vNPCMotion.end())
			return (*iter_Current).first;
		else
		{
			iter_Current = m_vNPCMotion.end();
			return (*iter_Current).first;
		}
	}
private:
	StateMachine<CLizardNPC>* m_pStateMachine;
	vector<pair<LizardMotion, long long>> m_vNPCMotion;
	vector<pair<LizardMotion, long long>>::iterator iter_Current;
	vector<pair<LizardMotion, long long>>::iterator iter_Next;
};

