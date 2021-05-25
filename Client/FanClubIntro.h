#pragma once
#include "Scene.h"
class CFanClubIntro :
	public CScene
{
public:
	CFanClubIntro();
	virtual ~CFanClubIntro();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void Set_Note() override;

private:
	HWND m_hVideo;
};

