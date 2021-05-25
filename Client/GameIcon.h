#pragma once
#include "ButtonUI.h"
class CGameIcon :
	public CButtonUI
{
public:
	CGameIcon();
	virtual ~CGameIcon();

	// CButtonUI을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
public:
	void Update_BoxRect();
	void Update_MedalRect();
private:
	INFO box_info;
	RECT box_rect;
	FRAME box_frame;

	INFO Medal_info;
	RECT Medal_rect;
	FRAME Medal_frame;
private:
	FrameID::ID m_eFrame;
};

