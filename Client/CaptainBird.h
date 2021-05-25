#pragma once
#include "NPC.h"
#include "CaptainBirdState.h"
#include "StateMachine.h"

class CCaptainBird :
	public CNPC
{
public:
	CCaptainBird();
	virtual ~CCaptainBird();

	// CNPC을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
	virtual void Set_Note() override;
	StateMachine<CCaptainBird>*GetFSM() { return this->m_pStateMachine; }

	enum BirdMotion { IDLE, TALK, WAIT, STRETCH, ANGRY, END };

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
	void UpdateEffect();
	void UpdateEffectPos();
	void MoveEffectFrame();

private:
	StateMachine<CCaptainBird>* m_pStateMachine;
	vector<pair<BirdMotion, long long>> m_vNPCMotion;
	vector<pair<BirdMotion, long long>>::iterator iter_Current;
	vector<pair<BirdMotion, long long>>::iterator iter_Next;

private:
	INFO m_tEffectInfo;
	RECT m_tEffectRect;
	FRAME m_tEffectFrame;
	int m_iSpeed;
};

