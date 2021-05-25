#pragma once
#include "NPC.h"
#include "FanNPCState.h"
#include "StateMachine.h"

class CFanNPC :
	public CNPC
{
public:
	CFanNPC();
	~CFanNPC();

	// CNPC을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

public:
	enum NPC_MOTION { IDLE, JUMP, CLAP, CLAP_UP };
	virtual void Set_Note() override;
	StateMachine<CFanNPC>*GetFSM() { return this->m_pStateMachine; }
	const NPC_MOTION Get_Motion() 
	{ 
		if(iter_CurNote != m_vNPCNote.end())
			return (*iter_CurNote).first;
		else
		{
			iter_CurNote = m_vNPCNote.end();
			return (*iter_CurNote).first;
		}
	}
	const vector<pair<NPC_MOTION, long long>>* Get_Vec() const { return &m_vNPCNote; }
	void Set_FrameKey(TCHAR* pKey) { m_pFrameKey = pKey; }

private:
	vector<pair<NPC_MOTION, long long>> m_vNPCNote;
	vector<pair<NPC_MOTION, long long>>::iterator iter_NextNote;
	vector<pair<NPC_MOTION, long long>>::iterator iter_CurNote;
	StateMachine<CFanNPC>* m_pStateMachine;
};

