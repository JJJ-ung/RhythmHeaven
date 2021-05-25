#pragma once
#include "NPC.h"
class CIdol :
	public CNPC
{
public:
	CIdol();
	virtual ~CIdol();

	// CNPC을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

public:
	virtual void Set_Note() override;

private:
	enum NPC_MOTION {IDLE_BASIC, IDLE_FIRST, IDLE_SECOND, POSE};
	vector<pair<NPC_MOTION, long long>> m_vNPCNote;
	vector<pair<NPC_MOTION, long long>>::iterator iter_NPCNote;
};

