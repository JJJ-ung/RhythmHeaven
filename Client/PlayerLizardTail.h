#pragma once
#include "PlayerLizard.h"

class CPlayerLizardBody;
class CPlayerLizardTail :
	public CPlayerLizard
{
public:
	CPlayerLizardTail();
	virtual ~CPlayerLizardTail();

	// CPlayerLizard��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

private:
	POINT m_pPoint;
};

