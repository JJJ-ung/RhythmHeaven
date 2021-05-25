#pragma once
#include "ButtonUI.h"
class CInven :
	public CButtonUI
{
public:
	CInven();
	virtual ~CInven();

	// CButtonUI을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
};

