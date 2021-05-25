#pragma once
#include "NPC.h"
#include "NPCBirdState.h"
#include "StateMachine.h"

class CNPCBird :
	public CNPC
{
public:
	CNPCBird();
	virtual ~CNPCBird();

	// CNPC을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
	virtual void Set_Note() override;
	StateMachine<CNPCBird>*GetFSM() { return this->m_pStateMachine; }

	enum BirdMotion { TOUCH_READY, SLIDE_READY, SLIDE_READY2, IDLE, PECK, PECK_UP, STRETCH };

	const BirdMotion Get_Ready()
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
	StateMachine<CNPCBird>* m_pStateMachine;
	vector<pair<BirdMotion, long long>> m_vNPCMotion;
	vector<pair<BirdMotion, long long>>::iterator iter_Current;
	vector<pair<BirdMotion, long long>>::iterator iter_Next;
};

