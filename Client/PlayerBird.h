#pragma once
#include "Player.h"
#include "PlayerBirdState.h"

class CPlayerBird :
	public CPlayer
{
public:
	CPlayerBird();
	virtual ~CPlayerBird();

	// CPlayer을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

	enum BirdMotion { TOUCH_READY, SLIDE_READY, SLIDE_READY2, IDLE, WAIT, WAIT2 };

public:
	const BirdMotion Get_Ready()
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
	StateMachine<CPlayerBird>*GetFSM() { return this->m_pStateMachine; }

private:
	system_clock::time_point m_tTime;
	StateMachine<CPlayerBird>* m_pStateMachine;
	vector<pair<BirdMotion, long long>> m_vReadyTime;
	vector<pair<BirdMotion, long long>>::iterator iter_Current;
	vector<pair<BirdMotion, long long>>::iterator iter_Next;
};

