#pragma once
#include "ButtonUI.h"
class CInven :
	public CButtonUI
{
public:
	CInven();
	virtual ~CInven();

	// CButtonUI��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
};

