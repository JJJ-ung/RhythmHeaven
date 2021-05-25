#pragma once
#include "NPC.h"
class CBirdEffect :
	public CNPC
{
public:
	CBirdEffect();
	virtual ~CBirdEffect();

	// CNPC을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
	virtual void Set_Note() override;

	enum NPC_MOTION {FADE_IN, QUICK_FADE_IN, ON_SCREEN, FADE_OUT, QUICK_FADE_OUT, OUT_SCREEN, ADD};
private:
	int m_iAlpha;
	int m_iAmount;
	int m_iIndex;
	BLENDFUNCTION _bf;
	vector<pair<NPC_MOTION, long long>> m_vNPCNote;
	vector<pair<NPC_MOTION, long long>>::iterator iter_NPCNote;
};

