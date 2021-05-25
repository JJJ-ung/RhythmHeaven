#pragma once
#include "Player.h"
#include "PlayerFarmerState.h"

class CPlayerFarmer :
	public CPlayer
{
public:
	CPlayerFarmer();
	virtual ~CPlayerFarmer();

	// CPlayer��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

	StateMachine<CPlayerFarmer>*GetFSM() { return this->m_pStateMachine; }

private:
	StateMachine<CPlayerFarmer>* m_pStateMachine;

};

