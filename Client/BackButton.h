#pragma once
#include "ButtonUI.h"
class CBackButton :
	public CButtonUI
{
public:
	CBackButton();
	virtual ~CBackButton();

	// CButtonUI��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
};

