#pragma once
#include "ButtonUI.h"
class CMedal :
	public CButtonUI
{
public:
	CMedal();
	virtual ~CMedal();

	// CButtonUI��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
};

