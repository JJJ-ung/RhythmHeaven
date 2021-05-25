#pragma once
#include "Obj.h"
class CButtonUI
	:public CObj
{
public:
	CButtonUI();
	virtual ~CButtonUI();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC _hdc) = 0;
	virtual void Release() = 0;

protected:
	int m_iDrawID;
};

